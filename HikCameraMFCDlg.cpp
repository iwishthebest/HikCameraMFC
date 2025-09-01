// DemoDlg.cpp : 实现文件

#include "pch.h"          // 预编译头文件，通常包含 framework.h
#include "framework.h"    // MFC框架头文件
#include <string>          // 标准库头文件
#include "HCNetSDK.h"     // 第三方库头文件，海康SDK
#include "PlayM4.h"       // 第三方库头文件，播放库
#include "HikCameraMFC.h" // 项目特定头文件
#include "HikCameraMFCDlg.h" // 项目特定头文件，主对话框类
#include "afxdialogex.h"    // MFC对话框扩展类头文件

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
  public:
    CAboutDlg();

    // 对话框数据
#ifdef AFX_DESIGN_TIME
    enum
    {
        IDD = IDD_ABOUTBOX
    };
#endif

  protected:
    virtual void DoDataExchange(CDataExchange *pDX); // DDX/DDV 支持

    // 实现
  protected:
    DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX) {}

void CAboutDlg::DoDataExchange(CDataExchange *pDX) { CDialogEx::DoDataExchange(pDX); }

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)

END_MESSAGE_MAP()

// CHikCameraMFCDlg 对话框

// 在CHikCameraMFCDlg.cpp的构造函数中初始化（可选，建议初始化）：
CHikCameraMFCDlg::CHikCameraMFCDlg(CWnd *pParent /*=nullptr*/)
    : CDialogEx(IDD_HIKCAMERAMFC_DIALOG, pParent),
      m_bInitLayout(false)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHikCameraMFCDlg::DoDataExchange(CDataExchange *pDX) { CDialogEx::DoDataExchange(pDX); }

BEGIN_MESSAGE_MAP(CHikCameraMFCDlg, CDialogEx)
ON_WM_SIZE()
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()

ON_BN_CLICKED(IDNO, &CHikCameraMFCDlg::OnBnClickedNo)
// 添加以下行：关联按钮ID和处理函数
ON_BN_CLICKED(IDC_BTN_START_PREVIEW, &CHikCameraMFCDlg::OnBnClickedStartPreview)
ON_BN_CLICKED(IDC_BTN_CAPTURE, &CHikCameraMFCDlg::OnBnClickedBtnCapture) // 自动生成的映射
ON_EN_CHANGE(IDC_EDIT_IP, &CHikCameraMFCDlg::OnEnChangeEditIp)
ON_STN_CLICKED(IDC_VIDEO_DISPLAY, &CHikCameraMFCDlg::OnStnClickedVideoDisplay)
ON_BN_CLICKED(IDOK, &CHikCameraMFCDlg::OnBnClickedOk)
ON_BN_CLICKED(IDCANCEL, &CHikCameraMFCDlg::OnBnClickedCancel)
ON_BN_CLICKED(IDC_BTN_LOGIN, &CHikCameraMFCDlg::OnBnClickedBtnLogin)
ON_BN_CLICKED(IDC_BTN_LOGOUT, &CHikCameraMFCDlg::OnBnClickedBtnLogout)
ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_CAMERAS, &CHikCameraMFCDlg::OnLvnItemchangedListCameras)
ON_BN_CLICKED(IDC_BTN_BATCH_LOGIN, &CHikCameraMFCDlg::OnBnClickedBtnBatchLogin)
ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_PREVIEW, &CHikCameraMFCDlg::OnTcnSelchangeTabPreview)
ON_NOTIFY(LVN_ITEMCHANGED, IDC_CAMERA_LIST, &CHikCameraMFCDlg::OnLvnItemchangedCameraList)
END_MESSAGE_MAP()

// CHikCameraMFCDlg 消息处理程序

