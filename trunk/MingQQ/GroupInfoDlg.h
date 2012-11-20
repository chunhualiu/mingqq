#pragma once

#include "QQClient/QQClient.h"
#include "Utils.h"

class CGroupInfoDlg : public CDialogImpl<CGroupInfoDlg>
{
public:
	CGroupInfoDlg(void);
	~CGroupInfoDlg(void);

	enum { IDD = IDD_GROUPINFODLG };

	BEGIN_MSG_MAP_EX(CGroupInfoDlg)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_CLOSE(OnClose)
		MSG_WM_DESTROY(OnDestroy)
		COMMAND_HANDLER_EX(ID_BTN_OK, BN_CLICKED, OnBtn_Ok)
		COMMAND_HANDLER_EX(ID_BTN_CANCEL, BN_CLICKED, OnBtn_Cancel)
	END_MSG_MAP()

public:
	void OnUpdateGroupInfo();	// ����Ⱥ��Ϣ
	void OnUpdateGroupNumber();	// ����Ⱥ����

private:
	BOOL OnInitDialog(CWindow wndFocus, LPARAM lInitParam);
	void OnClose();
	void OnDestroy();
	void OnBtn_Ok(UINT uNotifyCode, int nID, CWindow wndCtl);		// ��ȷ������ť
	void OnBtn_Cancel(UINT uNotifyCode, int nID, CWindow wndCtl);	// ��ȡ������ť

	CGroupInfo * GetGroupInfoPtr();
	void UpdateCtrls();

public:
	CQQClient * m_lpQQClient;
	HWND m_hMainDlg;
	UINT m_nGroupCode;
	HICON m_hDlgIcon, m_hDlgSmallIcon;
};
