#include "stdafx.h"
#include "��Ϸ����.h"
#include "extend.h"
#include "Ѱ·����.h"
#include "memory.h"


����Call_���� g_����Call_����;


VOID ����Call()
{
	if (ȡ��ɫ״̬() == 0) {
		writeInteger(readInteger(�����ַ) + ��ɫ״̬ƫ��, createRandom(1, 2));
	}
	DWORD �����ַ = g_����Call_����.�����ַ;
	int x = g_����Call_����.x;
	int y = g_����Call_����.y;
	int z = g_����Call_����.z;
	__asm {
		mov esi, �����ַ //��������ָ��
		mov edi, dword ptr[esi]
		push z //z_���� һ����0
		push y //y_���� 
		push x //x_���� 
		mov eax, dword ptr[edi + 0xB4]
		mov ecx, esi
		call eax
	}
}


