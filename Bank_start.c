#include "BankingSystem.h"

int login(void);  //로그인 함수
void join(void);   //회원가입 함수

//프로그램 시작 함수
int start(void)
{
	int key;               //키보드 입력 값
	int X = 18, Y = 10;    //커서 위치 좌표

	//화면 구성
	screen();
	gotoxy(17, 5);
	printf("은행 관리 시스템");
	gotoxy(14, 9);
	printf("┏━━━━━━━━━━━━━━━━━━━━┓");
	gotoxy(14, 10);
	printf("┃    로그인          ┃");
	gotoxy(14, 11);
	printf("┃    회원가입        ┃");
	gotoxy(14, 12);
	printf("┃    프로그램 종료   ┃");
	gotoxy(14, 13);
	printf("┗━━━━━━━━━━━━━━━━━━━━┛");
	gotoxy(0, 16);
	printf("메뉴 이동 : 키보드 UP, DOWN 방향키\n메뉴 선택 : 키보드 ENTER키");
	gotoxy(X, Y);
	printf(">");

	//메뉴 조작
	while (1)
	{
		key = _getch();       //키보드 값 입력 받아 저장
		switch (key)
		{
		case UP:              //UP 방향키 누를 경우 위 방향으로 메뉴 이동
			if (Y > 10)
			{
				gotoxy(X, Y);
				printf(" ");
				Y--;
				gotoxy(X, Y);
				printf(">");
			}
			break;
		case DOWN:            //DOWN 방향키 누를 경우 아래 방향으로 메뉴 이동
			if (Y < 12)
			{
				gotoxy(X, Y);
				printf(" ");
				Y++;
				gotoxy(X, Y);
				printf(">");
			}
			break;
		case ENTER:           //ENTER 키 누를 경우 메뉴 선택
			system("cls");
			switch (Y)
			{
			case 10:           //로그인 선택
				return login();
			case 11:           //회원가입 선택
				join();
				return login();
			default:           //프로그램 종료 선택
				return -1;
			}
			break;
		}
	}
}

//로그인 함수
int login(void)
{
	int i;
	char recieve_account[10];      //입력받을 계좌번호
	int password;                  //입력받을 비밀번호

	CursorView(1);                 //마우스 커서 표시

retry:
	//화면 구성
	screen();
	gotoxy(22, 5);
	printf("로그인");
	gotoxy(14, 9);
	printf("┏━━━━━━━━━━━━━━━━━━━━┓");
	gotoxy(14, 10);
	printf("┃ 계좌번호 ____-____ ┃");
	gotoxy(14, 11);
	printf("┃ 비밀번호 ______    ┃");
	gotoxy(14, 12);
	printf("┗━━━━━━━━━━━━━━━━━━━━┛");
	gotoxy(0, 16);
	printf("값을 입력한 후 ENTER를 누르세요.\n계좌번호 입력 시 -을 꼭 입력해주세요.");

	gotoxy(25, 10);
	scanf_s("%s", recieve_account, 10);   //계좌번호 입력
	gotoxy(25, 11);
	scanf_s("%d", &password);             //비밀번호 입력

	//회원 정보 데이터와 일치하는 계좌번호 및 비밀번호가 있는지 확인
	for (i = 0; i <= N; i++)
	{
		if (strcmp(recieve_account, user_data[i].account) == 0)
		{
			if (password == user_data[i].password)
			{
				system("cls");
				CursorView(0);  //마우스 커서 숨기기
				return i;       //로그인 성공 -> 메인 화면으로 이동
			}
			else
			{
				system("cls");
				gotoxy(12, 7);
				printf("비밀번호가 올바르지 않습니다.");
				goto retry;   //로그인 다시 하기
			}
		}
	}
	gotoxy(12, 7);
	printf("계좌번호가 올바르지 않습니다.");
	goto retry;  //로그인 다시 하기
}

//회원가입 함수
void join(void)
{
	int i;
	char recieve_account[10];  //입력 받을 계좌번호

	CursorView(1);  //마우스 커서 표시

	//user_data 배열의 크기를 넘길 경우 오류 메시지 출력
	if (N >= 50)
	{
		printf("회원가입이 불가능합니다.");
		Sleep(1000);
		return;
	}

	N++;   //user_data의 마지막 배열 요소 첨자 1 증가

retry:
	//화면 구성
	screen();
	gotoxy(21, 5);
	printf("회원가입");
	gotoxy(14, 9);
	printf("┏━━━━━━━━━━━━━━━━━━━━┓");
	gotoxy(14, 10);
	printf("┃ 이름 _____         ┃");
	gotoxy(14, 11);
	printf("┃ 계좌번호 ____-____ ┃");
	gotoxy(14, 12);
	printf("┃ 비밀번호 ______    ┃");
	gotoxy(14, 13);
	printf("┗━━━━━━━━━━━━━━━━━━━━┛");
	gotoxy(0, 16);
	printf("값을 입력한 후 ENTER를 누르세요.\n계좌번호 입력 시 -을 꼭 입력해주세요.");

	gotoxy(21, 10);
	scanf_s("%s", user_data[N].name, 20);   //이름 입력
	gotoxy(25, 11);
	scanf_s("%s", recieve_account, 10);     //계좌번호 입력
	gotoxy(25, 12);
	scanf_s("%d", &user_data[N].password);  //비밀번호 입력

	//중복되는 계좌번호가 있는지 검색
	for (i = 0; i < N; i++)
	{
		if (strcmp(recieve_account, user_data[i].account) == 0)
		{
			system("cls");
			gotoxy(12, 7);
			printf("사용이 불가능한 계좌번호입니다.");
			goto retry;  //회원가입 다시하기
		}
	}
	
	//회원가입 성공
	//user_data에 계좌번호 저장
	for (i = 0; i < strlen(recieve_account); i++)
	{
		user_data[N].account[i] = recieve_account[i];
	}
	user_data[N].account[i] = '\0';  //마지막에 NULL문자 대입

	user_data[N].money = 0;  //금액을 0으로 초기화
	user_data[N].list_n = 0; //거래 내역 수를 0으로 초기화

	system("cls");
	CursorView(0);   //마우스 커서 미표시

	return;
}