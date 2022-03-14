#include<stdbool.h>
#include "local.h"
#include "MiniProject_ERP_1struct.h"
#define True >=1
#define False 0


#pragma warning(disable:4996)


//���� ��� ���� ����ؼ� ��ȸ
int jaego_print()
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


	char Parameter_Insert[1000] = { NULL };
	char temp_int[20] = { 0 };



	if (initalizing("Jaego") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	for (int select_List = 1; select_List < 7; select_List++)
	{


		char select_num_List[100] = "num_jaego=";
		itoa(select_List, temp_int, 10);
		strcat(select_num_List, temp_int);

		if (_select(select_num_List, "num_jaego, name_item, num_item, date, chogi_item, ibgo_item, chulgo_item, jaego_item", &select_result_str) == -1) {
			printf("%s\n", err_msg);
			_getch();

			file_column_free();
			return -1;
		}

		if ((result_count = recv_result(&_result, select_result_str)) == -1) {
			printf("%s\n", err_msg);

			file_column_free();
			return -1;
		}

		//num_jaego
		itoa(*(_result->_int_data), temp_int, 10);
		strcat(Parameter_Insert, temp_int);
		strcat(Parameter_Insert, ", ");


		// name_item
		strcat(Parameter_Insert, "\'");
		strcat(Parameter_Insert, *(_result->next->_string_data));
		strcat(Parameter_Insert, "\', ");

		//num_item
		strcat(Parameter_Insert, "\'");
		strcat(Parameter_Insert, *(_result->next->next->_string_data));
		strcat(Parameter_Insert, "\', ");

		//date
		itoa(today_date, temp_int, 10);							// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
		strcat(Parameter_Insert, temp_int);						// ��ȯ�� ���ڿ��� Parameter_Insert�� ����
		strcat(Parameter_Insert, ", ");							// �������� �ǹ��ϴ� ����


		// �ʱ�������
		int chogi_data = *(_result->next->next->next->next->_int_data);
		itoa(chogi_data, temp_int, 10);
		strcat(Parameter_Insert, temp_int);
		strcat(Parameter_Insert, ", ");


		// �԰�������
		int num_InWarehouse = *(_result->next->next->next->next->next->_int_data);
		itoa(num_InWarehouse, temp_int, 10);
		strcat(Parameter_Insert, temp_int);
		strcat(Parameter_Insert, ", ");

		// ���������
		int chulgo_data = *(_result->next->next->next->next->next->next->_int_data);
		itoa(chulgo_data, temp_int, 10);
		strcat(Parameter_Insert, temp_int);
		strcat(Parameter_Insert, ", ");

		// �� ������
		int jaego_data = chogi_data + num_InWarehouse - chulgo_data;
		itoa(jaego_data, temp_int, 10);
		strcat(Parameter_Insert, temp_int);

		char update_rest_num[100] = "jaego_item=";

		if (jaego_data < 0)								//��� ���̳ʽ��� ������ ��
		{
			printf("======================================\n");
			printf("��� ������ �����ϹǷ� 0���� �ʱ�ȭ �մϴ�.");
			printf("======================================\n");
			jaego_data = 0;

			itoa(jaego_data, temp_int, 10);		// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
			strcat(update_rest_num, temp_int);

			// ��� ���� �� ������Ʈ�Ѵ�
			if (_update(select_num_List, update_rest_num) == -1)
			{
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}

		}

		itoa(jaego_data, temp_int, 10);		// �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
		strcat(update_rest_num, temp_int);

		// ��� ���� �� ������Ʈ�Ѵ�
		if (_update(select_num_List, update_rest_num) == -1)
		{
			printf("%s\n", err_msg);

			file_column_free();
			return -1;
		}

		result_free(_result, result_count);

	}
	print_data();
	system("pause");
	file_column_free();

}