BOOL CHikCameraMFCDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // 初始禁用注销按钮
    GetDlgItem(IDC_BTN_LOGOUT)->EnableWindow(FALSE);

    // 设置IDC_EDIT_IP的默认值
    SetDlgItemText(IDC_EDIT_IP, _T("192.168.0.101")); // 使用_T宏确保 Unicode 兼容性
    SetDlgItemText(IDC_EDIT_PORT, _T("8000"));        // 海康默认端口
    SetDlgItemText(IDC_EDIT_USERNAME, _T("admin"));
    SetDlgItemText(IDC_EDIT_PASSWORD, _T("fkqxk010"));

    // 初始化SDK
    if (!NET_DVR_Init())
    {
        AfxMessageBox(_T("SDK初始化失败！错误码：") + CString(std::to_string(NET_DVR_GetLastError()).c_str()));
        return FALSE;
    }
    // 设置连接超时和重连
    NET_DVR_SetConnectTime(2000, 1);
    NET_DVR_SetReconnect(10000, TRUE);

    // 将“关于...”菜单项添加到系统菜单中。

    // IDM_ABOUTBOX 必须在系统命令范围内。
    ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
    ASSERT(IDM_ABOUTBOX < 0xF000);

    CMenu *pSysMenu = GetSystemMenu(FALSE);
    if (pSysMenu != nullptr)
    {
        BOOL bNameValid;
        CString strAboutMenu;
        bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
        ASSERT(bNameValid);
        if (!strAboutMenu.IsEmpty())
        {
            pSysMenu->AppendMenu(MF_SEPARATOR);
            pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
        }
    }

    // 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
    //  执行此操作
    SetIcon(m_hIcon, TRUE);  // 设置大图标
    SetIcon(m_hIcon, FALSE); // 设置小图标

    // TODO: 在此添加额外的初始化代码
    
// 初始化相机列表
    m_cameraList.SubclassDlgItem(IDC_CAMERA_LIST, this);
    m_cameraList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
    m_cameraList.InsertColumn(0, _T("序号"), LVCFMT_LEFT, 50);
    m_cameraList.InsertColumn(1, _T("IP地址"), LVCFMT_LEFT, 120);
    m_cameraList.InsertColumn(2, _T("端口"), LVCFMT_LEFT, 60);
    m_cameraList.InsertColumn(3, _T("状态"), LVCFMT_LEFT, 80);
    m_cameraList.InsertColumn(4, _T("操作"), LVCFMT_LEFT, 200);

    // 添加测试相机（可通过按钮动态添加）
    AddCamera(_T("192.168.0.101"), 8000, _T("admin"), _T("12345"));
    AddCamera(_T("192.168.0.102"), 8000, _T("admin"), _T("12345"));
    //
    // 初始化布局变量
    m_bInitLayout = false;
    GetClientRect(m_rectOrigDlg); // 记录对话框初始大小

    // 所有需要调整的控件ID（参考Resource.h）
    UINT arrCtrlIDs[] = {
        IDC_EDIT_IP,           IDC_EDIT_PORT,   IDC_EDIT_USERNAME, IDC_EDIT_PASSWORD, IDC_VIDEO_DISPLAY,
        IDC_BTN_START_PREVIEW, IDC_BTN_CAPTURE, IDC_BTN_LOGIN,     IDC_BTN_LOGOUT,    IDC_STATIC1,
        IDC_STATIC2,           IDC_STATIC3,     IDC_STATIC4,       IDC_STATIC_STATUS, IDC_STATIC_CAPTURE_INFO};
    int nCtrlCount = sizeof(arrCtrlIDs) / sizeof(UINT);

    // 记录每个控件的初始位置和大小（客户区坐标）
    for (int i = 0; i < nCtrlCount; i++)
    {
        CWnd *pCtrl = GetDlgItem(arrCtrlIDs[i]);
        if (pCtrl && pCtrl->GetSafeHwnd())
        {
            CRect rectCtrl;
            pCtrl->GetWindowRect(rectCtrl);
            ScreenToClient(rectCtrl); // 转换为对话框客户区坐标
            m_mapCtrlOrigRect.SetAt(arrCtrlIDs[i], rectCtrl);
        }
    }

    m_bInitLayout = true;

    return TRUE; // 除非将焦点设置到控件，否则返回 TRUE
}

void CHikCameraMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
    if ((nID & 0xFFF0) == IDM_ABOUTBOX)
    {
        CAboutDlg dlgAbout;
        dlgAbout.DoModal();
    }
    else
    {
        CDialogEx::OnSysCommand(nID, lParam);
    }
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CHikCameraMFCDlg::OnPaint()
{
    if (IsIconic())
    {
        CPaintDC dc(this); // 用于绘制的设备上下文

        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        // 使图标在工作区矩形中居中
        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        // 绘制图标
        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        CDialogEx::OnPaint();
    }
}

void CHikCameraMFCDlg::OnSize(UINT nType, int cx, int cy)
{
    CDialogEx::OnSize(nType, cx, cy);

    // 跳过初始化阶段或窗口最小化的情况
    if (!m_bInitLayout || nType == SIZE_MINIMIZED)
        return;

    // 计算宽高缩放比例（相对于初始大小）
    double dScaleX = (double)cx / m_rectOrigDlg.Width();
    double dScaleY = (double)cy / m_rectOrigDlg.Height();

    // 遍历所有控件，按比例调整
    POSITION pos = m_mapCtrlOrigRect.GetStartPosition();
    while (pos)
    {
        UINT nCtrlID;
        CRect rectOrig;
        m_mapCtrlOrigRect.GetNextAssoc(pos, nCtrlID, rectOrig);

        CWnd *pCtrl = GetDlgItem(nCtrlID);
        if (pCtrl && pCtrl->GetSafeHwnd())
        {
            // 计算新位置和大小（四舍五入）
            int nNewLeft = (int)(rectOrig.left * dScaleX);
            int nNewTop = (int)(rectOrig.top * dScaleY);
            int nNewWidth = (int)(rectOrig.Width() * dScaleX);
            int nNewHeight = (int)(rectOrig.Height() * dScaleY);

            // 特殊处理视频显示区域（让其占更大空间）
            if (nCtrlID == IDC_VIDEO_DISPLAY)
            {
                nNewLeft = 20;         // 左边距20px
                nNewTop = 20;          // 上边距20px
                nNewWidth = cx - 40;   // 右边距20px
                nNewHeight = cy - 120; // 底部预留120px给按钮和状态
            }

            // 调整控件位置和大小
            pCtrl->MoveWindow(nNewLeft, nNewTop, nNewWidth, nNewHeight);
        }
    }
}

// 当用户拖动最小化窗口时系统调用此函数取得光标
// 显示。
HCURSOR CHikCameraMFCDlg::OnQueryDragIcon() { return static_cast<HCURSOR>(m_hIcon); }

// 在HikCameraMFCDlg.cpp文件中添加预览回调函数，用于处理接收到的视频数据：
void CALLBACK RealDataCallBack(LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void *pUser)
{
    CameraInfo *cam = (CameraInfo *)pUser;
    if (!cam)
        return;

    if (dwDataType == NET_DVR_SYSHEAD)
    {
        if (!PlayM4_GetPort(&cam->playPort))
        {
            AfxMessageBox(_T("获取播放端口失败！"));
            return;
        }
        if (!PlayM4_SetStreamOpenMode(cam->playPort, STREAME_REALTIME))
        {
            PlayM4_FreePort(cam->playPort);
            cam->playPort = -1;
            return;
        }
        if (!PlayM4_OpenStream(cam->playPort, pBuffer, dwBufSize, 1024 * 1024))
        {
            PlayM4_FreePort(cam->playPort);
            cam->playPort = -1;
            return;
        }
        if (!PlayM4_Play(cam->playPort, cam->displayWnd->m_hWnd))
        {
            PlayM4_CloseStream(cam->playPort);
            PlayM4_FreePort(cam->playPort);
            cam->playPort = -1;
            return;
        }
        if (cam->playPort != -1)
        {
            PlayM4_Stop(cam->playPort);        // 停止播放
            PlayM4_CloseStream(cam->playPort); // 关闭流
            PlayM4_FreePort(cam->playPort);    // 释放端口（关键）
            cam->playPort = -1;
        }
    }
    else if (dwDataType == NET_DVR_STREAMDATA)
    {
        if (cam->playPort != -1)
        {
            PlayM4_InputData(cam->playPort, pBuffer, dwBufSize);
        }
    }
}

