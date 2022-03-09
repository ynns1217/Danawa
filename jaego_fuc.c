#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include "local.h"
#include "struct_jaego.h"
#include "MiniProject_ERP_struct_warehousing.h"

#pragma warning(disable:4996)

result* _result;
result* find;
int result_count;


//최종 재고 수량 출력해서 조회
int jaego_print()
{
	result* _result;
	result* find;
	int result_count;
	char Select_WH[10];

	time_t timer;
	struct tm* t;
	timer = time(NULL);
	t = localtime(&timer);

	int today_date = 0;
	today_date = ((t->tm_year + 1900) * 10000) + ((t->tm_mon + 1) * 100) + (t->tm_mday);	// 오늘 날짜( 20220304 꼴 )


	char Parameter_Insert[1000] = { NULL };
	char temp_int[20] = { 0 };
	char Select_BuyingList_num[20] = { 0 };

	
	if (initalizing("Jaego") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}


	for (int Select_BuyingList_num = 1; Select_BuyingList_num < 7; Select_BuyingList_num++)
	{

		char select_num_BuyList[100] = "num_jaego=";
		itoa(Select_BuyingList_num, temp_int, 10);
		strcat(select_num_BuyList, temp_int);


		if (_select(select_num_BuyList, "num_jaego, name_item, num_item, date, chogi_item, ibgo_item, chulgo_item, jaego_item", &select_result_str) == -1) {
			printf("%s\n", err_msg);

			file_column_free();
			return -1;
		}

		if ((result_count = recv_result(&_result, select_result_str)) == -1) {
			printf("%s\n", err_msg);

			file_column_free();
			return -1;
		}


		itoa(*(_result->_int_data), temp_int, 10);
		strcat(Parameter_Insert, temp_int);
		strcat(Parameter_Insert, ", ");

		// name_item
		strcat(Parameter_Insert, "\'");
		strcat(Parameter_Insert, *(_result->next->_string_data));
		strcat(Parameter_Insert, "\', ");


		//num_item
		strcat(Parameter_Insert, "\'");
		strcat(Parameter_Insert, *(_result->next->next->_string_data));
		strcat(Parameter_Insert, "\', ");



		//date
		itoa(today_date, temp_int, 10);							// 받아온 정보가 int형이므로 문자열로 형변환수행
		strcat(Parameter_Insert, temp_int);						// 변환한 문자열을 Parameter_Insert에 붙임
		strcat(Parameter_Insert, ", ");							// 끝났음을 의미하는 띄어쓰기



		// 초기재고수량
		int gicho_data = *(_result->next->next->next->next->_int_data);
		itoa(gicho_data, temp_int, 10);
		strcat(Parameter_Insert, temp_int);
		strcat(Parameter_Insert, ", ");

		// 입고재고수량
		int num_InWarehouse = *(_result->next->next->next->next->next->_int_data);
		itoa(num_InWarehouse, temp_int, 10);
		strcat(Parameter_Insert, temp_int);
		strcat(Parameter_Insert, ", ");

		// 출고재고수량
		int chulgo_data = *(_result->next->next->next->next->next->next->_int_data);
		itoa(chulgo_data, temp_int, 10);
		strcat(Parameter_Insert, temp_int);
		strcat(Parameter_Insert, ", ");

		// 총 재고수량
		int jaego_data = gicho_data + num_InWarehouse - chulgo_data;
		itoa(jaego_data, temp_int, 10);
		strcat(Parameter_Insert, temp_int);

		file_column_free();
		result_free(_result, result_count);


		if (initalizing("Jaego") == -1) {
			printf("%s\n", err_msg);

			file_column_free();
			return -1;
		}

		char update_rest_num[100] = "jaego_item=";

		itoa(jaego_data, temp_int, 10);		// 받아온 정보가 int형이므로 문자열로 형변환수행
		strcat(update_rest_num, temp_int);


		// 입고한 다음 입고 수량 을 업데이트한다
		if (_update(select_num_BuyList, update_rest_num) == -1)
		{
			printf("%s\n", err_msg);

			file_column_free();
			return -1;
		}
	}

	print_data();
	system("pause");
	file_column_free();
}

