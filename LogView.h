#pragma once
#include "afxcmn.h"
#include "afxwin.h"

// 日志级别
enum LogLevel
{
    LOG_INFO,    // 普通信息
    LOG_WARNING, // 警告信息
    LOG_ERROR,   // 错误信息
    LOG_SUCCESS  // 成功信息
};

// CLogView 类 - 显示操作日志
class CLogView : public CListCtrl
{
    DECLARE_DYNAMIC(CLogView)

  public:
    CLogView();
    virtual ~CLogView();

    // 初始化视图
    void Initialize();

    // 添加日志条目
    void AddLogEntry(LogLevel level, const CString &message);

    // 添加带时间戳的日志条目
    void AddLogEntryWithTimestamp(LogLevel level, const CString &message);

    // 清除日志
    void ClearLog();

    // 保存日志到文件
    BOOL SaveToFile(const CString &filePath);

  protected:
    DECLARE_MESSAGE_MAP()

    afx_msg void OnContextMenu(CWnd *pWnd, CPoint point);
    afx_msg void OnClearLog();
    afx_msg void OnSaveLog();
    afx_msg void OnCopyLog();
    afx_msg void OnRClick(NMHDR *pNMHDR, LRESULT *pResult);

  private:
    // 获取当前时间字符串
    CString GetCurrentTimeString();

    // 获取日志级别字符串
    CString GetLevelString(LogLevel level);

    // 获取日志级别颜色
    COLORREF GetLevelColor(LogLevel level);
};