#include "local.h"
#pragma warning(disable:4996)

int main() {

	char* values = "NULL, 800, '키보드', NULL , 4 ,0,0,0";
	char* values1 = "NULL, 500, '마우스', NULL , 10 ,0,0,0";
	char* set = "name_item = '키보드'";
	//char* conditional=getchar();
	char* select_column = "name_item, bill, date, num_item ";

	result* _result;
	result* find;
	int result_count;

	int option1, option2, option3;

	//사업장 재고 테이블 (재고등록 + 조회 + 재고 이동)
	if (_create("Stock_In_Factory", "name_factory VARCHAR(20) num_factory INT name_item VARCHAR(20) name_responsible VARCHAR(20) num_responsible INT bill INT date INT num_item INT")==-1)
	{
		printf("%s\n", err_msg);
		
		return -1;
	}

	//사업장의 창고 재고 테이블 (재고등록 + 조회 + 재고 이동)
	if (_create("Stock_In_Warehouse", "name_factory VARCHAR(20) num_factory INT name_warehouse VARCHAR(20) num_warehouse INT name_item VARCHAR(20) name_responsible VARCHAR(20) num_responsible INT bill INT date INT num_item INT") == -1)
	{
		printf("%s\n", err_msg);

		return -1;
	}

	if (initalizing("C:\\Users\\user\\Source\\Repos\\Danawa\\Stock_In_Factory") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	//테이블에 데이터 입력하는 함수//
	if (_insert(values) == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
	if (_insert(values1) == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	while (1)
	{
		system("cls");
		printf("\t재고관리\n");
		printf("1.재고조회 2.재고등록 3.재고이동\n");
		printf("======================================\n");
		scanf("%d", &option1);
		system("cls");

/// ///////////////////////////////////////////////////////////////////
/// ///////////////////////////////////////////////////////////////////

		switch (option1)
		{

		case 1:
			printf("\t재고조회\n");
			printf("1.사업장 2.창고 \n");
			printf("======================================\n");
			scanf("%d", &option2);

/// ///////////////////////////////////////////////////////////////////
/// ///////////////////////////////////////////////////////////////////
/// 
			switch (option2)
			{
			case 1:
				printf("\t사업장\n");
				printf("======================================\n");
				printf("1.전체 2.검색 \n");
				printf("======================================\n");
				scanf("%d", &option3);

/// ///////////////////////////////////////////////////////////////////
/// ///////////////////////////////////////////////////////////////////
/// 
				if (option3 == 1)
				{
					print_data();
					printf("\n");
					system("pause");

				}
				else if (option3 == 2)
				{
					print_data();
					system("pause");

					printf("검색할 품명을 입력하시오\n");

					

					//조건에 맞는 레코드를 전부 찾아 해당 레코드의 원하는 컬럼의 값만 추출하는 함수//				
					//if(조건문, 추출할 컬럼 리스트, 결과 문자열이 저장될 공간//

					if (initalizing("C:\\Users\\user\\Source\\Repos\\Danawa\\Stock_In_Factory") == -1) {
						printf("%s\n", err_msg);

						file_column_free();
						return -1;
					}

					if (_select(conditional, select_column, &select_result_str) == -1)
					{
						printf("%s\n", err_msg);
						file_column_free();
						return -1;
					}

					else
					{
						printf("%s\n\n", select_result_str);
					}

					//_select함수에서 저장된 문자열(select_result_str)을 result_column 구조체에 해당 타입에 맞춰 배열 형태로 정리하여 저장

					if ((result_count = recv_result(&_result, select_result_str)) == -1)
					{
						printf("%s\n", err_msg);

						file_column_free();
						return -1;
					}

					result_print(_result, result_count);
					printf("\n\n");



					//result 연결리스트 중 원하는 컬럼을 찾는 함수

					if ((find = find_result(_result, "FLdf")) == -1)
					{
						printf("%s\n", err_msg);

						file_column_free();
						result_free(_result, result_count);
						return -1;
					}

					printf("     %s\n", find->name);
					printf("=============\n");

					for (int i = 0; i < result_count; i++)
					{
						switch (find->type)
						{
						case INT:
							if (int_is_null(find->_int_data[i]))
								printf("     (null)\n");
							else
								printf("     %d\n", find->_int_data[i]);
							break;

						case FLOAT:
							if (float_is_null(find->_float_data[i]))
								printf("     (null)\n");
							else
								printf("     %.5f\n", find->_float_data[i]);
							break;

						case DOUBLE:
							if (double_is_null(find->_double_data[i]))
								printf("     (null)\n");
							else
								printf("     %.12lf\n", find->_double_data[i]);
							break;

						case CHAR:
							if (char_is_null(find->_char_data[i]))
								printf("     (null)\n");
							else
								printf("     %c\n", find->_char_data[i]);
							break;

						case VARCHAR:
							if (string_is_null(find->_string_data[i]))
								printf("     (null)\n");
							else
								printf("     %s\n", find->_string_data[i]);
							break;
						}
					}

					print_data();
					file_column_free();
					result_free(_result, result_count);
				}
				else
					break;
				break;

			case 2:
				printf("\t창고\n");
				printf("======================================\n");

				if (initalizing("C:\\Users\\PKNU\\source\\repos\\Ynns1217\\Danawa\\Stock_In_Warehouse") == -1)
				{
					printf("%s\n", err_msg);

					file_column_free();
					return -1;
				}
				print_data();
				printf("\n");
				system("pause");
				break;

			default:
				break;
			}

			break;
		

		case 2:
			printf("\t재고조회\n");
			printf("1.사업장 2.창고 \n");
			printf("======================================\n");
			scanf("%d", &option2);

			break;
		
		case 3:
			printf("\t재고이동\n");
			printf("1.사업장 2.창고 \n");
			printf("======================================\n");
			scanf("%d", &option2);

			break;

		default:
			break;
		}

	}

	file_column_free();


	//			//테이블에 데이터 입력하는 함수//
	//if (_insert(values) == -1) {
	//	printf("%s\n", err_msg);

	//	file_column_free();
	//	return -1;
	//}


				//테이블에 데이터 삭제하는 함수//
	/*if (_delete(conditional) == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}*/


				//테이블에 데이터 수정하는 함수//
	/*if (_update(conditional, set) == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}*/




				//조건에 맞는 레코드를 전부 찾아 해당 레코드의 원하는 컬럼의 값만 추출하는 함수//				
				//if(조건문, 추출할 컬럼 리스트, 결과 문자열이 저장될 공간//

	/*if (_select(conditional, select_column, &select_result_str) == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
	else {
		printf("%s\n\n", select_result_str);
	}


				//_select함수에서 저장된 문자열(select_result_str)을 result_column 구조체에 해당 타입에 맞춰 배열 형태로 정리하여 저장

	if ((result_count = recv_result(&_result, select_result_str)) == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
	result_print(_result, result_count);
	printf("\n\n");*/



				//result 연결리스트 중 원하는 컬럼을 찾는 함수

	/*if ((find = find_result(_result, "FLdf")) == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		result_free(_result, result_count);
		return -1;
	}*/
	/*printf("     %s\n", find->name);
	printf("=============\n");
	for (int i = 0; i < result_count; i++) {
		switch (find->type) {
		case INT:
			if (int_is_null(find->_int_data[i]))
				printf("     (null)\n");
			else
				printf("     %d\n", find->_int_data[i]);
			break;
		case FLOAT:
			if (float_is_null(find->_float_data[i]))
				printf("     (null)\n");
			else
				printf("     %.5f\n", find->_float_data[i]);
			break;
		case DOUBLE:
			if (double_is_null(find->_double_data[i]))
				printf("     (null)\n");
			else
				printf("     %.12lf\n", find->_double_data[i]);
			break;
		case CHAR:
			if (char_is_null(find->_char_data[i]))
				printf("     (null)\n");
			else
				printf("     %c\n", find->_char_data[i]);
			break;
		case VARCHAR:
			if (string_is_null(find->_string_data[i]))
				printf("     (null)\n");
			else
				printf("     %s\n", find->_string_data[i]);
			break;
		}
	}

	file_column_free();
	result_free(_result, result_count);*/
}