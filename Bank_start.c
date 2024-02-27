#include "BankingSystem.h"

int login(void);  //�α��� �Լ�
void join(void);   //ȸ������ �Լ�

//���α׷� ���� �Լ�
int start(void)
{
	int key;               //Ű���� �Է� ��
	int X = 18, Y = 10;    //Ŀ�� ��ġ ��ǥ

	//ȭ�� ����
	screen();
	gotoxy(17, 5);
	printf("���� ���� �ý���");
	gotoxy(14, 9);
	printf("��������������������������������������������");
	gotoxy(14, 10);
	printf("��    �α���          ��");
	gotoxy(14, 11);
	printf("��    ȸ������        ��");
	gotoxy(14, 12);
	printf("��    ���α׷� ����   ��");
	gotoxy(14, 13);
	printf("��������������������������������������������");
	gotoxy(0, 16);
	printf("�޴� �̵� : Ű���� UP, DOWN ����Ű\n�޴� ���� : Ű���� ENTERŰ");
	gotoxy(X, Y);
	printf(">");

	//�޴� ����
	while (1)
	{
		key = _getch();       //Ű���� �� �Է� �޾� ����
		switch (key)
		{
		case UP:              //UP ����Ű ���� ��� �� �������� �޴� �̵�
			if (Y > 10)
			{
				gotoxy(X, Y);
				printf(" ");
				Y--;
				gotoxy(X, Y);
				printf(">");
			}
			break;
		case DOWN:            //DOWN ����Ű ���� ��� �Ʒ� �������� �޴� �̵�
			if (Y < 12)
			{
				gotoxy(X, Y);
				printf(" ");
				Y++;
				gotoxy(X, Y);
				printf(">");
			}
			break;
		case ENTER:           //ENTER Ű ���� ��� �޴� ����
			system("cls");
			switch (Y)
			{
			case 10:           //�α��� ����
				return login();
			case 11:           //ȸ������ ����
				join();
				return login();
			default:           //���α׷� ���� ����
				return -1;
			}
			break;
		}
	}
}

//�α��� �Լ�
int login(void)
{
	int i;
	char recieve_account[10];      //�Է¹��� ���¹�ȣ
	int password;                  //�Է¹��� ��й�ȣ

	CursorView(1);                 //���콺 Ŀ�� ǥ��

retry:
	//ȭ�� ����
	screen();
	gotoxy(22, 5);
	printf("�α���");
	gotoxy(14, 9);
	printf("��������������������������������������������");
	gotoxy(14, 10);
	printf("�� ���¹�ȣ ____-____ ��");
	gotoxy(14, 11);
	printf("�� ��й�ȣ ______    ��");
	gotoxy(14, 12);
	printf("��������������������������������������������");
	gotoxy(0, 16);
	printf("���� �Է��� �� ENTER�� ��������.\n���¹�ȣ �Է� �� -�� �� �Է����ּ���.");

	gotoxy(25, 10);
	scanf_s("%s", recieve_account, 10);   //���¹�ȣ �Է�
	gotoxy(25, 11);
	scanf_s("%d", &password);             //��й�ȣ �Է�

	//ȸ�� ���� �����Ϳ� ��ġ�ϴ� ���¹�ȣ �� ��й�ȣ�� �ִ��� Ȯ��
	for (i = 0; i <= N; i++)
	{
		if (strcmp(recieve_account, user_data[i].account) == 0)
		{
			if (password == user_data[i].password)
			{
				system("cls");
				CursorView(0);  //���콺 Ŀ�� �����
				return i;       //�α��� ���� -> ���� ȭ������ �̵�
			}
			else
			{
				system("cls");
				gotoxy(12, 7);
				printf("��й�ȣ�� �ùٸ��� �ʽ��ϴ�.");
				goto retry;   //�α��� �ٽ� �ϱ�
			}
		}
	}
	gotoxy(12, 7);
	printf("���¹�ȣ�� �ùٸ��� �ʽ��ϴ�.");
	goto retry;  //�α��� �ٽ� �ϱ�
}

//ȸ������ �Լ�
void join(void)
{
	int i;
	char recieve_account[10];  //�Է� ���� ���¹�ȣ

	CursorView(1);  //���콺 Ŀ�� ǥ��

	//user_data �迭�� ũ�⸦ �ѱ� ��� ���� �޽��� ���
	if (N >= 50)
	{
		printf("ȸ�������� �Ұ����մϴ�.");
		Sleep(1000);
		return;
	}

	N++;   //user_data�� ������ �迭 ��� ÷�� 1 ����

retry:
	//ȭ�� ����
	screen();
	gotoxy(21, 5);
	printf("ȸ������");
	gotoxy(14, 9);
	printf("��������������������������������������������");
	gotoxy(14, 10);
	printf("�� �̸� _____         ��");
	gotoxy(14, 11);
	printf("�� ���¹�ȣ ____-____ ��");
	gotoxy(14, 12);
	printf("�� ��й�ȣ ______    ��");
	gotoxy(14, 13);
	printf("��������������������������������������������");
	gotoxy(0, 16);
	printf("���� �Է��� �� ENTER�� ��������.\n���¹�ȣ �Է� �� -�� �� �Է����ּ���.");

	gotoxy(21, 10);
	scanf_s("%s", user_data[N].name, 20);   //�̸� �Է�
	gotoxy(25, 11);
	scanf_s("%s", recieve_account, 10);     //���¹�ȣ �Է�
	gotoxy(25, 12);
	scanf_s("%d", &user_data[N].password);  //��й�ȣ �Է�

	//�ߺ��Ǵ� ���¹�ȣ�� �ִ��� �˻�
	for (i = 0; i < N; i++)
	{
		if (strcmp(recieve_account, user_data[i].account) == 0)
		{
			system("cls");
			gotoxy(12, 7);
			printf("����� �Ұ����� ���¹�ȣ�Դϴ�.");
			goto retry;  //ȸ������ �ٽ��ϱ�
		}
	}
	
	//ȸ������ ����
	//user_data�� ���¹�ȣ ����
	for (i = 0; i < strlen(recieve_account); i++)
	{
		user_data[N].account[i] = recieve_account[i];
	}
	user_data[N].account[i] = '\0';  //�������� NULL���� ����

	user_data[N].money = 0;  //�ݾ��� 0���� �ʱ�ȭ
	user_data[N].list_n = 0; //�ŷ� ���� ���� 0���� �ʱ�ȭ

	system("cls");
	CursorView(0);   //���콺 Ŀ�� ��ǥ��

	return;
}