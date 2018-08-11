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

struct ��ͼ�ṹ
{
	int ��ͼ��ַ;
	int �׵�ַ;
	int β��ַ;
	int ��������;
	int �����ַ;
	int ������Ӫ;
	int ��������;
	int ����Ѫ��;
};

struct �����ṹ
{
	int ������ַ;
	int �����׵�ַ;
	int ��Ʒ�׵�ַ;
	int ��Ʒ��ַ;
	int ��Ʒ����;
	std::string ��Ʒ����;
};

struct ����ṹ
{
	int �����ַ;
	int �׵�ַ;
	int β��ַ;
	int ��������;
};

struct ����Call_����
{
	DWORD �����ַ;
	int x;
	int y;
	int z = 0;
};