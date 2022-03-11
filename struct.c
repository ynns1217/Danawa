#include "product.h"

void initCreate()
{
	//_create("jisi", "date VARCHAR(20) indicated_quantity INT work_order_num VARCHAR(20) LOT VARCHAR(20) Product_num VARCHAR(20) Product_name VARCHAR(20) client VARCHAR(20)");
	//납기일 지시수량 작업지시번호 LOT 품번 품명 고객 
	
	_create("Work_Order_Registration", "Due_Date INT Quantity INT Work_Instruction_Number VARCHAR(20) LOT VARCHAR(20) Item_Number VARCHAR(20) Name VARCHAR(20) Customer VARCHAR(20)");
	//Work Instruction Number에 (제품구분+(공정)+날짜+번호) 들어감
	//Due_Date(납기일) Quantity(지시수량) Work_Instruction_Number(작업지시번호) LOT(LOT) Item_Number(품번) Name(품명) Customer(고객)

	_create("performance", "Work_Instruction_Number VARCHAR(20) Item_Number VARCHAR(20) Name VARCHAR(20) Customer VARCHAR(20) Quantity INT performance_quantity INT performance_num VARCHAR(20) LOT VARCHAR(20)");
	//work_order_num(작업지시번호) Item_Number(품번) Name(품명) Customer(고객) Quantity(지시수량) performance_quantity(실적수량) performance_num(실적번호) LOT(LOT)

	_create("product_warehous", "Work_Instruction_Number VARCHAR(20) performance_num VARCHAR(20) Item_Number VARCHAR(20) Name VARCHAR(20) performance_quantity INT Customer VARCHAR(20) LOT VARCHAR(20) stock_num VARCHAR(20) stock_date INT stock_warehouse VARCHAR(20) stock_location VARCHAR(20) stock_count INT");
	//Work_Instruction_Number(작업지시번호) performance_num(실적번호) Product_num(품번) Name(품명) performance_quantity(실적수량) Customer(고객) LOT stock_num(입고번호) stock_date(입고일자) stock_warehouse(입고창고) stock_location(입고장소) stock_count(입고수량) 

}

void initSampledata()
{
	char* values1 = "20210910, 15, 'W02109000002', NULL, 'PC02', '데스크탑PC', '사는회사'";
	char* values2 = "20210325, 10, 'W02109000007', NULL, 'PC04', '데스크탑PC2', '우리회사'";
	
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