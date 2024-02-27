#include "BankingSystem.h"

//�ݾ� ���ϱ� �Լ�
void PLUS(struct DATA* ptr, int money)
{
	ptr->money += money;
}

//�ݾ� ���� �Լ�
void MINUS(struct DATA* ptr, int money)
{
	ptr->money -= money;
}

//�Ա� �Լ�
void deposit(int ID)
{
	int money = 0;  //�Ա��� �ݾ�
	CursorView(1);  //Ŀ�� ǥ��

	//ȭ�� ����
	screen();
	gotoxy(23, 5);
	printf("�Ա�");
	gotoxy(10, 9);
	printf("��������������������������������������������������������������");
	gotoxy(10, 10);
	printf("�� �Ա��� �ݾ� ____________��  ��");
	gotoxy(10, 11);
	printf("��������������������������������������������������������������");
	gotoxy(0, 16);
	printf("���� �Է��� �� ENTER�� ��������.");

	gotoxy(24, 10);
	scanf_s("%d", &money);   //�Ա��� �ݾ� �Է�

	PLUS(&user_data[ID], money);  //�Ա� ó��

	//�ŷ� ���� ����
	user_data[ID].list_n++;
	user_data[ID].user_list[user_data[ID].list_n - 1].type = 1;
	user_data[ID].user_list[user_data[ID].list_n - 1].cash = money;
	user_data[ID].user_list[user_data[ID].list_n - 1].total = user_data[ID].money;

	CursorView(0);  //Ŀ�� ǥ��

	//��ü ��� ���
	system("cls");
	screen();
	gotoxy(14, 5);
	printf("�Ա��� �Ϸ�Ǿ����ϴ�.");
	gotoxy(11, 9);
	printf("������������������������������������������������������");
	gotoxy(11, 10);
	printf("��                         ��");
	gotoxy(11, 11);
	printf("��                         ��");
	gotoxy(11, 12);
	printf("������������������������������������������������������");
	gotoxy(13, 10);
	printf("�Ա� : %d��", money);
	gotoxy(13, 11);
	printf("���� �ܾ� : %d��", user_data[ID].money);
	gotoxy(0, 16);
	printf("2�� �� ���� ȭ������ ���ư��ϴ�.");
	Sleep(2000);

	return;
}

//��� �Լ�
void withdraw(int ID)
{
	int money = 0;  //����� �ݾ�
	CursorView(1);  //Ŀ�� ǥ��

retry:
	//ȭ�� ����
	screen();
	gotoxy(23, 5);
	printf("���");
	gotoxy(10, 9);
	printf("��������������������������������������������������������������");
	gotoxy(10, 10);
	printf("�� ����� �ݾ� ____________��  ��");
	gotoxy(10, 11);
	printf("��������������������������������������������������������������");
	gotoxy(0, 16);
	printf("���� �Է��� �� ENTER�� ��������.");

	gotoxy(24, 10);
	scanf_s("%d", &money);   //����� �ݾ� �Է�

	//������ �ܾ��� �������� ������ Ȯ��
	if (money <= user_data[ID].money)
	{
		MINUS(&user_data[ID], money);  //��� ó��

		//�ŷ� ���� ����
		user_data[ID].list_n++;
		user_data[ID].user_list[user_data[ID].list_n - 1].type = 2;
		user_data[ID].user_list[user_data[ID].list_n - 1].cash = money;
		user_data[ID].user_list[user_data[ID].list_n - 1].total = user_data[ID].money;
	}
	else
	{
		system("cls");
		gotoxy(17, 7);
		printf("�ܾ��� �����մϴ�.");
		gotoxy(17, 8);
		printf("������ �ܾ� : %d", user_data[ID].money);
		goto retry;   //�ܾ��� ������ ��� ����� �ݾ� �ٽ� �Է� �ޱ�
	}

	CursorView(0);   //Ŀ�� ��ǥ��

	//��ü ��� ���
	system("cls");
	screen();
	gotoxy(14, 5);
	printf("����� �Ϸ�Ǿ����ϴ�.");
	gotoxy(11, 9);
	printf("������������������������������������������������������");
	gotoxy(11, 10);
	printf("��                         ��");
	gotoxy(11, 11);
	printf("��                         ��");
	gotoxy(11, 12);
	printf("������������������������������������������������������");
	gotoxy(13, 10);
	printf("��� : %d��", money);
	gotoxy(13, 11);
	printf("���� �ܾ� : %d��", user_data[ID].money);
	gotoxy(0, 16);
	printf("2�� �� ���� ȭ������ ���ư��ϴ�.");
	Sleep(2000);

	return;
}

