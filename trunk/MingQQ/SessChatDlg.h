#pragma once

#include "resource.h"
#include "QQClient/QQClient.h"
#include "Utils.h"
#include "FaceList.h"
#include "FaceSelDlg.h"
#include "ImageEx.h"

class CSessChatDlg : public CDialogImpl<CSessChatDlg>, public CMessageFilter
{
public:
	CSessChatDlg(void);
	~CSessChatDlg(void);

	enum { IDD = IDD_BUDDYCHATDLG };

	virtual BOOL PreTranslateMessage(MSG* pMsg);

	BEGIN_MSG_MAP_EX(CSessChatDlg)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_CLOSE(OnClose)
		MSG_WM_DESTROY(OnDestroy)
		COMMAND_HANDLER_EX(ID_LINK_BUDDYNAME, BN_CLICKED, OnLnk_BuddyName)
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
		COMMAND_ID_HANDLER_EX(ID_MENU_CUT, OnMenu_Cut)
		COMMAND_ID_HANDLER_EX(ID_MENU_COPY, OnMenu_Copy)
		COMMAND_ID_HANDLER_EX(ID_MENU_PASTE, OnMenu_Paste)
		COMMAND_ID_HANDLER_EX(ID_MENU_SELALL, OnMenu_SelAll)
		COMMAND_ID_HANDLER_EX(ID_MENU_CLEAR, OnMenu_Clear)
		MESSAGE_HANDLER_EX(FACE_CTRL_SEL, OnFaceCtrlSel)
	END_MSG_MAP()

public:
	void OnRecvMsg(UINT nQQUin, UINT nMsgId);
	void OnUpdateC2CMsgSig();
	//void OnUpdateBuddyHeadPic();		// ���º���ͷ��֪ͨ

private:
	BOOL OnInitDialog(CWindow wndFocus, LPARAM lInitParam);
	void OnClose();
	void OnDestroy();
	void OnLnk_BuddyName(UINT uNotifyCode, int nID, CWindow wndCtl);// ���������ơ������ӿؼ�
	void OnBtn_Face(UINT uNotifyCode, int nID, CWindow wndCtl);		// �����顱��ť
	void OnCbo_SelChange_FontName(UINT uNotifyCode, int nID, CWindow wndCtl);// ���������ơ���Ͽ�
	void OnCbo_SelChange_FontSize(UINT uNotifyCode, int nID, CWindow wndCtl);// �������С����Ͽ�
	void OnChk_Bold(UINT uNotifyCode, int nID, CWindow wndCtl);		// ���Ӵ֡���ѡ��
	void OnChk_Italic(UINT uNotifyCode, int nID, CWindow wndCtl);	// ��б�塱��ѡ��
	void OnChk_UnderLine(UINT uNotifyCode, int nID, CWindow wndCtl);// ���»��ߡ���ѡ��
	void OnBtn_Color(UINT uNotifyCode, int nID, CWindow wndCtl);	// ����ɫ����ť
	void OnBtn_Close(UINT uNotifyCode, int nID, CWindow wndCtl);	// ���رա���ť
	void OnBtn_Send(UINT uNotifyCode, int nID, CWindow wndCtl);		// �����͡���ť
	LRESULT OnRichEdit_Recv_Link(LPNMHDR pnmh);						//	��������Ϣ�����ı������ӵ����Ϣ
	void OnMenu_Cut(UINT uNotifyCode, int nID, CWindow wndCtl);		// �����С��˵�
	void OnMenu_Copy(UINT uNotifyCode, int nID, CWindow wndCtl);	// �����ơ��˵�
	void OnMenu_Paste(UINT uNotifyCode, int nID, CWindow wndCtl);	// ��ճ�����˵�
	void OnMenu_SelAll(UINT uNotifyCode, int nID, CWindow wndCtl);	// ��ȫ��ѡ�񡱲˵�
	void OnMenu_Clear(UINT uNotifyCode, int nID, CWindow wndCtl);	// ���������˵�
	LRESULT OnFaceCtrlSel(UINT uMsg, WPARAM wParam, LPARAM lParam);	// �����顱�ؼ�ѡȡ��Ϣ

	CGroupInfo * GetGroupInfoPtr();		// ��ȡȺ��Ϣָ��
	CBuddyInfo * GetBuddyInfoPtr();		// ��ȡ������Ϣָ��
	CBuddyInfo * GetUserInfoPtr();		// ��ȡ�û���Ϣָ��
	void UpdateData();					// ��������
	void UpdateDlgTitle();				// ���¶Ի��������
	void UpdateBuddyNameCtrl();			// ���º������ƿؼ�
	void UpdateGroupNameCtrl();			// ����Ⱥ���ƿؼ�
	BOOL InitCtrls();					// ��ʼ���ؼ�
	BOOL UnInitCtrls();					// ����ʼ���ؼ�
	BOOL InitMidToolBar();				// ��ʼ���м乤����
	void AddMsg(CSessMessage * lpSessMsg);
	void AddMsg(LPCTSTR lpText);

public:
	CQQClient * m_lpQQClient;
	CFaceList * m_lpFaceList;
	HWND m_hMainDlg;
	UINT m_nGroupCode;
	UINT m_nQQUin;

private:
	CStatic m_picHead, m_picAD1, m_picAD2, m_picAD3;
	CHyperLink m_lnkBuddyName;
	CEdit m_edtGroupName;
	CRichEditCtrl m_richRecv, m_richSend;
	CComboBox m_cboFontName, m_cboFontSize;
	CButton m_btnBold, m_btnItalic, m_btnUnderLine;
	CFaceSelDlg m_FaceSelDlg;
	CAccelerator m_Accelerator;
	CMenu m_menuRichEdit;
	CImageEx m_imgHead, m_imgAD1, m_imgAD2, m_imgAD3;
	HICON m_hDlgIcon, m_hDlgSmallIcon;

	CFontInfo m_fontInfo;
	std::vector<CString> m_arrPengingMsg;

	UINT m_nGroupId;
	UINT m_nQQNumber;
	CString m_strBuddyName;
	CString m_strGroupName;
	CString m_strUserName;
	CString m_strGroupSig;
};
