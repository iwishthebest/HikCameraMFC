#include "pch.h"
#include "InfoPanel.h"
#include "resource.h"

IMPLEMENT_DYNAMIC(CInfoPanel, CDialogEx)

CInfoPanel::CInfoPanel(CWnd *pParent) : CDialogEx(IDD_INFO_PANEL, pParent)
{
    // 初始化默认值
    m_deviceInfo.model = _T("N/A");
    m_deviceInfo.serial = _T("N/A");
    m_deviceInfo.firmware = _T("N/A");
    m_deviceInfo.ip = _T("N/A");

    m_statusInfo.connectionStatus = _T("未连接");
    m_statusInfo.captureStatus = _T("未采集");
    m_statusInfo.resolution = _T("N/A");
    m_statusInfo.frameRate = _T("N/A");

    m_performanceInfo.cpuUsage = _T("0%");
    m_performanceInfo.memoryUsage = _T("0 MB");
    m_performanceInfo.networkUsage = _T("0 Kbps");
}

CInfoPanel::~CInfoPanel()
{
    // 清理字体
    if (m_boldFont.GetSafeHandle())
        m_boldFont.DeleteObject();
    if (m_normalFont.GetSafeHandle())
        m_normalFont.DeleteObject();
}

void CInfoPanel::DoDataExchange(CDataExchange *pDX) { CDialogEx::DoDataExchange(pDX); }

BEGIN_MESSAGE_MAP(CInfoPanel, CDialogEx)
ON_WM_DRAWITEM() // 处理Owner Draw控件的绘制
END_MESSAGE_MAP()

BOOL CInfoPanel::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // 创建字体
    m_boldFont.CreatePointFont(90, _T("Segoe UI"), nullptr);
    m_normalFont.CreatePointFont(85, _T("Segoe UI"), nullptr);

    // 创建信息组
    CreateDeviceInfoGroup();
    CreateStatusInfoGroup();
    CreatePerformanceGroup();

    return TRUE;
}

void CInfoPanel::CreateDeviceInfoGroup()
{
    // 创建设备信息分组框
    m_deviceGroup.Create(_T("设备信息"), WS_CHILD | WS_VISIBLE | BS_GROUPBOX, CRect(10, 10, 380, 150), this, 0);
    m_deviceGroup.SetFont(&m_boldFont);

    int yPos = 40;
    AddInfoItem(m_deviceGroup, _T("设备型号:"), m_deviceInfo.model, yPos);
    AddInfoItem(m_deviceGroup, _T("序列号:"), m_deviceInfo.serial, yPos);
    AddInfoItem(m_deviceGroup, _T("固件版本:"), m_deviceInfo.firmware, yPos);
    AddInfoItem(m_deviceGroup, _T("IP地址:"), m_deviceInfo.ip, yPos);
}

void CInfoPanel::CreateStatusInfoGroup()
{
    // 创建状态信息分组框
    m_statusGroup.Create(_T("状态信息"), WS_CHILD | WS_VISIBLE | BS_GROUPBOX, CRect(10, 160, 380, 280), this, 0);
    m_statusGroup.SetFont(&m_boldFont);

    int yPos = 190;
    AddInfoItem(m_statusGroup, _T("连接状态:"), m_statusInfo.connectionStatus, yPos);
    AddInfoItem(m_statusGroup, _T("采集状态:"), m_statusInfo.captureStatus, yPos);
    AddInfoItem(m_statusGroup, _T("分辨率:"), m_statusInfo.resolution, yPos);
    AddInfoItem(m_statusGroup, _T("帧率:"), m_statusInfo.frameRate, yPos);
}

void CInfoPanel::CreatePerformanceGroup()
{
    // 创建性能信息分组框
    m_performanceGroup.Create(_T("性能指标"), WS_CHILD | WS_VISIBLE | BS_GROUPBOX, CRect(10, 290, 380, 380), this, 0);
    m_performanceGroup.SetFont(&m_boldFont);

    int yPos = 320;
    AddInfoItem(m_performanceGroup, _T("CPU使用率:"), m_performanceInfo.cpuUsage, yPos);
    AddInfoItem(m_performanceGroup, _T("内存占用:"), m_performanceInfo.memoryUsage, yPos);
    AddInfoItem(m_performanceGroup, _T("网络带宽:"), m_performanceInfo.networkUsage, yPos);
}

