#pragma once
// ��ȡ�������
POINT getMouseCoord();
// �����������
BOOL setMouseCoord(INT x, INT y);
// ��굥��
VOID mouseClick(INT s = 50);
// ���˫��
VOID mouseDoubleClick(INT s = 50);
// true ���� false ̧��
BOOL getKeyStatus(INT keyCode);
// ��ȡ����ɨ����
INT getSCan(INT keyCode);
// ������
VOID keyDown(INT keyCode);
// ��̧��
VOID keyUp(INT keyCode);
// ����
VOID doKeyPress(INT keyCode, INT s = 50);