// 在资源视图中，双击 “开始预览” 按钮，自动生成按钮点击事件处理函数，在HikCameraMFCDlg.cpp中实现
void CHikCameraMFCDlg::OnBnClickedStartPreview()
{
    m_selectedIndex = m_cameraList.GetSelectionMark();
    if (m_selectedIndex < 0 || m_selectedIndex >= (int)m_cameras.size())
        return;

    CameraInfo &cam = m_cameras[m_selectedIndex];
    if (!cam.isLoggedIn || cam.userID < 0)
    {
        AfxMessageBox(_T("请先登录相机"));
        return;
    }

    // 停止已有预览
    if (cam.realHandle >= 0)
    {
        NET_DVR_StopRealPlay(cam.realHandle);
    }

    // 配置预览参数
    NET_DVR_CLIENTINFO clientInfo = {0};
    clientInfo.lChannel = 1;
    clientInfo.hPlayWnd = cam.displayWnd->m_hWnd; // 绑定当前相机的显示窗口
    clientInfo.lLinkMode = 0;

    // 启动预览（传递相机信息指针）
    cam.realHandle = NET_DVR_RealPlay_V30(cam.userID, &clientInfo, RealDataCallBack, &cam, TRUE);

    if (cam.realHandle < 0)
    {
        CString err;
        err.Format(_T("预览失败，错误码：%d"), NET_DVR_GetLastError());
        AfxMessageBox(err);
        return;
    }

    // 显示窗口并调整大小
    CRect dispRect;
    GetDlgItem(IDC_DISPLAY_AREA)->GetClientRect(dispRect); // 假设存在显示区域容器
    cam.displayWnd->MoveWindow(dispRect);
    cam.displayWnd->ShowWindow(SW_SHOW);
}

