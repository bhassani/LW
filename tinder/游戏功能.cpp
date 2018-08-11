#include "stdafx.h"
#include "游戏功能.h"
#include "extend.h"
#include "寻路函数.h"
#include "memory.h"


坐标Call_参数 g_坐标Call_参数;


VOID 坐标Call()
{
	if (取角色状态() == 0) {
		writeInteger(readInteger(人物基址) + 角色状态偏移, createRandom(1, 2));
	}
	DWORD 对象地址 = g_坐标Call_参数.对象地址;
	int x = g_坐标Call_参数.x;
	int y = g_坐标Call_参数.y;
	int z = g_坐标Call_参数.z;
	__asm {
		mov esi, 对象地址 //这里人物指针
		mov edi, dword ptr[esi]
		push z //z_坐标 一般是0
		push y //y_坐标 
		push x //x_坐标 
		mov eax, dword ptr[edi + 0xB4]
		mov ecx, esi
		call eax
	}
}


