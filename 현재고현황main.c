#include "local.h"
#pragma warning(disable:4996)

int main() {

	char* values = "NULL, 800, 'Ű����', 800, NULL , 4 ,0,0,0";
	char* values1 = "NULL, 500, '���콺', 500, NULL , 10 ,0,0,0";
	char* values2 = "NULL, 600, '�����1', 600, NULL , 10 ,0,0,0";
	char* values3 = "NULL, 700, '�����2', 700, NULL , 10 ,0,0,0";

	char* values00 = "NULL, 800, NULL, 800, 'Ű����', 800, NULL , 4 ,0,0,0";
	char* values01 = "NULL, 500, NULL, 500, '���콺', 500, NULL , 10 ,0,0,0";
	char* values02 = "NULL, 600, NULL, 600, '�����1', 600, NULL , 10 ,0,0,0";
	char* values03 = "NULL, 700, NULL, 700, '�����2', 700, NULL , 10 ,0,0,0";

	char* set = "name_item = 'Ű����'";
	char* conditional = "name_item = 'Ű����'";
	char* select_column = "name_item, bill, date, num_item ";

	result* _result;
	result* find;
	int result_count;

	int option1, option2, option3;


	while (1)
	{
		system("cls");
		printf("\t������\n");
		printf("1.�����ȸ 2.����� 3.����̵�\n");
		printf("======================================\n");
		scanf("%d", &option1);
		system("cls");

		/// ///////////////////////////////////////////////////////////////////
		/// ///////////////////////////////////////////////////////////////////

		switch (option1)
		{

		case 1:
			printf("\t�����ȸ\n");
			printf("1.����� 2.â�� \n");
			printf("======================================\n");
			scanf("%d", &option2);

			/// ///////////////////////////////////////////////////////////////////
			/// ///////////////////////////////////////////////////////////////////
			/// 
			switch (option2)
			{
			case 1:
				//����� ��� ���̺� (����� + ��ȸ + ��� �̵�)
				if (_create("Stock_In_Factory", "name_factory VARCHAR(20) num_factory INT name_item VARCHAR(20) num_item INT name_responsible VARCHAR(20) num_responsible INT bill INT date INT count_item INT") == -1)
				{
					printf("%s\n", err_msg);

					return -1;
				}

				//���� �ʱ�ȭ
				if (initalizing("C:\\Users\\PKNU\\source\\repos\\Danawa\\Stock_In_Factory") == -1) {
					printf("%s\n", err_msg);

					file_column_free();
					return -1;
				}

				//���̺� ������ �Է��ϴ� �Լ�//
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
				if (_insert(values2) == -1) {
					printf("%s\n", err_msg);

					file_column_free();
					return -1;
				}
				if (_insert(values3) == -1) {
					printf("%s\n", err_msg);

					file_column_free();
					return -1;
				}


				printf("\t�����\n");
				printf("======================================\n");
				printf("1.��ü 2.�˻� \n");
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

					char temp_insert[100];
					char Select_IT[100];

					printf("�˻��� ǰ���� �Է��Ͻÿ�\n");
					scanf("%s", &Select_IT);

					char select_num_item[100] = "num_item=";
					char Parameter_Insert[1000] = { NULL };
					char temp_int[20] = { 0 };
					strcat(select_num_item, Select_IT);	// select�Լ��� �������� �Է��ϱ� ���� ��ĸ����
																// ex) ������� [select_num_warehouse = num_warehouse=1999]

					if (_select(select_num_item, "name_item, num_item, count_item", &select_result_str) == -1) {	// ���� ����� ���� â���Ͽ��� ���� Į�������� ������ �޾ƿ�
						printf("%s\n", err_msg);

						file_column_free();
						return -1;
					}
					else
					{
						printf("%s\n\n", select_result_str);
					}

					//_select�Լ����� ����� ���ڿ�(select_result_str)�� result_column ����ü�� �ش� Ÿ�Կ� ���� �迭 ���·� �����Ͽ� ����

					if ((result_count = recv_result(&_result, select_result_str)) == -1) {		// select�� �޾ƿ� ������ _result ����Ʈ ����ü�� ����� ������
						printf("%s\n", err_msg);

						file_column_free();
						return -1;
					}

					strcat(Parameter_Insert, "\'");							// ���ڿ��� ��� �յڷ� ��������ǥ �ʿ�
					strcat(Parameter_Insert, *(_result->_string_data));		// �޾ƿ� ����� ����
					strcat(Parameter_Insert, "\' ");						// ���ڿ��� ��� �յڷ� ��������ǥ �ʿ� + �������� �ǹ��ϴ� ����

																			// ex) ������� [Parameter_Insert = 'warehouse1' ]

					itoa(*(_result->next->_int_data), temp_int, 10);		// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
					strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
					strcat(Parameter_Insert, " ");							// �������� �ǹ��ϴ� ����
																			// ex) ������� [Parameter_Insert = 'warehouse1' 1999 ]

					itoa(*(_result->next->next->_int_data), temp_int, 10);		// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
					strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
					strcat(Parameter_Insert, " ");							// �������� �ǹ��ϴ� ����

																			// ex) ������� [Parameter_Insert = 'warehouse1' 1999 ]

					printf("%s\n", Parameter_Insert);
					system("pause");
					printf("\n\n");
					result_free(_result, result_count);

					file_column_free();
				}
				else
				{
					break;
				}
			break;
			file_column_free();

			case 2:

				/// ///////////////////////////////////////////////////////////////////
				/// ///////////////////////////////////////////////////////////////////

				if (_create("Stock_In_Warehouse", "name_factory VARCHAR(20) num_factory INT name_warehouse VARCHAR(20) num_warehouse INT name_item VARCHAR(20) num_item INT name_responsible VARCHAR(20) num_responsible INT bill INT date INT count_item INT") == -1)
				{
					printf("%s\n", err_msg);

					return -1;
				}

				if (initalizing("C:\\Users\\PKNU\\source\\repos\\Danawa\\Stock_In_Warehouse") == -1) {
					printf("%s\n", err_msg);

					file_column_free();
					return -1;
				}

				//���̺� ������ �Է��ϴ� �Լ�//
				if (_insert(values00) == -1) {
					printf("%s\n", err_msg);

					file_column_free();
					return -1;
				}
				if (_insert(values01) == -1) {
					printf("%s\n", err_msg);

					file_column_free();
					return -1;
				}
				if (_insert(values02) == -1) {
					printf("%s\n", err_msg);

					file_column_free();
					return -1;
				}
				if (_insert(values03) == -1) {
					printf("%s\n", err_msg);

					file_column_free();
					return -1;
				}

				printf("\tâ��\n");
				printf("======================================\n");
				printf("1.��ü 2.�˻� \n");
				printf("======================================\n");
				scanf("%d", &option3);

				/// ///////////////////////////////////////////////////////////////////
				/// ///////////////////////////////////////////////////////////////////


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

					char temp_insert[100];
					char Select_IT[100];

					printf("�˻��� ǰ���� �Է��Ͻÿ�\n");
					scanf("%s", &Select_IT);

					char select_num_item[100] = "num_item=";
					char Parameter_Insert[1000] = { NULL };
					char temp_int[20] = { 0 };
					strcat(select_num_item, Select_IT);	// select�Լ��� �������� �Է��ϱ� ���� ��ĸ����
																// ex) ������� [select_num_warehouse = num_warehouse=1999]

					if (_select(select_num_item, "name_item, num_item, count_item", &select_result_str) == -1) {	// ���� ����� ���� â���Ͽ��� ���� Į�������� ������ �޾ƿ�
						printf("%s\n", err_msg);

						file_column_free();
						return -1;
					}
					else
					{
						printf("%s\n\n", select_result_str);
					}

					//_select�Լ����� ����� ���ڿ�(select_result_str)�� result_column ����ü�� �ش� Ÿ�Կ� ���� �迭 ���·� �����Ͽ� ����

					if ((result_count = recv_result(&_result, select_result_str)) == -1) {		// select�� �޾ƿ� ������ _result ����Ʈ ����ü�� ����� ������
						printf("%s\n", err_msg);

						file_column_free();
						return -1;
					}

					strcat(Parameter_Insert, "\'");							// ���ڿ��� ��� �յڷ� ��������ǥ �ʿ�
					strcat(Parameter_Insert, *(_result->_string_data));		// �޾ƿ� ����� ����
					strcat(Parameter_Insert, "\' ");						// ���ڿ��� ��� �յڷ� ��������ǥ �ʿ� + �������� �ǹ��ϴ� ����

																			// ex) ������� [Parameter_Insert = 'warehouse1' ]

					itoa(*(_result->next->_int_data), temp_int, 10);		// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
					strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
					strcat(Parameter_Insert, " ");							// �������� �ǹ��ϴ� ����;
					// ex) ������� [Parameter_Insert = 'warehouse1' 1999 ]

					itoa(*(_result->next->next->_int_data), temp_int, 10);		// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
					strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
					strcat(Parameter_Insert, " ");							// �������� �ǹ��ϴ� ����



					printf("%s\n", Parameter_Insert);
					system("pause");
					printf("\n\n");
					result_free(_result, result_count);

					file_column_free();
				}
				else
				{
					break;
				}
				break;
				file_column_free();

			default:
				break;
			}

			break;
			file_column_free();


		case 2:
			printf("\t�����\n");
			printf("1.����� 2.â�� \n");
			printf("======================================\n");
			scanf("%d", &option2);

			break;

		case 3:
			printf("\t����̵�\n");
			printf("1.����� 2.â�� \n");
			printf("======================================\n");
			scanf("%d", &option2);

			break;

		default:
			break;
		}

	}
}



	//			//���̺� ������ �Է��ϴ� �Լ�//
	//if (_insert(values) == -1) {
	//	printf("%s\n", err_msg);

	//	file_column_free();
	//	return -1;
	//}


				//���̺� ������ �����ϴ� �Լ�//
	/*if (_delete(conditional) == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}*/


				//���̺� ������ �����ϴ� �Լ�//
	/*if (_update(conditional, set) == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}*/




				//���ǿ� �´� ���ڵ带 ���� ã�� �ش� ���ڵ��� ���ϴ� �÷��� ���� �����ϴ� �Լ�//				
				//if(���ǹ�, ������ �÷� ����Ʈ, ��� ���ڿ��� ����� ����//

	/*if (_select(conditional, select_column, &select_result_str) == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
	else {
		printf("%s\n\n", select_result_str);
	}


				//_select�Լ����� ����� ���ڿ�(select_result_str)�� result_column ����ü�� �ش� Ÿ�Կ� ���� �迭 ���·� �����Ͽ� ����

	if ((result_count = recv_result(&_result, select_result_str)) == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
	result_print(_result, result_count);
	printf("\n\n");*/



				//result ���Ḯ��Ʈ �� ���ϴ� �÷��� ã�� �Լ�

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