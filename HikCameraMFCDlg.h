
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
	DECLARE_MESSAGE_MAP()

// 其他代码...
private:
	LONG m_lUserID; // 设备登录句柄
};
