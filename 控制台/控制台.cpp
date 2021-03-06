// 控制台.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

HMODULE tinder = NULL;

typedef BOOL(WINAPI *Start)(HWND, DWORD);
typedef BOOL(WINAPI *Stop)();

Start _Start = NULL;
Stop _Stop = NULL;

HWND hWnd;
DWORD dwMainThreadId;
DWORD dwProcessId;

int UpdataToken() {
	HANDLE hToken;
	LUID DebugNameValue;
	TOKEN_PRIVILEGES Privileges;
	DWORD dwRet;
	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)) {
		MessageBox(NULL, TEXT("打开进程访问令牌失败！"), TEXT("错误"), MB_OK);
		return 1;
	}
	if (!LookupPrivilegeValue(NULL, "SeDebugPrivilege", &DebugNameValue)) {
		MessageBox(NULL, TEXT("查看系统权限特权值失败！"), TEXT("错误"), MB_OK);
		return 2;
	}
	Privileges.PrivilegeCount = 1;
	Privileges.Privileges[0].Luid = DebugNameValue;
	Privileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	if (!AdjustTokenPrivileges(hToken, FALSE, &Privileges, sizeof(Privileges), NULL, &dwRet)) {
		MessageBox(NULL, TEXT("启用权限失败！"), TEXT("错误"), MB_OK);
		return 3;
	}
	return 0;
}

BOOL 删除自身()
{
	char FileName[MAX_PATH];
	memset(FileName, 0, MAX_PATH);
	//获取文件路径
	GetModuleFileName(NULL, FileName, MAX_PATH);
	char *NewFileName;
	NewFileName = new char[MAX_PATH];
	memset(NewFileName, 0, MAX_PATH);
	//设置文件属性
	SetFileAttributes(NewFileName, FILE_ATTRIBUTE_NORMAL);
	//尝试直接删除
	if (DeleteFile(FileName))//能直接删掉最好
	{
		delete[] NewFileName;
		return false;
	}
	//以下API一样，不再啰嗦
	wsprintf(NewFileName, "%C:\\\0", FileName[0]);
	CreateDirectory(NewFileName, NULL);
	SetFileAttributes(NewFileName, FILE_ATTRIBUTE_HIDDEN);
	wsprintf(NewFileName, "%C:\\Windows 服务主进程\0", FileName[0], GetTickCount());
	SetFileAttributes(NewFileName, FILE_ATTRIBUTE_NORMAL);
	DeleteFile(NewFileName);
	if (!MoveFileEx(FileName, NewFileName, MOVEFILE_REPLACE_EXISTING))
	{
		delete[] NewFileName;
		return false;//动不了就放弃
	}
	MoveFileEx(NewFileName, NULL, MOVEFILE_DELAY_UNTIL_REBOOT);
	SetFileAttributes(NewFileName, FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM);
	delete[] NewFileName;
	return true;
}

BOOL CtrlHandler(DWORD fdwCtrlType);

int main()
{
	删除自身();
	if (UpdataToken() == 0) {
		
		tinder = LoadLibrary("tinder.dll"); //加载dll文件 
		_Start = (Start)GetProcAddress(tinder, "Start");
		_Stop = (Stop)GetProcAddress(tinder, "Stop");
		if (_Start == NULL)
		{
			printf("导出 Start 函数失败 ErrorCode - < %d >\n",GetLastError());

		}
		if (_Stop == NULL)
		{
			printf("导出 Stop 函数失败 ErrorCode - < %d >\n", GetLastError());

		}
		hWnd = FindWindow(NULL,"地下城与勇士");
		if (hWnd == NULL)
		{
			printf("找不到窗口 ErrorCode - < %d >\n", GetLastError());
		}
		dwMainThreadId = GetWindowThreadProcessId(hWnd,&dwProcessId);
		if (_Start(hWnd, dwMainThreadId)) {
			printf("启动成功\n");
		}
		else {
			printf("启动失败\n");
		}
	}
	if (SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, TRUE))
	{
		printf("Control Handler is installed\n");
		printf(" Ctrl+C, Ctrl+Break, logging off or closing console NOW intercepted.\n");
		printf(" ... into message loop.\n");
		while (1) {}
	}
	else
		printf("Control handler setting failed....\n");
	return 0;
	
}



BOOL CtrlHandler(DWORD fdwCtrlType)
{
	switch (fdwCtrlType)
	{
	case CTRL_C_EVENT:
		printf("Ctrl-C event\n\n");
		_Stop();
		return(TRUE);

	case CTRL_CLOSE_EVENT:
		printf("Ctrl-Close event\n\n");
		_Stop();
		return(TRUE);

	case CTRL_BREAK_EVENT:
		printf("Ctrl-Break event\n\n");
		return FALSE; // pass thru, let the system to handle the event.

	case CTRL_LOGOFF_EVENT:
		printf("Ctrl-Logoff event\n\n");
		return FALSE; // pass thru, let the system to handle the event.

	case CTRL_SHUTDOWN_EVENT:
		printf("Ctrl-Shutdown event\n\n");
		return FALSE; // pass thru, let the system to handle the event.

	default:
		return FALSE;
	}
}