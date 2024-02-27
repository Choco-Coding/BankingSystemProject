#include "BankingSystem.h"

int main(void)
{
	int ID;                //����� �ĺ� ��ȣ(�ش� user_data �迭�� ÷��)
	int key;               //Ű���� �Է� ��
	int X = 0, Y = 8;      //Ŀ�� ��ġ

	read_DATABASE();       //DATABASE ���Ϸκ��� ȸ�� ���� ������ �ҷ�����
	system("title Banking System");
	CursorView(0);         //���콺 Ŀ�� ��ǥ��

restart:
	ID = start();          //���α׷� ���� �Լ��κ��� ����� �ĺ� ��ȣ ��ȯ

	if (ID == -1)          //����ڰ� ���α׷� ����(ID == -1)������ ���
	{
		write_DATABASE();  //����ü �迭�� ����Ǿ� �ִ� �����͸� DATABASE ���Ͽ� ����
		return 0;          //���α׷� ����
	}
	else
	{
	re_main:
		//ȭ�� ����
		screen();
		gotoxy(0, 2);
		printf("%s�� ȯ���մϴ�.", user_data[ID].name);
		gotoxy(0, 3);
		printf("��������������������������������������������������������������������\n");
		printf("��                                ��\n");
		printf("��                                ��\n");
		printf("��������������������������������������������������������������������\n");
		gotoxy(1, 4);
		printf("���� ���¹�ȣ : %s", user_data[ID].account);
		gotoxy(1, 5);
		printf("���� �ܾ� : %d��", user_data[ID].money);
		gotoxy(1, 8);
		printf("�ŷ� ����");
		gotoxy(1, 9);
		printf("�Ա�");
		gotoxy(1, 10);
		printf("���");
		gotoxy(1, 11);
		printf("��ü");
		gotoxy(1, 12);
		printf("�̷�ã�� ����");
		gotoxy(1, 13);
		printf("�α׾ƿ�");
		gotoxy(0, 16);
		printf("�޴� �̵� : Ű���� UP, DOWN ����Ű\n�޴� ���� : Ű���� ENTERŰ");
		gotoxy(0, 19);
		printf("����) �α׾ƿ� �� ���α׷� ������� ������\n      �����Ͱ� ����˴ϴ�.");
		gotoxy(X, Y);
		printf(">");

		//�޴� ����
		while (1)
		{
			key = _getch();
			switch (key)
			{
			case UP:                 //UP ����Ű ���� ��� ���� �޴� �̵�
				if (Y > 8)
				{
					gotoxy(X, Y);
					printf(" ");
					Y--;
					gotoxy(X, Y);
					printf(">");
				}
				break;
			case DOWN:               //DOWN ����Ű ���� ��� �Ʒ��� �޴� �̵�
				if (Y < 13)
				{
					gotoxy(X, Y);
					printf(" ");
					Y++;
					gotoxy(X, Y);
					printf(">");
				}
				break;
			case ENTER:              //ENTERŰ ���� ��� �޴� ����
				system("cls");
				switch (Y)
				{
				case 8:       //�ŷ� ���� ����
					print_List(ID);
					system("cls");
					goto re_main;
				case 9:       //�Ա� ����
					deposit(ID);
					system("cls");
					goto re_main;
				case 10:      //��� ����
					withdraw(ID);
					system("cls");
					goto re_main;
				case 11:      //��ü ����
					transfer(ID);
					system("cls");
					goto re_main;
				case 12:      //����Ʈ ���� ����
					MazeGame(ID);
					system("cls");
					goto re_main;
				default:      //�α׾ƿ� ���� -> ���α׷� ���� ȭ������ �̵�
					goto restart;
				}
				break;
			}
		}
	}
}