
// HikCameraMFCDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "HikCameraMFC.h"
#include "HikCameraMFCDlg.h"
#include "afxdialogex.h"
#include <string>

#include "plaympeg4.h" 

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#undef ZOOM_IN
#undef ZOOM_OUT
#include "HCNetSDK.h"  // 海康SDK头文件



// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	
	
END_MESSAGE_MAP()


// CHikCameraMFCDlg 对话框

//在CHikCameraMFCDlg.cpp的构造函数中初始化（可选，建议初始化）：
CHikCameraMFCDlg::CHikCameraMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_HIKCAMERAMFC_DIALOG, pParent)
	, m_lUserID(-1)
	, m_lRealHandle(-1)
	, m_nPort(-1)  // 初始化播放端口为无效值
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}


void CHikCameraMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CHikCameraMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(IDNO, &CHikCameraMFCDlg::OnBnClickedNo)
	// 添加以下行：关联按钮ID和处理函数
	ON_BN_CLICKED(IDC_BTN_START_PREVIEW, &CHikCameraMFCDlg::OnBnClickedStartPreview)
	ON_BN_CLICKED(IDC_BTN_CAPTURE, &CHikCameraMFCDlg::OnBnClickedBtnCapture) // 自动生成的映射
END_MESSAGE_MAP()


// CHikCameraMFCDlg 消息处理程序

BOOL CHikCameraMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 初始化SDK
	if (!NET_DVR_Init())
	{
		AfxMessageBox(_T("SDK初始化失败！错误码：") + CString(std::to_string(NET_DVR_GetLastError()).c_str()));
		return FALSE;
	}
	// 设置连接超时和重连
	NET_DVR_SetConnectTime(2000, 1);
	NET_DVR_SetReconnect(10000, TRUE);

	// 获取用户在界面输入的相机信息（假设通过Edit Control控件输入）
	CString strIP, strPort, strUser, strPwd;
	GetDlgItemText(IDC_EDIT_IP, strIP);
	GetDlgItemText(IDC_EDIT_PORT, strPort);
	GetDlgItemText(IDC_EDIT_USERNAME, strUser);
	GetDlgItemText(IDC_EDIT_PASSWORD, strPwd);

	// 转换为char*类型
	char  ipBuf[16] = { 0 };
	char  userBuf[32] = { 0 };
	char  pwdBuf[32] = { 0 };
	int port = _ttoi(strPort);

	// 使用 WideCharToMultiByte 转换宽字符到窄字符
	// 转换 IP
	WideCharToMultiByte(CP_ACP, 0, strIP, -1, ipBuf, sizeof(ipBuf), NULL, NULL);
	// 转换用户名
	WideCharToMultiByte(CP_ACP, 0, strUser, -1, userBuf, sizeof(userBuf), NULL, NULL);
	// 转换密码
	WideCharToMultiByte(CP_ACP, 0, strPwd, -1, pwdBuf, sizeof(pwdBuf), NULL, NULL);

	// 声明设备信息结构体（需包含海康SDK头文件）
	NET_DVR_DEVICEINFO_V30 deviceInfo = { 0 };

	// 登录相机（此时参数类型匹配）
	m_lUserID = NET_DVR_Login_V30(ipBuf, port, userBuf, pwdBuf, &deviceInfo);

	// 检查登录结果
	if (m_lUserID < 0) {
		DWORD err = NET_DVR_GetLastError();
		CString strErr;
		strErr.Format(_T("登录失败，错误码：%d"), err);
		AfxMessageBox(strErr);
	}
	else {
		AfxMessageBox(_T("登录成功！"));
	}

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
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
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CHikCameraMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//在HikCameraMFCDlg.cpp文件中添加预览回调函数，用于处理接收到的视频数据：
void CALLBACK RealDataCallBack(LONG lRealHandle, DWORD dwDataType, BYTE* pBuffer, DWORD dwBufSize, void* pUser)
{
	// 将pUser转换为对话框指针（关键修正）
	CHikCameraMFCDlg* pDlg = (CHikCameraMFCDlg*)pUser;
	if (pDlg == nullptr) return;

	if (dwDataType == NET_DVR_SYSHEAD)
	{
		// 初始化播放库相关操作，获取播放端口等
		// 通过对话框指针访问m_nPort成员变量
		if (!PlayM4_GetPort(&pDlg->m_nPort))
		{
			return;
		}
		if (!PlayM4_SetStreamOpenMode(pDlg->GetPort(), STREAME_REALTIME))
		{
			return;
		}
		if (!PlayM4_OpenStream(pDlg->GetPort(), pBuffer, dwBufSize, 1024 * 1024))
		{
			return;
		}
		// 获取对话框中用于显示视频的Static Text控件句柄
		CWnd* pWnd = ((CHikCameraMFCDlg*)pUser)->GetDlgItem(IDC_VIDEO_DISPLAY);
		if (!PlayM4_SetDisplayBuf(pDlg->GetPort(), 15))
		{
			return;
		}
		if (!PlayM4_Play(pDlg->GetPort(), pWnd->m_hWnd))
		{
			return;
		}
	}
	else if (dwDataType == NET_DVR_STREAMDATA)
	{
		// 输入视频流数据到播放库进行解码播放
		PlayM4_InputData(pDlg->GetPort(), pBuffer, dwBufSize);
	}
}

