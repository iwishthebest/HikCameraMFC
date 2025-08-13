// HikCameraMFCDlg.h: 头文件
//
#include "HCNetSDK.h"

#pragma once

// CHikCameraMFCDlg 对话框
class CHikCameraMFCDlg : public CDialogEx
{
	// 声明回调函数为友元（关键修改）
	friend void CALLBACK RealDataCallBack(LONG lRealHandle, DWORD dwDataType, BYTE* pBuffer, DWORD dwBufSize, void* pUser);

	// 构造
public:
	CHikCameraMFCDlg(CWnd* pParent = nullptr);	// 标准构造函数

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HIKCAMERAMFC_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedStartPreview();  // "开始预览"按钮的点击事件处理函数
	afx_msg void OnBnClickedBtnCapture(); // 抓图
	afx_msg void OnCancel(); // 添加OnCancel声明
	DECLARE_MESSAGE_MAP()

	// 其他代码...
private:
	LONG m_lPort;  // 播放端口成员变量，替代全局变量
	// 登录句柄（海康SDK用）
	LONG m_lUserID;          // 初始化为-1（未登录）
	// 登录状态标识
	bool m_bIsLoggedIn;      // 初始化为false
	// 视频预览句柄（如果需要）
	LONG m_lRealHandle;      // 初始化为-1

public:
	afx_msg void OnBnClickedNo();
	afx_msg void OnEnChangeEditIp();
	afx_msg void OnStnClickedVideoDisplay();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedBtnLogin();
	afx_msg void OnBnClickedBtnLogout();
};
