#pragma once

// 2012.4.26 modify 

namespace ZYM
{

class CPath
{
public:
	CPath(void);
	~CPath(void);

	static CString GetAppPath();	// ��ȡӦ�ó���ִ��·��
	static CString GetCurDir();	// ��ȡӦ�ó���ǰĿ¼
	static CString GetTempPath();	// ��ȡ��ǰϵͳ����ʱ�ļ��е�·��
	static CString GetTempFileName(LPCTSTR lpszFileName);	// ��ȡ��ǰϵͳ����ʱ�ļ��е�·���µ�Ψһ��������ʱ�ļ���(ȫ·��)
	static CString GetRandomFileName(LPCTSTR lpszPath, LPCTSTR lpszFileName);	// ��ȡ����ļ���(ȫ·��)

	static BOOL IsDirectory(LPCTSTR lpszPath);	// ���ָ��·���Ƿ�Ŀ¼
	static BOOL IsFileExist(LPCTSTR lpszFileName);	// ���ָ���ļ��Ƿ����
	static BOOL IsDirectoryExist(LPCTSTR lpszPath);	// ���ָ��Ŀ¼�Ƿ����
	static BOOL CreateDirectory(LPCTSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes);

	static CString GetPathRoot(LPCTSTR lpszPath);	// ��ȡָ��·���ĸ�Ŀ¼��Ϣ
	static CString GetDirectoryName(LPCTSTR lpszPath);	// ����ָ��·���ַ�����Ŀ¼��Ϣ
	static CString GetFileName(LPCTSTR lpszPath); // ����ָ��·���ַ������ļ�������չ��
	static CString GetFileNameWithoutExtension(LPCTSTR lpszPath);	// ���ز�������չ����·���ַ������ļ���
	static CString GetExtension(LPCTSTR lpszPath);	// ����ָ����·���ַ�������չ��
	static CString GetFullPath(LPCTSTR lpszPath);	// ����ָ�������·����ȡ����·��
};

}