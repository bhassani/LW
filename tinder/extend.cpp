// ��չ����
#include"stdafx.h"
#include "extend.h"
#include <ctime>
#include "memory.h"
#include "��������.h"

VOID debug_print(CONST CHAR* szpFormatName, ...)
{
	va_list argList;
	CHAR buffer[0x500];
	CHAR szBuffer_Game[0x500] = "[LW] ";
	va_start(argList, szpFormatName);
	vsprintf_s(buffer, szpFormatName, argList);
	strcat_s(szBuffer_Game, buffer);
	OutputDebugString(szBuffer_Game);
	va_end(argList);
}

INT createRandom(INT min, INT max)
{
	INT random = 0;
	if (max > min) {
		srand((unsigned)time(NULL));
		random = (rand() % (min - max + 1) + max);
	}
	else {
		srand((unsigned)time(NULL));
		random = (rand() % (max - min + 1) + min);
	}
	return random;
}

INT decrypt(INT Address)
{
	int eax, esi, edx, i;
	eax = readInteger(Address);
	esi = readInteger(���ܻ�ַ);
	edx = eax >> 16;
	edx = readInteger(esi + edx * 4 + 36);
	eax = eax & 65535;
	eax = readInteger(edx + eax * 4 + 8468);
	edx = eax & 65535;
	esi = edx << 16;
	esi = esi | edx;
	i = readInteger(Address + 4);
	esi = esi ^ i;
	return esi;
}

BOOL ��ȡ��ǰ��������(Coordinate &��ǰ��������)
{
	int ��ʱ��ַ;
	��ʱ��ַ = readInteger(readInteger(readInteger(������) + ʱ���ַ) + ����ƫ��);
	if (!��ʱ��ַ) {
		debug_print("��ȡ��ǰ�������� ��ʱ��ַ error!");
		return false;
	}
	��ǰ��������.x = readInteger(��ʱ��ַ + ��ǰ����x);
	��ǰ��������.y = readInteger(��ʱ��ַ + ��ǰ����y);
	return true;
}

BOOL ��ȡ������������(Coordinate &������������)
{
	int ��ʱ��ַ;
	��ʱ��ַ = readInteger(readInteger(readInteger(������) + ʱ���ַ) + ����ƫ��);
	if (!��ʱ��ַ) {
		debug_print("��ȡ������������ ��ʱ��ַ error!");
		return false;
	}
	������������.x = readInteger(��ʱ��ַ + ��������x);
	������������.y = readInteger(��ʱ��ַ + ��������y);
	return true;
}

INT ȡ��Ϸ״̬()
{
	INT ״̬;
	״̬ = readInteger(��Ϸ״̬);
	return ״̬;
}

INT ��ȡ������Ʒ����(const char *��Ʒ����)
{
	�����ṹ _�����ṹ;
	��������(_�����ṹ);
	for (size_t i = 0; i < 279; i++)
	{
		_�����ṹ.��Ʒ��ַ = readInteger(_�����ṹ.��Ʒ�׵�ַ + i * 4);
		if (_�����ṹ.��Ʒ��ַ)
		{
			_�����ṹ.��Ʒ���� = readString(readInteger(_�����ṹ.��Ʒ��ַ + 36), 100);
			if (strcmp(��Ʒ����, _�����ṹ.��Ʒ����.c_str()) == 0)
			{
				return i + 9;
			}
		}
	}
	debug_print("%s δ�ҵ�\n", ��Ʒ����);
	return -1;
}

INT ȡ��ɫ״̬() // 0�޶��� 1�ܶ��� 2�ͷż�����
{
	INT ״̬;
	״̬ = readInteger(readInteger(�����ַ) + ��ɫ״̬ƫ��);
	return ״̬;
}