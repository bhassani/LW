#pragma once

VOID debug_print(CONST CHAR * szpFormatName, ...);

INT createRandom(INT min, INT max);

INT decrypt(INT Address);

INT 获取背包物品索引(const char * 物品名称);

INT 取角色状态();

BOOL 获取当前房间坐标(Coordinate & 当前房间坐标);

BOOL 获取领主房间坐标(Coordinate & 领主房间坐标);

INT 取游戏状态();


