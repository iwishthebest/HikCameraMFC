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
    : CDialogEx(IDD_HIKCAMERAMFC_DIALOG, pParent), m_lUserID(-1), m_lRealHandle(-1),
      m_bIsLoggedIn(false), // 初始化未登录
      m_lPort(-1),          // 初始化播放端口为无效值
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
    
    // 初始化相机列表控件
    CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST_CAMERAS);
    pList->SetExtendedStyle(pList->GetExtendedStyle() | LVS_EX_FULLROWSELECT | // 整行选择
                            LVS_EX_GRIDLINES);                                 // 网格线

    // 添加列：序号、IP地址、端口、状态、操作
    pList->InsertColumn(0, _T("序号"), LVCFMT_CENTER, 60);
    pList->InsertColumn(1, _T("IP地址"), LVCFMT_CENTER, 120);
    pList->InsertColumn(2, _T("端口"), LVCFMT_CENTER, 80);
    pList->InsertColumn(3, _T("状态"), LVCFMT_CENTER, 100);
    pList->InsertColumn(4, _T("操作"), LVCFMT_CENTER, 150);

    // 初始添加几个相机（可从配置文件读取）
    AddCameraToList(_T("192.168.0.101"), 8000);
    AddCameraToList(_T("192.168.0.102"), 8000);
    AddCameraToList(_T("192.168.0.103"), 8000);

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
    // 将pUser转换为对话框指针
    CHikCameraMFCDlg *pDlg = (CHikCameraMFCDlg *)pUser;
    if (pDlg == nullptr)
        return;

    if (dwDataType == NET_DVR_SYSHEAD)
    {
        // 初始化播放库相关操作，获取播放端口等
        // 通过对话框指针访问m_nPort成员变量
        if (!PlayM4_GetPort(&pDlg->m_lPort))
        {
            return;
        }
        if (!PlayM4_SetStreamOpenMode(pDlg->m_lPort, STREAME_REALTIME))
        {
            return;
        }
        if (!PlayM4_OpenStream(pDlg->m_lPort, pBuffer, dwBufSize, 1024 * 1024))
        {
            return;
        }
        // 获取对话框中用于显示视频的Static Text控件句柄
        CWnd *pWnd = ((CHikCameraMFCDlg *)pUser)->GetDlgItem(IDC_VIDEO_DISPLAY);
        if (!PlayM4_SetDisplayBuf(pDlg->m_lPort, 15))
        {
            return;
        }
        if (!PlayM4_Play(pDlg->m_lPort, pWnd->m_hWnd))
        {
            return;
        }
    }
    else if (dwDataType == NET_DVR_STREAMDATA)
    {
        // 输入视频流数据到播放库进行解码播放
        PlayM4_InputData(pDlg->m_lPort, pBuffer, dwBufSize);
    }
}

// 在资源视图中，双击 “开始预览” 按钮，自动生成按钮点击事件处理函数，在HikCameraMFCDlg.cpp中实现
void CHikCameraMFCDlg::OnBnClickedStartPreview()
{
    if (m_lUserID < 0 || !m_bIsLoggedIn)
    {
        AfxMessageBox(_T("请先登录相机！"));
        return;
    }

    // 声明并初始化 NET_DVR_CLIENTINFO 结构体（与函数参数匹配）
    NET_DVR_CLIENTINFO clientInfo = {0};
    clientInfo.lChannel = 1;    // 预览通道号（根据相机实际通道调整，通常从1开始）
    clientInfo.hPlayWnd = NULL; // 设为NULL表示通过回调函数处理视频流（不使用SDK自带窗口）
    clientInfo.lLinkMode = 0;   // 连接方式：0-TCP（推荐，稳定性高），1-UDP（效率高但可能丢包）

    // 调用 NET_DVR_RealPlay_V30 函数，参数类型完全匹配
    m_lRealHandle = NET_DVR_RealPlay_V30(m_lUserID,        // 登录句柄（已通过 NET_DVR_Login_V30 获取）
                                         &clientInfo,      // 结构体指针（NET_DVR_CLIENTINFO* 类型，与函数要求一致）
                                         RealDataCallBack, // 视频流回调函数（处理实时数据）
                                         this,             // 用户数据（传递当前对话框指针，供回调函数访问成员）
                                         TRUE              // 阻塞取流模式（TRUE表示阻塞，FALSE表示非阻塞）
    );

    // 检查预览是否成功
    if (m_lRealHandle < 0)
    {
        DWORD errCode = NET_DVR_GetLastError();
        CString strErr;
        strErr.Format(_T("预览启动失败！错误码：%d"), errCode);
        AfxMessageBox(strErr);
    }
    else
    {
        AfxMessageBox(_T("预览启动成功！"));
    }
}

