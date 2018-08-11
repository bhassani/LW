#include "stdafx.h"
#include "钩子管理.h"
#include "extend.h"
#include "memory.h"



DWORD 坐标call跳转地址;
DWORD 坐标call跳回地址;
BOOL 坐标Call开关 = FALSE;
DWORD 坐标Call_ECX;
int 对象地址 = g_坐标Call_参数.对象地址;
int x = 100;
int y = 100;
int z = 0;
VOID __declspec(naked) 坐标Call处理函数()
{
	
	if (坐标Call开关 == TRUE) {
		__asm{
			pushad
			pushfd
			mov eax, 对象地址
			mov eax,dword ptr[eax]
			cmp eax,ecx
			je newcode
			newcode:
				mov eax,x
				mov dword ptr[ebp + 0x8], eax
				mov eax, y
				mov dword ptr[ebp + 0xc], eax
				mov eax, z
				mov dword ptr[ebp + 0x10], eax
			popfd
			popad
		}
	}
	__asm {
		push ebx
		push esi
		push edi
		mov esi, ecx
		jmp 坐标call跳回地址
	}
}

VOID 设置坐标Call钩子()
{
	坐标call跳转地址 = readInteger(readInteger(readInteger(人物基址) + 0) + 0xb4) + 0x6;
	坐标call跳回地址 = 坐标call跳转地址 + 0x5;
	DWORD addr;
	VirtualProtect(LPVOID(坐标call跳转地址), 5, PAGE_EXECUTE_READWRITE, &addr);
	BYTE Jmp[5] = { 0xE9,0,0,0,0 };
	*((size_t*)(Jmp + 1)) = (DWORD)坐标Call处理函数 - 坐标call跳转地址 - 5;
	memcpy((LPVOID)坐标call跳转地址, Jmp, 5);
	VirtualProtect(LPVOID(坐标call跳转地址), 5, addr, 0);
}