// 添加 “抓图” 按钮点击事件处理函数，在HikCameraMFCDlg.cpp中实现：
void CHikCameraMFCDlg::OnBnClickedBtnCapture()
{
    // 1. 检查是否选中相机
    int nSelected = m_cameraList.GetSelectionMark();
    if (nSelected < 0 || nSelected >= (int)m_cameras.size())
    {
        AfxMessageBox(_T("请先在列表中选择一台相机"));
        return;
    }

    CameraInfo &cam = m_cameras[nSelected];

    // 2. 检查相机状态（必须已登录且正在预览）
    if (!cam.isLoggedIn || cam.userID < 0)
    {
        AfxMessageBox(_T("请先登录相机"));
        return;
    }
    if (cam.realHandle < 0)
    {
        AfxMessageBox(_T("请先启动预览"));
        return;
    }

    // 3. 配置抓图参数
    NET_DVR_JPEGPARA jpegPara = {0};
    jpegPara.wPicSize = 0;    // 0-默认大小，1-2倍放大，2-4倍放大
    jpegPara.wPicQuality = 2; // 图像质量（0-最好，1-较好，2-一般）

    // 4. 获取保存路径（通过文件对话框）
    CString strFilter = _T("JPEG图像 (*.jpg)|*.jpg|所有文件 (*.*)|*.*||");
    CFileDialog dlg(FALSE, _T("jpg"), _T("Capture_"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, strFilter, this);

    if (dlg.DoModal() != IDOK)
    {
        return; // 用户取消保存
    }
    CString strSavePath = dlg.GetPathName();

    // 将CString转换为char*
    int nLen = WideCharToMultiByte(CP_ACP, 0, strSavePath, -1, NULL, 0, NULL, NULL);
    char *pSavePath = new char[nLen];
    WideCharToMultiByte(CP_ACP, 0, strSavePath, -1, pSavePath, nLen, NULL, NULL);

    // 5. 调用SDK抓图接口（注意：通道号通常从1开始）
    BOOL bRet = NET_DVR_CaptureJPEGPicture(cam.userID, 1, &jpegPara, pSavePath);

    // 释放内存
    delete[] pSavePath;

    // 处理抓图结果
    if (!bRet)
    {
        // 抓图失败，显示错误码
        CString strErr;
        strErr.Format(_T("抓图失败！错误码: %d"), NET_DVR_GetLastError());
        AfxMessageBox(strErr);
        return;
    }

    // 6. 抓图成功提示
    CString strMsg;
    strMsg.Format(_T("抓图成功！\n保存路径: %s"), strSavePath);
    AfxMessageBox(strMsg);
}

// 在对话框关闭时，需要释放 SDK 资源，在对话框类的OnCancel函数（位于HikCameraMFCDlg.cpp）中添加以下代码：
void CHikCameraMFCDlg::OnCancel()
{

}

void CHikCameraMFCDlg::OnBnClickedNo()
{
    // TODO: 在此添加控件通知处理程序代码
}

void CHikCameraMFCDlg::OnEnChangeEditIp()
{
    // TODO:  如果该控件是 RICHEDIT 控件，它将不
    // 发送此通知，除非重写 CDialogEx::OnInitDialog()
    // 函数并调用 CRichEditCtrl().SetEventMask()，
    // 同时将 ENM_CHANGE 标志“或”运算到掩码中。

    // TODO:  在此添加控件通知处理程序代码
}

void CHikCameraMFCDlg::OnStnClickedVideoDisplay()
{
    // TODO: 在此添加控件通知处理程序代码
}

//
void CHikCameraMFCDlg::OnBnClickedOk()
{
    // TODO: 在此添加控件通知处理程序代码
    CDialogEx::OnOK();
}

void CHikCameraMFCDlg::OnBnClickedCancel()
{
    // TODO: 在此添加控件通知处理程序代码
    CDialogEx::OnCancel();
}
void CHikCameraMFCDlg::OnBnClickedBtnLogin()
{
    // TODO: 在此添加控件通知处理程序代码
    m_selectedIndex = m_cameraList.GetSelectionMark();
    if (m_selectedIndex < 0 || m_selectedIndex >= (int)m_cameras.size())
    {
        AfxMessageBox(_T("请先选择相机"));
        return;
    }

    CameraInfo &cam = m_cameras[m_selectedIndex];
    NET_DVR_DEVICEINFO_V30 deviceInfo = {0};
    cam.userID = NET_DVR_Login_V30(cam.ip, cam.port, cam.username, cam.password, &deviceInfo);

    if (cam.userID < 0)
    {
        CString err;
        err.Format(_T("登录失败，错误码：%d"), NET_DVR_GetLastError());
        AfxMessageBox(err);
        return;
    }

    cam.isLoggedIn = true;
    UpdateCameraList();
    AfxMessageBox(_T("登录成功"));
}

void CHikCameraMFCDlg::OnBnClickedBtnLogout()
{
    // TODO: 在此添加控件通知处理程序代码
    m_selectedIndex = m_cameraList.GetSelectionMark();
    if (m_selectedIndex < 0 || m_selectedIndex >= (int)m_cameras.size())
        return;

    CameraInfo &cam = m_cameras[m_selectedIndex];
    if (cam.realHandle >= 0)
    {
        NET_DVR_StopRealPlay(cam.realHandle); // 先停止预览
        cam.realHandle = -1;
    }
    if (cam.userID >= 0)
    {
        NET_DVR_Logout(cam.userID); // 注销登录
        cam.userID = -1;
    }
    if (cam.playPort != -1)
    {
        PlayM4_ReleasePort(cam.playPort); // 释放播放端口
        cam.playPort = -1;
    }
    cam.isLoggedIn = false;
    cam.displayWnd->ShowWindow(SW_HIDE); // 隐藏显示窗口
    UpdateCameraList();
}

// 生成带时间戳的字符串（用于抓图文件名）
CString CHikCameraMFCDlg::GetCurrentTimeStr()
{
    CTime currentTime = CTime::GetCurrentTime(); // 获取当前系统时间
    // 格式化为"YYYYMMDD_HHMMSS"（避免文件名包含特殊字符）
    return currentTime.Format(_T("%Y%m%d_%H%M%S"));
}

void CHikCameraMFCDlg::AddCameraToList(LPCTSTR lpszIP, int nPort)
{
    CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST_CAMERAS);
    int nItem = pList->GetItemCount(); // 新项的索引

    // 添加行数据
    pList->InsertItem(nItem, _T("")); // 序号留空，后续填充
    pList->SetItemText(nItem, 1, lpszIP);
    pList->SetItemText(nItem, 2, CString(std::to_string(nPort).c_str()));
    pList->SetItemText(nItem, 3, _T("未登录"));
    pList->SetItemText(nItem, 4, _T("登录 | 预览")); // 操作按钮文本

    // 填充序号
    pList->SetItemText(nItem, 0, CString(std::to_string(nItem + 1).c_str()));

    // 同步更新CameraInfo数组
    CameraInfo cam;
    cam.strIP = lpszIP;
    cam.nPort = nPort;
    cam.strUser = _T("admin"); // 默认用户名
    cam.strPwd = _T("12345");  // 默认密码
    cam.lUserID = -1;
    cam.lRealHandle = -1;
    cam.bIsLoggedIn = false;
    m_arrCameras.Add(cam);
}

