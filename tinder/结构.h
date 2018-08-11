#pragma once
struct GameInfo
{
	HWND hWnd;
	DWORD dwMainThreadId;
};

struct Coordinate {
	int x, y, z;
};

struct RoomInfo {
	Coordinate coordinate;
	Coordinate parent_coordinate;
	int weight;
	int numbering;
	bool up;
	bool bottom;
	bool left;
	bool right;
};

struct MapInfo {
	int width;
	int height;
	std::vector<int> channel;
	Coordinate start_coordinate;
	Coordinate end_coordinate;
};

struct 地图结构
{
	int 地图地址;
	int 首地址;
	int 尾地址;
	int 对象数量;
	int 对象地址;
	int 对象阵营;
	int 对象类型;
	int 对象血量;
};

struct 背包结构
{
	int 背包地址;
	int 背包首地址;
	int 物品首地址;
	int 物品地址;
	int 物品属性;
	std::string 物品名称;
};

struct 任务结构
{
	int 任务地址;
	int 首地址;
	int 尾地址;
	int 任务数量;
};

struct 坐标Call_参数
{
	DWORD 对象地址;
	int x;
	int y;
	int z = 0;
};