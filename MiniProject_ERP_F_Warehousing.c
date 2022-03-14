#include "local.h"
#include"MiniProject_ERP_1struct.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
int num = 4;			// ���õ����ͼ� + 1

void Insert_WarehousingData_from_BuyingList(void)	// �����԰� - ���������� �ҷ��ͼ� �Է�
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
	today_date = ((t->tm_year + 1900) * 10000) + ((t->tm_mon + 1) * 100) + (t->tm_mday);	// ���� ��¥( 20220304 �� )

	
	char Parameter_Insert[1000] = { NULL };				// �������� _insert�Լ��� �־��� ���ڿ� (sample.c������ value�� ����)
	char temp_int[20] = { 0 };							// int���� ���ڿ��� �ٲܶ� �� �ӽ� ���ڿ�
	char Select_BuyingList_num[20] = { 0 };				// ���ֹ�ȣ �Է¹��� �ӽ� ���ڿ�����
	

	// â����
	if (initalizing("WareHouse") == -1) {		// â������(WareHouse) ����
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	print_data();							// â���� ���
	printf("\n");

	printf("\n�԰��� â���ȣ�� �Է����ּ��� : ");		// ��µ� â���Ͽ��� ���ϴ� â���ȣ�� ���� �Է�
	scanf("%s", Select_WH);					// â���ȣ�� �Է¹޾� ����
											// ex) 1999�� �Է��� = [Select_WH = 1999](���ڿ����� ����)
	
	char select_num_warehouse[100] = "num_warehouse=";
	strcat(select_num_warehouse, Select_WH);	// select�Լ��� �������� �Է��ϱ� ���� ��ĸ����
												
	if (_select(select_num_warehouse, "name_warehouse, num_warehouse", &select_result_str) == -1) {	// ���� ����� ���� â���Ͽ��� ���� Į�������� ������ �޾ƿ�
		printf("%s\n", err_msg);

		file_column_free();		// â������(WareHouse) ����
		return -1;
	}


	if ((result_count = recv_result(&_result, select_result_str)) == -1) {		// select�� �޾ƿ� ������ _result ����Ʈ ����ü�� ����� ������
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	// num_In_WareHouse
	itoa(num, temp_int, 10);								// ��������num �� �ʱⰪ���� ���� �Էµ��ִ� ���õ������� ����(= 3)���� ����
	strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
	strcat(Parameter_Insert, ", ");							// ���� ������ ���� ��ǥ(',')�� ����(' ')

	// name_warehouse
	strcat(Parameter_Insert, "\'");							// ���ڿ��� ��� �յڷ� ��������ǥ �ʿ�
	strcat(Parameter_Insert, *(_result->_string_data));		// �޾ƿ� ����� ����
	strcat(Parameter_Insert, "\', ");						// ���ڿ��� ��� �յڷ� ��������ǥ �ʿ� + �������� �ǹ��ϴ� ����

															// ex) ������� Parameter_Insert = [4, 'warehouse1', ]
	// num_warehouse
	itoa(*(_result->next->_int_data), temp_int, 10);		// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
	strcat(Parameter_Insert, ", ");							// �������� �ǹ��ϴ� ����

															// ex) ������� Parameter_Insert = [4, 'warehouse1', 1999, ]

	printf("\n\n");
	result_free(_result, result_count);			// ����� ���� ���(�����Ҵ�)����
	file_column_free();							// â������(WareHouse) ����

	// ���ָ���Ʈ ��� �� ���� �޾ƿ���
	if (initalizing("Buy_item") == -1)	// ���ָ���Ʈ(Buy_item) ���Ͽ���
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}


	print_data();				// ���ָ���Ʈ ������
	printf("\n");

	printf("\n������ �ҷ��� ���ֹ�ȣ�� �Է����ּ��� : ");			// ��µ� ���ָ�Ͽ��� ó���� ���ֹ�ȣ�� �Է�
	scanf("%s", Select_BuyingList_num);				// �Է��� ���ֹ�ȣ�� ����

	char select_num_BuyList[100] = "num_BuyList=";			// select�Լ��� ����ϱ� ���� ���ǿ� ���� ���ڿ���������
	strcat(select_num_BuyList, Select_BuyingList_num);		// ������ ���ڿ��� �Է��� ���ֹ�ȣ�� �־� ����� �ϼ�

	// �ϼ��� ����� �������� ���ָ���Ʈ���� [ǰ���/��ȣ/��Ʈ�ѹ�, �԰�¥, ������̸�/��ȣ, ���ּ���, �ܰ�, ���ް���, ����, �հ��, ���� ���ּ���] �� �޾ƿ� 
	if (_select(select_num_BuyList, "item_NAME, item_NUMBER, item_LOT, date, name_responsible, num_responsible, num_buy, bill, pay_in, tax, pay_sum, rest_num_in", &select_result_str) == -1) {	// ���� ����� ���� â���Ͽ��� ���� Į�������� ������ �޾ƿ�
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if ((result_count = recv_result(&_result, select_result_str)) == -1) {		// select�� �޾ƿ� ������ _result ����Ʈ ����ü�� ����� ������
		printf("%s\n", err_msg);												// ����ü����� ���Ḯ��Ʈ

		file_column_free();
		return -1;
	}
		
	

	// name_item
	strcat(Parameter_Insert, "\'");							
	strcat(Parameter_Insert, *(_result->_string_data));		
	strcat(Parameter_Insert, "\', ");						

	// ������� Parameter_Insert = [4, 'warehouse1', 1999, 'SampleItem1', ]

	//num_item
	char temp_num_item[10] = "'";
	strcat(Parameter_Insert, "\'");
	strcat(Parameter_Insert, *(_result->next->_string_data));
	strcat(Parameter_Insert, "\', ");

	strcat(temp_num_item, *(_result->next->_string_data));
	strcat(temp_num_item, "\'");

	// ������� Parameter_Insert = [4, 'warehouse1', 1999, 'SampleItem1', 19999, ]

	//LOT_number
	strcat(Parameter_Insert, "\'");												
	strcat(Parameter_Insert, *(_result->next->next->_string_data));		
	strcat(Parameter_Insert, "\', ");										

	// ������� Parameter_Insert = [4, 'warehouse1', 1999, 'SampleItem1', 19999, 'RA00001', ]

	//date
	itoa(*(_result->next->next->next->_int_data), temp_int, 10);		
	strcat(Parameter_Insert, temp_int);						
	strcat(Parameter_Insert, ", ");							

	// ������� Parameter_Insert = [4, 'warehouse1', 1999, 'SampleItem1', 19999, 'RA00001', 20220304, ]

	//name_responsible
	strcat(Parameter_Insert, "\'");							
	strcat(Parameter_Insert, *(_result->next->next->next->next->_string_data));		
	strcat(Parameter_Insert, "\', ");						

	// ������� Parameter_Insert = [4, 'warehouse1', 1999, 'SampleItem1', 19999, 'RA00001', 20220304, 'SamplePerson1', ]

	//num_responsible
	itoa(*(_result->next->next->next->next->next->_int_data), temp_int, 10);		
	strcat(Parameter_Insert, temp_int);						
	strcat(Parameter_Insert, ", ");

	// ������� Parameter_Insert = [4, 'warehouse1', 1999, 'SampleItem1', 19999, 'RA00001', 20220304, 'SamplePerson1', 199, ]

	// �԰���� �Է�
	int num_InWarehouse = 0;
	printf("�԰������ �Է��ϼ��� : ");
	scanf("%d", &num_InWarehouse);

	itoa(num_InWarehouse, temp_int, 10);					
	strcat(Parameter_Insert, temp_int);						
	strcat(Parameter_Insert, ", ");

	// 80�� �Է��ߴٴ� ����
	// ������� Parameter_Insert = [4, 'warehouse1', 1999, 'SampleItem1', 19999, 'RA00001', 20220304, 'SamplePerson1', 199, 80, ]
	
	// bill = �ܰ�
	int bill = *(_result->next->next->next->next->next->next->next->_int_data);
	itoa(bill, temp_int, 10);		
	strcat(Parameter_Insert, temp_int);						
	strcat(Parameter_Insert, ", ");
	
	// ������� Parameter_Insert = [4, 'warehouse1', 1999, 'SampleItem1', 19999, 'RA00001', 20220304, 'SamplePerson1', 199, 80, 1000, ]


	// pay_in = ���ް�
	int pay_in = num_InWarehouse * bill;	// �԰���� * �ܰ�
	itoa(pay_in, temp_int, 10);		
	strcat(Parameter_Insert, temp_int);						
	strcat(Parameter_Insert, ", ");

	// ������� Parameter_Insert = [4, 'warehouse1', 1999, 'SampleItem1', 19999, 'RA00001', 20220304, 'SamplePerson1', 199, 80, 1000, 80000, ]
	
	// tax =����
	int tax = pay_in / 10;		// ���ް� / 10
	itoa(tax, temp_int, 10);		
	strcat(Parameter_Insert, temp_int);						
	strcat(Parameter_Insert, ", ");
	
	// ������� Parameter_Insert = [4, 'warehouse1', 1999, 'SampleItem1', 19999, 'RA00001', 20220304, 'SamplePerson1', 199, 80, 1000, 80000, 8000, ]

	// pay_sum = �հ��
	int pay_sum = pay_in + tax;		// ���� + ���ް�
	itoa(pay_sum, temp_int, 10);		
	strcat(Parameter_Insert, temp_int);						
	
	// ������� Parameter_Insert = [4, 'warehouse1', 1999, 'SampleItem1', 19999, 'RA00001', 20220304, 'SamplePerson1', 199, 80, 1000, 80000, 8000, 88000]

	// rest_num_in (�԰����� ��)
	int rest_num_for_Warehousing_after;					// �԰��� ���� ���ַ�
	int rest_num_for_Warehousing_before = *(_result->next->next->next->next->next->next->next->next->next->next->next->_int_data);		// �԰��� �������ַ�
	
	// rest_num_in (�԰����� ��)
	rest_num_for_Warehousing_after = rest_num_for_Warehousing_before - num_InWarehouse;			//  (�԰��� ���� ���ַ� = �԰��� ���� ���ַ� - �԰�)
	if (rest_num_for_Warehousing_after < 0)
	{
		printf("\n === !!! �߸��� �԰������ �Է��ϼ̽��ϴ�. !!! === \n");
		printf(" �԰������ ���� ���ּ����� �Ѿ�� �����ϴ�.\n");
		printf(" - �԰���� : %d\n", num_InWarehouse);
		printf(" - ���� ���ּ���: %d\n\n", rest_num_for_Warehousing_before);
		return -1;
	}
																						


	
	printf("\n\n");
	file_column_free();							// ���ָ���Ʈ����(Buy_item) �ݱ�
	result_free(_result, result_count);			// _result ����Ʈ����ü ����
	

	if (initalizing("In_WareHouse") == -1) {
		printf("%s\n", err_msg); 

		file_column_free();
		return -1;
	}

	if (_insert(Parameter_Insert) == -1)
	{	// = _insert("4, 'warehouse1', 1999, 'SampleItem1', 19999, 'RA00001', 20220304, 'SamplePerson1', 199, 80, 1000, 80000, 8000, 88000") �� �ȴ�
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	print_data();
	printf("\n\n");
	file_column_free();

	if (initalizing("Buy_item") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	char update_rest_num_BuyList_before[100] = "rest_num_in=";
	char update_rest_num_BuyList_after[100] = "rest_num_in=";

	itoa(rest_num_for_Warehousing_before, temp_int, 10);		// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(update_rest_num_BuyList_before, temp_int);				// ��ȯ�� ���ڿ��� Parameter_Insert�� ����

	itoa(rest_num_for_Warehousing_after, temp_int, 10);			// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(update_rest_num_BuyList_after, temp_int);				// ��ȯ�� ���ڿ��� Parameter_Insert�� ����

	// �԰��� ���� ���������� ���� ���ּ����� ������Ʈ�Ѵ�
	if (_update(select_num_BuyList, update_rest_num_BuyList_after) == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	print_data();
	printf("\n �԰���� ���� ���� ���� ������ < %d > ���Դϴ�.\n", rest_num_for_Warehousing_after);
	num++;
	file_column_free();

	

	// ������̺� �ش�ǰ����� �԰������ŭ ������Ʈ

	if (initalizing("Jaego") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	char item_number[100] = "num_item=";
	strcat(item_number, temp_num_item);

	if (_select(item_number, "ibgo_item", &select_result_str) == -1) {	// ���� ����� ���� â���Ͽ��� ���� Į�������� ������ �޾ƿ�
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if ((result_count = recv_result(&_result, select_result_str)) == -1) {		// select�� �޾ƿ� ������ _result ����Ʈ ����ü�� ����� ������
		printf("%s\n", err_msg);												// ����ü����� ���Ḯ��Ʈ

		file_column_free();
		return -1;
	}


	char update_jago_from_ibgo[100] = "ibgo_item=";
	num_InWarehouse = num_InWarehouse + (*(_result->_int_data));	// ���� �԰������ ��� �԰�� ������ ���Ѱ��� ������Ʈ
	itoa(num_InWarehouse, temp_int, 10);
	strcat(update_jago_from_ibgo, temp_int);
	

	if (_update(item_number, update_jago_from_ibgo) == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	file_column_free();							// ���ָ���Ʈ����(Buy_item) �ݱ�
	result_free(_result, result_count);			// _result ����Ʈ����ü ����


}



void Insert_WarehousingData(void)		// �����԰� - ������ �ϳ��ϳ� �Է�
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

	char Select_WH[10];
	char Select_Item[100];
	char Select_Person[100];
	char Parameter_Insert[1000] = { NULL };
	char temp_int[20] = { 0 };
	

	// â����
	if (initalizing("WareHouse") == -1) {		// â������(WareHouse) ����
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	print_data();				// â���� ���
	printf("\n");

	printf("\n�԰��� â���ȣ�� �Է����ּ��� : ");		// ��µ� â���Ͽ��� ���ϴ� â���ȣ�� ���� �Է�
	scanf("%s", Select_WH);							// â���ȣ�� �Է¹޾� ����
													// ex) 1999�� �Է��� = [Select_WH = 1999](���ڿ����� ����)
		
	char select_num_warehouse[100] = "num_warehouse=";
	strcat(select_num_warehouse, Select_WH);		// select�Լ��� �������� �Է��ϱ� ���� ��ĸ����
													// ex) ������� [select_num_warehouse] = [num_warehouse] = [1999]
	if (_select(select_num_warehouse, "name_warehouse, num_warehouse", &select_result_str) == -1) {	// ���� ����� ���� â���Ͽ��� ���� Į�������� ������ �޾ƿ�
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}


	if ((result_count = recv_result(&_result, select_result_str)) == -1) {		// select�� �޾ƿ� ������ _result ����Ʈ ����ü�� ����� ������
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
	// num_Warehousing
	itoa(num, temp_int, 10);
	strcat(Parameter_Insert, temp_int);
	strcat(Parameter_Insert, ", ");						

	// name_warehouse
	strcat(Parameter_Insert, "\'");							
	strcat(Parameter_Insert, *(_result->_string_data));		
	strcat(Parameter_Insert, "\', ");						

	// ������� [Parameter_Insert = 'warehouse1', ]

	// num_warehouse
	itoa(*(_result->next->_int_data), temp_int, 10);		
	strcat(Parameter_Insert, temp_int);						
	strcat(Parameter_Insert, ", ");							

	// ������� [Parameter_Insert = 'warehouse1', 1999, ]

	printf("\n\n");
	result_free(_result, result_count);		// _result����ü ����
	file_column_free();						// â������(WareHouse) �ݱ�


	//ǰ����
	if (initalizing("ITEM") == -1) {  // ǰ������(item) ����
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	print_data();		// ǰ���� ���
	printf("\n");

	printf("\nǰ���ȣ�� �Է����ּ��� : ");		// ��µ� â���Ͽ��� ���ϴ� â���ȣ�� ���� �Է�
	scanf("%s", Select_Item);				// â���ȣ�� �Է¹޾� ����

	char select_num_item[100] = "item_NUMBER=";
	strcat(select_num_item, Select_Item);

	if (_select(select_num_item, "item_NAME, item_NUMBER, item_LOT", &select_result_str) == -1) {	// ���� ����� ���� â���Ͽ��� ���� Į�������� ������ �޾ƿ�
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}


	if ((result_count = recv_result(&_result, select_result_str)) == -1) {		// select�� �޾ƿ� ������ _result ����Ʈ ����ü�� ����� ������
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	// name_item
	strcat(Parameter_Insert, "\'");							
	strcat(Parameter_Insert, *(_result->_string_data));		
	strcat(Parameter_Insert, "\', ");						

	// ������� [Parameter_Insert = 'warehouse1', 1999, 'SampleItem1', ]
	
	// num_item
	strcat(Parameter_Insert, "\'");
	strcat(Parameter_Insert, *(_result->next->_string_data));
	strcat(Parameter_Insert, "\', ");

	// ������� [Parameter_Insert = 'warehouse1', 1999, 'SampleItem1', 19999, ]

	// LOT_number
	strcat(Parameter_Insert, "\'");										
	strcat(Parameter_Insert, *(_result->next->next->_string_data));		
	strcat(Parameter_Insert, "\', ");									
	
	// ������� [Parameter_Insert = 'warehouse1', 1999, 'SampleItem1', 19999, 'RA0001', ]
	
	printf("\n\n");
	result_free(_result, result_count);		// _result ������ ����ü ����
	file_column_free();						// ǰ������(item) ����


	// ��¥�Է� - �ڵ����
	itoa(today_date, temp_int, 10);		
	strcat(Parameter_Insert, temp_int);						
	strcat(Parameter_Insert, ", ");							

	// ������� [Parameter_Insert = 'warehouse1', 1999, 'SampleItem1', 19999, 'RA0001', 20220304, ]

	// ������Է�
	if (initalizing("Person_responsibe") == -1) {		
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	print_data();		// ����ڸ�� ���
	printf("\n");

	printf("\n����ڹ�ȣ�� �Է����ּ��� : ");		// ��µ� ����ڸ�Ͽ��� ���ϴ� ����ڹ�ȣ�� ���� �Է�
	scanf("%s", Select_Person);					// ����ڹ�ȣ�� �Է¹޾� ����

	char select_num_person[100] = "num_responsible=";
	strcat(select_num_person, Select_Person);

	if (_select(select_num_person, "name_responsible, num_responsible", &select_result_str) == -1) {	
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}


	if ((result_count = recv_result(&_result, select_result_str)) == -1) {		// select�� �޾ƿ� ������ _result ����Ʈ ����ü�� ����� ������
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	// ����� �̸�
	strcat(Parameter_Insert, "\'");							
	strcat(Parameter_Insert, *(_result->_string_data));		
	strcat(Parameter_Insert, "\', ");						

	// ����� ��ȣ
	itoa(*(_result->next->_int_data), temp_int, 10);		
	strcat(Parameter_Insert, temp_int);						
	strcat(Parameter_Insert, ", ");							

	// printf("%s", Parameter_Insert);

	printf("\n\n");
	result_free(_result, result_count);				// _result �����ͱ���ü ����
	file_column_free();								// ���������(Person_responsibe) �ݱ�



	// �԰����,�ܰ��Է� �� ��갪 �Է�
	int num_InWarehouse = 0;
	printf("�԰������ �Է��ϼ��� : ");
	scanf("%d", &num_InWarehouse);

	itoa(num_InWarehouse, temp_int, 10);					
	strcat(Parameter_Insert, temp_int);						
	strcat(Parameter_Insert, ", ");							

	// �ܰ�
	int bill = 0;
	printf("�ܰ��� �Է��ϼ��� : ");
	scanf("%d", &bill);

	itoa(bill, temp_int, 10);					
	strcat(Parameter_Insert, temp_int);						
	strcat(Parameter_Insert, ", ");							

	int pay_in = bill * num_InWarehouse;

	// ���ް�
	itoa(pay_in, temp_int, 10);					
	strcat(Parameter_Insert, temp_int);						
	strcat(Parameter_Insert, ", ");						

	int tax = pay_in / 10;

	// ����
	itoa(tax, temp_int, 10);					
	strcat(Parameter_Insert, temp_int);						
	strcat(Parameter_Insert, ", ");							

	// �հ��
	int pay_sum = pay_in + tax;
	itoa(pay_sum, temp_int, 10);					
	strcat(Parameter_Insert, temp_int);						

	
	printf("\n\n");

	// �԰����̺� �ϼ��� �Ķ���� �Է�
	if (initalizing("In_WareHouse") == -1) { // �԰�����(In_WareHouse) ����
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert(Parameter_Insert) == -1)	// �ϼ��� ���ȭ�� ���ڿ��� _insert
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	num++;

	print_data();
	printf("\n\n");
	file_column_free();		// �԰�����(In_WareHouse) �ݱ�

	
	if (initalizing("Jaego") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	char item_number[100] = "num_item=";
	strcat(item_number, Select_Item);

	if (_select(item_number, "ibgo_item", &select_result_str) == -1) {	// ���� ����� ���� â���Ͽ��� ���� Į�������� ������ �޾ƿ�
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if ((result_count = recv_result(&_result, select_result_str)) == -1) {		// select�� �޾ƿ� ������ _result ����Ʈ ����ü�� ����� ������
		printf("%s\n", err_msg);												// ����ü����� ���Ḯ��Ʈ

		file_column_free();
		return -1;
	}


	char update_jago_from_ibgo[100] = "ibgo_item=";
	num_InWarehouse = num_InWarehouse + (*(_result->_int_data));	// ���� �԰������ ��� �԰�� ������ ���Ѱ��� ������Ʈ
	itoa(num_InWarehouse, temp_int, 10);
	strcat(update_jago_from_ibgo, temp_int);

	
	if (_update(item_number, update_jago_from_ibgo) == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	file_column_free();							// ���ָ���Ʈ����(Buy_item) �ݱ�
	result_free(_result, result_count);			// _result ����Ʈ����ü ����


}

void print_Warehousing_state(void)		// �԰���Ȳ���
{
		int Select_Sort = 0;
		if (initalizing("In_WareHouse") == -1) {
			printf("%s\n", err_msg);

			file_column_free();
			return -1;
		}

		print_data();
		printf("\n\n");

	file_column_free();
}

void delete_Warehousing(void)
{
	result* _result;
	result* find;
	int result_count;

	char Select_del_Warehousing[10];

	if (initalizing("In_WareHouse") == -1) { // �԰�����(In_WareHouse) ����
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	print_data();
	printf("\n");

	printf("\n����� �԰��ȣ�� �Է����ּ��� : ");		// ��µ� ǰ���Ͽ��� ���ϴ� ǰ���ȣ�� ���� �Է�
	scanf("%s", Select_del_Warehousing);

	char select_num_Warehousing[100] = "num_In_WareHouse=";
	strcat(select_num_Warehousing, Select_del_Warehousing);
	printf("%s", select_num_Warehousing);

	//if (_select(select_num_Warehousing, ", num_responsible", &select_result_str) == -1) {
	//	printf("%s\n", err_msg);

	//	file_column_free();
	//	return -1;
	//}


	//if ((result_count = recv_result(&_result, select_result_str)) == -1) {		// select�� �޾ƿ� ������ _result ����Ʈ ����ü�� ����� ������
	//	printf("%s\n", err_msg);

	//	file_column_free();
	//	return -1;
	//}


	if (_delete(select_num_Warehousing) == -1) // ���� ����� ���� ǰ���Ͽ��� ���� Į�������� ������ �޾ƿ�
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