//在资源视图中，双击 “开始预览” 按钮，自动生成按钮点击事件处理函数，在HikCameraMFCDlg.cpp中实现
void CHikCameraMFCDlg::OnBnClickedStartPreview()
{
	if (m_lUserID < 0)
	{
		AfxMessageBox(_T("请先登录相机！"));
		return;
	}

	// 声明并初始化 NET_DVR_CLIENTINFO 结构体（与函数参数匹配）
	NET_DVR_CLIENTINFO clientInfo = { 0 };
	clientInfo.lChannel = 1;              // 预览通道号（根据相机实际通道调整，通常从1开始）
	clientInfo.hPlayWnd = NULL;           // 设为NULL表示通过回调函数处理视频流（不使用SDK自带窗口）
	clientInfo.lLinkMode = 0;             // 连接方式：0-TCP（推荐，稳定性高），1-UDP（效率高但可能丢包）

	// 调用 NET_DVR_RealPlay_V30 函数，参数类型完全匹配
	m_lRealHandle = NET_DVR_RealPlay_V30(
		m_lUserID,                   // 登录句柄（已通过 NET_DVR_Login_V30 获取）
		&clientInfo,                 // 结构体指针（NET_DVR_CLIENTINFO* 类型，与函数要求一致）
		RealDataCallBack,            // 视频流回调函数（处理实时数据）
		this,                        // 用户数据（传递当前对话框指针，供回调函数访问成员）
		TRUE                         // 阻塞取流模式（TRUE表示阻塞，FALSE表示非阻塞）
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

//添加 “抓图” 按钮点击事件处理函数，在HikCameraMFCDlg.cpp中实现：
void CHikCameraMFCDlg::OnBnClickedBtnCapture()
{
	if (m_lUserID < 0)
	{
		AfxMessageBox(_T("请先登录相机！"));
		return;
	}
	NET_DVR_JPEGPARA jpegPara = { 0 };
	jpegPara.wPicSize = 0;  // 图片尺寸，0表示默认
	jpegPara.wPicQuality = 0; // 图片质量，0表示最好

	CString strSavePath = _T("G:\\captured_image.jpg"); // 抓图保存路径，可自定义
	char   savePathBuf[MAX_PATH] = { 0 };

	// 将宽字符CString转换为窄字符char*（关键修正）
	WideCharToMultiByte(CP_ACP, 0, strSavePath, -1, savePathBuf, sizeof(savePathBuf), NULL, NULL);
	// 此时savePathBuf为char*类型，与函数参数匹配
	if (!NET_DVR_CaptureJPEGPicture(m_lUserID, 1, &jpegPara, savePathBuf))
	{
		AfxMessageBox(_T("抓图失败！错误码：") + CString(std::to_string(NET_DVR_GetLastError()).c_str()));
	}
	else
	{
		AfxMessageBox(_T("抓图成功！"));
	}
}

//在对话框关闭时，需要释放 SDK 资源，在对话框类的OnCancel函数（位于HikCameraMFCDlg.cpp）中添加以下代码：
void CHikCameraMFCDlg::OnCancel()
{
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
	if (m_nPort >= 0)
	{
		PlayM4_Stop(m_nPort);
		PlayM4_CloseStream(m_nPort);
		PlayM4_FreePort(m_nPort);
	}
	CDialogEx::OnCancel();
}

void CHikCameraMFCDlg::OnBnClickedNo()
{
	// TODO: 在此添加控件通知处理程序代码
}
