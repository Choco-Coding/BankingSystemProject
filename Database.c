#include "BankingSystem.h"

//DATABASE���� ������ �ҷ����� �Լ�
void read_DATABASE(void)
{
	FILE* fp;    //���� ������ ����
	int i, k;
	int r;       //fscanf�Լ��� ��ȯ�� ������ ����

	fp = fopen("DATABASE.txt", "r");  //�б� ���� ���� ����

	if (fp == NULL)  //������ ���� ���� ��� ���� �޽��� ��� �� ���α׷� ����
	{
		printf("������ �߻��߽��ϴ�.");
		Sleep(1000);
		exit(1);
	}

	//DATABASE ���Ϸκ��� �����͸� �о�ͼ� user_data ����ü �迭�� ����
	for (i = 0; i < 50; i++)
	{
		//���¹�ȣ, ��й�ȣ, �̸�, ���� �ܾ�, �ŷ����� ��
		r = fscanf(fp, "%s %d %s %d %d", user_data[i].account, &user_data[i].password, user_data[i].name, &user_data[i].money, &user_data[i].list_n);

		//�ŷ�����
		for (k = 0; k < user_data[i].list_n; k++)
		{
			fscanf(fp, "%d %d %d", &user_data[i].user_list[k].type, &user_data[i].user_list[k].cash, &user_data[i].user_list[k].total);
		}

		//�����͸� ��� �о���� �ݺ��� ����
		if (r == EOF)
		{
			break;
		}
	}

	N = i - 1;   //user_data�� ������ �迭 ��� ÷��

	fclose(fp);  //���� �ݱ�

	return;
}

//����ü �迭�� ����Ǿ� �ִ� �����͸� DATABASE ���Ͽ� �����ϴ� �Լ�
void write_DATABASE(void)
{
	FILE* fp;  //���� ������ ����
	int i, k;

	fp = fopen("DATABASE.txt", "w");  //���� �뵵�� ���� ����

	if (fp == NULL)  //������ ���� ���� ��� ���α׷� ����
	{
		printf("������ �߻��߽��ϴ�.");
		Sleep(1000);
		exit(1);
	}

	//DATABASE ���Ͽ� user_data ����ü�� ������ ����
	for (i = 0; i <= N; i++)
	{
		//���¹�ȣ, ��й�ȣ, �̸�, ���� �ܾ�, �ŷ����� ��
		fprintf(fp, "%s %d %s %d %d ", user_data[i].account, user_data[i].password, user_data[i].name, user_data[i].money, user_data[i].list_n);

		//�ŷ�����
		for (k = 0; k < user_data[i].list_n; k++)
		{
			fprintf(fp, "%d %d %d ", user_data[i].user_list[k].type, user_data[i].user_list[k].cash, user_data[i].user_list[k].total);
		}

		//�� �ٲٱ�
		fputc('\n', fp);
	}

	return;
}