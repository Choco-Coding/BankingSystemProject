#include "BankingSystem.h"

//금액 더하기 함수
void PLUS(struct DATA* ptr, int money)
{
	ptr->money += money;
}

//금액 빼기 함수
void MINUS(struct DATA* ptr, int money)
{
	ptr->money -= money;
}

//입금 함수
void deposit(int ID)
{
	int money = 0;  //입금할 금액
	CursorView(1);  //커서 표시

	//화면 구성
	screen();
	gotoxy(23, 5);
	printf("입금");
	gotoxy(10, 9);
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	gotoxy(10, 10);
	printf("┃ 입금할 금액 ____________원  ┃");
	gotoxy(10, 11);
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	gotoxy(0, 16);
	printf("값을 입력한 후 ENTER를 누르세요.");

	gotoxy(24, 10);
	scanf_s("%d", &money);   //입금할 금액 입력

	PLUS(&user_data[ID], money);  //입금 처리

	//거래 내역 저장
	user_data[ID].list_n++;
	user_data[ID].user_list[user_data[ID].list_n - 1].type = 1;
	user_data[ID].user_list[user_data[ID].list_n - 1].cash = money;
	user_data[ID].user_list[user_data[ID].list_n - 1].total = user_data[ID].money;

	CursorView(0);  //커서 표시

	//이체 결과 출력
	system("cls");
	screen();
	gotoxy(14, 5);
	printf("입금이 완료되었습니다.");
	gotoxy(11, 9);
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	gotoxy(11, 10);
	printf("┃                         ┃");
	gotoxy(11, 11);
	printf("┃                         ┃");
	gotoxy(11, 12);
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	gotoxy(13, 10);
	printf("입금 : %d원", money);
	gotoxy(13, 11);
	printf("통장 잔액 : %d원", user_data[ID].money);
	gotoxy(0, 16);
	printf("2초 후 메인 화면으로 돌아갑니다.");
	Sleep(2000);

	return;
}

//출금 함수
void withdraw(int ID)
{
	int money = 0;  //출금할 금액
	CursorView(1);  //커서 표시

retry:
	//화면 구성
	screen();
	gotoxy(23, 5);
	printf("출금");
	gotoxy(10, 9);
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	gotoxy(10, 10);
	printf("┃ 출금할 금액 ____________원  ┃");
	gotoxy(10, 11);
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	gotoxy(0, 16);
	printf("값을 입력한 후 ENTER를 누르세요.");

	gotoxy(24, 10);
	scanf_s("%d", &money);   //출금할 금액 입력

	//통장의 잔액이 부족하지 않은지 확인
	if (money <= user_data[ID].money)
	{
		MINUS(&user_data[ID], money);  //출금 처리

		//거래 내역 저장
		user_data[ID].list_n++;
		user_data[ID].user_list[user_data[ID].list_n - 1].type = 2;
		user_data[ID].user_list[user_data[ID].list_n - 1].cash = money;
		user_data[ID].user_list[user_data[ID].list_n - 1].total = user_data[ID].money;
	}
	else
	{
		system("cls");
		gotoxy(17, 7);
		printf("잔액이 부족합니다.");
		gotoxy(17, 8);
		printf("현재의 잔액 : %d", user_data[ID].money);
		goto retry;   //잔액이 부족한 경우 출금할 금액 다시 입력 받기
	}

	CursorView(0);   //커서 미표시

	//이체 결과 출력
	system("cls");
	screen();
	gotoxy(14, 5);
	printf("출금이 완료되었습니다.");
	gotoxy(11, 9);
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	gotoxy(11, 10);
	printf("┃                         ┃");
	gotoxy(11, 11);
	printf("┃                         ┃");
	gotoxy(11, 12);
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	gotoxy(13, 10);
	printf("출금 : %d원", money);
	gotoxy(13, 11);
	printf("통장 잔액 : %d원", user_data[ID].money);
	gotoxy(0, 16);
	printf("2초 후 메인 화면으로 돌아갑니다.");
	Sleep(2000);

	return;
}

