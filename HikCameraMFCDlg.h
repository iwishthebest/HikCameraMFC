
// HikCameraMFCDlg.h: 头文件
//
#include "HCNetSDK.h"

#pragma once


// CHikCameraMFCDlg 对话框
class CHikCameraMFCDlg : public CDialogEx
{
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
	DECLARE_MESSAGE_MAP()

// 其他代码...
private:
	int m_nPort;  // 播放端口成员变量，替代全局变量
	LONG m_lUserID;  // 已有的设备登录句柄
	LONG m_lRealHandle;  // 已有的预览句柄

public:
	afx_msg void OnBnClickedNo();
};