//입고 정보를 불러와서 입고재고에 업데이트
void ibgo_jaego_print1()
{

result* _result;
	result* find;
	int result_count;
	char Select_WH[10];

	time_t timer;
	struct tm* t;
	timer = time(NULL);
	t = localtime(&timer);

	int today_date = 0;
	today_date = ((t->tm_year + 1900) * 10000) + ((t->tm_mon + 1) * 100) + (t->tm_mday);	// 오늘 날짜( 20220304 꼴 )

	char Parameter_Insert[1000] = { NULL };				
	char temp_int[20] = { 0 };							
	char Select_BuyingList_num[20] = { 0 };				
	

	
	// 입고리스트 출력 및 정보 받아오기
	if (initalizing("In_WareHouse") == -1)	
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}


	print_data();				
	printf("\n");

	printf("\n입고 정보를 불러올 품목 번호 를 선택해주세요 : ");			
	scanf("%s", Select_BuyingList_num);				

	char select_num_BuyList[100] = "num_item=";			
	strcat(select_num_BuyList, Select_BuyingList_num);		

	
	if (_select(select_num_BuyList, "name_item, num_item, LOT_number, date, num_in", &select_result_str) == -1) {
		printf("%s\n", err_msg);
		system("pause");
		file_column_free();
		return -1;
	}

	if ((result_count = recv_result(&_result, select_result_str)) == -1) {		
		printf("%s\n", err_msg);											
		system("pause");
		file_column_free();
		return -1;
	}
		
	

	// name_item
	strcat(Parameter_Insert, "\'");							
	strcat(Parameter_Insert, *(_result->_string_data));		
	strcat(Parameter_Insert, "\', ");						


	//num_item
	strcat(Parameter_Insert, "\'");
	strcat(Parameter_Insert, *(_result->next->_string_data));
	strcat(Parameter_Insert, "\', ");


	//LOT_number
	strcat(Parameter_Insert, "\'");												
	strcat(Parameter_Insert, *(_result->next->next->_string_data));		
	strcat(Parameter_Insert, "\', ");										


	//date
	itoa(today_date, temp_int, 10);							// 받아온 정보가 int형이므로 문자열로 형변환수행
	strcat(Parameter_Insert, temp_int);						// 변환한 문자열을 Parameter_Insert에 붙임
	strcat(Parameter_Insert, ", ");							// 끝났음을 의미하는 띄어쓰기




	// 입고수량
	int num_InWarehouse = *(_result->next->next->next->next->_int_data);
	itoa(num_InWarehouse, temp_int, 10);					
	strcat(Parameter_Insert, temp_int);																									


	printf("%s\n", Parameter_Insert);
	system("pause");
	printf("\n\n");
	file_column_free();							
	result_free(_result, result_count);		
	

	if (initalizing("Jaego") == -1) {
		printf("%s\n", err_msg); 

		file_column_free();
		return -1;
	}

	char update_num[100] = "ibgo_item=";

	itoa(num_InWarehouse, temp_int, 10);		// 받아온 정보가 int형이므로 문자열로 형변환수행
	strcat(update_num, temp_int);


	// 입고한 다음 입고 재고 수량 을 업데이트한다
	if (_update(select_num_BuyList, update_num) == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	char update_time[100] = "date=";

	itoa(today_date, temp_int, 10);		// 받아온 정보가 int형이므로 문자열로 형변환수행
	strcat(update_time, temp_int);


	// 입고한 다음 입고 재고 수량 을 업데이트한다
	if (_update(select_num_BuyList, update_time) == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	jaego_print();
}

//출고 정보를 불러와서 출고재고에 업데이트
void chulgo_jaego_print()
{

}


