#pragma once

#include <WinInet.h>
#include <string>
#include <vector>

#pragma comment(lib, "wininet.lib")

// IE8 on Windows 7
#define		IE8_USER_AGENT	 _T("Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 6.1; Trident/4.0)")

enum HTTP_REQ_METHOD	// HTTP���󷽷�
{
	REQ_METHOD_GET,
	REQ_METHOD_POST,
};

enum HTTP_STATUS_EVENT	// HTTP״̬�¼���ʶ
{
	CONNECTED_EVENT,
	REQUEST_OPENED_EVENT,
	REQUEST_COMPLETE_EVENT,
	USER_CANCEL_EVENT
};

class CHttpClient
{
public:
	CHttpClient(void);
	~CHttpClient(void);

public:
	BOOL OpenRequest(LPCTSTR lpszUrl, HTTP_REQ_METHOD nReqMethod = REQ_METHOD_GET);	// ��HTTP������
	BOOL AddReqHeaders(LPCTSTR lpHeaders);	// ���һ������HTTP����ͷ����
	BOOL SendRequest(const CHAR * lpData, DWORD dwLen);	// ����HTTP������
	BOOL SendRequestEx(DWORD dwLen);	// ��ʼ����HTTP������
	BOOL SendReqBodyData(CHAR * lpBuf, DWORD dwLen, DWORD& dwSendLen);	// ����HTTP������Ϣ�����ݺ���
	BOOL EndSendRequest();	// ��������HTTP������
	DWORD GetRespCode();	// ��ȡHTTP��Ӧ�뺯��
	std::wstring GetRespHeader();	// ��ȡȫ��HTTPͷ
	std::wstring GetRespHeader(LPCTSTR lpszName, int nIndex = 0);	// ��ȡHTTPͷָ���ֶ����Ƶ�ֵ
	int GetRespHeaderByInt(LPCTSTR lpszName, int nIndex = 0);	// ��ȡHTTPͷָ���ֶ����Ƶ�ֵ(Int)
	BOOL GetRespBodyData(CHAR * lpBuf, DWORD dwLen, DWORD& dwRecvLen);	// ��ȡHTTP��Ӧ��Ϣ�����ݺ���
	void CloseRequest();	// �ر�HTTP������

	void SetConnectTimeOut(DWORD dwTimeOut);	// �������ӳ�ʱ(��λ������)
	void SetCancalEvent();	// ����ȡ���¼�����
	void SetProxy(LPCTSTR lpszServer, WORD nPort, 
		LPCTSTR lpszUser = NULL, LPCTSTR lpszPwd = NULL);	// ����HTTP���������

private:
	static void __stdcall StatusCallback(HINTERNET hInternet, DWORD dwContext,	// ״̬�ص�����
		DWORD dwInternetStatus, LPVOID lpStatusInfo, DWORD dwStatusInfoLen);

	BOOL ParseURL(LPCTSTR lpszUrl, LPTSTR lpszScheme, DWORD dwSchemeLength,
		LPTSTR lpszHostName, DWORD dwHostNameLength, WORD& nPort, 
		LPTSTR lpszUrlPath, DWORD dwUrlPathLength);	// ����Url�������ֺ���
	BOOL WaitForEvent(HTTP_STATUS_EVENT nEvent, DWORD dwTimeOut);	// �ȴ��¼�����

	DWORD __GetRespHeaderLen();	// ��ȡHTTP��Ӧͷ����
	BOOL __GetRespHeader();	// ��ȡHTTP��Ӧͷ�����б�����m_arrRespHeader����

private:
	HINTERNET m_hInternet;
	HINTERNET m_hConnect;
	HINTERNET m_hRequest;

	HANDLE m_hConnectedEvent;
	HANDLE m_hRequestOpenedEvent;
	HANDLE m_hRequestCompleteEvent;
	HANDLE m_hCancelEvent;

	DWORD m_dwConnectTimeOut;
	DWORD m_dwContext;

	std::vector<std::wstring> m_arrRespHeader;

	std::wstring m_strProxy;
	std::wstring m_strUser, m_strPwd;
};
