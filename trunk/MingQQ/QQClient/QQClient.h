#pragma once

#include "QQUser.h"
#include "QQProtocol.h"
#include "LoginTask.h"
#include "LogoutTask.h"
#include "PollTask.h"
#include "SendMsgTask.h"
#include "InfoTask.h"
#include "GetC2CMsgSigTask.h"
#include "ChangeStatusTask.h"

class CQQClient
{
public:
	CQQClient(void);
	~CQQClient(void);

public:
	BOOL Init();										// ��ʼ���ͻ���
	void UnInit();										// ����ʼ���ͻ���

	void SetUser(LPCTSTR lpQQNum, LPCTSTR lpQQPwd);		// ����QQ���������
	void SetLoginStatus(QQ_STATUS nStatus);				// ���õ�¼״̬
	void SetCallBackWnd(HWND hCallBackWnd);				// ���ûص����ھ��
	void SetVerifyCode(LPCTSTR lpVerifyCode);			// ������֤��

	BOOL Login();										// ��¼
	BOOL Logout();										// ע��

	void CancelLogin();									// ȡ����¼
	
	void ChangeStatus(QQ_STATUS nStatus);				// �ı�����״̬
	void UpdateBuddyList();								// ���º����б�
	void UpdateGroupList();								// ����Ⱥ�б�
	void UpdateRecentList();							// ���������ϵ���б�
	void UpdateBuddyInfo(UINT nQQUin);					// ���º�����Ϣ
	void UpdateGroupMemberInfo(UINT nGroupCode, UINT nQQUin);	// ����Ⱥ��Ա��Ϣ
	void UpdateGroupInfo(UINT nGroupCode);				// ����Ⱥ��Ϣ
	void UpdateBuddyNum(UINT nQQUin);					// ���º��Ѻ���
	void UpdateGroupMemberNum(UINT nGroupCode, UINT nQQUin);	// ����Ⱥ��Ա����
	void UpdateGroupMemberNum(UINT nGroupCode, std::vector<UINT> * arrQQUin);	// ����Ⱥ��Ա����
	void UpdateGroupNum(UINT nGroupCode);				// ����Ⱥ����
	void UpdateBuddySign(UINT nQQUin);					// ���º��Ѹ���ǩ��
	void UpdateGroupMemberSign(UINT nGroupCode, UINT nQQUin);	// ����Ⱥ��Ա����ǩ��
	void ModifyQQSign(LPCTSTR lpSign);					// �޸�QQ����ǩ��
	void UpdateBuddyHeadPic(UINT nQQUin, UINT nQQNum);			// ���º���ͷ��
	void UpdateGroupMemberHeadPic(UINT nGroupCode, UINT nQQUin, UINT nGroupNum, UINT nQQNum);// ����Ⱥ��Աͷ��
	void UpdateGroupHeadPic(UINT nGroupCode, UINT nGroupNum);	// ����Ⱥͷ��
	void UpdateC2CMsgSignal(UINT nGroupId, UINT nQQUin);// ������ʱ�Ự����
	BOOL SendBuddyMsg(UINT nToUin, int nFace, LPCTSTR lpMsg,// ���ͺ�����Ϣ
		LPCTSTR lpFontName, int nFontSize, COLORREF clrText, 
		BOOL bBold, BOOL bItalic, BOOL bUnderLine);
	BOOL SendGroupMsg(UINT nToUin, LPCTSTR lpMsg,			// ����Ⱥ��Ϣ
		LPCTSTR lpFontName,	int nFontSize, COLORREF clrText, 
		BOOL bBold, BOOL bItalic, BOOL bUnderLine);
	BOOL SendSessMsg(UINT nToUin, int nFace, LPCTSTR lpGroupSig, // ������ʱ�Ự��Ϣ
		LPCTSTR lpMsg, LPCTSTR lpFontName, int nFontSize, 
		COLORREF clrText, BOOL bBold, BOOL bItalic, BOOL bUnderLine);

	BOOL IsOnline();									// �Ƿ�����״̬
	QQ_STATUS GetStatus();								// ��ȡ����״̬
	BOOL GetVerifyCodePic(const BYTE *& lpData, DWORD& dwSize);	// ��ȡ��֤��ͼƬ

	CBuddyInfo * GetUserInfo();							// ��ȡ�û���Ϣ
	CBuddyList * GetBuddyList();						// ��ȡ�����б�
	CGroupList * GetGroupList();						// ��ȡȺ�б�
	CRecentList * GetRecentList();						// ��ȡ�����ϵ���б�
	CMessageList * GetMessageList();					// ��ȡ��Ϣ�б�

	tstring GetHeadPicFullName(UINT nGroupNum, UINT nQQNum);
	tstring GetChatPicFullName(LPCTSTR lpszFileName);

	tstring GetBuddyHeadPicPath();						// ��ȡ����ͷ��ͼƬ���·��
	tstring GetGroupHeadPicPath();						// ��ȡȺͷ��ͼƬ���·��
	tstring GetChatPicPath();							// ��ȡ����ͼƬ���·��
	void SetChatPicPath(LPCTSTR lpPath);				// ��������ͼƬ���·��

	void OnUpdateUserInfo(CBuddyInfoResult * lpBuddyInfoResult);
	void OnUpdateBuddyList(CBuddyListResult * lpBuddyListResult);
	void OnUpdateGroupList(CGroupListResult * lpGroupListResult);
	void OnUpdateRecentList(CRecentListResult * lpRecentListResult);
	void OnBuddyMsg(CBuddyMessage * lpBuddyMsg);
	void OnGroupMsg(CGroupMessage * lpGroupMsg);
	void OnSessMsg(CSessMessage * lpSessMsg);
	void OnSysGroupMsg(CSysGroupMessage * lpSysGroupMsg);
	void OnStatusChangeMsg(CStatusChangeMessage * lpStatusChangeMsg);
	void OnUpdateBuddyNumber(CGetQQNumResult * lpGetQQNumResult);
	void OnUpdateGMemberNumber(UINT nGroupCode, CGetQQNumResult * lpGetQQNumResult);
	void OnUpdateGroupNumber(UINT nGroupCode, CGetQQNumResult * lpGetQQNumResult);
	void OnUpdateBuddySign(CGetSignResult * lpGetSignResult);
	void OnUpdateGMemberSign(UINT nGroupCode, CGetSignResult * lpGetSignResult);
	void OnUpdateBuddyInfo(CBuddyInfoResult * lpBuddyInfoResult);
	void OnUpdateGMemberInfo(UINT nGroupCode, CBuddyInfoResult * lpBuddyInfoResult);
	void OnUpdateGroupInfo(UINT nGroupCode, CGroupInfoResult * lpGroupInfoResult);
	void OnUpdateC2CMsgSig(CGetC2CMsgSigResult * lpGetC2CMsgSigResult);
	void OnChangeStatusResult(BOOL bSuccess, QQ_STATUS nNewStatus);

	BOOL CalcPwdHash(LPCTSTR lpQQPwd, LPCTSTR lpVerifyCode, 
		const CHAR * lpPtUin, int nPtUinLen, TCHAR * lpPwdHash, int nLen)
	{
		return m_QQProtocol.CalcPwdHash(lpQQPwd, lpVerifyCode, lpPtUin, nPtUinLen, lpPwdHash, nLen);
	}

private:
	CQQUser m_QQUser;
	CQQProtocol m_QQProtocol;
	CThreadPool m_ThreadPool;
	CLoginTask m_LoginTask;
	CLogoutTask m_LogoutTask;
	CPollTask m_PollTask;
	CSendMsgTask m_SendMsgTask;
};
