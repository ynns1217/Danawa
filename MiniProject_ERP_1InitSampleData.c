#include "local.h"
#include"MiniProject_ERP_1struct.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

void Create_File(void)
{
	// [���ֵ��]
	_create("contract_regi", "con_num VARCHAR(10) con_date INT client VARCHAR(20) VAT INT in_charge VARCHAR(20)");

	// [���ֵ��-��ǰ���]
	_create("contract_item_regi", "con_num VARCHAR(10) NO INT item_num VARCHAR(50) item_name VARCHAR(50) due_date INT date_shipment INT amount INT unit_price INT supply_price INT tax INT total_price INT");

	// �մ����̺� ����
	_create("CUSTOMER", "customer VARCHAR(20)");
	
	// �԰����̺� ������ ����
	_create("In_WareHouse", "num_In_WareHouse INT name_warehouse VARCHAR(20) num_warehouse INT name_item VARCHAR(20) num_item VARCHAR(20) LOT_number VARCHAR(20)  date INT name_responsible VARCHAR(20) num_responsible INT num_in INT bill INT pay_in INT tax INT pay_sum INT");
							// �԰����				â���̸�						â���ȣ			ǰ���					ǰ��			ǰ���Ʈ�ѹ�				��¥		����ڸ�							����ڹ�ȣ		�԰����		�ܰ�		���ް�		����		�հ��
	
	// �������̺� ������ ����
	_create("Buy_item", "num_BuyList INT item_NAME VARCHAR(20) item_NUMBER VARCHAR(20) item_LOT VARCHAR(20) date INT name_responsible VARCHAR(20) num_responsible INT num_buy INT bill INT pay_in INT tax INT pay_sum INT rest_num_in INT");
	//						���ֹ�ȣ			ǰ���				ǰ��					ǰ���Ʈ�ѹ�				��¥			����ڸ�						����ڹ�ȣ		���ּ���		�ܰ�		���ް���		����			�հ��			�������ּ���
	
	// �ŷ�ó���̺� ������ ����
	_create("Buy_company", "name_buy_company VARCHAR(20) num_buy_company INT");
	//							�ŷ�ó��						�ŷ�ó��ȣ
	
	// ��������̺� ������ ����
	_create("Person_responsibe", "name_responsible VARCHAR(20) num_responsible INT");
	//								����ڸ�							����ڹ�ȣ
	
	// ǰ�����̺� ������ ����
	_create("ITEM", "item_NAME VARCHAR(20) item_NUMBER VARCHAR(20) item_TYPE VARCHAR(20) item_GOAL INT item_LOT VARCHAR(20) item_SirealNUMBER VARCHAR(20)");
	//				ǰ���					ǰ��						��������				���ϻ��귮		�����Ʈ�ѹ�				�ø���ѹ�
	
	// â������̺� ������ ����
	_create("WareHouse", "name_warehouse VARCHAR(30) num_warehouse INT");
	//						â���̸�						â���ȣ

	// <�����ȹ���>

	_create("Production_Plan_Registration", "Item_Number VARCHAR(20) Name VARCHAR(20) Daily_Capacity INT Order VARCHAR(20) ETC INT Quantity INT");
	//Item_Number(ǰ��) INT Name(ǰ��) Daily_Capacity(�� ���귮) Order(����) ETC(�۾�������) Quantity(����)


	//<�۾����õ��>

	_create("Work_Order_Registration", "Due_Date INT Quantity INT Work_Instruction_Number VARCHAR(20) LOT VARCHAR(20) Item_Number VARCHAR(20) Name VARCHAR(20) Customer VARCHAR(20)");
	//Work Instruction Number�� (��ǰ����+(����)+��¥+��ȣ) ��
	//Due_Date(������) Quantity(���ü���) Work_Instruction_Number(�۾����ù�ȣ) LOT(LOT) Item_Number(ǰ��) Name(ǰ��) Customer(��)
	
	// ���������Ȳ(�۾���) ���̺� ����
	_create("Work_Use", "Work_Instruction_Number VARCHAR(20) Item_Number VARCHAR(20) Name VARCHAR(20) Amountused INT Performanced_number INT LOT_NO VARCHAR(20)");
	//                   �۾����ù�ȣ		        ,ǰ�� INT				,ǰ��       CHAR       ,������ INT , ������ȣ           INT, LOT NO

	_create("performance", "Work_Instruction_Number VARCHAR(20) Item_Number VARCHAR(20) Name VARCHAR(20) Customer VARCHAR(20) Quantity INT performance_quantity INT performance_num VARCHAR(20) LOT VARCHAR(20)");
	//work_order_num(�۾����ù�ȣ) Item_Number(ǰ��) Name(ǰ��) Customer(��) Quantity(���ü���) performance_quantity(��������) performance_num(������ȣ) LOT(LOT)


	//��������Ȳ(��ǰ��) ���̺� ����
	_create("Product_usage_status", "Work_Instruction_Number VARCHAR(20) Name VARCHAR(20) Item_Number VARCHAR(20) Quantity INT LOT_NO VARCHAR(20) item_NAME VARCHAR(20) item_NUMBER VARCHAR(20) item_LOT VARCHAR(20) Amountused INT");
	//								, �۾����ù�ȣ             , ǰ��               ,ǰ��				          ,���ü���    ,lot��ȣ   ,         ��ǰ���ǰ�� INT    ,   ��ǰ ���ǰ��       , ������ lot��ȣ     ,������              

	// ������̺� ������ ����
	_create("Jaego", "num_jaego INT name_item VARCHAR(20) num_item VARCHAR(20) name_warehouse VARCHAR(20) num_warehouse INT LOT_number VARCHAR(20)  date INT  chogi_item INT ibgo_item INT chulgo_item INT jaego_item INT");

	_create("product_warehous", "Work_Instruction_Number VARCHAR(20) performance_num VARCHAR(20) Item_Number VARCHAR(20) Name VARCHAR(20) performance_quantity INT Customer VARCHAR(20) LOT VARCHAR(20) stock_num VARCHAR(20) stock_date INT stock_warehouse VARCHAR(20) stock_location VARCHAR(20) stock_count INT");
	//Work_Instruction_Number(�۾����ù�ȣ) performance_num(������ȣ) Product_num(ǰ��) Name(ǰ��) performance_quantity(��������) Customer(��) LOT stock_num(�԰��ȣ) stock_date(�԰�����) stock_warehouse(�԰�â��) stock_location(�԰����) stock_count(�԰����) 
}