//이체 함수
void transfer(int ID)
{
	int i;
	int money = 0;             //이체할 금액
	char recieve_account[10];  //받는 분 계좌번호

	CursorView(1);   //커서 표시

retry:
	//화면 구성
	screen();
	gotoxy(23, 5);
	printf("이체");
	gotoxy(10, 9);
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	gotoxy(10, 10);
	printf("┃받는 분의 계좌번호 ____-____ ┃");
	gotoxy(10, 11);
	printf("┃이체할 금액 ____________원   ┃");
	gotoxy(10, 12);
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	gotoxy(0, 16);
	printf("값을 입력한 후 ENTER를 누르세요.\n계좌번호 입력 시 -을 꼭 입력해주세요.");

	gotoxy(30, 10);
	scanf_s("%s", recieve_account, 10);   //받는 분 계좌번호 입력
	gotoxy(23, 11);
	scanf_s("%d", &money);                //이체할 금액 입력

	//통장의 잔액이 부족하지 않은지 확인
	if (money <= user_data[ID].money)
	{
		//계좌번호에 맞는 사용자 검색
		for (i = 0; i <= N; i++)
		{
			if (strcmp(recieve_account, user_data[i].account) == 0 && i != ID)
			{
				MINUS(&user_data[ID], money);  //보내는 분의 돈 출금 처리
				PLUS(&user_data[i], money);    //받는 분의 돈 입금 처리

				//보내는 분의 거래내역 저장
				user_data[ID].list_n++;
				user_data[ID].user_list[user_data[ID].list_n - 1].type = 2;
				user_data[ID].user_list[user_data[ID].list_n - 1].cash = money;
				user_data[ID].user_list[user_data[ID].list_n - 1].total = user_data[ID].money;

				//받는 분의 거래내역 저장
				user_data[i].list_n++;
				user_data[i].user_list[user_data[i].list_n - 1].type = 1;
				user_data[i].user_list[user_data[i].list_n - 1].cash = money;
				user_data[i].user_list[user_data[i].list_n - 1].total = user_data[i].money;

				break;
			}
		}
	}
	else
	{
		system("cls");
		gotoxy(17, 7);
		printf("잔액이 부족합니다.");
		gotoxy(17, 8);
		printf("현재의 잔액 : %d", user_data[ID].money);
		goto retry;             //이체 정보 다시 입력 받기
	}

	//계좌번호가 검색되지 않을 경우
	if (i == (N + 1))
	{
		system("cls");
		gotoxy(11, 6);
		printf("계좌번호가 올바르지 않습니다.");
		goto retry;             //이체 정보 다시 입력 받기
	}

	CursorView(0);    //커서 미표시

	//이체 결과 출력
	system("cls");
	screen();
	gotoxy(14, 5);
	printf("이체가 완료되었습니다.");
	gotoxy(11, 9);
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	gotoxy(11, 10);
	printf("┃                         ┃");
	gotoxy(11, 11);
	printf("┃                         ┃");
	gotoxy(11, 12);
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	gotoxy(13, 10);
	printf("이체한 금액 : %d원", money);
	gotoxy(13, 11);
	printf("통장 잔액 : %d원", user_data[ID].money);
	gotoxy(0, 16);
	printf("2초 후 메인 화면으로 돌아갑니다.");
	Sleep(2000);

	return;
}

//거래내역 출력 함수
void print_List(ID)
{
	int i;
	char key;  //키보드 값 저장

	//거래 내역 출력
	printf("거래 종류      거래 금액           잔액\n");
	printf("-------------------------------------------------\n");
	for (i = 0; i < user_data[ID].list_n; i++)
	{
		if (user_data[ID].user_list[i].type == 1)
		{
			printf("입금           %-10d          %d\n", user_data[ID].user_list[i].cash, user_data[ID].user_list[i].total);
		}
		else
		{
			printf("출금           %-10d          %d\n", user_data[ID].user_list[i].cash, user_data[ID].user_list[i].total);
		}
	}
	printf("-------------------------------------------------\n");
	printf("\n메인 화면으로 돌아가려면 ENTER키를 누르세요");

	//ENTER 키 누르면 메인 화면으로 돌아가기
	while (1)
	{
		key = _getch();

		if (key == ENTER)
			break;
	}

	return;
}