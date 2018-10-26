#include "StdAfx.h"
#include "DataManager.h"

CDataManager::CDataManager(void)
{
}

CDataManager::~CDataManager(void)
{
}

BOOL CDataManager::ReadString( HKEY hKey, LPCTSTR lpKey, LPCTSTR lpValue, LPBYTE lpRet, DWORD nSize )
{
	HKEY key;
	DWORD dwDisp;
	DWORD Size;

	if (RegCreateKeyEx(hKey, lpKey, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_READ, NULL, &key, &dwDisp) != ERROR_SUCCESS)
		return FALSE;

	Size = nSize;

	if (RegQueryValueEx(key, lpValue, 0, NULL, (LPBYTE)lpRet, &Size) != ERROR_SUCCESS)
	{
		return FALSE;
	}

	RegCloseKey(key);

	return TRUE;
}

BOOL CDataManager::WriteString( HKEY hKey, LPCTSTR lpKey, LPCTSTR lpValue, LPSTR lpData )
{
	HKEY key;
	DWORD dwDisp;

	if (RegCreateKeyEx(hKey, lpKey, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &key, &dwDisp) != ERROR_SUCCESS)
		return FALSE;

	if (RegSetValueEx(key, lpValue, 0, REG_SZ, (LPBYTE)lpData, (DWORD)(strlen(lpData) + 1) ) != ERROR_SUCCESS)
		return FALSE;

	RegCloseKey(key);

	return TRUE;
}