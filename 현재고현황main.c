#include "local.h"
#pragma warning(disable:4996)


char* values = "'Ű����', 800, 1 , 2 ,3,4, NULL";
char* values1 = "'���콺', 500, 2 , 10 ,0,9,NULL";
char* values2 = "'����ũž', 600, 0 , 10 ,0,10,NULL";
char* values3 = "'������ �ϵ�', 700, 0 , 10 ,0,11,NULL";
char* values4 = "'������ �ϵ�', 400, 0 , 10 ,0,11,NULL";

result* _result;
result* find;

char* set = "jaego_item = gicho_item + ibgo_item - culgoitem";
char* conditional = "jaego_item = NULL";
char* select_column = "name_item, num_item, date, jaego_item ";

int result_count;
int option1, option2, option3;

void table_init()
{
	if (_create("Stock_In", "name_item VARCHAR(20) num_item INT date INT gicho_item INT ibgo_item INT chulgo_item INT jaego_item INT ") == -1)
	{
		printf("%s\n", err_msg);

		return -1;
	}

	if (_create("ITEM", "name_item VARCHAR(20) num_item INT ") == -1)
	{
		printf("%s\n", err_msg);

		return -1;
	}

	//���� �ʱ�ȭ
	if (initalizing("C:\\Users\\PKNU\\source\\repos\\Danawa\\Stock_In") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}


}
void insert_table()
{
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

	if (_insert(values4) == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
}
void edit_minus_table()
{
	if (initalizing("C:\\Users\\PKNU\\source\\repos\\Danawa\\Stock_In") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	char* conditional = "num_item=800";
	char* set = "chulgo_item=5";

	if (_update(conditional, set) == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
}
void edit_plus_table()
{
	if (initalizing("C:\\Users\\PKNU\\source\\repos\\Danawa\\Stock_In") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	char* conditional = "num_item=800";
	char* set = "chulgo_item=5";

	if (_update(conditional, set) == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
}
int jaego_count() {
	printf("\t�� ��� ����\n");
	printf("======================================\n");

	if (initalizing("C:\\Users\\PKNU\\source\\repos\\Danawa\\Stock_In") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
	char temp_insert[100];
	char Select_IT[100];

	printf("�˻��� ǰ���� �Է��Ͻÿ�\n");
	scanf("%s", &Select_IT);

	char select_num_item[100] = "num_item=";
	char Parameter_Insert[1000] = { NULL };
	char temp_int[20] = { 0 };
	strcat(select_num_item, Select_IT);	// select�Լ��� �������� �Է��ϱ� ���� ��ĸ����
												// ex) ������� [select_num_warehouse = num_warehouse=1999]

	if (_select(select_num_item, "name_item, num_item, date, gicho_item, ibgo_item, chulgo_item, jaego_item", &select_result_str) == -1) {	// ���� ����� ���� â���Ͽ��� ���� Į�������� ������ �޾ƿ�
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	else
	{
		printf("======================================\n");
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
	itoa(*(_result->next->next->next->_int_data), temp_int, 10);		// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
	strcat(Parameter_Insert, " ");							// �������� �ǹ��ϴ� ����

															// ex) ������� [Parameter_Insert = 'warehouse1' 1999 ]
	itoa(*(_result->next->next->next->next->_int_data), temp_int, 10);		// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
	strcat(Parameter_Insert, " ");							// �������� �ǹ��ϴ� ����

															// ex) ������� [Parameter_Insert = 'warehouse1' 1999 ]
	itoa(*(_result->next->next->next->next->next->_int_data), temp_int, 10);		// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
	strcat(Parameter_Insert, " ");							// �������� �ǹ��ϴ� ����

															// ex) ������� [Parameter_Insert = 'warehouse1' 1999 ]


	//�� ��� ���� ����ؼ� ���
	*(_result->next->next->next->next->next->next->_int_data) = *(_result->next->next->next->_int_data) + *(_result->next->next->next->next->_int_data) - *(_result->next->next->next->next->next->_int_data);

	itoa(*(_result->next->next->next->next->next->next->_int_data), temp_int, 10);		// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
	strcat(Parameter_Insert, " ");							// �������� �ǹ��ϴ� ����

															// ex) ������� [Parameter_Insert = 'warehouse1' 1999 ]



	if ((find = find_result(_result, "jaego_item")) == -1)
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
			if (int_is_null(find->_int_data[i]))
				printf("     (null)\n");
			else
			{
				printf("     %d\n", find->_int_data[i]);
			}
				break;
		
				return find->_int_data[i];
	}

	printf("======================================\n");
	printf("%s\n", Parameter_Insert);
	system("pause");
	printf("\n\n");
	file_column_free();
	result_free(_result, result_count);

} 		//�� ��� ����
void ibgo_chulgo_count()		
{
	printf("\t��� ��Ȳ\n");
	printf("======================================\n");
	print_data();
	printf("\n");
	file_column_free();
	system("pause");
}	   //�������� �����Ȳ
void jaego_print()
{
	if (initalizing("C:\\Users\\PKNU\\source\\repos\\Danawa\\Stock_In") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
	char temp_insert[100];
	char Select_IT[100];

	printf("�˻��� ǰ���� �Է��Ͻÿ�\n");
	scanf("%s", &Select_IT);

	char select_num_item[100] = "num_item=";
	char Parameter_Insert[1000] = { NULL };
	char temp_int[20] = { 0 };
	strcat(select_num_item, Select_IT);	// select�Լ��� �������� �Է��ϱ� ���� ��ĸ����
												// ex) ������� [select_num_warehouse = num_warehouse=1999]

	if (_select(select_num_item, "name_item, num_item, date, gicho_item, ibgo_item, chulgo_item, jaego_item", &select_result_str) == -1) {	// ���� ����� ���� â���Ͽ��� ���� Į�������� ������ �޾ƿ�
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	else
	{
		printf("======================================\n");
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
	itoa(*(_result->next->next->next->_int_data), temp_int, 10);		// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
	strcat(Parameter_Insert, " ");							// �������� �ǹ��ϴ� ����

															// ex) ������� [Parameter_Insert = 'warehouse1' 1999 ]
	itoa(*(_result->next->next->next->next->_int_data), temp_int, 10);		// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
	strcat(Parameter_Insert, " ");							// �������� �ǹ��ϴ� ����

															// ex) ������� [Parameter_Insert = 'warehouse1' 1999 ]
	itoa(*(_result->next->next->next->next->next->_int_data), temp_int, 10);		// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
	strcat(Parameter_Insert, " ");							// �������� �ǹ��ϴ� ����

															// ex) ������� [Parameter_Insert = 'warehouse1' 1999 ]


	//�� ��� ���� ����ؼ� ���
	*(_result->next->next->next->next->next->next->_int_data) = *(_result->next->next->next->_int_data) + *(_result->next->next->next->next->_int_data) - *(_result->next->next->next->next->next->_int_data);

	itoa(*(_result->next->next->next->next->next->next->_int_data), temp_int, 10);		// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
	strcat(Parameter_Insert, " ");							// �������� �ǹ��ϴ� ����

															// ex) ������� [Parameter_Insert = 'warehouse1' 1999 ]



	if ((find = find_result(_result, "jaego_item")) == -1)
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
		if (int_is_null(find->_int_data[i]))
			printf("     (null)\n");
		else
		{
			printf("     %d\n", find->_int_data[i]);
		}
		break;

		return find->_int_data[i];
	}

	printf("======================================\n");
	printf("%s\n", Parameter_Insert);
	system("pause");
	printf("\n\n");
	file_column_free();
}
void jaego_use()
{

}

int main() {
		//�� ��� ���̺� (����� + ��ȸ + ��� �̵�)

	while (1)
	{
		system("cls");
		table_init();
		insert_table();

		printf("\t������\n");
		printf("1.�� ��� ��Ȳ 2.��� �̵� \n");
		printf("======================================\n");
		scanf("%d", &option1);

		system("cls");

		switch (option1)
		{

		case 1:
			printf("\t�� ��� ��Ȳ\n");
			printf("======================================\n");
			printf("1. ����� ��� ��Ȳ 2. ������ ��� ��ȸ \n");
			printf("======================================\n");
			scanf("%d", &option1);

			if (option1 == 1)
			{
				//�������� �����Ȳ
				ibgo_chulgo_count();
				break;
			}
			else if (option1 == 2)
			{
				jaego_count();

				break;
			}

		case 2:
			printf("\t��� ����ϱ� \n");
			printf("======================================\n");

			jaego_print();

			for (int i = 0; i < result_count; i++)
			{
				if ((find->_int_data[i]) >= 1)
				{
					printf("======================================\n");
					printf("�����Ϸ� ������\n");

					edit_table();
					jaego_count();
				}

				else
				{
					printf("======================================\n");
					printf("�����Ϸ� ������\n");

				}
			}
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