void CHikCameraMFCDlg::UpdateCameraStatus(int nIndex, LPCTSTR lpszStatus)
{
    if (nIndex < 0 || nIndex >= m_arrCameras.GetSize())
        return;
    CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST_CAMERAS);
    pList->SetItemText(nIndex, 3, lpszStatus);
}

void CHikCameraMFCDlg::OnLvnItemchangedListCameras(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
    // TODO: 在此添加控件通知处理程序代码
    *pResult = 0;
}

void CHikCameraMFCDlg::OnNMClickListCameras(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);

    CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST_CAMERAS);
    int nItem = pNMItemActivate->iItem;       // 点击的行索引
    int nSubItem = pNMItemActivate->iSubItem; // 点击的列索引

    // 只处理"操作"列（索引4）的点击
    if (nItem >= 0 && nSubItem == 4)
    {
        // 获取点击位置的坐标
        CPoint pt(pNMItemActivate->ptAction);
        pList->ScreenToClient(&pt);

        // 获取"操作"列的文本范围
        CRect rect;
        pList->GetSubItemRect(nItem, 4, LVIR_LABEL, rect);

        if (rect.PtInRect(pt))
        {
            // 判断点击的是"登录"还是"预览"
            CString strText = pList->GetItemText(nItem, 4);
            int nLoginPos = strText.Find(_T("登录"));
            int nPreviewPos = strText.Find(_T("预览"));

            // 计算文本区域（简单判断左右区域）
            int nSplit = rect.left + rect.Width() / 2;
            if (pt.x < nSplit && nLoginPos != -1)
            {
                // 点击"登录"
                OnCameraLogin(nItem);
            }
            else if (pt.x >= nSplit && nPreviewPos != -1)
            {
                // 点击"预览"
                OnCameraPreview(nItem);
            }
        }
    }

    *pResult = 0;
}

