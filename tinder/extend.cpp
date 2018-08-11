// 扩展函数
#include"stdafx.h"
#include "extend.h"
#include <ctime>
#include "memory.h"
#include "遍历数据.h"

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
	esi = readInteger(解密基址);
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

BOOL 获取当前房间坐标(Coordinate &当前房间坐标)
{
	int 临时地址;
	临时地址 = readInteger(readInteger(readInteger(房间编号) + 时间基址) + 门型偏移);
	if (!临时地址) {
		debug_print("获取当前房间坐标 临时地址 error!");
		return false;
	}
	当前房间坐标.x = readInteger(临时地址 + 当前房间x);
	当前房间坐标.y = readInteger(临时地址 + 当前房间y);
	return true;
}

BOOL 获取领主房间坐标(Coordinate &领主房间坐标)
{
	int 临时地址;
	临时地址 = readInteger(readInteger(readInteger(房间编号) + 时间基址) + 门型偏移);
	if (!临时地址) {
		debug_print("获取领主房间坐标 临时地址 error!");
		return false;
	}
	领主房间坐标.x = readInteger(临时地址 + 领主房间x);
	领主房间坐标.y = readInteger(临时地址 + 领主房间y);
	return true;
}

INT 取游戏状态()
{
	INT 状态;
	状态 = readInteger(游戏状态);
	return 状态;
}

INT 获取背包物品索引(const char *物品名称)
{
	背包结构 _背包结构;
	遍历背包(_背包结构);
	for (size_t i = 0; i < 279; i++)
	{
		_背包结构.物品地址 = readInteger(_背包结构.物品首地址 + i * 4);
		if (_背包结构.物品地址)
		{
			_背包结构.物品名称 = readString(readInteger(_背包结构.物品地址 + 36), 100);
			if (strcmp(物品名称, _背包结构.物品名称.c_str()) == 0)
			{
				return i + 9;
			}
		}
	}
	debug_print("%s 未找到\n", 物品名称);
	return -1;
}

INT 取角色状态() // 0无动作 1跑动中 2释放技能中
{
	INT 状态;
	状态 = readInteger(readInteger(人物基址) + 角色状态偏移);
	return 状态;
}