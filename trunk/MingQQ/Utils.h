#pragma once

#include <vector>
#include <string>
#include "ImageOle.h"

#if defined(UNICODE) || defined(_UNICODE)
	typedef std::wstring tstring;
#else
	typedef std::string tstring;
#endif

BOOL EnumSysFont(std::vector<tstring> * arrSysFont);	// ö��ϵͳ����
BOOL FlashWindowEx(HWND hWnd, int nCount);				// ��˸���ڱ�����
BOOL GetTrayWndRect(RECT * lpRect);						// ��ȡϵͳ����������

void RichEdit_SetDefFont(CRichEditCtrl& richEdit, LPCTSTR lpFontName, int nFontSize,	// ����RichEditĬ������
					  COLORREF clrText, BOOL bBold, BOOL bItalic, BOOL bUnderLine);	
void RichEdit_SetDefFont(CRichEditCtrl& richEdit, LPCTSTR lpFontName, int nFontSize);	// ����RichEditĬ���������ƺʹ�С
void RichEdit_SetDefTextColor(CRichEditCtrl& richEdit, COLORREF clrText);	// ����RichEditĬ��������ɫ
void RichEdit_SetFont(CRichEditCtrl& richEdit, LPCTSTR lpFontName, int nFontSize,	// ����RichEdit����
					  COLORREF clrText, BOOL bBold, BOOL bItalic, BOOL bUnderLine);	
void RichEdit_SetFont(CRichEditCtrl& richEdit, LPCTSTR lpFontName, int nFontSize);	// ����RichEdit�������ƺʹ�С
void RichEdit_SetTextColor(CRichEditCtrl& richEdit, COLORREF clrText);	// ����RichEdit������ɫ
void RichEdit_AppendText(CRichEditCtrl& richEdit, LPCTSTR lpText);		// RichEdit����ı�
void RichEdit_SetStartIndent(CRichEditCtrl& richEdit, int nSize);	// RichEdit����������(��λ:�)
BOOL RichEdit_InsertFace(CRichEditCtrl& richEdit, LPCTSTR lpszFileName, int nFaceId);	// �������ͼƬ
void RichEdit_GetText(CRichEditCtrl& richEdit, CString& strText);	// ��ȡ�ı�

/********************************* CMainDlg�Զ�����Ϣ *********************************/
#define			WM_TRAYICON_NOTIFY		WM_USER + 1		// ϵͳ����ͼ��֪ͨ��Ϣ
#define			WM_SHOW_BUDDYCHATDLG	WM_USER + 2		// ��ʾ���ѻỰ����Ի�����Ϣ
#define			WM_SHOW_GROUPCHATDLG	WM_USER + 3		// ��ʾȺ�Ự����Ի�����Ϣ
#define			WM_SHOW_SESSCHATDLG		WM_USER + 4		// ��ʾ��ʱ�Ự����Ի�����Ϣ
#define			WM_SHOW_SYSGROUPCHATDLG	WM_USER + 5		// ��ʾȺϵͳ�Ի�����Ϣ
#define			WM_SHOW_BUDDYINFODLG	WM_USER + 6		// ��ʾ������Ϣ�Ի�����Ϣ
#define			WM_SHOW_GMEMBERINFODLG	WM_USER + 8		// ��ʾȺ��Ա��Ϣ�Ի�����Ϣ
#define			WM_SHOW_GROUPINFODLG	WM_USER + 9		// ��ʾȺ��Ϣ�Ի�����Ϣ
#define			WM_CLOSE_BUDDYCHATDLG	WM_USER + 10	// �رպ��ѻỰ����Ի�����Ϣ
#define			WM_CLOSE_GROUPCHATDLG	WM_USER + 11	// �ر�Ⱥ�Ự����Ի�����Ϣ
#define			WM_CLOSE_SESSCHATDLG	WM_USER + 12	// �ر���ʱ�Ự����Ի�����Ϣ
#define			WM_CLOSE_SYSGROUPCHATDLG WM_USER + 13	// �ر�Ⱥϵͳ�Ի�����Ϣ
#define			WM_CLOSE_BUDDYINFODLG	WM_USER + 14	// �رպ�����Ϣ�Ի�����Ϣ
#define			WM_CLOSE_GROUPINFODLG	WM_USER + 15	// �ر�Ⱥ��Ա��Ϣ�Ի�����Ϣ
#define			WM_CLOSE_GMEMBERINFODLG	WM_USER + 16	// �ر�Ⱥ��Ϣ�Ի�����Ϣ
#define			WM_DEL_MSG_SENDER		WM_USER + 17	// ɾ����������Ϣ
#define			WM_CANCEL_FLASH			WM_USER + 18	// ȡ������ͼ����˸��Ϣ
/********************************* CMainDlg�Զ�����Ϣ *********************************/