void CHikCameraMFCDlg::OnBnClickedBtnBatchLogin()
{
    // TODO: 在此添加控件通知处理程序代码
    for (int i = 0; i < m_arrCameras.GetSize(); i++)
    {
        if (!m_arrCameras[i].bIsLoggedIn)
        {
            // 显示登录进度
            CString strMsg;
            strMsg.Format(_T("正在登录相机 %d..."), i + 1);
            UpdateCameraStatus(i, strMsg);

            // 执行登录（实际项目中建议用线程避免UI卡顿）
            if (LoginCamera(i))
            {
                UpdateCameraStatus(i, _T("已登录"));
            }
            else
            {
                UpdateCameraStatus(i, _T("登录失败"));
            }
        }
    }
}
bool CHikCameraMFCDlg::LoginCamera(int nIndex)
{
    if (nIndex < 0 || nIndex >= m_arrCameras.GetSize())
        return false;

    CameraInfo &cam = m_arrCameras[nIndex];

    // 这里可以弹出输入框让用户输入用户名密码
    // 简化处理：使用预设值
    cam.strUser = _T("admin");
    cam.strPwd = _T("12345");

    // 海康SDK登录流程（同之前的实现）
    NET_DVR_DEVICEINFO_V30 deviceInfo = {0};
    cam.lUserID = NET_DVR_Login_V30(cam.strIP, cam.nPort, cam.strUser, cam.strPwd, &deviceInfo);

    if (cam.lUserID < 0)
    {
        CString strErr;
        strErr.Format(_T("错误码: %d"), NET_DVR_GetLastError());
        UpdateCameraStatus(nIndex, strErr);
        cam.bIsLoggedIn = false;
        return false;
    }

    cam.bIsLoggedIn = true;
    return true;
}
void CHikCameraMFCDlg::OnTcnSelchangeTabPreview(NMHDR *pNMHDR, LRESULT *pResult)
{
    // TODO: 在此添加控件通知处理程序代码
    *pResult = 0;
}
void CHikCameraMFCDlg::AddCamera(CString ip, int port, CString user, CString pwd)
{
    CameraInfo cam;
    cam.ip = ip;
    cam.port = port;
    cam.username = user;
    cam.password = pwd;
    cam.userID = -1;
    cam.realHandle = -1;
    cam.playPort = -1;
    cam.isLoggedIn = false;
    cam.listIndex = m_cameras.size();

    // 创建显示窗口（隐藏状态，预览时显示）
    CStatic *pWnd = new CStatic();
    pWnd->Create(_T(""), WS_CHILD | WS_VISIBLE | SS_WINDOWEDGE, CRect(0, 0, 0, 0), this,
                 IDC_VIDEO_DISPLAY + m_cameras.size());
    pWnd->ShowWindow(SW_HIDE);
    cam.displayWnd = pWnd;

    m_cameras.push_back(cam);
    UpdateCameraList(); // 更新列表显示
}

// 更新列表显示
void CHikCameraMFCDlg::UpdateCameraList()
{
    m_cameraList.DeleteAllItems();
    for (size_t i = 0; i < m_cameras.size(); i++)
    {
        CString indexStr;
        indexStr.Format(_T("%d"), i + 1);
        m_cameraList.InsertItem(i, indexStr);
        m_cameraList.SetItemText(i, 1, m_cameras[i].ip);

        CString portStr;
        portStr.Format(_T("%d"), m_cameras[i].port);
        m_cameraList.SetItemText(i, 2, portStr);

        m_cameraList.SetItemText(i, 3, m_cameras[i].isLoggedIn ? _T("已登录") : _T("未登录"));
        m_cameraList.SetItemText(i, 4, _T("登录 | 预览 | 注销"));
    }
}


CHikCameraMFCDlg::~CHikCameraMFCDlg()
{
    // 释放所有相机资源
    for (auto &cam : m_cameras)
    {
        if (cam.realHandle >= 0)
            NET_DVR_StopRealPlay(cam.realHandle);
        if (cam.userID >= 0)
            NET_DVR_Logout(cam.userID);
        if (cam.playPort != -1)
        {
            PlayM4_Stop(cam.playPort);
            PlayM4_CloseStream(cam.playPort);
            PlayM4_ReleasePort(cam.playPort);
        }
        if (cam.displayWnd)
        {
            delete cam.displayWnd;
            cam.displayWnd = nullptr;
        }
    }
    m_cameras.clear();
    NET_DVR_Cleanup(); // 清理SDK
}

afx_msg  void OnLvnItemchangedCameraList(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
    if (pNMLV->uNewState & LVIS_SELECTED)
    {
        m_selectedIndex = pNMLV->iItem;
    }
    *pResult = 0;
}