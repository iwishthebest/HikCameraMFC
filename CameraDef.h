#pragma once
#include <afxstr.h>
#include <afxwin.h>
// �����Ϣ�ṹ��
struct CameraInfo
{
    CString strIP;     // ���IP
    int nPort;         // �˿ڣ�Ĭ��8000��
    CString strUser;   // �û���
    CString strPwd;    // ����
    LONG lUserID;      // ��¼�����-1��ʾδ��¼��
    LONG lRealHandle;  // Ԥ�������-1��ʾδԤ����
    LONG lPort;        // ���Ŷ˿�
    bool bIsLoggedIn;  // ��¼״̬
    CWnd *pDisplayWnd; // ��ʾ���ڣ�ָ����Ƶ��ʾ�ؼ���
};