#include "local.h"
#include"MiniProject_ERP_1struct.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)


void insertOrderData(void)		// ���� ���
{
	result* _result;
	result* find;
	int result_count;

	time_t timer;
	struct tm* t;
	timer = time(NULL);
	t = localtime(&timer);

	int today_date = 0;
	today_date = ((t->tm_year + 1900) * 10000) + ((t->tm_mon + 1) * 100) + (t->tm_mday);	// ���� ��¥( 20220304 �� )

	char Select_Item[100];
	char Select_Person[100];
	char Parameter_Insert[1000] = { NULL };
	char temp_int[20] = { 0 };

	int num_orderList = 0;
	printf("���ֵ�� ��ȣ�� �Է��ϼ��� : ");
	scanf("%d", &num_orderList);

	itoa(num_orderList, temp_int, 10);					// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);
	strcat(Parameter_Insert, ", ");

	printf("\n\n");

	//ǰ����
	if (initalizing("ITEM") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	print_data();		// ǰ���� ���
	printf("\n");

	printf("\nǰ�� ��ȣ�� �Է����ּ��� : ");		// ��µ� ǰ���Ͽ��� ���ϴ� ǰ���ȣ�� ���� �Է�
	scanf("%s", Select_Item);						// ǰ���ȣ�� �Է¹޾� ����

	char select_num_item[100] = "item_NUMBER=";
	strcat(select_num_item, Select_Item);

	if (_select(select_num_item, "item_NAME, item_NUMBER, item_LOT", &select_result_str) == -1) // ���� ����� ���� ǰ���Ͽ��� ���� Į�������� ������ �޾ƿ�
	{	
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}


	if ((result_count = recv_result(&_result, select_result_str)) == -1) // select�� �޾ƿ� ������ _result ����Ʈ ����ü�� ����� ������
	{		
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	strcat(Parameter_Insert, "\'");							// ���ڿ��� ��� �յڷ� ��������ǥ �ʿ�
	strcat(Parameter_Insert, *(_result->_string_data));		// �޾ƿ� ����� ����
	strcat(Parameter_Insert, "\', ");						// ���ڿ��� ��� �յڷ� ��������ǥ �ʿ� + �������� �ǹ��ϴ� ����

	strcat(Parameter_Insert, "\'");							// ���ڿ��� ��� �յڷ� ��������ǥ �ʿ�
	strcat(Parameter_Insert , *(_result->next->_string_data));
	strcat(Parameter_Insert, "\', ");						// �������� �ǹ��ϴ� ����

	strcat(Parameter_Insert, "\'");							// ���ڿ��� ��� �յڷ� ��������ǥ �ʿ�
	strcat(Parameter_Insert, *(_result->next->next->_string_data));		// �޾ƿ� ����� ����
	strcat(Parameter_Insert, "\', ");

															// // ex) ������� [Parameter_Insert = 'warehouse1', 1999, 'SampleItem1', 19999, ]
	// printf("%s", Parameter_Insert);

	printf("\n\n");
	result_free(_result, result_count);
	file_column_free();


	// ��¥�Է�
	itoa(today_date, temp_int, 10);							// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
	strcat(Parameter_Insert, ", ");							// �������� �ǹ��ϴ� ����
	//printf("%s", Parameter_Insert);


	// ������Է�
	if (initalizing("Person_responsibe") == -1) 
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	print_data();									// ����ڸ�� ���
	printf("\n");

	printf("\n����� ��ȣ�� �Է����ּ��� : ");		    // ��µ� ����ڸ�Ͽ��� ���ϴ� ����ڹ�ȣ �� ���� �Է�
	scanf("%s", Select_Person);						// ����� ��ȣ�� �Է¹޾� ����

	char select_num_person[100] = "num_responsible=";
	strcat(select_num_person, Select_Person);

	if (_select(select_num_person, "name_responsible, num_responsible", &select_result_str) == -1) // ���� ����� ���� ����ڸ�Ͽ��� ���� Į�������� ������ �޾ƿ�
	{	
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}


	if ((result_count = recv_result(&_result, select_result_str)) == -1) // select�� �޾ƿ� ������ _result ����Ʈ ����ü�� ����� ������
	{		
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	strcat(Parameter_Insert, "\'");							// ���ڿ��� ��� �յڷ� ��������ǥ �ʿ�
	strcat(Parameter_Insert, *(_result->_string_data));		// �޾ƿ� ����� ����
	strcat(Parameter_Insert, "\', ");						// ���ڿ��� ��� �յڷ� ��������ǥ �ʿ� + , �� ���� ������ ���� �غ�

															// ex) ������� [Parameter_Insert = 'warehouse1' ]

	itoa(*(_result->next->_int_data), temp_int, 10);		// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
	strcat(Parameter_Insert, ", ");							// , �� ���� ������ ���� �غ�

	// printf("%s", Parameter_Insert);

	printf("\n\n");
	result_free(_result, result_count);
	file_column_free();



	// �԰����,�ܰ��Է� �� ��갪 �Է�
	int num_orderCnt = 0;
	printf("���ּ����� �Է��ϼ��� : ");						// ���� ���� �Է�
	scanf("%d", &num_orderCnt);
	printf("\n");

	itoa(num_orderCnt, temp_int, 10);						// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
	strcat(Parameter_Insert, ", ");							// , �� ���� ������ ���� �غ�

	int bill = 0;
	printf("�ܰ��� �Է��ϼ��� : ");							// �ܰ� �Է�
	scanf("%d", &bill);

	itoa(bill, temp_int, 10);								// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
	strcat(Parameter_Insert, ", ");							// , �� ���� ������ ���� �غ�

	int pay_in = bill * num_orderCnt;						// ���ް��� ���� (�ܰ� * ���ּ���)

	itoa(pay_in, temp_int, 10);								// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
	strcat(Parameter_Insert, ", ");							// , �� ���� ������ ���� �غ�

	int tax = pay_in / 10;									// �ΰ��� ���� (���ް��� / 10)

	itoa(tax, temp_int, 10);								// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
	strcat(Parameter_Insert, ", ");							// , �� ���� ������ ���� �غ�

	int pay_sum = pay_in + tax;								// �հ�� ���� (���ް��� + �ΰ���)

	itoa(pay_sum, temp_int, 10);							// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
	strcat(Parameter_Insert, ", ");							// , �� ���� ������ ���� �غ�

	itoa(num_orderCnt, temp_int, 10);						// ���� ���� �������� ������ �Է� ���� num_orderCnt ���� ���� ���
	strcat(Parameter_Insert, temp_int);

	// printf("%s", Parameter_Insert);
	printf("\n\n");

	// �������̺� �ϼ��� �Ķ���� �Է�
	if (initalizing("Buy_item") == -1) 
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert(Parameter_Insert) == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	print_data();
	printf("\n==========================================================================\n");

	printf("\n\n");
	file_column_free();
}

void orderList(void)
{
	if (initalizing("Buy_item") == -1)
	{
		printf("%s\n", err_msg);
	}

	print_data();
	printf("\n==========================================================================\n");

	printf("\n\n");
	file_column_free();
}

void deleteOrderData(void)
{
	char Select_order[100];

	if (initalizing("Buy_item") == -1)
	{
		printf("%s\n", err_msg);
	}

	print_data();
	printf("\n");

	printf("\n����� ���� ��ȣ�� �Է����ּ��� : ");		// ��µ� ǰ���Ͽ��� ���ϴ� ǰ���ȣ�� ���� �Է�
	scanf("%s", Select_order);

	char select_num_order[100] = "num_BuyList=";
	strcat(select_num_order, Select_order);
	printf("%s", select_num_order);

	if (_delete(select_num_order) == -1) // ���� ����� ���� ǰ���Ͽ��� ���� Į�������� ������ �޾ƿ�
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	print_data();
	printf("\n==========================================================================\n");

	printf("\n\n");
	file_column_free();
}