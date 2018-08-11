// Êó¼üÄ£Äâ
#include "stdafx.h"
#include "Êó¼üº¯Êý.h"
#include "extend.h"

POINT getMouseCoord()
{
	POINT Coord;
	if (GetCursorPos(&Coord)) {
		debug_print("getMouseCoord Erro!\n");
	}
	return Coord;
}

BOOL setMouseCoord(INT x, INT y)
{
	BOOL result;
	result = SetCursorPos(x, y);
	if (result == FALSE) {
		debug_print("setMouseCoord Erro!\n");
	}
	return result;
}

VOID mouseClick(INT s)
{
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(s + createRandom(0, 10));
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	Sleep(50 + createRandom(0, 10));
}

VOID mouseDoubleClick(INT s)
{
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(s + createRandom(0, 10));
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	Sleep(50 + createRandom(0, 10));
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(s + createRandom(0, 10));
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	Sleep(50 + createRandom(0, 10));
}

BOOL getKeyStatus(INT keyCode)
{
	if (GetKeyState(keyCode) < 0) {
		return TRUE;
	}
	return FALSE;
}

INT getSCan(INT keyCode)
{
	INT sCan = MapVirtualKey(keyCode, 0);
	if (
		keyCode == VK_LEFT ||
		keyCode == VK_RIGHT ||
		keyCode == VK_DOWN ||
		keyCode == VK_UP
		)
	{
		sCan += 0x80;
	}
	return sCan;
}

VOID keyDown(INT keyCode)
{
	if (getKeyStatus(keyCode) == FALSE) {
		keybd_event(keyCode, getSCan(keyCode), 0, 0);
	}
}

VOID keyUp(INT keyCode)
{
	if (getKeyStatus(keyCode) == TRUE) {
		keybd_event(keyCode, getSCan(keyCode), KEYEVENTF_KEYUP, 0);
	}
}

VOID doKeyPress(INT keyCode, INT s)
{
	keyDown(keyCode);
	Sleep(s + createRandom(0, 10));
	keyUp(keyCode);
	Sleep(50 + createRandom(0, 10));
}
