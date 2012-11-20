#pragma once

#include "resource.h"
#include "QQClient/QQClient.h"
#include "Utils.h"
#include "FaceList.h"
#include "FaceSelDlg.h"
#include "ImageEx.h"
#include "HeadImageList.h"

class CGroupChatDlg : public CDialogImpl<CGroupChatDlg>, public CMessageFilter
{
public:
	CGroupChatDlg(void);
	~CGroupChatDlg(void);

	enum { IDD = IDD_GROUPCHATDLG };

	virtual BOOL PreTranslateMessage(MSG* pMsg);

	BEGIN_MSG_MAP_EX(CGroupChatDlg)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_CLOSE(OnClose)
		MSG_WM_DESTROY(OnDestroy)
		COMMAND_HANDLER_EX(ID_LINK_GROUPNAME, BN_CLICKED, OnLnk_GroupName)
		COMMAND_HANDLER_EX(ID_BTN_FACE, BN_CLICKED, OnBtn_Face)
		COMMAND_HANDLER_EX(ID_COMBO_FONT_NAME, CBN_SELCHANGE, OnCbo_SelChange_FontName)
		COMMAND_HANDLER_EX(ID_COMBO_FONT_SIZE, CBN_SELCHANGE, OnCbo_SelChange_FontSize)
		COMMAND_HANDLER_EX(ID_CHECK_BOLD, BN_CLICKED, OnChk_Bold)
		COMMAND_HANDLER_EX(ID_CHECK_ITALIC, BN_CLICKED, OnChk_Italic)
		COMMAND_HANDLER_EX(ID_CHECK_UNDERLINE, BN_CLICKED, OnChk_UnderLine)
		COMMAND_HANDLER_EX(ID_BTN_COLOR, BN_CLICKED, OnBtn_Color)
		COMMAND_HANDLER_EX(ID_BTN_CLOSE, BN_CLICKED, OnBtn_Close)
		COMMAND_ID_HANDLER_EX(ID_BTN_SEND, OnBtn_Send)
		NOTIFY_HANDLER_EX(ID_RICHEDIT_RECV, EN_LINK, OnRichEdit_Recv_Link)
		NOTIFY_HANDLER_EX(ID_LIST_MERBER, NM_DBLCLK, OnGMemberList_DblClick)
		NOTIFY_HANDLER_EX(ID_LIST_MERBER, NM_RCLICK, OnGMemberList_RClick)
		COMMAND_ID_HANDLER_EX(ID_MENU_CUT, OnMenu_Cut)
		COMMAND_ID_HANDLER_EX(ID_MENU_COPY, OnMenu_Copy)
		COMMAND_ID_HANDLER_EX(ID_MENU_PASTE, OnMenu_Paste)
		COMMAND_ID_HANDLER_EX(ID_MENU_SELALL, OnMenu_SelAll)
		COMMAND_ID_HANDLER_EX(ID_MENU_CLEAR, OnMenu_Clear)
		COMMAND_ID_HANDLER_EX(ID_MENU_VIEW_INFO, OnMenu_ViewInfo)
		COMMAND_ID_HANDLER_EX(ID_MENU_SEND_MSG, OnMenu_SendMsg)
		MESSAGE_HANDLER_EX(FACE_CTRL_SEL, OnFaceCtrlSel)
	END_MSG_MAP()

public:
	void OnRecvMsg(UINT nGroupCode, UINT nMsgId);				// ����Ⱥ��Ϣ
	void OnUpdateGroupInfo();									// ����Ⱥ��Ϣ
	void OnUpdateGroupNumber();									// ����Ⱥ����
	void OnUpdateGMemberNumber(WPARAM wParam, LPARAM lParam);	// ����Ⱥ��Ա����

private:
	BOOL OnInitDialog(CWindow wndFocus, LPARAM lInitParam);
	void OnClose();
	void OnDestroy();
	void OnLnk_GroupName(UINT uNotifyCode, int nID, CWindow wndCtl);// ��Ⱥ���ơ������ӿؼ�
	void OnBtn_Face(UINT uNotifyCode, int nID, CWindow wndCtl);	// �����顱��ť
	void OnCbo_SelChange_FontName(UINT uNotifyCode, int nID, CWindow wndCtl);	// ���������ơ���Ͽ�
	void OnCbo_SelChange_FontSize(UINT uNotifyCode, int nID, CWindow wndCtl);	// �������С����Ͽ�
	void OnChk_Bold(UINT uNotifyCode, int nID, CWindow wndCtl);	// ���Ӵ֡���ѡ��
	void OnChk_Italic(UINT uNotifyCode, int nID, CWindow wndCtl);// ��б�塱��ѡ��
	void OnChk_UnderLine(UINT uNotifyCode, int nID, CWindow wndCtl);// ���»��ߡ���ѡ��
	void OnBtn_Color(UINT uNotifyCode, int nID, CWindow wndCtl);// ����ɫ����ť
	void OnBtn_Close(UINT uNotifyCode, int nID, CWindow wndCtl);// ���رա���ť
	void OnBtn_Send(UINT uNotifyCode, int nID, CWindow wndCtl);	// �����͡���ť
	LRESULT OnRichEdit_Recv_Link(LPNMHDR pnmh);						//	��������Ϣ�����ı������ӵ����Ϣ
	LRESULT OnGMemberList_DblClick(LPNMHDR pnmh);					// ��Ⱥ��Ա���б�˫����Ϣ
	LRESULT OnGMemberList_RClick(LPNMHDR pnmh);						// ��Ⱥ��Ա���б��Ҽ�������Ϣ
	void OnMenu_Cut(UINT uNotifyCode, int nID, CWindow wndCtl);		// �����С��˵�
	void OnMenu_Copy(UINT uNotifyCode, int nID, CWindow wndCtl);	// �����ơ��˵�
	void OnMenu_Paste(UINT uNotifyCode, int nID, CWindow wndCtl);	// ��ճ�����˵�
	void OnMenu_SelAll(UINT uNotifyCode, int nID, CWindow wndCtl);	// ��ȫ��ѡ�񡱲˵�
	void OnMenu_Clear(UINT uNotifyCode, int nID, CWindow wndCtl);	// ���������˵�
	void OnMenu_ViewInfo(UINT uNotifyCode, int nID, CWindow wndCtl);// ���鿴���ϡ��˵�
	void OnMenu_SendMsg(UINT uNotifyCode, int nID, CWindow wndCtl);	// ��������Ϣ���˵�
	LRESULT OnFaceCtrlSel(UINT uMsg, WPARAM wParam, LPARAM lParam);	// �����顱�ؼ�ѡȡ��Ϣ

