#include "pch.h"
#include "ControlPanel.h"

#include "resource.h"
#include <afxwin.h>      // 包含 CClientDC 定义
#include <afxcmn.h>      // 包含 MFC 通用控件定义
#include <afxext.h>      // 包含 MFC 扩展功能
#include <afxbutton.h>      // CMFCButton

IMPLEMENT_DYNAMIC(CControlPanel, CDialogEx)

CControlPanel::CControlPanel(CWnd *pParent) : CDialogEx(IDD_CONTROL_PANEL, pParent) {}

CControlPanel::~CControlPanel() {}

void CControlPanel::DoDataExchange(CDataExchange *pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_CAMERA_LIST, m_cameraList);
    DDX_Control(pDX, IDC_IP_ADDRESS, m_ipAddress);
    DDX_Control(pDX, IDC_CONNECT_BTN, m_btnConnect);
    DDX_Control(pDX, IDC_DISCONNECT_BTN, m_btnDisconnect);
    DDX_Control(pDX, IDC_BRIGHTNESS_SLIDER, m_sldBrightness);
    DDX_Control(pDX, IDC_CONTRAST_SLIDER, m_sldContrast);
    DDX_Control(pDX, IDC_SATURATION_SLIDER, m_sldSaturation);
    DDX_Control(pDX, IDC_RESOLUTION_COMBO, m_cmbResolution);
    DDX_Control(pDX, IDC_FRAME_RATE_COMBO, m_cmbFrameRate);
    DDX_Control(pDX, IDC_MOTION_DETECT_CHECK, m_chkMotionDetect);
    DDX_Control(pDX, IDC_AUTO_EXPOSURE_CHECK, m_chkAutoExposure);
    DDX_Control(pDX, IDC_AUTO_WB_CHECK, m_chkAutoWhiteBalance);

    // 添加缺失的控件绑定
    DDX_Control(pDX, IDC_CAPTURE_START_BTN, m_btnCaptureStart);
    DDX_Control(pDX, IDC_CAPTURE_STOP_BTN, m_btnCaptureStop);
    DDX_Control(pDX, IDC_SNAPSHOT_BTN, m_btnSnapshot);
    DDX_Control(pDX, IDC_RECORD_BTN, m_btnRecord);
}

BEGIN_MESSAGE_MAP(CControlPanel, CDialogEx)
ON_BN_CLICKED(IDC_CONNECT_BTN, &CControlPanel::OnConnectClicked)
ON_BN_CLICKED(IDC_DISCONNECT_BTN, &CControlPanel::OnDisconnectClicked)
ON_BN_CLICKED(IDC_CAPTURE_START_BTN, &CControlPanel::OnCaptureClicked)
ON_BN_CLICKED(IDC_CAPTURE_STOP_BTN, &CControlPanel::OnCaptureClicked)
ON_CBN_SELCHANGE(IDC_RESOLUTION_COMBO, &CControlPanel::OnSettingsChanged)
ON_CBN_SELCHANGE(IDC_FRAME_RATE_COMBO, &CControlPanel::OnSettingsChanged)
ON_NOTIFY(NM_CUSTOMDRAW, IDC_BRIGHTNESS_SLIDER, &CControlPanel::OnSliderCustomDraw)
ON_NOTIFY(NM_CUSTOMDRAW, IDC_CONTRAST_SLIDER, &CControlPanel::OnSliderCustomDraw)
ON_NOTIFY(NM_CUSTOMDRAW, IDC_SATURATION_SLIDER, &CControlPanel::OnSliderCustomDraw)
ON_BN_CLICKED(IDC_MOTION_DETECT_CHECK, &CControlPanel::OnSettingsChanged)
ON_BN_CLICKED(IDC_AUTO_EXPOSURE_CHECK, &CControlPanel::OnSettingsChanged)
ON_BN_CLICKED(IDC_AUTO_WB_CHECK, &CControlPanel::OnSettingsChanged)
END_MESSAGE_MAP()