//��������� ������ �ҷ��ͼ� ���� ��� ������Ʈ 
void choijong_jaego_print(char n[100])
{
    result* _result;
    result* find;
    int result_count;

    time_t timer;
    struct tm* t;
    timer = time(NULL);
    t = localtime(&timer);

    char Parameter_Insert[1000] = { NULL };
    char temp_int[20] = { 0 };
    char Select_item_num[20] = { 0 };
    char select_num_chulgoList[100] = "item_NUMBER=";


    // �������� (�� �������) ����Ʈ ��� �� ���� �޾ƿ���
    if (initalizing("Product_usage_status") == -1)
    {
        printf("%s\n", err_msg);

        file_column_free();
        return -1;
    }

 

    if (_select(select_num_chulgoList, "Amountused", &select_result_str) == -1) {

        file_column_free();
        return -1;
    }

    if ((result_count = recv_result(&_result, select_result_str)) == -1) {
        file_column_free();
        return -1;
    }

    // ����� ���緮
    int Amountused = *(_result->_int_data);
    itoa(Amountused, temp_int, 10);
    strcat(Parameter_Insert, temp_int);



    file_column_free();
    result_free(_result, result_count);

    /// ������� �ȵ�  

    if (initalizing("Jaego") == -1)
    {
        printf("%s\n", err_msg);

        file_column_free();
        return -1;
    }

    char select_numList[100] = "num_item=";
    strcat(select_numList, "\'");
    strcat(select_numList, n);
    strcat(select_numList, "\'");

    if (_select(select_numList, "chulgo_item", &select_result_str) == -1) {
        printf("%s\n", err_msg);
        system("pause");
        file_column_free();
        return -1;
    }

    if ((result_count = recv_result(&_result, select_result_str)) == -1) {
        printf("%s\n", err_msg);
        system("pause");
        file_column_free();
        return -1;
    }

    // chulgo_item
    char update_num[100] = "chulgo_item=";

    itoa(Amountused, temp_int, 10);      // �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
    strcat(update_num, temp_int);

    // ����� ���� �԰� ��� ���� �� ������Ʈ�Ѵ�
    if (_update(select_numList, update_num) == -1)
    {
        printf("%s\n", err_msg);
        file_column_free();
        return -1;
    }

    result_free(_result, result_count);
    file_column_free();

    jaego_print();

}

void choijong_jaego_print_all()
{
    choijong_jaego_print("CP10");
    choijong_jaego_print("HR10");
    choijong_jaego_print("KE10");
    choijong_jaego_print("MO10");
    choijong_jaego_print("CA10");
    choijong_jaego_print("MB10");
}

