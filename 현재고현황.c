#include<stdio.h>
#include<time.h>
#include "local.h"
#include "struct_jaego.h"
#include "MiniProject_ERP_1struct.h"

#pragma warning(disable:4996)


int option1, option2, option3;

int main() {

	Create_File();
	Init_SampleData();

	while (1)
	{
		system("cls");


		printf("\t������\n");
		printf("1.�� ��� ��Ȳ 2.��� �̵� 3. ���� �����Ȳ(��������) = �� ��� ��Ȳ\n");
		printf("======================================\n");

		scanf("%d", &option1);

		system("cls");

		switch (option1)
		{

		case 1:
			printf("\t�� ��� ��Ȳ\n");
			printf("======================================\n");
			jaego_print();
			break;

		case 2:
			printf("\t��� ����ϱ� \n");
			printf("======================================\n");

			int a= chulgo_jaego_print();
			if (a >0)
			{
				printf("======================================\n");
				printf("�����Ϸ�������\n");
				printf("======================================\n");
				system("pause");

			}
			else
			{
				printf("======================================\n");
				printf("�����Ϸ�������\n");
				printf("======================================\n");
				insertOrderData();
			}

			break;

		case 3:
			choijong_jaego_print();
			jaego_print();
			break;

		default:
			break;
		}
	}	
}