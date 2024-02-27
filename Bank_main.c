#include "BankingSystem.h"

int main(void)
{
	int ID;                //사용자 식별 번호(해당 user_data 배열의 첨자)
	int key;               //키보드 입력 값
	int X = 0, Y = 8;      //커서 위치

	read_DATABASE();       //DATABASE 파일로부터 회원 정보 데이터 불러오기
	system("title Banking System");
	CursorView(0);         //마우스 커서 미표시

restart:
	ID = start();          //프로그램 시작 함수로부터 사용자 식별 번호 반환

	if (ID == -1)          //사용자가 프로그램 종료(ID == -1)선택할 경우
	{
		write_DATABASE();  //구조체 배열에 저장되어 있는 데이터를 DATABASE 파일에 저장
		return 0;          //프로그램 종료
	}
	else
	{
	re_main:
		//화면 구성
		screen();
		gotoxy(0, 2);
		printf("%s님 환영합니다.", user_data[ID].name);
		gotoxy(0, 3);
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("┃                                ┃\n");
		printf("┃                                ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		gotoxy(1, 4);
		printf("통장 계좌번호 : %s", user_data[ID].account);
		gotoxy(1, 5);
		printf("통장 잔액 : %d원", user_data[ID].money);
		gotoxy(1, 8);
		printf("거래 내역");
		gotoxy(1, 9);
		printf("입금");
		gotoxy(1, 10);
		printf("출금");
		gotoxy(1, 11);
		printf("이체");
		gotoxy(1, 12);
		printf("미로찾기 게임");
		gotoxy(1, 13);
		printf("로그아웃");
		gotoxy(0, 16);
		printf("메뉴 이동 : 키보드 UP, DOWN 방향키\n메뉴 선택 : 키보드 ENTER키");
		gotoxy(0, 19);
		printf("주의) 로그아웃 후 프로그램 종료까지 눌러야\n      데이터가 저장됩니다.");
		gotoxy(X, Y);
		printf(">");

		//메뉴 조작
		while (1)
		{
			key = _getch();
			switch (key)
			{
			case UP:                 //UP 방향키 누를 경우 위로 메뉴 이동
				if (Y > 8)
				{
					gotoxy(X, Y);
					printf(" ");
					Y--;
					gotoxy(X, Y);
					printf(">");
				}
				break;
			case DOWN:               //DOWN 방향키 누를 경우 아래로 메뉴 이동
				if (Y < 13)
				{
					gotoxy(X, Y);
					printf(" ");
					Y++;
					gotoxy(X, Y);
					printf(">");
				}
				break;
			case ENTER:              //ENTER키 누를 경우 메뉴 선택
				system("cls");
				switch (Y)
				{
				case 8:       //거래 내역 선택
					print_List(ID);
					system("cls");
					goto re_main;
				case 9:       //입금 선택
					deposit(ID);
					system("cls");
					goto re_main;
				case 10:      //출금 선택
					withdraw(ID);
					system("cls");
					goto re_main;
				case 11:      //이체 선택
					transfer(ID);
					system("cls");
					goto re_main;
				case 12:      //포인트 게임 선택
					MazeGame(ID);
					system("cls");
					goto re_main;
				default:      //로그아웃 선택 -> 프로그램 시작 화면으로 이동
					goto restart;
				}
				break;
			}
		}
	}
}