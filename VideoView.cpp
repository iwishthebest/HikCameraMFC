#include "pch.h"
#include "VideoView.h"
#include "resource.h"
#include <algorithm> // 包含 min 函数

IMPLEMENT_DYNAMIC(CVideoView, CWnd)

BEGIN_MESSAGE_MAP(CVideoView, CWnd)
ON_WM_PAINT()
ON_WM_ERASEBKGND()
ON_WM_SIZE()
END_MESSAGE_MAP()

CVideoView::CVideoView() : m_bShowPlaceholder(true), m_placeholderText(_T("等待视频信号..."))
{
    CreateBackgroundBrush();
}

CVideoView::~CVideoView() {}

void CVideoView::CreateBackgroundBrush()
{
    // 创建深灰色背景画刷
    m_bgBrush.CreateSolidBrush(RGB(25, 25, 25));
}

void CVideoView::UpdateFrame(const cv::Mat &frame)
{
    if (!frame.empty())
    {
        frame.copyTo(m_currentFrame);
        m_bShowPlaceholder = false;
        Invalidate(FALSE); // 请求重绘，不擦除背景
    }
}

void CVideoView::ClearFrame()
{
    m_currentFrame.release();
    m_bShowPlaceholder = true;
    Invalidate(FALSE);
}

void CVideoView::OnPaint()
{
    CPaintDC dc(this); // 设备上下文用于绘制

    // 获取客户区域
    CRect rect;
    GetClientRect(&rect);

    // 创建内存DC用于双缓冲
    CDC memDC;
    memDC.CreateCompatibleDC(&dc);
    CBitmap memBitmap;
    memBitmap.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
    CBitmap *pOldBitmap = memDC.SelectObject(&memBitmap);

    // 填充背景
    memDC.FillRect(rect, &m_bgBrush);

    // 绘制视频帧或占位符
    if (!m_bShowPlaceholder && !m_currentFrame.empty())
    {
        DrawFrame(memDC);
    }
    else
    {
        DrawPlaceholder(memDC, rect);
    }

    // 绘制边框
    DrawBorder(memDC, rect);

    // 将内存DC复制到屏幕DC
    dc.BitBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, SRCCOPY);

    // 清理
    memDC.SelectObject(pOldBitmap);
}

BOOL CVideoView::OnEraseBkgnd(CDC *pDC)
{
    // 阻止擦除背景，减少闪烁
    return TRUE;
}

void CVideoView::OnSize(UINT nType, int cx, int cy)
{
    CWnd::OnSize(nType, cx, cy);
    Invalidate(TRUE);
}

void CVideoView::DrawFrame(CDC &dc)
{
    CRect rect;
    GetClientRect(&rect);

    // 计算保持宽高比的缩放尺寸
    double scaleX = (double)rect.Width() / m_currentFrame.cols;
    double scaleY = (double)rect.Height() / m_currentFrame.rows;
    double scale = std::min(scaleX, scaleY);

    int newWidth = (int)(m_currentFrame.cols * scale);
    int newHeight = (int)(m_currentFrame.rows * scale);

    // 计算居中位置
    int offsetX = (rect.Width() - newWidth) / 2;
    int offsetY = (rect.Height() - newHeight) / 2;

    // 转换OpenCV Mat到BITMAPINFO
    BITMAPINFO bmi;
    ZeroMemory(&bmi, sizeof(BITMAPINFO));
    bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biWidth = m_currentFrame.cols;
    bmi.bmiHeader.biHeight = -m_currentFrame.rows; // 负值表示从上到下
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biBitCount = 24;
    bmi.bmiHeader.biCompression = BI_RGB;

    // 创建临时RGB Mat
    cv::Mat rgbFrame;
    if (m_currentFrame.channels() == 1)
    {
        cv::cvtColor(m_currentFrame, rgbFrame, cv::COLOR_GRAY2RGB);
    }
    else
    {
        cv::cvtColor(m_currentFrame, rgbFrame, cv::COLOR_BGR2RGB);
    }

    // 绘制图像
    ::StretchDIBits(dc.GetSafeHdc(), offsetX, offsetY, newWidth, newHeight, 0, 0, rgbFrame.cols, rgbFrame.rows,
                    rgbFrame.data, &bmi, DIB_RGB_COLORS, SRCCOPY);
}

void CVideoView::DrawPlaceholder(CDC &dc, CRect rect)
{
    dc.SetBkMode(TRANSPARENT);
    dc.SetTextColor(RGB(180, 180, 180));

    // 创建字体
    CFont font;
    font.CreatePointFont(180, _T("Segoe UI"));
    CFont *pOldFont = dc.SelectObject(&font);

    // 绘制居中文本
    CSize textSize = dc.GetTextExtent(m_placeholderText);
    int x = (rect.Width() - textSize.cx) / 2;
    int y = (rect.Height() - textSize.cy) / 2;
    dc.TextOut(x, y, m_placeholderText);

    // 绘制相机图标
    HICON hIcon = AfxGetApp()->LoadIcon(IDI_CAMERA_PLACEHOLDER);
    if (hIcon)
    {
        int iconSize = 64;
        int iconX = (rect.Width() - iconSize) / 2;
        int iconY = y - iconSize - 20;
        dc.DrawIcon(iconX, iconY, hIcon);
    }

    dc.SelectObject(pOldFont);
}

void CVideoView::DrawBorder(CDC &dc, CRect rect)
{
    CPen pen(PS_SOLID, 1, RGB(60, 60, 60));
    CPen *pOldPen = dc.SelectObject(&pen);

    // 绘制内边框
    dc.MoveTo(rect.left, rect.top);
    dc.LineTo(rect.right - 1, rect.top);
    dc.LineTo(rect.right - 1, rect.bottom - 1);
    dc.LineTo(rect.left, rect.bottom - 1);
    dc.LineTo(rect.left, rect.top);

    dc.SelectObject(pOldPen);
}