void CInfoPanel::AddInfoItem(CStatic &group, const CString &label, const CString &value, int &yPos)
{
    CRect rect;
    group.GetWindowRect(&rect);
    ScreenToClient(&rect);

    // 创建Owner Draw静态控件
    CStatic *pLabel = new CStatic();
    CStatic *pValue = new CStatic();

    // 添加SS_OWNERDRAW风格
    pLabel->Create(label, WS_CHILD | WS_VISIBLE | SS_OWNERDRAW, CRect(20, yPos, 120, yPos + 20), this);
    pValue->Create(value, WS_CHILD | WS_VISIBLE | SS_OWNERDRAW, CRect(130, yPos, rect.right - 20, yPos + 20), this);

    // 存储指针
    m_deviceInfoItems.push_back({&(*pLabel), &(*pValue)});

    yPos += 25;
}

void CInfoPanel::UpdateDeviceInfo(const CString &model, const CString &serial, const CString &firmware,
                                  const CString &ip)
{
    m_deviceInfo.model = model;
    m_deviceInfo.serial = serial;
    m_deviceInfo.firmware = firmware;
    m_deviceInfo.ip = ip;

    // 更新显示
    if (m_deviceInfoItems.size() >= 4)
    {
        m_deviceInfoItems[0].second->SetWindowText(model);
        m_deviceInfoItems[1].second->SetWindowText(serial);
        m_deviceInfoItems[2].second->SetWindowText(firmware);
        m_deviceInfoItems[3].second->SetWindowText(ip);
    }
}

void CInfoPanel::UpdateStatusInfo(const CString &connectionStatus, const CString &captureStatus,
                                  const CString &resolution, const CString &frameRate)
{
    m_statusInfo.connectionStatus = connectionStatus;
    m_statusInfo.captureStatus = captureStatus;
    m_statusInfo.resolution = resolution;
    m_statusInfo.frameRate = frameRate;

    // 更新显示
    if (m_statusInfoItems.size() >= 4)
    {
        m_statusInfoItems[0].second->SetWindowText(connectionStatus);
        m_statusInfoItems[1].second->SetWindowText(captureStatus);
        m_statusInfoItems[2].second->SetWindowText(resolution);
        m_statusInfoItems[3].second->SetWindowText(frameRate);

        // 根据状态设置颜色
        // 触发重绘
        if (m_statusInfoItems.size() >= 4)
        {
            m_statusInfoItems[0].second->Invalidate();
            m_statusInfoItems[1].second->Invalidate();
        }
    }
}

void CInfoPanel::UpdatePerformanceInfo(const CString &cpuUsage, const CString &memoryUsage, const CString &networkUsage)
{
    m_performanceInfo.cpuUsage = cpuUsage;
    m_performanceInfo.memoryUsage = memoryUsage;
    m_performanceInfo.networkUsage = networkUsage;

    // 更新显示
    if (m_performanceItems.size() >= 3)
    {
        m_performanceItems[0].second->SetWindowText(cpuUsage);
        m_performanceItems[1].second->SetWindowText(memoryUsage);
        m_performanceItems[2].second->SetWindowText(networkUsage);

        // 根据CPU使用率设置颜色
        // 触发重绘
        if (m_performanceItems.size() >= 3)
        {
            m_performanceItems[0].second->Invalidate();
        }
    }
}

void CInfoPanel::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
    CDC *pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
    pDC->SetBkMode(TRANSPARENT);

    // 获取控件文本
    CString text;
    ::GetWindowText(lpDrawItemStruct->hwndItem, text.GetBuffer(256), 256);
    text.ReleaseBuffer();

    // 动态设置文本颜色
    if (m_statusInfoItems.size() >= 4)
    {
        if (lpDrawItemStruct->hwndItem == m_statusInfoItems[0].second->GetSafeHwnd())
        {
            pDC->SetTextColor(m_statusInfo.connectionStatus == _T("已连接") ? RGB(70, 200, 70) : RGB(200, 70, 70));
        }
        else if (lpDrawItemStruct->hwndItem == m_statusInfoItems[1].second->GetSafeHwnd())
        {
            pDC->SetTextColor(m_statusInfo.captureStatus == _T("正在采集") ? RGB(70, 200, 70) : RGB(200, 70, 70));
        }
    }

    if (m_performanceItems.size() >= 3)
    {
        if (lpDrawItemStruct->hwndItem == m_performanceItems[0].second->GetSafeHwnd())
        {
            int cpuValue = _ttoi(m_performanceInfo.cpuUsage.Left(m_performanceInfo.cpuUsage.GetLength() - 1));
            pDC->SetTextColor(cpuValue > 80 ? RGB(255, 100, 100)
                                            : (cpuValue > 60 ? RGB(255, 165, 0) : RGB(100, 200, 100)));
        }
    }

    // 统一绘制文本
    pDC->DrawText(text, &lpDrawItemStruct->rcItem, DT_LEFT | DT_VCENTER);
}