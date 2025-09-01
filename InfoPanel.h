#pragma once
#include "resource.h"
#include "afxcmn.h"
#include "afxwin.h"
#include <vector>

// CInfoPanel 类 - 显示设备和系统信息
class CInfoPanel : public CDialogEx
{
    DECLARE_DYNAMIC(CInfoPanel)

  public:
    CInfoPanel(CWnd *pParent = NULL);
    virtual ~CInfoPanel();

    enum
    {
        IDD = IDD_INFO_PANEL
    };

    // 初始化
    virtual BOOL OnInitDialog();

    // 更新设备信息
    void UpdateDeviceInfo(const CString &model, const CString &serial, const CString &firmware, const CString &ip);

    // 更新状态信息
    void UpdateStatusInfo(const CString &connectionStatus, const CString &captureStatus, const CString &resolution,
                          const CString &frameRate);

    // 更新性能信息
    void UpdatePerformanceInfo(const CString &cpuUsage, const CString &memoryUsage, const CString &networkUsage);

  protected:
    virtual void DoDataExchange(CDataExchange *pDX);
    afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
    DECLARE_MESSAGE_MAP()

  private:
    // 创建设备信息组
    void CreateDeviceInfoGroup();

    // 创建状态信息组
    void CreateStatusInfoGroup();

    // 创建性能信息组
    void CreatePerformanceGroup();

    // 添加信息项
    void AddInfoItem(CStatic &group, const CString &label, const CString &value, int &yPos);

  private:
    // 设备信息组
    CStatic m_deviceGroup;
    std::vector<std::pair<CStatic *, CStatic *>> m_deviceInfoItems;

    // 状态信息组
    CStatic m_statusGroup;
    std::vector<std::pair<CStatic *, CStatic *>> m_statusInfoItems;

    // 性能信息组
    CStatic m_performanceGroup;
    std::vector<std::pair<CStatic *, CStatic *>> m_performanceItems;

    // 信息存储
    struct
    {
        CString model;
        CString serial;
        CString firmware;
        CString ip;
    } m_deviceInfo;

    struct
    {
        CString connectionStatus;
        CString captureStatus;
        CString resolution;
        CString frameRate;
    } m_statusInfo;

    struct
    {
        CString cpuUsage;
        CString memoryUsage;
        CString networkUsage;
    } m_performanceInfo;

    // 字体
    CFont m_boldFont;
    CFont m_normalFont;
};