#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>

#define UP 72       //키보드 UP 방향키
#define DOWN 80     //키보드 DOWN 방향키
#define LEFT 75     //키보드 왼쪽 방향키
#define RIGHT 77    //키보드 오른쪽 방향키
#define ENTER 13    //키보드 ENTER 키

//거래 내역 구조체
struct LIST {
	int type;  //거래 유형(1:입금, 2:출금)
	int cash;  //거래 금액
	int total; //통장 잔액
};

//고객 개인 정보 구조체
struct DATA {
	char account[10];             //계좌번호
	int password;                 //비밀번호
	char name[20];                //이름
	int money;                    //통장 잔액
	int list_n;                   //거래 내역 수
	struct LIST user_list[50];    //거래 내역
} user_data[50];

int N;  //user_data의 마지막 배열 요소 첨자

void read_DATABASE(void);      //DATABASE에서 데이터 불러오는 함수
void write_DATABASE(void);     //구도체 배열에 저장되어 있는 데이터를 DATABASE 파일에 저장하는 함수

void gotoxy(int x, int y);     //콘솔 위의 커서 위치를 바꾸는 함수
void screen(void);             //화면 기본 틀 출력 함수
void CursorView(char show);    //커서 표시/미표시 함수
int GetKey(void);                  //키를 받아들이는 함수

int start(void);            //프로그램 시작 함수

void PLUS(struct DATA* ptr, int money);   //금액 더하기 함수
void MINUS(struct DATA* ptr, int money);  //금액 빼기 함수

void deposit(int ID);     //입금 함수
void withdraw(int ID);    //출금 함수
void transfer(int ID);    //이체 함수
void print_List(int ID);  //거래내역 출력 함수

void MazeGame(int ID);    //미로 게임 함수