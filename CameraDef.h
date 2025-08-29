#pragma once
#include <afxstr.h>
#include <afxwin.h>
// 相机信息结构体
struct CameraInfo
{
    CString strIP;     // 相机IP
    int nPort;         // 端口（默认8000）
    CString strUser;   // 用户名
    CString strPwd;    // 密码
    LONG lUserID;      // 登录句柄（-1表示未登录）
    LONG lRealHandle;  // 预览句柄（-1表示未预览）
    LONG lPort;        // 播放端口
    bool bIsLoggedIn;  // 登录状态
    CWnd *pDisplayWnd; // 显示窗口（指向视频显示控件）
};