	CGroupInfo * GetGroupInfoPtr();		// ��ȡȺ��Ϣָ��
	CBuddyInfo * GetUserInfoPtr();		// ��ȡ�û���Ϣָ��
	void UpdateData();					// ������Ϣ
	void UpdateDlgTitle();				// ���¶Ի��������
	BOOL UpdateGroupNameCtrl();			// ����Ⱥ���ƿؼ�
	BOOL UpdateGroupMemo();				// ����Ⱥ����
	BOOL UpdateGroupMemberList();		// ����Ⱥ��Ա�б�
	BOOL InitCtrls();					// ��ʼ���ؼ�
	BOOL UnInitCtrls();					// ����ʼ���ؼ�
	BOOL InitMidToolBar();				// ��ʼ���м乤����
	void AddMsg(CGroupMessage * lpGroupMsg);
	void AddMsg(LPCTSTR lpText);
	void GetSenderInfo(UINT nQQUin, CString& strName, UINT& nQQNum);

public:
	CQQClient * m_lpQQClient;
	CFaceList * m_lpFaceList;
	HWND m_hMainDlg;
	UINT m_nGroupCode;

private:
	CStatic m_picHead;
	CHyperLink m_lnkGroupName;
	CStatic m_picAD;
	CEdit m_edtMemo;
	CComboBox m_cboFontName, m_cboFontSize;
	CButton m_btnBold, m_btnItalic, m_btnUnderLine;
	CListViewCtrl m_ListCtrl;
	CRichEditCtrl m_richRecv, m_richSend;
	CFaceSelDlg m_FaceSelDlg;
	CAccelerator m_Accelerator;
	CMenu m_menuRichEdit;
	CHeadImageList m_headImageList;
	CImageEx m_imgHead, m_imgAD;
	HICON m_hDlgIcon, m_hDlgSmallIcon;

	CFontInfo m_fontInfo;
	BOOL m_bIsHasGroupInfo;
	BOOL m_bIsHasGroupNumber;
	BOOL m_bIsHasGMemberNumber;
	int m_nGMemberNumberReq;
	CString m_strCurLink;

	UINT m_nGroupId, m_nGroupNumber;
	UINT m_nUserNumber;
	CString m_strGroupName;
	CString m_strUserName;
	int m_nMemberCnt, m_nOnlineMemberCnt;
};
