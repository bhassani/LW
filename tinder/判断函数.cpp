#include "stdafx.h"
#include "�жϺ���.h"
#include "extend.h"
#include "memory.h"

BOOL �Ƿ���()
{
	if (decrypt(readInteger(readInteger(�����ַ) + ��ͼƫ��) + ����ƫ��) == 0) {
		return true;
	}
	else {
		return false;
	}
}

BOOL �Ƿ���������()
{
	Coordinate ��ǰ��������;
	Coordinate ������������;
	��ȡ��ǰ��������(��ǰ��������);
	��ȡ������������(������������);
	if (��ǰ��������.x == ������������.x && ��ǰ��������.y == ������������.y) {
		return true;
	}
	else {
		return false;
	}
}

