#include "product.h"

void initCreate()
{
	//_create("jisi", "date VARCHAR(20) indicated_quantity INT work_order_num VARCHAR(20) LOT VARCHAR(20) Product_num VARCHAR(20) Product_name VARCHAR(20) client VARCHAR(20)");
	//������ ���ü��� �۾����ù�ȣ LOT ǰ�� ǰ�� �� 
	
	_create("Work_Order_Registration", "Due_Date INT Quantity INT Work_Instruction_Number VARCHAR(20) LOT VARCHAR(20) Item_Number VARCHAR(20) Name VARCHAR(20) Customer VARCHAR(20)");
	//Work Instruction Number�� (��ǰ����+(����)+��¥+��ȣ) ��
	//Due_Date(������) Quantity(���ü���) Work_Instruction_Number(�۾����ù�ȣ) LOT(LOT) Item_Number(ǰ��) Name(ǰ��) Customer(��)

	_create("performance", "Work_Instruction_Number VARCHAR(20) Item_Number VARCHAR(20) Name VARCHAR(20) Customer VARCHAR(20) Quantity INT performance_quantity INT performance_num VARCHAR(20) LOT VARCHAR(20)");
	//work_order_num(�۾����ù�ȣ) Item_Number(ǰ��) Name(ǰ��) Customer(��) Quantity(���ü���) performance_quantity(��������) performance_num(������ȣ) LOT(LOT)

	_create("product_warehous", "Work_Instruction_Number VARCHAR(20) performance_num VARCHAR(20) Item_Number VARCHAR(20) Name VARCHAR(20) performance_quantity INT Customer VARCHAR(20) LOT VARCHAR(20) stock_num VARCHAR(20) stock_date INT stock_warehouse VARCHAR(20) stock_location VARCHAR(20) stock_count INT");
	//Work_Instruction_Number(�۾����ù�ȣ) performance_num(������ȣ) Product_num(ǰ��) Name(ǰ��) performance_quantity(��������) Customer(��) LOT stock_num(�԰��ȣ) stock_date(�԰�����) stock_warehouse(�԰�â��) stock_location(�԰����) stock_count(�԰����) 

}

void initSampledata()
{
	char* values1 = "20210910, 15, 'W02109000002', NULL, 'PC02', '����ũžPC', '���ȸ��'";
	char* values2 = "20210325, 10, 'W02109000007', NULL, 'PC04', '����ũžPC2', '�츮ȸ��'";
	
	if (initalizing("Work_Order_Registration") == -1) {
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
	file_column_free();
}