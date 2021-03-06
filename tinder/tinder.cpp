// tinder.cpp: 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "extend.h"
#include "游戏功能.h"
#include "钩子管理.h"


#ifdef __cplusplus
#define DLLEXPORT extern "C" _declspec(dllexport)  
#else  
#define DLLEXPORT _declspec(dllexport) 
#endif

using namespace std;

#pragma data_seg("Shared")  
HHOOK hHook = NULL;
BOOL g_MainThreadFlag = TRUE;
#pragma data_seg()  
#pragma comment(linker,"/section:Shared,rws")  
GameInfo g_GameInfo;
string temp_str;
HANDLE g_MainThreadId;



DLLEXPORT BOOL Start(HWND hWnd, DWORD dwThreadId);
DLLEXPORT BOOL Stop();

void 对话框() {
	int i = 0;
	while (g_MainThreadFlag)
	{
		debug_print("读内存测试 当前游戏状态 - %d",to_string(i));
		i++;
		Sleep(10);
	}
	return;
}

// 钩子回调
LRESULT CALLBACK KeyBoardProc(INT code, WPARAM wParam, LPARAM lParam)
{
	if ((lParam &(1 << 31)) == 0) {
		switch (wParam)
		{
		case VK_HOME:
			//g_MainThreadId = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)对话框, NULL, 0, NULL);
			设置坐标Call钩子();
			break;
		}
	}
	return CallNextHookEx(hHook,code, wParam, lParam);
}
BOOL Start(HWND hWnd,DWORD dwMainThreadId)
{
	
	g_GameInfo.hWnd = hWnd;
	g_GameInfo.dwMainThreadId = dwMainThreadId;
	hHook = SetWindowsHookEx(WH_KEYBOARD, (HOOKPROC)KeyBoardProc, g_hModule, dwMainThreadId);
	if (hHook == NULL)
	{
		debug_print("设置钩子失败 ErrorCood - < %d >", GetLastError());
		Stop();
		return TRUE;
	}
	return TRUE;
}

BOOL Stop()
{
	g_MainThreadFlag = FALSE;
	if (g_MainThreadId)
	{
		WaitForSingleObject(g_MainThreadId, 0xFF);
	}
	/*if (g_MainThreadId) {
		WaitForSingleObject(g_MainThreadId, 0xFF);
		CloseHandle(g_MainThreadId);
	}
	BOOL bFlag = TRUE;
	if (hHook != NULL)
	{
		if (UnhookWindowsHookEx(hHook) == FALSE) {
			bFlag = FALSE;
			temp_str = "[LW] 卸载钩子失败 ErrorCood - < " + to_string(GetLastError()) + " >";
			OutputDebugString(temp_str.c_str());
		}
	}
	if (bFlag == TRUE)
	{
		FreeLibraryAndExitThread(g_hModule, 0);
		return TRUE;
	}*/
	return FALSE;
}