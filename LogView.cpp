#include "pch.h"
#include "LogView.h"
#include "resource.h"
#include <atltime.h>

IMPLEMENT_DYNAMIC(CLogView, CListCtrl)

CLogView::CLogView() {}

CLogView::~CLogView() {}

BEGIN_MESSAGE_MAP(CLogView, CListCtrl)
ON_WM_CONTEXTMENU()
ON_COMMAND(ID_LOG_CLEAR, &CLogView::OnClearLog)
ON_COMMAND(ID_LOG_SAVE, &CLogView::OnSaveLog)
ON_COMMAND(ID_LOG_COPY, &CLogView::OnCopyLog)
ON_NOTIFY(NM_RCLICK, 0, &CLogView::OnRClick)
END_MESSAGE_MAP()

void CLogView::Initialize()
{
    // 设置扩展样式
    SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_DOUBLEBUFFER);

    // 添加列
    InsertColumn(0, _T("时间"), LVCFMT_LEFT, 120);
    InsertColumn(1, _T("级别"), LVCFMT_LEFT, 80);
    InsertColumn(2, _T("消息"), LVCFMT_LEFT, 600);

    // 设置字体
    CFont font;
    font.CreatePointFont(85, _T("Consolas"));
    SetFont(&font);
}

void CLogView::AddLogEntry(LogLevel level, const CString &message)
{
    // 添加新行
    int nIndex = InsertItem(GetItemCount(), _T(""));

    // 设置时间
    SetItemText(nIndex, 0, GetCurrentTimeString());

    // 设置级别
    SetItemText(nIndex, 1, GetLevelString(level));

    // 设置消息
    SetItemText(nIndex, 2, message);

    // 设置颜色
    SetItemData(nIndex, level);

    // 确保最后一行可见
    EnsureVisible(nIndex, FALSE);
}

void CLogView::AddLogEntryWithTimestamp(LogLevel level, const CString &message) { AddLogEntry(level, message); }

void CLogView::ClearLog() { DeleteAllItems(); }

BOOL CLogView::SaveToFile(const CString &filePath)
{
    CStdioFile file;
    if (!file.Open(filePath, CFile::modeCreate | CFile::modeWrite | CFile::typeText))
    {
        return FALSE;
    }

    try
    {
        // 写入标题
        file.WriteString(_T("时间,级别,消息\n"));

        // 写入所有条目
        for (int i = 0; i < GetItemCount(); i++)
        {
            CString line;
            line.Format(_T("\"%s\",\"%s\",\"%s\"\n"), GetItemText(i, 0), GetItemText(i, 1), GetItemText(i, 2));
            file.WriteString(line);
        }

        file.Close();
        return TRUE;
    }
    catch (CFileException *e)
    {
        e->Delete();
        return FALSE;
    }
}

CString CLogView::GetCurrentTimeString()
{
    CTime time = CTime::GetCurrentTime();
    return time.Format(_T("%H:%M:%S"));
}

CString CLogView::GetLevelString(LogLevel level)
{
    switch (level)
    {
    case LOG_INFO:
        return _T("信息");
    case LOG_WARNING:
        return _T("警告");
    case LOG_ERROR:
        return _T("错误");
    case LOG_SUCCESS:
        return _T("成功");
    default:
        return _T("未知");
    }
}

COLORREF CLogView::GetLevelColor(LogLevel level)
{
    switch (level)
    {
    case LOG_INFO:
        return RGB(200, 200, 200); // 灰色
    case LOG_WARNING:
        return RGB(255, 165, 0); // 橙色
    case LOG_ERROR:
        return RGB(255, 0, 0); // 红色
    case LOG_SUCCESS:
        return RGB(0, 200, 0); // 绿色
    default:
        return RGB(0, 0, 0); // 黑色
    }
}

void CLogView::OnContextMenu(CWnd *pWnd, CPoint point)
{
    CMenu menu;
    menu.LoadMenu(IDR_LOG_CONTEXT_MENU);

    CMenu *pPopup = menu.GetSubMenu(0);
    if (pPopup)
    {
        // 如果有选中项，启用复制菜单项
        pPopup->EnableMenuItem(ID_LOG_COPY, MF_BYCOMMAND | (GetSelectedCount() > 0 ? MF_ENABLED : MF_GRAYED));

        pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
    }
}

void CLogView::OnClearLog() { ClearLog(); }

void CLogView::OnSaveLog()
{
    CFileDialog dlg(FALSE, _T("csv"), _T("camera_log"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
                    _T("CSV文件 (*.csv)|*.csv|所有文件 (*.*)|*.*||"), this);

    if (dlg.DoModal() == IDOK)
    {
        SaveToFile(dlg.GetPathName());
    }
}

void CLogView::OnCopyLog()
{
    CString selectedText;

    // 获取所有选中项
    POSITION pos = GetFirstSelectedItemPosition();
    while (pos)
    {
        int nItem = GetNextSelectedItem(pos);
        CString time = GetItemText(nItem, 0);
        CString level = GetItemText(nItem, 1);
        CString message = GetItemText(nItem, 2);

        selectedText += time + _T("\t") + level + _T("\t") + message + _T("\r\n");
    }

    // 复制到剪贴板
    if (OpenClipboard())
    {
        HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, (selectedText.GetLength() + 1) * sizeof(TCHAR));
        if (hMem)
        {
            LPTSTR pMem = (LPTSTR)GlobalLock(hMem);
            _tcscpy_s(pMem, selectedText.GetLength() + 1, selectedText);
            GlobalUnlock(hMem);

            EmptyClipboard();
            SetClipboardData(CF_UNICODETEXT, hMem);
        }
        CloseClipboard();
    }
}

void CLogView::OnRClick(NMHDR *pNMHDR, LRESULT *pResult)
{
    // 获取鼠标位置
    CPoint point;
    GetCursorPos(&point);

    // 显示上下文菜单
    OnContextMenu(this, point);

    *pResult = 0;
}