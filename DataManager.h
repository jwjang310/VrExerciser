#pragma once

class CDataManager
{
public:
	CDataManager(void);
	~CDataManager(void);

public:
	BOOL	ReadString(HKEY hKey, LPCTSTR lpKey, LPCTSTR lpValue, LPBYTE lpRet, DWORD nSize);
	BOOL	WriteString(HKEY hKey, LPCTSTR lpKey, LPCTSTR lpValue, LPSTR lpData);
};
