// HikCameraMFCDlg.h: 头文件
//

#pragma once
#include <vector>

// 相机信息结构体
struct CameraInfo
{
    CString ip;       // IP地址
    int port;         // 端口
    CString username; // 用户名
    CString password; // 密码
    LONG userID;      // 登录句柄
    LONG realHandle;  // 预览句柄
    LONG playPort;    // 播放端口
    bool isLoggedIn;  // 登录状态
    CWnd *displayWnd; // 显示窗口
    int listIndex;    // 在列表中的索引
};

// CHikCameraMFCDlg 对话框
class CHikCameraMFCDlg : public CDialogEx
{
    // 声明回调函数为友元（关键修改）
    friend void CALLBACK RealDataCallBack(LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize,
                                          void *pUser);

    // 构造
  public:
    CHikCameraMFCDlg(CWnd *pParent = nullptr); // 标准构造函数

    // 对话框数据
#ifdef AFX_DESIGN_TIME
    enum
    {
        IDD = IDD_HIKCAMERAMFC_DIALOG
    };
#endif

  protected:
    virtual void DoDataExchange(CDataExchange *pDX); // DDX/DDV 支持

    // 实现
  protected:
    HICON m_hIcon;

    // 生成的消息映射函数
    virtual BOOL OnInitDialog();
    afx_msg void OnSize(UINT nType, int cx, int cy); // 处理最大化 / 最小化
    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    afx_msg void OnBnClickedStartPreview(); // "开始预览"按钮的点击事件处理函数
    afx_msg void OnBnClickedBtnCapture();   // 抓图：采集图像
    afx_msg void OnCancel();                // 添加OnCancel声明
    DECLARE_MESSAGE_MAP()

    // 其他代码...
  private:
    // 移除原有单相机变量，替换为多相机容器
    std::vector<CameraInfo> m_cameras; // 相机列表
    CListCtrl m_cameraList;            // 相机列表控件
    int m_selectedIndex;               // 当前选中相机索引

    // 保留其他原有成员（布局、抓图等）
    // 抓图相关
    CString m_strCapturePath; // 保存抓图路径
    CString GetCurrentTimeStr();

    // 控件布局相关
    CMap<UINT, UINT, CRect, CRect> m_mapCtrlOrigRect; // 存储控件初始位置和大小
    bool m_bInitLayout;                               // 标记布局是否已初始化
    CRect m_rectOrigDlg;                              // 对话框初始客户区大小

    // 向列表添加相机
    void AddCameraToList(LPCTSTR lpszIP, int nPort);
    // 更新列表中相机的状态
    void UpdateCameraStatus(int nIndex, LPCTSTR lpszStatus);

  public:
    afx_msg void OnBnClickedNo();
    afx_msg void OnEnChangeEditIp();
    afx_msg void OnStnClickedVideoDisplay();
    afx_msg void OnBnClickedOk();
    afx_msg void OnBnClickedCancel();
    afx_msg void OnBnClickedBtnLogin();
    afx_msg void OnBnClickedBtnLogout();
    afx_msg void OnLvnItemchangedListCameras(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnBnClickedBtnBatchLogin();
    afx_msg void OnTcnSelchangeTabPreview(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnLvnItemchangedCameraList(NMHDR *pNMHDR, LRESULT *pResult);
    void AddCamera(CString ip, int port, CString user, CString pwd);
};
