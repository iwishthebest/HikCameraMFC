
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
	afx_msg void OnCancel(); // 添加OnCancel声明
	DECLARE_MESSAGE_MAP()

// 其他代码...
private:
	LONG m_nPort;  // 播放端口成员变量，替代全局变量
	LONG m_lUserID;  // 已有的设备登录句柄
	LONG m_lRealHandle;  // 已有的预览句柄

public:
	afx_msg void OnBnClickedNo();
	// 添加公共接口：获取/设置播放端口（仅暴露必要操作）
	int GetPort() const { return m_nPort; }         // 只读访问
	int* GetPortPtr() { return &m_nPort; }          // 提供指针（供PlayM4_GetPort修改）
	void SetPort(int port) { m_nPort = port; }      // 写访问（可选，按需添加）

};