// 添加 “抓图” 按钮点击事件处理函数，在HikCameraMFCDlg.cpp中实现：
void CHikCameraMFCDlg::OnBnClickedBtnCapture()
{
    // 检查登录状态
    if (m_lUserID < 0 || !m_bIsLoggedIn)
    {
        AfxMessageBox(_T("请先登录相机！"));
        return;
    }
    // 1. 设置抓图参数（图片尺寸和质量）
    NET_DVR_JPEGPARA jpegPara = {0};
    jpegPara.wPicSize = 0;    // 0-默认尺寸，1-D1，2-CIF，3-QCIF（根据相机支持调整）
    jpegPara.wPicQuality = 0; // 0-最好质量，1-较好，2-一般

    // 2. 生成带时间戳的保存路径（避免文件名重复）
    CString strTime = GetCurrentTimeStr(); // 调用自定义时间函数
    CString strSavePath;
    // 保存到项目内capture文件夹，文件名含时间戳
    strSavePath.Format(_T("./capture/%s.jpg"), (LPCTSTR)strTime);

    // 3. 转换宽字符路径为窄字符（海康SDK接口要求char*类型）
    char savePathBuf[MAX_PATH] = {0};
    WideCharToMultiByte(CP_ACP,              // 代码页（匹配系统ANSI编码）
                        0,                   // 转换标志
                        strSavePath,         // 源宽字符串
                        -1,                  // 自动计算长度（包含终止符）
                        savePathBuf,         // 目标窄字符缓冲区
                        sizeof(savePathBuf), // 缓冲区大小
                        NULL, NULL           // 不使用默认字符
    );

    // 4. 调用SDK抓图接口（通道号通常从1开始，根据实际设备调整）
    BOOL bSuccess = NET_DVR_CaptureJPEGPicture(m_lUserID,  // 登录句柄
                                               1,          // 通道号（与预览通道一致）
                                               &jpegPara,  // 抓图参数结构体
                                               savePathBuf // 保存路径（char*类型）
    );

    // 5. 处理抓图结果
    if (bSuccess)
    {
        CString strMsg;
        strMsg.Format(_T("抓图成功！\n保存路径：%s"), (LPCTSTR)strSavePath);
        AfxMessageBox(strMsg);
        // 可选：更新界面显示抓图信息（如IDC_STATIC_CAPTURE_INFO）
        SetDlgItemText(IDC_STATIC_CAPTURE_INFO, _T("最近抓图：") + strSavePath);
    }
    else
    {
        // 抓图失败，获取错误码
        DWORD dwErr = NET_DVR_GetLastError();
        CString strErr;
        strErr.Format(_T("抓图失败！错误码：%d"), dwErr);
        AfxMessageBox(strErr);
    }
}

