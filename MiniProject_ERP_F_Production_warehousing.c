#include "local.h"
#include"MiniProject_ERP_1struct.h"
//����ǰâ���԰�ó��
//�հ�ǰ�� ���˻�ǰ�� ��ǰâ��� �԰� / ���հ��� ������ 

void Production_warehousing()
{
	while(1){
	//����ǰâ���԰�ó��
	char* select_column = "Work_Instruction_Number, performance_num, Item_Number, Name, performance_quantity, Customer, LOT";
	char select_work[100] = { NULL };
	char work_order_Insert[1000] = { NULL };
	char Parameter_Insert[1000] = { NULL };
	char stock_num_del[1000] = { NULL };
	int temp_int[20] = { 0 };
	result* _result;
	int result_count;
	char stock_num_Insert[100] = { NULL };
	int stock_date_Insert = 0;
	char stock_warehouse_Insert[100] = { NULL };
	char stock_location_Insert[100] = { NULL };
	int stock_count_Insert = 0;
	char stock_num_delete[100] = { NULL };
	int Select = 0;

	printf("\n ==== < ���ϴ� �޴����� > ====\n\n");
	printf("\t1. ��ü ������ ��ȸ\n\t2. ����ǰâ���԰�ó�� ���\n\t3. ����ǰâ���԰�ó�� ����\n\t4. �ڷΰ���\n");
	scanf("%d", &Select);

		switch (Select) {
		case 1: //��ü ������ ��ȸ 
			system("cls");
			if (initalizing("product_warehous") == -1) {
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}
			else {
				//printf("%s\n\n", select_result_str);
			}
			print_data();
			file_column_free();
			break;
		case 2: //����ǰâ���԰�ó��
			system("cls");
			if (initalizing("performance") == -1) {
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}
			print_data();
			//������ȣ ��� 
			printf("\n����ǰâ���԰�ó���� ����� ������ȣ�� ����ּ���: ");
			scanf("%s", select_work);
			char select_work_condition[100] = "performance_num=";
			strcat(work_order_Insert, "\'");
			strcat(work_order_Insert, select_work);
			strcat(work_order_Insert, "\'");
			strcat(select_work_condition, work_order_Insert);

			//������ ���ù�ȣ�� �۾�������� �����͸� �޾ƿͼ� ������ 
			if (_select(select_work_condition, select_column, &select_result_str) == -1) {
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}
			else {
				//printf("%s\n\n", select_result_str);
			}

			if ((result_count = recv_result(&_result, select_result_str)) == -1) {
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}
			//result_print(_result, result_count); //������ �� ��������� 

			//�۾�������� ���̺� ����
			file_column_free();

			//����ǰâ���԰�ó�� ���̺� ����� ���ؼ� �޾ƿ� �� ���� 
			printf("\n\n");
			strcat(Parameter_Insert, "\'");
			strcat(Parameter_Insert, *(_result->_string_data));
			strcat(Parameter_Insert, "\', ");

			strcat(Parameter_Insert, "\'");
			strcat(Parameter_Insert, *(_result->next->_string_data));
			strcat(Parameter_Insert, "\', ");

			strcat(Parameter_Insert, "\'");
			strcat(Parameter_Insert, *(_result->next->next->_string_data));
			strcat(Parameter_Insert, "\', ");

			strcat(Parameter_Insert, "\'");
			strcat(Parameter_Insert, *(_result->next->next->next->_string_data));
			strcat(Parameter_Insert, "\', ");

			_itoa(*(_result->next->next->next->next->_int_data), temp_int, 10);
			strcat(Parameter_Insert, temp_int);
			strcat(Parameter_Insert, ", ");

			strcat(Parameter_Insert, "\'");
			strcat(Parameter_Insert, *(_result->next->next->next->next->next->_string_data));
			strcat(Parameter_Insert, "\', ");

			strcat(Parameter_Insert, "\'");
			strcat(Parameter_Insert, *(_result->next->next->next->next->next->next->_string_data));
			strcat(Parameter_Insert, "\'");

			//����ǰâ���԰�ó�� DB���� 
			

			//�԰��ȣ, �԰�����, �԰����, �԰������ �޾ƿͼ� ����ǰâ���԰�ó���� �ۼ�
			printf("\n�԰��ȣ�� �Է��ϼ���: ");
			scanf("%s", stock_num_Insert);

			printf("�԰����ڸ� �Է��ϼ���: ");
			scanf("%d", &stock_date_Insert);


			if (initalizing("WareHouse") == -1) {		// â������(WareHouse) ����
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}

			print_data();							// â���� ���
			printf("\n");
			file_column_free();

			printf("�԰�â�� �Է��ϼ���: ");
			scanf("%s", stock_warehouse_Insert);

			printf("�԰���Ҹ� �Է��ϼ���: ");
			scanf("%s", stock_location_Insert);

			printf("�԰������ �Է��ϼ���: ");
			scanf("%d", &stock_count_Insert);

			strcat(Parameter_Insert, ", \'");
			strcat(Parameter_Insert, stock_num_Insert);
			strcat(Parameter_Insert, "\', ");

			_itoa(stock_date_Insert, temp_int, 10);
			strcat(Parameter_Insert, temp_int);
			strcat(Parameter_Insert, ", ");

			strcat(Parameter_Insert, "\'");
			strcat(Parameter_Insert, stock_warehouse_Insert);
			strcat(Parameter_Insert, "\', ");

			strcat(Parameter_Insert, "\'");
			strcat(Parameter_Insert, stock_location_Insert);
			strcat(Parameter_Insert, "\', ");

			_itoa(stock_count_Insert, temp_int, 10);
			strcat(Parameter_Insert, temp_int);

			if (initalizing("product_warehous") == -1) {
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}


			if (_insert(Parameter_Insert) == -1) {
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}

			print_data();
			file_column_free();
			break;
		case 3:
			system("cls");
			//����ǰâ���԰�ó�� DB����
			if (initalizing("product_warehous") == -1) {
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}
			print_data();
			printf("������ �԰��ȣ�� �Է��ϼ���: ");
			scanf("%s", stock_num_delete);
			char stock_num_num[100] = "stock_num=";
			strcat(stock_num_del, stock_num_delete);
			strcat(stock_num_num, stock_num_del);

			if (_delete(stock_num_num) == -1) {
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}
			print_data();
			file_column_free();
			break;
		case 4:
			return;
		default:
			break;
		}
	}
}