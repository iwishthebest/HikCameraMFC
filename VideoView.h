#pragma once
#include <opencv2/opencv.hpp>

// CVideoView 类用于显示视频流
class CVideoView : public CWnd
{
    DECLARE_DYNAMIC(CVideoView)

  public:
    CVideoView();
    virtual ~CVideoView();

    // 更新视频帧
    void UpdateFrame(const cv::Mat &frame);

    // 清除当前视频帧
    void ClearFrame();

    // 获取当前视频帧
    cv::Mat GetCurrentFrame() const { return m_currentFrame; }

  protected:
    DECLARE_MESSAGE_MAP()

    afx_msg void OnPaint();
    afx_msg BOOL OnEraseBkgnd(CDC *pDC);
    afx_msg void OnSize(UINT nType, int cx, int cy);

  private:
    // 绘制视频帧
    void DrawFrame(CDC &dc);

    // 绘制占位符
    void DrawPlaceholder(CDC &dc, CRect rect);

    // 绘制边框
    void DrawBorder(CDC &dc, CRect rect);

    // 创建背景画刷
    void CreateBackgroundBrush();

  private:
    cv::Mat m_currentFrame;    // 当前视频帧
    CBrush m_bgBrush;          // 背景画刷
    bool m_bShowPlaceholder;   // 是否显示占位符
    CString m_placeholderText; // 占位符文本
};