//��ü �Լ�
void transfer(int ID)
{
	int i;
	int money = 0;             //��ü�� �ݾ�
	char recieve_account[10];  //�޴� �� ���¹�ȣ

	CursorView(1);   //Ŀ�� ǥ��

retry:
	//ȭ�� ����
	screen();
	gotoxy(23, 5);
	printf("��ü");
	gotoxy(10, 9);
	printf("��������������������������������������������������������������");
	gotoxy(10, 10);
	printf("���޴� ���� ���¹�ȣ ____-____ ��");
	gotoxy(10, 11);
	printf("����ü�� �ݾ� ____________��   ��");
	gotoxy(10, 12);
	printf("��������������������������������������������������������������");
	gotoxy(0, 16);
	printf("���� �Է��� �� ENTER�� ��������.\n���¹�ȣ �Է� �� -�� �� �Է����ּ���.");

	gotoxy(30, 10);
	scanf_s("%s", recieve_account, 10);   //�޴� �� ���¹�ȣ �Է�
	gotoxy(23, 11);
	scanf_s("%d", &money);                //��ü�� �ݾ� �Է�

	//������ �ܾ��� �������� ������ Ȯ��
	if (money <= user_data[ID].money)
	{
		//���¹�ȣ�� �´� ����� �˻�
		for (i = 0; i <= N; i++)
		{
			if (strcmp(recieve_account, user_data[i].account) == 0 && i != ID)
			{
				MINUS(&user_data[ID], money);  //������ ���� �� ��� ó��
				PLUS(&user_data[i], money);    //�޴� ���� �� �Ա� ó��

				//������ ���� �ŷ����� ����
				user_data[ID].list_n++;
				user_data[ID].user_list[user_data[ID].list_n - 1].type = 2;
				user_data[ID].user_list[user_data[ID].list_n - 1].cash = money;
				user_data[ID].user_list[user_data[ID].list_n - 1].total = user_data[ID].money;

				//�޴� ���� �ŷ����� ����
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
		printf("�ܾ��� �����մϴ�.");
		gotoxy(17, 8);
		printf("������ �ܾ� : %d", user_data[ID].money);
		goto retry;             //��ü ���� �ٽ� �Է� �ޱ�
	}

	//���¹�ȣ�� �˻����� ���� ���
	if (i == (N + 1))
	{
		system("cls");
		gotoxy(11, 6);
		printf("���¹�ȣ�� �ùٸ��� �ʽ��ϴ�.");
		goto retry;             //��ü ���� �ٽ� �Է� �ޱ�
	}

	CursorView(0);    //Ŀ�� ��ǥ��

	//��ü ��� ���
	system("cls");
	screen();
	gotoxy(14, 5);
	printf("��ü�� �Ϸ�Ǿ����ϴ�.");
	gotoxy(11, 9);
	printf("������������������������������������������������������");
	gotoxy(11, 10);
	printf("��                         ��");
	gotoxy(11, 11);
	printf("��                         ��");
	gotoxy(11, 12);
	printf("������������������������������������������������������");
	gotoxy(13, 10);
	printf("��ü�� �ݾ� : %d��", money);
	gotoxy(13, 11);
	printf("���� �ܾ� : %d��", user_data[ID].money);
	gotoxy(0, 16);
	printf("2�� �� ���� ȭ������ ���ư��ϴ�.");
	Sleep(2000);

	return;
}

//�ŷ����� ��� �Լ�
void print_List(ID)
{
	int i;
	char key;  //Ű���� �� ����

	//�ŷ� ���� ���
	printf("�ŷ� ����      �ŷ� �ݾ�           �ܾ�\n");
	printf("-------------------------------------------------\n");
	for (i = 0; i < user_data[ID].list_n; i++)
	{
		if (user_data[ID].user_list[i].type == 1)
		{
			printf("�Ա�           %-10d          %d\n", user_data[ID].user_list[i].cash, user_data[ID].user_list[i].total);
		}
		else
		{
			printf("���           %-10d          %d\n", user_data[ID].user_list[i].cash, user_data[ID].user_list[i].total);
		}
	}
	printf("-------------------------------------------------\n");
	printf("\n���� ȭ������ ���ư����� ENTERŰ�� ��������");

	//ENTER Ű ������ ���� ȭ������ ���ư���
	while (1)
	{
		key = _getch();

		if (key == ENTER)
			break;
	}

	return;
}