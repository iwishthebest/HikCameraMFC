#pragma once
#include "afxbutton.h"
#include "afxcmn.h"
#include "Resource.h"
#include <vector>
#include <afxdialogex.h>
#include <afxtempl.h>


// CControlPanel 类 - 相机控制面板
class CControlPanel : public CDialogEx
{
    DECLARE_DYNAMIC(CControlPanel)

  public:
    CControlPanel(CWnd *pParent = NULL);
    virtual ~CControlPanel();

    enum
    {
        IDD = IDD_CONTROL_PANEL
    };

    // 初始化控件
    virtual BOOL OnInitDialog();
    virtual void DoDataExchange(CDataExchange *pDX);

    // 更新设备列表
    void UpdateDeviceList(const std::vector<CString> &devices);

    // 设置连接状态
    void SetConnectionStatus(bool connected);

  protected:
    //virtual void DoDataExchange(CDataExchange *pDX);
    DECLARE_MESSAGE_MAP()

    afx_msg void OnConnectClicked();
    afx_msg void OnDisconnectClicked();
    afx_msg void OnCaptureClicked();
    afx_msg void OnSettingsChanged();
    afx_msg void OnSliderCustomDraw(NMHDR *pNMHDR, LRESULT *pResult);

  private:
    // 创建控件组
    void CreateConnectionGroup();
    void CreateCaptureGroup();
    void CreateSettingsGroup();
    void CreateAdvancedGroup();

    // 设置按钮样式
    void SetButtonStyle(CButton &btn, COLORREF color, UINT iconId);

    // 更新参数显示
    void UpdateParameterDisplay();

    // 分组框
    CStatic m_connectionGroup;
    CStatic m_captureGroup;
    CStatic m_settingsGroup;
    CStatic m_advancedGroup;

    // 控件
    CComboBox m_cameraList;
    CIPAddressCtrl m_ipAddress;
    CButton m_btnConnect;
    CButton m_btnDisconnect;
    CSliderCtrl m_sldBrightness;
    CSliderCtrl m_sldContrast;
    CSliderCtrl m_sldSaturation;
    CComboBox m_cmbResolution;
    CComboBox m_cmbFrameRate;
    CButton m_chkMotionDetect;
    CButton m_chkAutoExposure;
    CButton m_chkAutoWhiteBalance;
    CMFCButton m_btnCaptureStart;
    CMFCButton m_btnCaptureStop;
    CMFCButton m_btnSnapshot;
    CMFCButton m_btnRecord;

    // 静态文本用于显示滑块值
    CStatic m_stcBrightness;
    CStatic m_stcContrast;
    CStatic m_stcSaturation;

};