#include "BankingSystem.h"

//커서 이동 함수
void gotoxy(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//은행 화면 기본 틀 출력 함수
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

//커서 표시 / 미표시 함수
void CursorView(char show) 
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

//키를 받아들이는 함수
int GetKey(void) 
{
	if (_kbhit() != 0) //키 입력이 유효할 경우
	{
		return _getch(); //입력한 키 반환
	}

	return 0; //그렇지 않을 경우 0반환
}