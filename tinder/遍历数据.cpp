#include "stdafx.h"
#include "遍历数据.h"
#include "memory.h"

BOOL 遍历地图(地图结构 &_地图结构)
{
	_地图结构.地图地址 = readInteger(readInteger(人物基址) + 地图偏移);
	if (!_地图结构.地图地址) {
		printf("遍历地图 地图地址 error!");
		return false;
	}
	_地图结构.首地址 = readInteger(_地图结构.地图地址 + 地图首地址);
	_地图结构.尾地址 = readInteger(_地图结构.地图地址 + 地图尾地址);
	_地图结构.对象数量 = (_地图结构.尾地址 - _地图结构.首地址) / 4;
	return true;
}

BOOL 遍历背包(背包结构 &_背包结构)
{
	_背包结构.背包地址 = readInteger(背包基址);
	if (!_背包结构.背包地址) {
		printf("遍历背包 背包地址 error!");
		return false;
	}
	_背包结构.背包首地址 = readInteger(_背包结构.背包地址 + 背包偏移);
	_背包结构.物品首地址 = _背包结构.背包首地址 + 36;;
	return true;
}

BOOL 遍历所有任务(任务结构 &_任务结构)
{
	_任务结构.任务地址 = readInteger(任务基址);
	if (!_任务结构.任务地址) {
		printf("遍历所有任务 任务地址 error!");
		return false;
	}
	_任务结构.首地址 = readInteger(_任务结构.任务地址 + 104);
	_任务结构.尾地址 = readInteger(_任务结构.任务地址 + 108);
	_任务结构.任务数量 = (_任务结构.尾地址 - _任务结构.首地址) / 4;
	return true;
}

BOOL 遍历已接任务(任务结构 &_任务结构)
{
	_任务结构.任务地址 = readInteger(任务基址);
	if (!_任务结构.任务地址) {
		printf("遍历所有任务 任务地址 error!");
		return false;
	}
	_任务结构.首地址 = readInteger(_任务结构.任务地址 + 8);
	_任务结构.尾地址 = readInteger(_任务结构.任务地址 + 12);
	_任务结构.任务数量 = (_任务结构.尾地址 - _任务结构.首地址) / 12;
	return true;
}