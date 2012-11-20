#include "StdAfx.h"
#include "Path.h"

namespace ZYM
{

CPath::CPath(void)
{
}

CPath::~CPath(void)
{
}

// ��ȡӦ�ó���ִ��·��
CString CPath::GetAppPath()
{
	static TCHAR szPath[MAX_PATH] = {0};

	if (szPath[0] == _T('\0'))
	{
		::GetModuleFileName(NULL, szPath, MAX_PATH);

		CString strPath = GetDirectoryName(szPath);
		_tcsncpy(szPath, strPath, MAX_PATH);
	}

	return szPath;
}

// ��ȡӦ�ó���ǰĿ¼
CString CPath::GetCurDir()
{
	TCHAR szCurDir[MAX_PATH] = {0};
	::GetCurrentDirectory(MAX_PATH, szCurDir);

	if (szCurDir[_tcslen(szCurDir) - 1] != _T('\\'))
		_tcscat(szCurDir, _T("\\"));

	return szCurDir;
}

// ��ȡ��ǰϵͳ����ʱ�ļ��е�·��
CString CPath::GetTempPath()
{
	TCHAR szTempPath[MAX_PATH] = {0};

	::GetTempPath(MAX_PATH, szTempPath);

	if (szTempPath[_tcslen(szTempPath) - 1] != _T('\\'))
		_tcscat(szTempPath, _T("\\"));

	return szTempPath;
}

// ��ȡ��ǰϵͳ����ʱ�ļ��е�·���µ�Ψһ��������ʱ�ļ���(ȫ·��)
CString CPath::GetTempFileName(LPCTSTR lpszFileName)
{
	return GetRandomFileName(GetTempPath(), lpszFileName);
}

// ��ȡ����ļ���(ȫ·��)
CString CPath::GetRandomFileName(LPCTSTR lpszPath, LPCTSTR lpszFileName)
{
	CString strPath, strFileName, strExtFileName, strFullPath;

	if (!IsDirectoryExist(lpszPath))
		strPath = GetCurDir();
	else
		strPath = lpszPath;

	strFileName = GetFileNameWithoutExtension(lpszFileName);
	strExtFileName = GetExtension(lpszFileName);

	for (int i = 2; i < 10000; i++)
	{
		if (strExtFileName.IsEmpty())
			strFullPath.Format(_T("%s%s%d"), strPath, strFileName, i);
		else
			strFullPath.Format(_T("%s%s%d.%s"), strPath, strFileName, i, strExtFileName);
		
		if (!IsFileExist(strFullPath))
		{
			return strFullPath;
		}
	}

	return _T("");
}

// ���ָ��·���Ƿ�Ŀ¼
BOOL CPath::IsDirectory(LPCTSTR lpszPath)
{
	if (NULL == lpszPath || _tcslen(lpszPath) <= 0)
		return FALSE;

	DWORD dwAttr = ::GetFileAttributes(lpszPath);

	if((dwAttr != 0xFFFFFFFF) && (dwAttr & FILE_ATTRIBUTE_DIRECTORY))
		return TRUE;
	else
		return FALSE;
}

// ���ָ���ļ��Ƿ����
BOOL CPath::IsFileExist(LPCTSTR lpszFileName)
{
	if (NULL == lpszFileName || _tcslen(lpszFileName) <= 0)
		return FALSE;

	if(::GetFileAttributes(lpszFileName) != 0xFFFFFFFF)
		return TRUE;
	else
		return FALSE;
}

// ���ָ��Ŀ¼�Ƿ����
BOOL CPath::IsDirectoryExist(LPCTSTR lpszPath)
{
	if (NULL == lpszPath || _tcslen(lpszPath) <= 0)
		return FALSE;

	DWORD dwAttr = ::GetFileAttributes(lpszPath);

	if((dwAttr != 0xFFFFFFFF) && (dwAttr & FILE_ATTRIBUTE_DIRECTORY))
		return TRUE;
	else
		return FALSE;
}

BOOL CPath::CreateDirectory(LPCTSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes)
{
	TCHAR cPath[MAX_PATH] = {0};
	TCHAR cTmpPath[MAX_PATH] = {0};
	TCHAR * lpPos = NULL;
	TCHAR cTmp = _T('\0');

	if (NULL == lpPathName || NULL == *lpPathName)
		return FALSE;

	_tcsncpy(cPath, lpPathName, MAX_PATH);

	lpPos = _tcschr(cPath, _T('\\'));
	while (lpPos != NULL)
	{
		if (lpPos == cPath)
		{
			lpPos++;
		}
		else
		{
			cTmp = *lpPos;
			*lpPos = _T('\0');
			_tcsncpy(cTmpPath, cPath, MAX_PATH);
			::CreateDirectory(cTmpPath, lpSecurityAttributes);
			*lpPos = cTmp;
			lpPos++;
		}
		lpPos = _tcschr(lpPos, _T('\\'));
	}

	return TRUE;
}

// ��ȡָ��·���ĸ�Ŀ¼��Ϣ
CString CPath::GetPathRoot(LPCTSTR lpszPath)
{
	CString strPath(lpszPath);

	int nPos = strPath.Find(_T('\\'));
	if (nPos != -1)
	{
		strPath = strPath.Left(nPos + 1);
	}

	return strPath;
}

// ����ָ��·���ַ�����Ŀ¼��Ϣ
CString CPath::GetDirectoryName(LPCTSTR lpszPath)
{
	CString strPath(lpszPath);

	int nPos = strPath.ReverseFind(_T('\\'));
	if (nPos != -1)
	{
		strPath = strPath.Left(nPos + 1);
	}

	return strPath;
}

// ����ָ��·���ַ������ļ�������չ��
CString CPath::GetFileName(LPCTSTR lpszPath)
{
	CString strPath(lpszPath);

	int nPos = strPath.ReverseFind(_T('\\'));
	if (nPos != -1)
	{
		strPath = strPath.Right(strPath.GetLength() - nPos - 1);
	}

	return strPath;
}

// ���ز�������չ����·���ַ������ļ���
CString CPath::GetFileNameWithoutExtension(LPCTSTR lpszPath)
{
	CString strPath(lpszPath);

	int nPos = strPath.ReverseFind(_T('\\'));
	if (nPos != -1)
		strPath = strPath.Right(strPath.GetLength() - nPos - 1);

	nPos = strPath.ReverseFind(_T('.'));
	if (nPos != -1)
		strPath = strPath.Left(nPos);

	return strPath;
}

// ����ָ����·���ַ�������չ��
CString CPath::GetExtension(LPCTSTR lpszPath)
{
	CString strPath(lpszPath);

	int nPos = strPath.ReverseFind(_T('.'));
	if (nPos != -1)
	{
		strPath = strPath.Right(strPath.GetLength() - nPos - 1);
	}

	return strPath;
}

// ����ָ�������·����ȡ����·��
CString CPath::GetFullPath(LPCTSTR lpszPath)
{
	CString strPath(lpszPath);

	TCHAR cFirstChar = strPath.GetAt(0);
	TCHAR cSecondChar = strPath.GetAt(1);

	if (cFirstChar == _T('\\'))
	{
		CString strCurDir = GetCurDir();
		CString strRootPath = GetPathRoot(strCurDir);
		return strRootPath + strPath;
	}
	else if (::IsCharAlpha(cFirstChar) && cSecondChar == _T(':'))
	{
		return strPath;
	}
	else
	{
		CString strCurDir = GetAppPath();
		return strCurDir + strPath;
	}
}

}