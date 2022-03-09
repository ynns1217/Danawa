#include "local.h"
#include"MiniProject_ERP_struct_warehousing.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)



int main(void)
{
	result* _result;
	result* find;
	int result_count;
	warehouse WH;

	time_t timer;
	struct tm* t;
	timer = time(NULL);
	t = localtime(&timer);

	int today_date = 0; 
	today_date = ((t->tm_year + 1900)*10000) + ((t->tm_mon + 1) * 100) + (t->tm_mday);	// ���� ��¥( 20220304 �� )

	// printf("%d", today_date);

	//���̺���� �� �ʱⵥ���� ����
	Create_File();												// ���ϻ����Լ� ( MiniProject_ERP_initSampleData �� ���� - ������ ������� )
	Init_SampleData();				// ���ϳ��ο� ��������(�ʱ�����)�� insert�ϴ� �Լ� ( MiniProject_ERP_initSampleData �� ���� - ������ ������� )
	
	//========================================= ����� ===========================================


	while (1)
	{
		int Select = 0;
		printf("�޴�����\n���ϴ� �޴�����\n");
		printf("1. ����\t2. �԰�\t3. �ڷΰ���\n");
		scanf("%d", &Select);
		
		if (Select == 1) // ����
		{
			while (1)
			{
				int Select_balju = 0;
				printf("���ָ޴��Դϴ�.\n ���ϴ� �޴��� �������ּ���\n");
				printf("1. ���ֵ��\t2. ������ȸ\t3. ���ֻ���\t4. �ڷΰ���\n");
				scanf("%d", &Select_balju);

				if (Select_balju == 1) //���ֵ��
				{
					insertOrderData();
				}
				else if (Select_balju == 2)// ������ȸ
				{
					orderList();
				}
				else if (Select_balju == 3) //���ֻ���
				{
					deleteOrderData();
				}
				else if (Select_balju == 4) //�ڷΰ���
				{
					break;
				}
				else
				{
					printf("�߸��� �Է°��Դϴ�.\n");
				}
			}
		}
		else if (Select == 2)	// �԰�
		{

			while (1)
			{
				int Select_ibgo = 0;
				printf(" �԰�޴��Դϴ�.\n ���Ͻô� �޴��� �������ּ��� : \n\n");
				printf("1. �����԰�\t2. �����԰�\t3. �԰���Ȳ\t4. �ڷΰ���\n");
				scanf("%d", &Select_ibgo);
				//getchar();

				if (Select_ibgo == 1)	// 1.�����԰�
				{
					Insert_WarehousingData();
				}

				else if (Select_ibgo == 2)	// 2.�����԰�
				{
					Insert_WarehousingData_from_BuyingList();
				}

				else if (Select_ibgo == 3)	// 3.�԰���Ȳ
				{
					print_Warehousing_state();
					break;
				}

				else if (Select_ibgo == 4)	// 4.�ڷΰ���
				{
					printf("���� �޴��� ���ư��ϴ�.");
					break;
				}
				else
				{
					printf("�߸��� ���Դϴ�.\n");
				}
			}
		}
		else if (Select == 3)	// �ڷΰ���
		{
			break;
		}
		else
		{
			printf("�߸��� �Է°� �Դϴ�\n");
		}
	}


	 file_column_free();

	return 0;
}

//if (_insert("'Warehouse1', 1999, 'SampleItem1', 19999, 20220304, 'SamplePerson1', 199, 99, 100, 0, 0, 0") == -1)
//{
//	printf("%s\n", err_msg);
//
//	file_column_free();
//	return -1;
//}