#include "BankingSystem.h"

//DATABASE에서 데이터 불러오는 함수
void read_DATABASE(void)
{
	FILE* fp;    //파일 포인터 선언
	int i, k;
	int r;       //fscanf함수의 반환값 저장할 변수

	fp = fopen("DATABASE.txt", "r");  //읽기 모드로 파일 열기

	if (fp == NULL)  //파일을 열지 못할 경우 오류 메시지 출력 후 프로그램 종료
	{
		printf("오류가 발생했습니다.");
		Sleep(1000);
		exit(1);
	}

	//DATABASE 파일로부터 데이터를 읽어와서 user_data 구조체 배열에 저장
	for (i = 0; i < 50; i++)
	{
		//계좌번호, 비밀번호, 이름, 통장 잔액, 거래내역 수
		r = fscanf(fp, "%s %d %s %d %d", user_data[i].account, &user_data[i].password, user_data[i].name, &user_data[i].money, &user_data[i].list_n);

		//거래내역
		for (k = 0; k < user_data[i].list_n; k++)
		{
			fscanf(fp, "%d %d %d", &user_data[i].user_list[k].type, &user_data[i].user_list[k].cash, &user_data[i].user_list[k].total);
		}

		//데이터를 모두 읽어오면 반복문 종료
		if (r == EOF)
		{
			break;
		}
	}

	N = i - 1;   //user_data의 마지막 배열 요소 첨자

	fclose(fp);  //파일 닫기

	return;
}

//구도체 배열에 저장되어 있는 데이터를 DATABASE 파일에 저장하는 함수
void write_DATABASE(void)
{
	FILE* fp;  //파일 포인터 선언
	int i, k;

	fp = fopen("DATABASE.txt", "w");  //쓰기 용도로 파일 열기

	if (fp == NULL)  //파일을 열지 못할 경우 프로그램 종료
	{
		printf("오류가 발생했습니다.");
		Sleep(1000);
		exit(1);
	}

	//DATABASE 파일에 user_data 구조체의 데이터 저장
	for (i = 0; i <= N; i++)
	{
		//계좌번호, 비밀번호, 이름, 통장 잔액, 거래내역 수
		fprintf(fp, "%s %d %s %d %d ", user_data[i].account, user_data[i].password, user_data[i].name, user_data[i].money, user_data[i].list_n);

		//거래내역
		for (k = 0; k < user_data[i].list_n; k++)
		{
			fprintf(fp, "%d %d %d ", user_data[i].user_list[k].type, user_data[i].user_list[k].cash, user_data[i].user_list[k].total);
		}

		//줄 바꾸기
		fputc('\n', fp);
	}

	return;
}