BOOL CControlPanel::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // 创建控件组
    CreateConnectionGroup();
    CreateCaptureGroup();
    CreateSettingsGroup();
    CreateAdvancedGroup();

    // 初始化范围
    m_sldBrightness.SetRange(0, 100);
    m_sldContrast.SetRange(0, 100);
    m_sldSaturation.SetRange(0, 100);

    m_sldBrightness.SetPos(50);
    m_sldContrast.SetPos(50);
    m_sldSaturation.SetPos(50);

    // 分辨率选项
    m_cmbResolution.AddString(_T("1920x1080"));
    m_cmbResolution.AddString(_T("1280x720"));
    m_cmbResolution.AddString(_T("1024x768"));
    m_cmbResolution.SetCurSel(0);

    // 帧率选项
    m_cmbFrameRate.AddString(_T("30 FPS"));
    m_cmbFrameRate.AddString(_T("25 FPS"));
    m_cmbFrameRate.AddString(_T("20 FPS"));
    m_cmbFrameRate.AddString(_T("15 FPS"));
    m_cmbFrameRate.SetCurSel(0);

    // 默认IP
    m_ipAddress.SetAddress(192, 168, 1, 64);

    return TRUE;
}

void CControlPanel::CreateConnectionGroup()
{
    CRect rect(10, 10, 380, 150);
    m_connectionGroup.Create(_T("设备连接"), WS_CHILD | WS_VISIBLE | BS_GROUPBOX, rect, this, 0);

    // IP地址控件
    m_ipAddress.Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP, CRect(20, 40, 200, 65), this, IDC_IP_ADDRESS);

    // 连接按钮
    m_btnConnect.Create(_T("连接"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | WS_TABSTOP, CRect(210, 40, 290, 65), this,
                        IDC_CONNECT_BTN);
    SetButtonStyle(m_btnConnect, RGB(70, 130, 180), IDI_CONNECT);

    // 断开按钮
    m_btnDisconnect.Create(_T("断开"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | WS_TABSTOP, CRect(300, 40, 380, 65),
                           this, IDC_DISCONNECT_BTN);
    SetButtonStyle(m_btnDisconnect, RGB(200, 80, 80), IDI_DISCONNECT);

    // 设备列表
    m_cameraList.Create(WS_CHILD | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | WS_TABSTOP, CRect(20, 80, 360, 200),
                        this, IDC_CAMERA_LIST);
    m_cameraList.SetFont(GetFont());
}

void CControlPanel::CreateCaptureGroup()
{
    CRect rect(10, 160, 380, 300);
    m_captureGroup.Create(_T("采集控制"), WS_CHILD | WS_VISIBLE | BS_GROUPBOX, rect, this, 0);

    // 开始采集按钮
    m_btnCaptureStart.Create(_T("开始采集"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | WS_TABSTOP,
                             CRect(20, 190, 120, 215), this, IDC_CAPTURE_START_BTN);
    SetButtonStyle(m_btnCaptureStart, RGB(70, 170, 70), IDI_PLAY);

    // 停止采集按钮
    m_btnCaptureStop.Create(_T("停止采集"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | WS_TABSTOP,
                            CRect(130, 190, 230, 215), this, IDC_CAPTURE_STOP_BTN);
    SetButtonStyle(m_btnCaptureStop, RGB(200, 80, 80), IDI_STOP);

    // 截图按钮
    m_btnSnapshot.Create(_T("截图"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | WS_TABSTOP, CRect(240, 190, 340, 215),
                         this, IDC_SNAPSHOT_BTN);
    SetButtonStyle(m_btnSnapshot, RGB(90, 90, 180), IDI_CAMERA);

    // 录像按钮
    m_btnRecord.Create(_T("录像"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | WS_TABSTOP, CRect(20, 225, 120, 250), this,
                       IDC_RECORD_BTN);
    SetButtonStyle(m_btnRecord, RGB(180, 70, 70), IDI_RECORD);
}

void CControlPanel::CreateSettingsGroup()
{
    CRect rect(10, 310, 380, 470);
    m_settingsGroup.Create(_T("图像设置"), WS_CHILD | WS_VISIBLE | BS_GROUPBOX, rect, this, 0);

    // 亮度滑块
    m_sldBrightness.Create(WS_CHILD | WS_VISIBLE | TBS_AUTOTICKS | TBS_BOTH | TBS_HORZ, CRect(120, 340, 360, 370), this,
                           IDC_BRIGHTNESS_SLIDER);

    // 对比度滑块
    m_sldContrast.Create(WS_CHILD | WS_VISIBLE | TBS_AUTOTICKS | TBS_BOTH | TBS_HORZ, CRect(120, 380, 360, 410), this,
                         IDC_CONTRAST_SLIDER);

    // 饱和度滑块
    m_sldSaturation.Create(WS_CHILD | WS_VISIBLE | TBS_AUTOTICKS | TBS_BOTH | TBS_HORZ, CRect(120, 420, 360, 450), this,
                           IDC_SATURATION_SLIDER);

    // 标签
    CStatic *pLabel;
    pLabel = new CStatic();
    pLabel->Create(_T("亮度:"), WS_CHILD | WS_VISIBLE, CRect(20, 340, 110, 370), this);
    pLabel->SetFont(GetFont());

    pLabel = new CStatic();
    pLabel->Create(_T("对比度:"), WS_CHILD | WS_VISIBLE, CRect(20, 380, 110, 410), this);
    pLabel->SetFont(GetFont());

    pLabel = new CStatic();
    pLabel->Create(_T("饱和度:"), WS_CHILD | WS_VISIBLE, CRect(20, 420, 110, 450), this);
    pLabel->SetFont(GetFont());

    // 分辨率
    m_cmbResolution.Create(WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | WS_TABSTOP, CRect(120, 460, 260, 490), this,
                           IDC_RESOLUTION_COMBO);

    pLabel = new CStatic();
    pLabel->Create(_T("分辨率:"), WS_CHILD | WS_VISIBLE, CRect(20, 460, 110, 490), this);
    pLabel->SetFont(GetFont());

    // 帧率
    m_cmbFrameRate.Create(WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | WS_TABSTOP, CRect(270, 460, 360, 490), this,
                          IDC_FRAME_RATE_COMBO);

    pLabel = new CStatic();
    pLabel->Create(_T("帧率:"), WS_CHILD | WS_VISIBLE, CRect(210, 460, 260, 490), this);
    pLabel->SetFont(GetFont());
}

void CControlPanel::CreateAdvancedGroup()
{
    CRect rect(10, 480, 380, 580);
    m_advancedGroup.Create(_T("高级设置"), WS_CHILD | WS_VISIBLE | BS_GROUPBOX, rect, this, 0);

    // 移动侦测
    m_chkMotionDetect.Create(_T("启用移动侦测"), WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX | WS_TABSTOP,
                             CRect(20, 510, 180, 535), this, IDC_MOTION_DETECT_CHECK);
    m_chkMotionDetect.SetFont(GetFont());

    // 自动曝光
    m_chkAutoExposure.Create(_T("自动曝光"), WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX | WS_TABSTOP,
                             CRect(200, 510, 360, 535), this, IDC_AUTO_EXPOSURE_CHECK);
    m_chkAutoExposure.SetFont(GetFont());
    m_chkAutoExposure.SetCheck(BST_CHECKED);

    // 自动白平衡
    m_chkAutoWhiteBalance.Create(_T("自动白平衡"), WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX | WS_TABSTOP,
                                 CRect(20, 545, 180, 570), this, IDC_AUTO_WB_CHECK);
    m_chkAutoWhiteBalance.SetFont(GetFont());
    m_chkAutoWhiteBalance.SetCheck(BST_CHECKED);
}

void CControlPanel::SetButtonStyle(CButton &btn, COLORREF color, UINT iconId)
{
    // 设置图标
    HICON hIcon = AfxGetApp()->LoadIcon(iconId);
    if (hIcon)
    {
        btn.SetIcon(hIcon);
        btn.ModifyStyle(0, BS_ICON); // 确保按钮样式包含BS_ICON
    }

    // 注意：普通CButton不支持直接设置颜色，需要自绘或使用其他方法
}

void CControlPanel::UpdateDeviceList(const std::vector<CString> &devices)
{
    m_cameraList.ResetContent();
    for (const auto &device : devices)
    {
        m_cameraList.AddString(device);
    }

    if (!devices.empty())
    {
        m_cameraList.SetCurSel(0);
    }
}

void CControlPanel::SetConnectionStatus(bool connected)
{
    m_btnConnect.EnableWindow(!connected);
    m_btnDisconnect.EnableWindow(connected);
    m_cameraList.EnableWindow(!connected);
    m_ipAddress.EnableWindow(!connected);
}

void CControlPanel::OnConnectClicked()
{
    // 获取选择的IP地址
    BYTE ip1, ip2, ip3, ip4;
    m_ipAddress.GetAddress(ip1, ip2, ip3, ip4);
    CString ip;
    ip.Format(_T("%d.%d.%d.%d"), ip1, ip2, ip3, ip4);

    // 获取选择的设备
    CString device;
    int sel = m_cameraList.GetCurSel();
    if (sel != CB_ERR)
    {
        m_cameraList.GetLBText(sel, device);
    }

    // 连接到设备
    AfxMessageBox(_T("连接到: ") + device + _T(" (") + ip + _T(")"));

    // 更新状态
    SetConnectionStatus(true);
}

void CControlPanel::OnDisconnectClicked()
{
    // 断开设备连接
    AfxMessageBox(_T("设备已断开"));

    // 更新状态
    SetConnectionStatus(false);
}

void CControlPanel::OnCaptureClicked()
{
    // 开始/停止采集
    AfxMessageBox(_T("采集控制"));
}

void CControlPanel::OnSettingsChanged()
{
    // 更新参数显示
    UpdateParameterDisplay();

    // 获取当前值
    int brightness = m_sldBrightness.GetPos();
    int contrast = m_sldContrast.GetPos();
    int saturation = m_sldSaturation.GetPos();

    // 格式化消息
    CString strMsg;
    strMsg.Format(_T("参数已更新: %d/%d/%d"), brightness, contrast, saturation);
    AfxMessageBox(strMsg);
}

void CControlPanel::OnSliderCustomDraw(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);

    *pResult = 0;

    if (pNMCD->dwDrawStage == CDDS_PREPAINT)
    {
        *pResult = CDRF_NOTIFYPOSTPAINT;
    }
    else if (pNMCD->dwDrawStage == CDDS_POSTPAINT)
    {
        // 获取滑块控件
        CSliderCtrl *pSlider = reinterpret_cast<CSliderCtrl *>(CWnd::FromHandle(pNMCD->hdr.hwndFrom));

        // 获取滑块位置
        int pos = pSlider->GetPos();

        // 更新对应的显示值
        if (pSlider->GetDlgCtrlID() == IDC_BRIGHTNESS_SLIDER)
        {
            CString str;
            str.Format(_T("%d%%"), pos);
            SetDlgItemText(IDC_BRIGHTNESS_STATIC, str);
        }
        else if (pSlider->GetDlgCtrlID() == IDC_CONTRAST_SLIDER)
        {
            CString str;
            str.Format(_T("%d%%"), pos);
            SetDlgItemText(IDC_CONTRAST_STATIC, str);
        }
        else if (pSlider->GetDlgCtrlID() == IDC_SATURATION_SLIDER)
        {
            CString str;
            str.Format(_T("%d%%"), pos);
            SetDlgItemText(IDC_SATURATION_STATIC, str);
        }

        *pResult = CDRF_DODEFAULT;
    }
}

void CControlPanel::UpdateParameterDisplay()
{
    // 使用静态文本来显示值
    CString strValue;

    // 亮度
    strValue.Format(_T("%d%%"), m_sldBrightness.GetPos());
    SetDlgItemText(IDC_BRIGHTNESS_STATIC, strValue);

    // 对比度
    strValue.Format(_T("%d%%"), m_sldContrast.GetPos());
    SetDlgItemText(IDC_CONTRAST_STATIC, strValue);

    // 饱和度
    strValue.Format(_T("%d%%"), m_sldSaturation.GetPos());
    SetDlgItemText(IDC_SATURATION_STATIC, strValue);
}