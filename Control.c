#include "BankingSystem.h"

//Ŀ�� �̵� �Լ�
void gotoxy(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//���� ȭ�� �⺻ Ʋ ��� �Լ�
void screen(void)
{
	int i;
	gotoxy(0, 0);
	for (i = 1; i <= 50; i++)
		printf("=");
	gotoxy(0, 15);
	for (i = 1; i <= 50; i++)
		printf("=");
	gotoxy(0, 18);
	for (i = 1; i <= 50; i++)
		printf("=");
}

//Ŀ�� ǥ�� / ��ǥ�� �Լ�
void CursorView(char show) 
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

//Ű�� �޾Ƶ��̴� �Լ�
int GetKey(void) 
{
	if (_kbhit() != 0) //Ű �Է��� ��ȿ�� ���
	{
		return _getch(); //�Է��� Ű ��ȯ
	}

	return 0; //�׷��� ���� ��� 0��ȯ
}