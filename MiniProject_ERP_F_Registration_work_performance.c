#include "local.h"
#include"MiniProject_ERP_1struct.h"

//�۾��������(�۾����õ�Ͽ��� �޾ƿ�)

void Registration_work_performance()
{	
	while(1){
	//�۾��������
	char* select_column = "Work_Instruction_Number, Item_Number, Name, Customer, Quantity";
	char select_work[100] = { NULL };
	int indicated_quantity_Insert = 0;
	int performance_quantity_Insert[100] = {NULL};
	char LOT_Insert[100] = { NULL };
	char work_order_Insert[1000] = { NULL };
	char performance_num_del[1000] = { NULL };
	char Parameter_Insert[1000] = { NULL };
	int temp_int[20] = { 0 };
	char performance_num_delete[100] = { NULL };
	result* _result;
	int result_count;
	int Select = 0;

	printf("\n ==== < ���ϴ� �޴����� > ====\n\n");
	printf("\t1. ��ü ������ ��ȸ\n\t2. �۾����� ���\n\t3. �۾����� ����\n\t4. �ڷΰ���\n");
	scanf("%d", &Select);

		switch (Select) {
		case 1:	//��ü ������ ��ȸ 
			system("cls");
			if (initalizing("performance") == -1) {
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

		case 2: //�۾��������
			system("cls");
			//�۾����õ�� ���̺� �ҷ��� 
			if (initalizing("Work_Order_Registration") == -1) {
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}
			print_data();
			//�۾����ù�ȣ ����
			printf("\n�۾������� ����� �۾����ù�ȣ�� ����ּ���: ");
			scanf("%s", select_work);
			char select_work_condition[100] = "Work_Instruction_Number=";
			strcat(work_order_Insert, "\'");
			strcat(work_order_Insert, select_work);
			strcat(work_order_Insert, "\'");
			strcat(select_work_condition, work_order_Insert);

			//������ ���ù�ȣ�� �۾�������� ���� �޾ƿ��� ���� ������
			if (_select(select_work_condition, select_column, &select_result_str) == -1) {
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}

			if ((result_count = recv_result(&_result, select_result_str)) == -1) {
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}

			//result_print(_result, result_count); //������ �� ��������� 

			//�۾����õ�� ���̺� ����
			file_column_free();

			//�۾�������� ���̺� ����� ���ؼ� �޾ƿ� �� ���� 
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

			//�۾�������� DB���� 
			if (initalizing("performance") == -1) {
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}

			//��������, ������ȣ, LOT�� �޾ƿͼ� �۾�������Ͽ� �ۼ� 
			printf("���������� �Է��ϼ���: ");
			scanf("%d", &indicated_quantity_Insert);
			printf("������ȣ�� �Է��ϼ���: ");
			scanf("%s", &performance_quantity_Insert);
			printf("LOT�� �Է��ϼ���: ");
			scanf("%s", LOT_Insert);


			strcat(Parameter_Insert, ", ");
			_itoa(indicated_quantity_Insert, temp_int, 10);
			strcat(Parameter_Insert, temp_int);
			strcat(Parameter_Insert, ", ");

			strcat(Parameter_Insert, "\'");
			strcat(Parameter_Insert, performance_quantity_Insert);
			strcat(Parameter_Insert, "\', ");


			strcat(Parameter_Insert, "\'");
			strcat(Parameter_Insert, LOT_Insert);
			strcat(Parameter_Insert, "\'");

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
			//�۾�������� DB���� 
			if (initalizing("performance") == -1) {
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}
			print_data();
			printf("������ ������ȣ�� �Է��ϼ��� : ");
			scanf("%s", performance_num_delete);
			char select_performance_num[100] = "performance_num=";
			strcat(performance_num_del, "\'");
			strcat(performance_num_del, performance_num_delete);
			strcat(performance_num_del, "\'");
			strcat(select_performance_num, performance_num_del);
			
			if (_delete(select_performance_num) == -1) {
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
//����ó��, UI�ٵ��, ���� �Ѿ�� �ȵǰ�, %d���� �����Է��ϸ� �ȵǰ� 