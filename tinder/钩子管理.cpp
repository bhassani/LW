#include "stdafx.h"
#include "���ӹ���.h"
#include "extend.h"
#include "memory.h"



DWORD ����call��ת��ַ;
DWORD ����call���ص�ַ;
BOOL ����Call���� = FALSE;
DWORD ����Call_ECX;
int �����ַ = g_����Call_����.�����ַ;
int x = 100;
int y = 100;
int z = 0;
VOID __declspec(naked) ����Call������()
{
	
	if (����Call���� == TRUE) {
		__asm{
			pushad
			pushfd
			mov eax, �����ַ
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
		jmp ����call���ص�ַ
	}
}

VOID ��������Call����()
{
	����call��ת��ַ = readInteger(readInteger(readInteger(�����ַ) + 0) + 0xb4) + 0x6;
	����call���ص�ַ = ����call��ת��ַ + 0x5;
	DWORD addr;
	VirtualProtect(LPVOID(����call��ת��ַ), 5, PAGE_EXECUTE_READWRITE, &addr);
	BYTE Jmp[5] = { 0xE9,0,0,0,0 };
	*((size_t*)(Jmp + 1)) = (DWORD)����Call������ - ����call��ת��ַ - 5;
	memcpy((LPVOID)����call��ת��ַ, Jmp, 5);
	VirtualProtect(LPVOID(����call��ת��ַ), 5, addr, 0);
}