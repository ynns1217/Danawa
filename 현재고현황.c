#include<stdio.h>
#include<time.h>
#include "local.h"
#include "struct_jaego.h"
#include "MiniProject_ERP_struct_warehousing.h"

#pragma warning(disable:4996)


int option1, option2, option3;

int main() {

	Create_File();
	Init_SampleData();

	while (1)
	{
		system("cls");


		printf("\t재고관리\n");
		printf("1.현 재고 현황 2.재고 이동 \n");
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
			//사용할 재고 입력 
			// (모든 조건 검색해서 하나라도 있으면 생산하러가고 갯수 하나씩 줄이기)
			//재고 0 이면 발주로 보내고 입고 받은 재고번호 받아서 update


			 //jogun();
			
			//if (jaego_item <= 0)
			//{
			//	printf("발주하러 가자이\n");
			//	printf("\n");

			//ibgo_jaego_print();

			//	printf("\n");
			//	printf("\n");
			//	break;
			//}

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
			//else
			//{
			//	printf("\n");
			//	printf("생산하러 가자이\n");
			//	printf("\n");

			break;

		default:
			break;
		}
	}	
}