// 在对话框关闭时，需要释放 SDK 资源，在对话框类的OnCancel函数（位于HikCameraMFCDlg.cpp）中添加以下代码：
void CHikCameraMFCDlg::OnCancel()
{
    // 若已登录，先注销
    if (m_bIsLoggedIn)
    {
        OnBnClickedBtnLogout(); // 调用注销函数
    }
    // 停止预览
    if (m_lRealHandle >= 0)
    {
        NET_DVR_StopRealPlay(m_lRealHandle);
    }
    // 退出登录
    if (m_lUserID >= 0)
    {
        NET_DVR_Logout(m_lUserID);
    }
    // 清理SDK
    NET_DVR_Cleanup();
    // 关闭播放库端口（如果使用了播放库）
    if (m_lPort >= 0)
    {
        PlayM4_Stop(m_lPort);
        PlayM4_CloseStream(m_lPort);
        PlayM4_FreePort(m_lPort);
    }
    CDialogEx::OnCancel();
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
    // 若已登录，直接返回
    if (m_bIsLoggedIn)
    {
        AfxMessageBox(_T("已登录，无需重复操作！"));
        return;
    }

    // 获取界面输入的登录信息
    CString strIP, strPort, strUser, strPwd;
    GetDlgItemText(IDC_EDIT_IP, strIP);
    GetDlgItemText(IDC_EDIT_PORT, strPort);
    GetDlgItemText(IDC_EDIT_USERNAME, strUser);
    GetDlgItemText(IDC_EDIT_PASSWORD, strPwd);

    // 简单校验输入
    if (strIP.IsEmpty() || strPort.IsEmpty() || strUser.IsEmpty())
    {
        AfxMessageBox(_T("IP、端口和用户名不能为空！"));
        return;
    }

    // 转换为海康SDK需要的C字符串（宽字符转窄字符）
    char ip[16] = {0}, user[32] = {0}, pwd[32] = {0};
    int port = _ttoi(strPort);
    WideCharToMultiByte(CP_ACP, 0, strIP, -1, ip, sizeof(ip), NULL, NULL);
    WideCharToMultiByte(CP_ACP, 0, strUser, -1, user, sizeof(user), NULL, NULL);
    WideCharToMultiByte(CP_ACP, 0, strPwd, -1, pwd, sizeof(pwd), NULL, NULL);

    // 调用海康SDK登录接口
    NET_DVR_DEVICEINFO_V30 deviceInfo = {0};
    m_lUserID = NET_DVR_Login_V30(ip, port, user, pwd, &deviceInfo);

    // 处理登录结果
    if (m_lUserID < 0)
    {
        DWORD err = NET_DVR_GetLastError();
        CString errMsg;
        errMsg.Format(_T("登录失败！错误码：%d"), err);
        AfxMessageBox(errMsg);
        SetDlgItemText(IDC_STATIC_STATUS, _T("登录失败"));
        return;
    }

    // 登录成功：更新状态和控件
    m_bIsLoggedIn = true;
    SetDlgItemText(IDC_STATIC_STATUS, _T("已登录"));
    GetDlgItem(IDC_BTN_LOGIN)->EnableWindow(FALSE); // 禁用登录按钮
    GetDlgItem(IDC_BTN_LOGOUT)->EnableWindow(TRUE); // 启用注销按钮
    // 可选：禁用输入框（防止登录后修改）
    GetDlgItem(IDC_EDIT_IP)->EnableWindow(FALSE);
    GetDlgItem(IDC_EDIT_PORT)->EnableWindow(FALSE);
    GetDlgItem(IDC_EDIT_USERNAME)->EnableWindow(FALSE);
    GetDlgItem(IDC_EDIT_PASSWORD)->EnableWindow(FALSE);
    AfxMessageBox(_T("登录成功！"));
}

void CHikCameraMFCDlg::OnBnClickedBtnLogout()
{
    // TODO: 在此添加控件通知处理程序代码
    // 若未登录，直接返回
    if (!m_bIsLoggedIn)
    {
        AfxMessageBox(_T("未登录，无需注销！"));
        return;
    }

    // 停止预览（如果正在预览）
    if (m_lRealHandle >= 0)
    {
        NET_DVR_StopRealPlay(m_lRealHandle);
        m_lRealHandle = -1;
    }

    // 调用海康SDK注销接口
    NET_DVR_Logout(m_lUserID);
    m_lUserID = -1; // 重置登录句柄

    // 更新状态和控件
    m_bIsLoggedIn = false;
    SetDlgItemText(IDC_STATIC_STATUS, _T("未登录"));
    GetDlgItem(IDC_BTN_LOGIN)->EnableWindow(TRUE);   // 启用登录按钮
    GetDlgItem(IDC_BTN_LOGOUT)->EnableWindow(FALSE); // 禁用注销按钮
    // 启用输入框（允许重新输入）
    GetDlgItem(IDC_EDIT_IP)->EnableWindow(TRUE);
    GetDlgItem(IDC_EDIT_PORT)->EnableWindow(TRUE);
    GetDlgItem(IDC_EDIT_USERNAME)->EnableWindow(TRUE);
    GetDlgItem(IDC_EDIT_PASSWORD)->EnableWindow(TRUE);
    AfxMessageBox(_T("注销成功！"));
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