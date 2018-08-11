#pragma once
// 获取鼠标坐标
POINT getMouseCoord();
// 设置鼠标坐标
BOOL setMouseCoord(INT x, INT y);
// 鼠标单击
VOID mouseClick(INT s = 50);
// 鼠标双击
VOID mouseDoubleClick(INT s = 50);
// true 按下 false 抬起
BOOL getKeyStatus(INT keyCode);
// 获取按键扫描码
INT getSCan(INT keyCode);
// 键按下
VOID keyDown(INT keyCode);
// 键抬起
VOID keyUp(INT keyCode);
// 按键
VOID doKeyPress(INT keyCode, INT s = 50);