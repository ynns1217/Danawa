#include "local.h"
#include"MiniProject_ERP_1struct.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

int Insert_Production_Plan_File(void) {
	result* _result;
	result* find;
	int result_count;
	char Select_Item[20];

	if (initalizing("contract_item_regi") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	printf("\n");
	print_data();
	file_column_free();

	printf("\nǰ���� �������ּ��� : ");		// ��µ� ǰ���Ͽ��� ���ϴ� ǰ���ȣ�� ���� �Է�
	scanf("%s", Select_Item);	// CASE01

	char select_num_item[100] = "item_NUMBER ="; // char* conditional =  "item_NAME = Select_item";
	strcat(select_num_item, Select_Item); // item_NUMBER = CASE01

	char Parameter_Insert[1000] = { NULL };
	char temp_int[20] = { 0 };

	if (initalizing(Select_Item) == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	printf("\n");
	print_data();

	file_column_free();

	if (initalizing("ITEM") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_select(select_num_item, "item_NUMBER, item_NAME, item_GOAL", &select_result_str) == -1) // ���� ����� ���� ǰ���Ͽ��� ���� Į�������� ������ �޾ƿ�
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

	//result_print(_result, result_count);

	strcat(Parameter_Insert, "\'");
	strcat(Parameter_Insert, *(_result->_string_data));
	strcat(Parameter_Insert, "\', ");

	strcat(Parameter_Insert, "\'");							// ���ڿ��� ��� �յڷ� ��������ǥ �ʿ� , '
	strcat(Parameter_Insert, *(_result->next->_string_data));		// �޾ƿ� ����� ����, 'CPU
	strcat(Parameter_Insert, "\', ");						// ���ڿ��� ��� �յڷ� ��������ǥ �ʿ� + �������� �ǹ��ϴ� ����, 'CPU', 

	itoa(*(_result->next->next->_int_data), temp_int, 10);        // �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
	strcat(Parameter_Insert, ", ");

	file_column_free();

	int order_VAR;
	printf("������ �Է����ּ��� : ");
	scanf("%d", &order_VAR); // Order �� �Է�

	itoa(order_VAR, temp_int, 10);
	strcat(Parameter_Insert, temp_int);
	strcat(Parameter_Insert, ", "); // Parameter_insert('CPU', 'PC01', 100, )+ 'order_VAR', = 'CPU', 'PC01', 100, 'order', 

	int ETC_NUM;
	printf("�۾��������� �Է����ּ��� : ");
	scanf("%d", &ETC_NUM);

	itoa(ETC_NUM, temp_int, 10);						    // �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
	strcat(Parameter_Insert, ", ");                         // Parameter_insert('CPU', 'PC01', 100, 'order', ) + ETC_NUM(20220309), = 'CPU', 'PC01', 100, 'order', 20220309, 

	int Quantity_NUM;
	printf("������ �Է����ּ��� : ");                      // Quantity_NUM - ����
	scanf("%d", &Quantity_NUM);

	itoa(Quantity_NUM, temp_int, 10);						    // �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
	strcat(Parameter_Insert, temp_int);						    // parameter ~ = 'CPU', 'PC01', 100, 'order', 20220309, 15

	if (initalizing("Production_Plan_Registration") == -1) {
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
	printf("\n");

	file_column_free();
	return Quantity_NUM;
}

void Insert_Work_order_File() {
	result* _result;
	result* find;
	int result_count;
	char Select_Item[20];
	char Customer_name[20];
	char Parameter_Insert[1000] = { NULL };
	char temp_int[20] = { 0 };

	if (initalizing("Production_Plan_Registration") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	printf("\n");
	print_data();
	printf("\n");

	file_column_free();

	if (initalizing("contract_item_regi") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	printf("ǰ���� �������ּ��� : ");		// ��µ� ǰ���Ͽ��� ���ϴ� ǰ���ȣ�� ���� �Է�
	scanf("%s", Select_Item);	// CASE01

	char select_num_item[100] = "item_num ="; // char* conditional =  "item_NAME = Select_item";
	strcat(select_num_item, Select_Item); // item_NUMBER = CASE01

	if (_select(select_num_item, "due_date, item_num, item_name", &select_result_str) == -1) // ���� ����� ���� ǰ���Ͽ��� ���� Į�������� ������ �޾ƿ�
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


	itoa(*(_result->_int_data), temp_int, 10);
	strcat(Parameter_Insert, temp_int);
	strcat(Parameter_Insert, ", "); // Parameter_insert('CPU', 'PC01', 100, )+ 'Due_Date', = 'CPU', 'PC01', 100, 'order',

	int Quantity;

	printf("���ü����� �Է��Ͻÿ� : ");
	scanf("%d", &Quantity);      // ���ü��� �Է� 

	itoa(Quantity, temp_int, 10);
	strcat(Parameter_Insert, temp_int);
	strcat(Parameter_Insert, ", ");

	char Work_Instruction_Number[20];

	printf("�۾����ù�ȣ�� �Է��Ͻÿ� : ");
	scanf("%s", Work_Instruction_Number); // �۾����ù�ȣ �� �Է�

	strcat(Parameter_Insert, "\'");
	strcat(Parameter_Insert, Work_Instruction_Number);
	strcat(Parameter_Insert, "\', ");

	char LOT[20];

	printf("LOT�� �Է��Ͻÿ� : ");
	scanf("%s", &LOT);   //LOT �� �Է�

	strcat(Parameter_Insert, "\'");
	strcat(Parameter_Insert, LOT);
	strcat(Parameter_Insert, "\', ");

	strcat(Parameter_Insert, "\'");     //�ҷ��°� ���̱�
	strcat(Parameter_Insert, *(_result->next->_string_data));
	strcat(Parameter_Insert, "\', ");

	strcat(Parameter_Insert, "\'");
	strcat(Parameter_Insert, *(_result->next->next->_string_data));
	strcat(Parameter_Insert, "\'");

	file_column_free();

	printf("\n");

	//COSTOMER 
	if (initalizing("contract_regi") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_select("*", "client", &select_result_str) == -1) // ���� ����� ���� ǰ���Ͽ��� ���� Į�������� ������ �޾ƿ�
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

	result_print(_result, result_count);
	printf("\n\n");

	printf("������ �Է��Ͻÿ� : ");
	scanf("%s", Customer_name);
	printf("\n");
	char select_customer[100] = "client ="; // char* conditional =  "item_NAME = Select_item";
	strcat(select_customer, Customer_name); // item_NUMBER = CASE01


	if (_select(select_customer, "client", &select_result_str) == -1) // ���� ����� ���� ǰ���Ͽ��� ���� Į�������� ������ �޾ƿ�
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

	//customer
	strcat(Parameter_Insert, "\, ");   // (    ,     ,     | <- ���⼭ �����⶧���� ,�� �������
	strcat(Parameter_Insert, "\'");
	strcat(Parameter_Insert, *(_result->_string_data));
	strcat(Parameter_Insert, "\'");

	file_column_free();

	if (initalizing("Work_Order_Registration") == -1) {
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
	printf("\n");

	file_column_free();

}
