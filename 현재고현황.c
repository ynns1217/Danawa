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


		printf("\t재고관리\n");
		printf("1.현 재고 현황 2.재고 이동 3. 최종 재고현황(자재사용후) = 현 재고 현황\n");
		printf("======================================\n");

		scanf("%d", &option1);

		system("cls");

		switch (option1)
		{

		case 1:
			printf("\t현 재고 현황\n");
			printf("======================================\n");
			jaego_print();
			break;

		case 2:
			printf("\t재고 사용하기 \n");
			printf("======================================\n");

			int a= chulgo_jaego_print();
			if (a >0)
			{
				printf("======================================\n");
				printf("생산하러가자이\n");
				printf("======================================\n");
				system("pause");

			}
			else
			{
				printf("======================================\n");
				printf("발주하러가자이\n");
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