//������ �� �ִ��� Ȯ���ϴ� �Լ�
void chulgo_jaego_print()
{
    result* _result;
    result* find;
    int result_count;

    time_t timer;
    struct tm* t;
    timer = time(NULL);
    t = localtime(&timer);

    int today_date = 0;
    today_date = ((t->tm_year + 1900) * 10000) + ((t->tm_mon + 1) * 100) + (t->tm_mday);   // ���� ��¥( 20220304 �� )

    char Parameter_Insert[1000] = { NULL };
    char temp_int[20] = { 0 };
    char Select_item_num[20] = { 0 };
    char select_num_chulgoList[100] = "num_item=";


    // �����Ʈ ��� �� ���� �޾ƿ���
    if (initalizing("Jaego") == -1)
    {
        printf("%s\n", err_msg);

        file_column_free();
        return -1;
    }

    for (int select_List = 1; select_List < 7; select_List++)
    {

        char select_num_chulgoList[100] = "num_jaego=";
        itoa(select_List, temp_int, 10);
        strcat(select_num_chulgoList, temp_int);

        strcat(select_num_chulgoList, "\'");
        strcat(select_num_chulgoList, Select_item_num);
        strcat(select_num_chulgoList, "\'");

        if (_select(select_num_chulgoList, "num_jaego, name_item, num_item, date, chogi_item, ibgo_item, chulgo_item, jaego_item", &select_result_str) == -1) {
            printf("%s\n", err_msg);
            system("pause");
            file_column_free();
            return -1;
        }

        if ((result_count = recv_result(&_result, select_result_str)) == -1) {
            printf("%s\n", err_msg);
            system("pause");
            file_column_free();
            return -1;
        }


        printf("%s�� ����մϴ�\n", *(_result->next->_string_data));

        // ��� ������ �Է�
        int chulgo_data = 0;
        printf("�������� �Է��ϼ��� : ");
        scanf("%d", &chulgo_data);


        //num_jaego
        itoa(*(_result->_int_data), temp_int, 10);
        strcat(Parameter_Insert, temp_int);
        strcat(Parameter_Insert, ", ");

        // name_item
        strcat(Parameter_Insert, "\'");
        strcat(Parameter_Insert, *(_result->next->_string_data));
        strcat(Parameter_Insert, "\', ");


        //num_item
        strcat(Parameter_Insert, "\'");
        strcat(Parameter_Insert, *(_result->next->next->_string_data));
        strcat(Parameter_Insert, "\', ");


        //date
        itoa(today_date, temp_int, 10);                     // �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
        strcat(Parameter_Insert, temp_int);                  // ��ȯ�� ���ڿ��� Parameter_Insert�� ����
        strcat(Parameter_Insert, ", ");                     // �������� �ǹ��ϴ� ����


        // �ʱ�������
        int gicho_data = *(_result->next->next->next->next->_int_data);
        itoa(gicho_data, temp_int, 10);
        strcat(Parameter_Insert, temp_int);
        strcat(Parameter_Insert, ", ");


        // �԰�������
        int num_InWarehouse = *(_result->next->next->next->next->next->_int_data);
        itoa(num_InWarehouse, temp_int, 10);
        strcat(Parameter_Insert, temp_int);
        strcat(Parameter_Insert, ", ");


        //���������
        itoa(chulgo_data, temp_int, 10);
        strcat(Parameter_Insert, temp_int);
        strcat(Parameter_Insert, ", ");

        // �� ������
        int can_use_data = gicho_data + num_InWarehouse;            //���� ���� ����� �� �ִ� ���
        int jaego_data = can_use_data - chulgo_data;
        itoa(jaego_data, temp_int, 10);
        strcat(Parameter_Insert, temp_int);



        char update_num[100] = "chulgo_item=";
        char update_num_jaego[100] = "jaego_item=";


        if (jaego_data < 0 || can_use_data < chulgo_data)               //��� 0�̰ų� ��� ���� ���� ������ ���� �ؾߵȴ�
        {
            //��� ������Ʈ 

            if (jaego_data == 0)
            {
                int bujok = chulgo_data;
                printf("======================================\n");
                printf("%s�� %d�� �̻� �ʿ��մϴ�.\n", *(_result->next->_string_data), bujok);
                printf("======================================\n");

                return bujok;
            }
            else if (can_use_data < chulgo_data)
            {
                jaego_data = 0;                                    //����� ���̳ʽ� ������ �ȵǰ� 0�� �־��ش�.
                itoa(jaego_data, temp_int, 10);                        // �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
                strcat(update_num_jaego, temp_int);


                int bujok = chulgo_data - can_use_data;
                printf("======================================\n");
                printf("%s�� %d�� �̻� �ʿ��մϴ�.\n", *(_result->next->_string_data), bujok);
                printf("======================================\n");
            }

            break;
        }

        else if (can_use_data >= chulgo_data)                                          //��� ������ �� 
        {
            printf("======================================\n");
            printf("���� �����մϴ�.\n");
            printf("======================================\n");

            if (select_List == 6)
                return 5050;
        }
    }

    file_column_free();

    jaego_print();

}
void choijong_jokup_print()
{
    result* _result;
    result* find;
    int result_count;

    time_t timer;
    struct tm* t;
    timer = time(NULL);
    t = localtime(&timer);

    char Parameter_Insert[1000] = { NULL };
    char temp_int[20] = { 0 };
    char Select_item_num[20] = { 0 };
    char select_num_chulgoList[100] = "Work_Instruction_Number=";
    char work[20] = { 0 };

    // �������� (�� �������) ����Ʈ ��� �� ���� �޾ƿ���
    if (initalizing("Work_Use") == -1)
    {
        printf("%s\n", err_msg);

        file_column_free();
        return -1;
    }


 
    system("pause");

    printf("�۾��� �Է��Ͻÿ� : ");
    scanf("%s", work);

    strcat(select_num_chulgoList, "\'");
    strcat(select_num_chulgoList, work);
    strcat(select_num_chulgoList, "\'");


    if (_select(select_num_chulgoList, "Amountused", &select_result_str) == -1) {
        printf("%s\n", err_msg);
        system("pause");
        file_column_free();
        return -1;
    }

    if ((result_count = recv_result(&_result, select_result_str)) == -1) {
        printf("%s\n", err_msg);
        system("pause");
        file_column_free();
        return -1;
    }


    // ����� ���緮
    int Amountused = *(_result->_int_data);
    itoa(Amountused, temp_int, 10);
    strcat(Parameter_Insert, temp_int);


    file_column_free();
    result_free(_result, result_count);

    /// ������� �ȵ�  

    if (initalizing("Jaego") == -1)
    {
        printf("%s\n", err_msg);

        file_column_free();
        return -1;
    }


    //1��
    char select_numList[100] = "num_item='CP10'";

    if (_select(select_numList, "chulgo_item", &select_result_str) == -1) {
        printf("%s\n", err_msg);
        system("pause");
        file_column_free();
        return -1;
    }

    if ((result_count = recv_result(&_result, select_result_str)) == -1) {
        printf("%s\n", err_msg);
        system("pause");
        file_column_free();
        return -1;
    }

    // chulgo_item
    char update_num[100] = "chulgo_item=";

    itoa(Amountused, temp_int, 10);      // �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
    strcat(update_num, temp_int);

    // ����� ���� �԰� ��� ���� �� ������Ʈ�Ѵ�
    if (_update(select_numList, update_num) == -1)
    {
        printf("%s\n", err_msg);
        file_column_free();
        return -1;
    }


    //2��
    char select_numList2[100] = "num_item='HR10'";

    if (_select(select_numList2, "chulgo_item", &select_result_str) == -1) {
        printf("%s\n", err_msg);
        print_data();
        system("pause");
        file_column_free();
        return -1;
    }

    if ((result_count = recv_result(&_result, select_result_str)) == -1) {
        printf("%s\n", err_msg);
        system("pause");
        file_column_free();
        return -1;
    }

    // chulgo_item
    char update_num_1[100] = "chulgo_item=";

    itoa(Amountused, temp_int, 10);      // �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
    strcat(update_num_1, temp_int);

    // ����� ���� �԰� ��� ���� �� ������Ʈ�Ѵ�
    if (_update(select_numList2, update_num_1) == -1)
    {
        printf("dkaf");
        printf("%s\n", err_msg);
        file_column_free();
        return -1;
    }

    //3��

    char select_numList3[100] = "num_item='KE10'";

    if (_select(select_numList3, "chulgo_item", &select_result_str) == -1) {
        printf("%s\n", err_msg);
        system("pause");
        file_column_free();
        return -1;
    }

    if ((result_count = recv_result(&_result, select_result_str)) == -1) {
        printf("%s\n", err_msg);
        system("pause");
        file_column_free();
        return -1;
    }

    // chulgo_item
    char update_num2[100] = "chulgo_item=";

    itoa(Amountused, temp_int, 10);      // �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
    strcat(update_num2, temp_int);

    // ����� ���� �԰� ��� ���� �� ������Ʈ�Ѵ�
    if (_update(select_numList3, update_num2) == -1)
    {
        printf("%s\n", err_msg);
        file_column_free();
        return -1;
    }

    //4��

    char select_numList4[100] = "num_item='MO10'";

    if (_select(select_numList4, "chulgo_item", &select_result_str) == -1) {
        printf("%s\n", err_msg);
        system("pause");
        file_column_free();
        return -1;
    }

    if ((result_count = recv_result(&_result, select_result_str)) == -1) {
        printf("%s\n", err_msg);
        system("pause");
        file_column_free();
        return -1;
    }

    // chulgo_item
    char update_num3[100] = "chulgo_item=";

    itoa(Amountused, temp_int, 10);      // �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
    strcat(update_num3, temp_int);

    // ����� ���� �԰� ��� ���� �� ������Ʈ�Ѵ�
    if (_update(select_numList4, update_num3) == -1)
    {
        printf("%s\n", err_msg);
        file_column_free();
        return -1;
    }

    //5��


    char select_numList5[100] = "num_item='MB10'";

    if (_select(select_numList5, "chulgo_item", &select_result_str) == -1) {
        printf("%s\n", err_msg);
        system("pause");
        file_column_free();
        return -1;
    }

    if ((result_count = recv_result(&_result, select_result_str)) == -1) {
        printf("%s\n", err_msg);
        system("pause");
        file_column_free();
        return -1;
    }

    // chulgo_item
    char update_num4[100] = "chulgo_item=";

    itoa(Amountused, temp_int, 10);      // �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
    strcat(update_num4, temp_int);

    // ����� ���� �԰� ��� ���� �� ������Ʈ�Ѵ�
    if (_update(select_numList5, update_num4) == -1)
    {
        printf("%s\n", err_msg);
        file_column_free();
        return -1;
    }


    //6��


    char select_numList6[100] = "num_item='CA10'";

    if (_select(select_numList6, "chulgo_item", &select_result_str) == -1) {
        printf("%s\n", err_msg);
        system("pause");
        file_column_free();
        return -1;
    }

    if ((result_count = recv_result(&_result, select_result_str)) == -1) {
        printf("%s\n", err_msg);
        system("pause");
        file_column_free();
        return -1;
    }

    // chulgo_item
    char update_num5[100] = "chulgo_item=";

    itoa(Amountused, temp_int, 10);      // �޾ƿ� ������ int���̹Ƿ� ���ڿ��� ����ȯ����
    strcat(update_num5, temp_int);

    // ����� ���� �԰� ��� ���� �� ������Ʈ�Ѵ�
    if (_update(select_numList6, update_num5) == -1)
    {
        printf("%s\n", err_msg);
        file_column_free();
        return -1;
    }
    /// <summary>
    /// //////////////////////////////////
    /// </summary>
    /// <param name="n"></param>

    result_free(_result, result_count);
    file_column_free();

    jaego_print();

}