int Init_SampleData(void)
{
	// �԰����̺� ���õ����� ����
	if (initalizing("In_WareHouse") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	//if (_insert("1, 'Warehouse1', 1999, 'CPU','CP10', 'CP20220308', 20220305, 'SamplePerson1', 199, 100, 990, 99000, 9900, 108900") == -1)
	//{
	//	printf("%s\n", err_msg);

	//	file_column_free();
	//	return -1;
	//}

	//if (_insert("2, 'Warehouse2', 2999, 'HARD', 'HR10', 'HR20220308', 20220307,  'SamplePerson1', 199, 20, 1000, 20000, 2000, 22000") == -1)
	//{
	//	printf("%s\n", err_msg);

	//	file_column_free();
	//	return -1;
	//}

	//if (_insert("3, 'Warehouse1', 1999, 'MAINBORAD', 'MB10', 'MB20220308', 20220301, 'SamplePerson1', 199, 100, 100, 10000, 1000, 11000") == -1)
	//{
	//	printf("%s\n", err_msg);

	//	file_column_free();
	//	return -1;
	//}

	int num_Warehousing_List = 0;
	//print_data();
	//printf("\n");
	
	file_column_free();


	// �������̺� ���õ����� ����
	if (initalizing("Buy_item") == -1) 
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	/*if (_insert("1, 'CPU','CP10','CP20220308', 20220304, 'SamplePerson1', 199, 100, 1000, 10000, 1000, 11000, 100") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
	if (_insert("2, 'MONITOR', 'MO10', 'MO20220308', 20220304, 'SamplePerson2', 299, 200, 2000, 40000, 4000, 44000, 100") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("3, 'CASE', 'CA10','CA20220308', 20220304, 'SamplePerson1', 199, 300, 3000, 90000, 9000, 99000, 100") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}*/

	//print_data();
	//printf("\n");
	
	
	file_column_free();


	// �ŷ�ó���̺� ���õ����� ����
	if (initalizing("Buy_company") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'Buyer1', 199999") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	//print_data();
	//printf("\n");
	file_column_free();



	// ��������̺� ���õ����� ����
	if (initalizing("Person_responsibe") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'SamplePerson1', 199") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'SamplePerson2', 299") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	//print_data();
	//printf("\n");
	
	file_column_free();

	// ���ֵ�����̺� ���õ����� ����
	if (initalizing("contract_regi") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'001', 20220101, '(��)�ٳ���', 1, '������'") == -1) {
		//1.��ǰ�� cpu 2.��ǰ��ȣ cp10 3.��ǰ�������� meterial 4.�ϻ��귮 100 5.LOT��ȣ cp20220308 6.�ø��� ��ȣ c19999p19
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	
	file_column_free();

	//����-��ǰ
	if (initalizing("contract_item_regi") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	
	if (_insert("'001', 1, 'PC10', 'PC1', 20220331, 20220329, 10, 10000, 200000, 20000, 180000") == -1) {
		//1.��ǰ�� cpu 2.��ǰ��ȣ cp10 3.��ǰ�������� meterial 4.�ϻ��귮 100 5.LOT��ȣ cp20220308 6.�ø��� ��ȣ c19999p19
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
	file_column_free();

	// ǰ�����̺� ���õ����� ����
	if (initalizing("ITEM") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
	if (_insert("'PC1','PC10','product',100,'PC20220301','P19999P11'") == -1) {
		//1.��ǰ�� cpu 2.��ǰ��ȣ cp10 3.��ǰ�������� meterial 4.�ϻ��귮 100 5.LOT��ȣ cp20220308 6.�ø��� ��ȣ c19999p19
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'CPU','CP10','meterial',0,'CP20220308','C19999P19'") == -1) {
		//1.��ǰ�� cpu 2.��ǰ��ȣ cp10 3.��ǰ�������� meterial 4.�ϻ��귮 100 5.LOT��ȣ cp20220308 6.�ø��� ��ȣ c19999p19
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'HARD','HR10','meterial',0,'HR20220308','H1999R19'") == -1) {
		//1.��ǰ�� hard 2.��ǰ��ȣ hr10 3.��ǰ�������� meterial 4.�ϻ��귮 100 5.LOT��ȣ hr20220308 6.�ø��� ��ȣ h1999r19
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'KEYBORAD','KE10','submeterial',0,'KE20220308','K1999E19'") == -1) {
		//1.��ǰ�� keyborad 2.��ǰ��ȣ ke10 3.��ǰ�������� submeterial 4.�ϻ��귮 100 5.LOT��ȣ ke20220308 6.�ø��� ��ȣ k1999e19
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'MAINBORAD','MB10','meterial',0,'MB20220308','M1999B19'") == -1) {
		//1.��ǰ�� mainborad 2.��ǰ��ȣ mb10 3.��ǰ�������� meterial 4.�ϻ��귮 100 5.LOT��ȣ mb20220308 6.�ø��� ��ȣ m1999b19
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'MONITOR','MO10','submeterial',0,'MO20220308','M1999O19'") == -1) {
		//1.��ǰ�� monitor 2.��ǰ��ȣ mo10 3.��ǰ�������� submeterial 4.�ϻ��귮 100 5.LOT��ȣ mo20220308 6.�ø��� ��ȣ m1999o19
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'CASE','CA10','meterial',100,'CA20220308','C1999A19'") == -1) {
		//1.��ǰ�� case 2.��ǰ��ȣ ca10 3.��ǰ�������� meterial 4.�ϻ��귮 100 5.LOT��ȣ ca20220308 6.�ø��� ��ȣ c1999a19
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	//print_data();
	//printf("\n");
	
	file_column_free();

	// â�����̺� ���õ����� ����
	if (initalizing("WareHouse") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'Warehouse1', 1999 ") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}


	//print_data();
	//printf("\n");
	file_column_free();

	//��������Ȳ ���õ����� �Է�
	if (initalizing("Work_Use") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
	file_column_free();

	//�۾����� ���õ����� �Է�
	if (initalizing("performance") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
	/*if (_insert("'1000', 'CA10', '�̵�����ü', '��ö��', 5 , 5, 101, '9'") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'2000', 'PR10', '������������', '��˰�', 10, 10, 102, '7'") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'3000', 'PC10', '����ũžPC', '�����', 18, 10, 103, '8'") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}*/
	file_column_free();

	//������ ��ǰ�� �����Է�
	if (initalizing("Product_usage_status") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
	file_column_free();

	// ������̺� ���õ����� ����
	if (initalizing("Jaego") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("1, 'CPU', 'CP10', 'Warehouse1', 1999, 'CP20220308', 20220305, 10, 0, 0, 0") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("2, 'HARD', 'HR10', 'Warehouse1', 1999, 'CP20220308', 20220305, 10, 0, 0, 0") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
	if (_insert("3, 'KEYBOARD', 'KE10', 'Warehouse1', 1999, 'CP20220308', 20220305, 10, 0, 0, 0") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
	if (_insert("4, 'MAINBOARD', 'MB10', 'Warehouse1', 1999, 'CP20220308', 20220305, 10, 0, 0, 0") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
	if (_insert("5, 'MONITOR', 'MO10', 'Warehouse1', 1999, 'CP20220308', 20220305, 10, 0, 0, 0") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
	if (_insert("6, 'CASE', 'CA10', 'Warehouse1', 1999, 'CP20220308', 20220305, 0, 0, 0, 0") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	//print_data();
	//printf("\n");

	file_column_free();

	char* values1 = "20210910, 15, 'W02109000002', NULL, 'PC02', '����ũžPC', '���ȸ��'";
	char* values2 = "20210325, 10, 'W02109000007', NULL, 'PC04', '����ũžPC2', '�츮ȸ��'";

	if (initalizing("Work_Order_Registration") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	//if (_insert(values1) == -1) {
	//	printf("%s\n", err_msg);

	//	file_column_free();
	//	return -1;
	//}

	//if (_insert(values2) == -1) {
	//	printf("%s\n", err_msg);

	//	file_column_free();
	//	return -1;
	//}
	file_column_free();

	// �մԳֱ�
	if (initalizing("CUSTOMER") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	//if (_insert("'������'") == -1) {
	//	printf("%s\n", err_msg);

	//	file_column_free();
	//	return -1;
	//}

	//if (_insert("'�ڼ���'") == -1) {
	//	printf("%s\n", err_msg);

	//	file_column_free();
	//	return -1;
	//}

	//if (_insert("'������'") == -1) {
	//	printf("%s\n", err_msg);

	//	file_column_free();
	//	return -1;
	//}

	//if (_insert("'������'") == -1) {
	//	printf("%s\n", err_msg);

	//	file_column_free();
	//	return -1;
	//}

	//if (_insert("'������'") == -1) {
	//	printf("%s\n", err_msg);

	//	file_column_free();
	//	return -1;
	//}

	//if (_insert("'�輼��'") == -1) {
	//	printf("%s\n", err_msg);

	//	file_column_free();
	//	return -1;
	//}

	// ������ �ݱ�
	file_column_free();
	
}