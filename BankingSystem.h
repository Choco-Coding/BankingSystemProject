#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>

#define UP 72       //Ű���� UP ����Ű
#define DOWN 80     //Ű���� DOWN ����Ű
#define LEFT 75     //Ű���� ���� ����Ű
#define RIGHT 77    //Ű���� ������ ����Ű
#define ENTER 13    //Ű���� ENTER Ű

//�ŷ� ���� ����ü
struct LIST {
	int type;  //�ŷ� ����(1:�Ա�, 2:���)
	int cash;  //�ŷ� �ݾ�
	int total; //���� �ܾ�
};

//�� ���� ���� ����ü
struct DATA {
	char account[10];             //���¹�ȣ
	int password;                 //��й�ȣ
	char name[20];                //�̸�
	int money;                    //���� �ܾ�
	int list_n;                   //�ŷ� ���� ��
	struct LIST user_list[50];    //�ŷ� ����
} user_data[50];

int N;  //user_data�� ������ �迭 ��� ÷��

void read_DATABASE(void);      //DATABASE���� ������ �ҷ����� �Լ�
void write_DATABASE(void);     //����ü �迭�� ����Ǿ� �ִ� �����͸� DATABASE ���Ͽ� �����ϴ� �Լ�

void gotoxy(int x, int y);     //�ܼ� ���� Ŀ�� ��ġ�� �ٲٴ� �Լ�
void screen(void);             //ȭ�� �⺻ Ʋ ��� �Լ�
void CursorView(char show);    //Ŀ�� ǥ��/��ǥ�� �Լ�
int GetKey(void);                  //Ű�� �޾Ƶ��̴� �Լ�

int start(void);            //���α׷� ���� �Լ�

void PLUS(struct DATA* ptr, int money);   //�ݾ� ���ϱ� �Լ�
void MINUS(struct DATA* ptr, int money);  //�ݾ� ���� �Լ�

void deposit(int ID);     //�Ա� �Լ�
void withdraw(int ID);    //��� �Լ�
void transfer(int ID);    //��ü �Լ�
void print_List(int ID);  //�ŷ����� ��� �Լ�

void MazeGame(int ID);    //�̷� ���� �Լ