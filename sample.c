#include "local.h"

int main() {

	char* values = "NULL, 800, 'q', 69.11212 , 4215.134555666777";
	char* set = "TP='c'";
	char* conditional = "TP='q'";
	char* select_column = "code, number, TP, FLT, DBL";


	result* _result;
	result* find;
	int result_count;


	int option1 =0, option2 = 0;

	//����� ��� ���̺� (����� + ��ȸ + ��� �̵�)
	//if (_create("Stock_In_Factory", "name_factory VARCHAR(20) num_factory INT name_item VARCHAR(20) name_responsible VARCHAR(20) num_responsible INT bill INT date INT num_item INT")==-1)
	//{
	//	printf("%s\n", err_msg);
	//	
	//	return -1;
	//}

	////������� â�� ��� ���̺� (����� + ��ȸ + ��� �̵�)
	//if (_create("Stock_In_Warehouse", "name_factory VARCHAR(20) num_factory INT name_warehouse VARCHAR(20) num_warehouse INT name_item VARCHAR(20) name_responsible VARCHAR(20) num_responsible INT bill INT date INT num_item INT") == -1)
	//{
	//	printf("%s\n", err_msg);

	//	return -1;
	//}



	while (1)
	{
		system("cls");
		printf("\t������\n");
		printf("1.�����ȸ 2.����� 3.����̵�\n");
		printf("======================================\n");
		scanf("%d", &option1);
		system("cls");

		switch (option1)
		{

		case 1:
			printf("\t�����ȸ\n");
			printf("1.����� 2.â�� \n");
			printf("======================================\n");
			scanf("%d", &option2);

			switch (option2)
			{
			case 1:
				printf("\t�����\n");
				printf("======================================\n");


				if (initalizing("C:\\Users\\PKNU\\source\\repos\\Ynns1217\\Danawa\\Stock_In_Factory") == -1) {
					printf("%s\n", err_msg);

					file_column_free();
					return -1;
				}

				print_data();
				printf("\n");
				system("pause");
				break;

			case 2:
				printf("\tâ��\n");
				printf("======================================\n");

				if (initalizing("C:\\Users\\PKNU\\source\\repos\\Ynns1217\\Danawa\\Stock_In_Warehouse") == -1) {
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
			printf("\t�����ȸ\n");
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

	file_column_free();


				//���̺� ������ �Է��ϴ� �Լ�//
	if (_insert(values) == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}


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
}