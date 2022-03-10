#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include "local.h"
#include "struct_jaego.h"
#include "MiniProject_ERP_struct_warehousing.h"

#pragma warning(disable:4996)



//최종 재고 수량 출력해서 조회
int jaego_print()
{
	result* _result;
	result* find;
	int result_count;

	time_t timer;
	struct tm* t;
	timer = time(NULL);
	t = localtime(&timer);

	int today_date = 0;
	today_date = ((t->tm_year + 1900) * 10000) + ((t->tm_mon + 1) * 100) + (t->tm_mday);	// 오늘 날짜( 20220304 꼴 )


	char Parameter_Insert[1000] = { NULL };
	char temp_int[20] = { 0 };

	

	if (initalizing("Jaego") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	for (int select_List = 1; select_List < 7; select_List++)
	{


		char select_num_List[100] = "num_jaego=";
		itoa(select_List, temp_int, 10);
		strcat(select_num_List, temp_int);

		if (_select(select_num_List, "num_jaego, name_item, num_item, date, chogi_item, ibgo_item, chulgo_item, jaego_item", &select_result_str) == -1) {
			printf("%s\n", err_msg);
			_getch();

			file_column_free();
			return -1;
		}

		if ((result_count = recv_result(&_result, select_result_str)) == -1) {
			printf("%s\n", err_msg);

			file_column_free();
			return -1;
		}

		//num_jaego
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
		int chogi_data = *(_result->next->next->next->next->_int_data);
		itoa(chogi_data, temp_int, 10);
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
		int jaego_data = chogi_data + num_InWarehouse - chulgo_data;
		itoa(jaego_data, temp_int, 10);
		strcat(Parameter_Insert, temp_int);

		char update_rest_num[100] = "jaego_item=";

		itoa(jaego_data, temp_int, 10);		// 받아온 정보가 int형이므로 문자열로 형변환수행
		strcat(update_rest_num, temp_int);


		// 입고한 다음 입고 수량 을 업데이트한다
		if (_update(select_num_List, update_rest_num) == -1)
		{
			printf("%s\n", err_msg);

			file_column_free();
			return -1;
		}

		result_free(_result, result_count);

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

	time_t timer;
	struct tm* t;
	timer = time(NULL);
	t = localtime(&timer);

	char Parameter_Insert[1000] = { NULL };				
	char temp_int[20] = { 0 };							
	char Select_item_num[20] = { 0 };
	char select_num_IbgoList[100] = "num_item=";

	
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
	scanf("%s", Select_item_num);	

	strcat(select_num_IbgoList, "\'");
	strcat(select_num_IbgoList, Select_item_num);
	strcat(select_num_IbgoList, "\'");

	if (_select(select_num_IbgoList, "name_item, num_item, LOT_number, date, num_in", &select_result_str) == -1) {
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
	itoa(*(_result->next->next->next->_int_data), temp_int, 10);							// 받아온 정보가 int형이므로 문자열로 형변환수행
	strcat(Parameter_Insert, temp_int);						// 변환한 문자열을 Parameter_Insert에 붙임
	strcat(Parameter_Insert, ", ");							// 끝났음을 의미하는 띄어쓰기



	// 입고수량
	int num_InWarehouse = *(_result->next->next->next->next->_int_data);
	itoa(num_InWarehouse, temp_int, 10);					
	strcat(Parameter_Insert, temp_int);																									


	printf("%s\n", Parameter_Insert);
	system("pause");

	file_column_free();

							
	result_free(_result, result_count);	



	if (initalizing("Jaego") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	char update_num[100] = "ibgo_item=";

	itoa(num_InWarehouse, temp_int, 10);		// 받아온 정보가 int형이므로 문자열로 형변환수행
	strcat(update_num, temp_int);

	// 입고한 다음 입고 재고 수량 을 업데이트한다
	if (_update(select_num_IbgoList, update_num) == -1)
	{
		printf("%s\n", err_msg);
		file_column_free();
		return -1;
	}

	file_column_free();

	jaego_print();
}


void chulgo_jaego_print()
{
	result* _result;
	result* find;
	int result_count;

	time_t timer;
	struct tm* t;
	timer = time(NULL);
	t = localtime(&timer);

	int today_date = 0;
	today_date = ((t->tm_year + 1900) * 10000) + ((t->tm_mon + 1) * 100) + (t->tm_mday);	// 오늘 날짜( 20220304 꼴 )

	char Parameter_Insert[1000] = { NULL };
	char temp_int[20] = { 0 };
	char Select_item_num[20] = { 0 };
	char select_num_chulgoList[100] = "num_item=";


	// 입고리스트 출력 및 정보 받아오기
	if (initalizing("Jaego") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}


	print_data();
	printf("\n");

	for (int select_List = 1; select_List < 7; select_List++)
	{


		char select_num_chulgoList[100] = "num_jaego=";
		itoa(select_List, temp_int, 10);
		strcat(select_num_chulgoList, temp_int);

		strcat(select_num_chulgoList, "\'");
		strcat(select_num_chulgoList, Select_item_num);
		strcat(select_num_chulgoList, "\'");

		if (_select(select_num_chulgoList, "num_jaego, name_item, num_item, date, chogi_item, ibgo_item, chulgo_item, jaego_item", &select_result_str) == -1) {
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


		printf("%s를 출고합니다\n", *(_result->next->_string_data));

		// 출고재고수량 입력
		int chulgo_data = 0;
		printf("출고수량을 입력하세요 : ");
		scanf("%d", &chulgo_data);


		//num_jaego
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


		//출고재고수량
		itoa(chulgo_data, temp_int, 10);
		strcat(Parameter_Insert, temp_int);
		strcat(Parameter_Insert, ", ");

		// 총 재고수량
		int jaego_data = gicho_data + num_InWarehouse - chulgo_data;
		itoa(jaego_data, temp_int, 10);
		strcat(Parameter_Insert, temp_int);


	

		char update_num[100] = "chulgo_item=";

		itoa(chulgo_data, temp_int, 10);		// 받아온 정보가 int형이므로 문자열로 형변환수행
		strcat(update_num, temp_int);

		// 입고한 다음 입고 재고 수량 을 업데이트한다
		if (_update(select_num_chulgoList, update_num) == -1)
		{
			printf("%s\n", err_msg);
			file_column_free();
			return -1;
		}

	}
	file_column_free();

	jaego_print();
}