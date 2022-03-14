#include "local.h"
#include"MiniProject_ERP_1struct.h"

#define SIZE 20
#pragma warning(disable : 4996)

// BOM, BOM_F, BOM_R ���̺� ����
//void Create_BOMFile() { // BOM ���̺� ����
// 
	 //BOM ���̺� ���� : BOM_Num(����), BOM_Code(ǰ���ڵ�), BOM_Name(ǰ��), BOM_Amount(����)
	//_create("BOM", "BOM_Num INT BOM_Code VARCHAR(10) BOM_Name VARCHAR(20) BOM_Amount FLOAT");
	 //BOM ������ ���̺� ���� : BOM_F_Num(����), BOM_F_Code(ǰ���ڵ�), BOM_F_Name(ǰ��), BOM_F_Material(����), BOM_F_Amount(����)
	//_create("BOM_F", "BOM_F_Num INT BOM_F_Code VARCHAR(10) BOM_F_Name VARCHAR(20) BOM_F_Material VARCHAR(20) BOM_F_Amount FLOAT");
	 //BOM ������ ���̺� ���� : BOM_R_Num(����), BOM_R_Code(ǰ���ڵ�), BOM_R_Name(ǰ��), BOM_R_Material(����), BOM_R_Amount(����)
	//_create("BOM_R", "BOM_R_Num INT BOM_R_Code VARCHAR(10) BOM_R_Name VARCHAR(20) BOM_R_Material VARCHAR(20) BOM_R_Amount FLOAT");
//
//}

// Sample ǰ�� ���̺� ����

// ��ǰ�񸶴� ���̺��� �������.
void Cre_BOM_Table(char Parent_Item[SIZE]) {

	Print_ITEM_File();

	_create(Parent_Item, "BOM_Num INT BOM_Code VARCHAR(10) BOM_Name VARCHAR(20) BOM_Amount FLOAT");

}
// BOM ���̺� ����, ǰ���ڵ带 �������� ��ǰ�����Ϳ��� ǰ���ڵ�, ǰ���� �޾ƿ��� ������ �Է�����.
void Make_BOM() {
	system("cls");

	getchar();

	result* _result;
	result* find;
	int result_count;

	//BOMFNode* Root = BOM_Create_Root_Node();
	//BOMFNode* Parent_Node;

	char Select_ITEM[10];
	char Parameter_Insert[1000] = { NULL };
	char temp_int[20] = { 0 };
	char temp_float[20] = { 0 };
	char Select_Parent[SIZE] = { NULL };
	float BOM_AMOUNT = 0; // BOM ������ �Է��ϱ� ���� ����
	int BOM_NUM = 0; // BOM ������ �Է��ϱ� ���� ����
	char Select_Cre_Table; // ���̺��� �����ϱ� ���� CMDâ���� �Է¹޴� ����

	printf("�� ��ǰ���� ����մϱ�? (Y) : ");     // ��ǰ���� �޾Ƽ� �� ���̺� ���鶧, �Ǵ� ������ ���̺��� �ʱ�ȭ �� �� 
	scanf("%c", &Select_Cre_Table);
	getchar();

	if (Select_Cre_Table == 'Y') {            // Y�� �Է��ϸ� �� ���̺��� ����� �ٸ� �Է��� ���� X

		char Parent_Item[SIZE] = { NULL };

		printf("\n");
		Print_ITEM_File();

		printf("���� ���� ���̺��� �Է��ϼ��� : ");
		scanf("%s", Parent_Item);

		Cre_BOM_Table(Parent_Item);

		//BOM_AddClidNode(Root, Parent_Item);

	}

	if (initalizing("ITEM") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	system("cls");

	printf("\n======================================= ǰ�� ��� ===========================================\n");
	print_ITEM();
	printf("\n");

	printf("��ǰ���� �������ּ��� : ");
	scanf("%s", Select_Parent);
	getchar();

	//Parent_Node = BOMF_FoundNode(Root, Select_Parent);
	//if (Parent_Node == NULL) {
	//   printf("ǰ���� �����ϴ�.\n");
	//   getch();
	//   continue;
	//}


	file_column_free();

	while (1) {

		if (initalizing(Select_Parent) == -1) {
			printf("%s\n", err_msg);

			file_column_free();

			return -1;
		}

		printf("\n");
		float Total = print_BOM_Total();
		printf("=========================================================\n");
		printf("                                 �����հ� : %.3f\n", Total);
		printf("\n");

		file_column_free();

		if (initalizing("ITEM") == -1) {
			printf("%s\n", err_msg);

			file_column_free();
			return -1;
		}

		// BOM_NUM

		while (1) {

			printf("�߰��� ������ �Է��ϼ���(1 ~ 99) : ");
			scanf("%d", &BOM_NUM);

			if (BOM_NUM > 0 && BOM_NUM < 99) break;

			else {

				printf("�ùٸ� ���� �Է����ּ���.\n");
			}
		}

		itoa(BOM_NUM, temp_int, 10);
		strcat(Parameter_Insert, temp_int);
		strcat(Parameter_Insert, ", ");

		printf("�߰��� ��ǰ���� �Է��ϼ��� : ");
		scanf("%s", Select_ITEM);
		getchar();

		//BOM_AddClidNode(Parent_Node, Select_ITEM);

		char Select_Item_Name[100] = "item_NUMBER =";
		strcat(Select_Item_Name, Select_ITEM);

		if (_select(Select_Item_Name, "item_NUMBER, item_NAME", &select_result_str) == -1) {
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

		// Item_Number
		strcat(Parameter_Insert, "\'");
		strcat(Parameter_Insert, *(_result->_string_data));
		strcat(Parameter_Insert, "\', ");

		// Item_Name
		strcat(Parameter_Insert, "\'");
		strcat(Parameter_Insert, *(_result->next->_string_data));
		strcat(Parameter_Insert, "\', ");

		// BOM_Amount
		printf("��ǰ���� ������ �Է��ϼ��� : ");
		scanf("%f", &BOM_AMOUNT);
		getchar();

		sprintf(temp_float, "%f", BOM_AMOUNT);
		strcat(Parameter_Insert, temp_float);

		file_column_free();

		if (initalizing(Select_Parent) == -1) {
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

		file_column_free();

		int Stop;

		while (1) {


			printf("\n1. ��� ���  2. ��� �Ϸ� : ");
			scanf("%d", &Stop);
			getchar();

			if (Stop == 1) break;

			else if (Stop == 2) {
				return;
			}

			else {

				printf("�ùٸ� �׸��� �Է����ּ���.\n");
				continue;
			}
		}
	}
}
// BOM ������ ���̺� ����
void Make_BOM_F(BOMFNode* Node, int Level) {

	if ((Node->LeftChild != NULL) && (Level > 0))
		Make_BOM_F(Node->LeftChild, Level- 1);

	if ((Node->RightSibling != NULL) && (Level >= 0))
		Make_BOM_F(Node->RightSibling, Level);

	if (Level == 0) {

		int i = 0;
		result* _result;
		result* find;
		int result_count;

		char Parameter_Insert[1000] = { NULL };
		char temp_int[20] = { 0 };
		char temp_float[20] = { 0 };

		char Select_Item_Name[100] = "item_NUMBER = ";
		strcat(Select_Item_Name, Node->Data);

		if (initalizing("ITEM") == -1) {
			printf("%s\n", err_msg);

			file_column_free();
			return -1;
		}

		if (_select(Select_Item_Name, "item_NUMBER, item_NAME, item_TYPE", &select_result_str) == -1) {
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

		// BOM_Num
		//BOM_F_NUM++;

		//itoa(BOM_F_NUM, temp_int, 10);
		strcat(Parameter_Insert, temp_int);
		strcat(Parameter_Insert, ", ");

		// Item_Number
		strcat(Parameter_Insert, "\'");
		strcat(Parameter_Insert, *(_result->_string_data));
		strcat(Parameter_Insert, "\', ");

		// Item_Name
		strcat(Parameter_Insert, "\'");
		strcat(Parameter_Insert, *(_result->next->_string_data));
		strcat(Parameter_Insert, "\', ");

		// Item_Type
		strcat(Parameter_Insert, "\'");
		strcat(Parameter_Insert, *(_result->next->next->_string_data));
		strcat(Parameter_Insert, "\'");

		file_column_free();

		if (initalizing("BOM") == -1) {
			printf("%s\n", err_msg);

			file_column_free();
			return -1;
		}

		char Select_BOM_CODE[100] = "BOM_Code ="; // BOM_Code = PC01
		strcat(Select_BOM_CODE, Node->Data);

		if (_select(Select_BOM_CODE, "BOM_Amount", &select_result_str) == -1) {
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

		// BOM_Amount
		strcat(Parameter_Insert, ", ");
		sprintf(temp_float,"%f", *(_result->_float_data));
		strcat(Parameter_Insert, temp_float);						
		
		file_column_free();

		if (initalizing("BOM_F") == -1) {
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


		file_column_free();
	}
}
// BOM ������ ���̺� ����(���� X)
void Make_BOM_R(BOMFNode* Node, int Level) {


}
// BOM �������� ���� Tree ���� ����
BOMFNode* BOM_Tree() {

	int i = 0;
	result* _result;
	result* find;
	int result_count;

	char Input_Child_data[SIZE] = { NULL };
	char Find_Parent_data[SIZE] = { NULL };

	int Node_Num = 0;
	int Select = 0;

	
	BOMFNode* Root = BOM_Create_Node("A");

	while (1) {

		system("cls");
		printf("1. �� �׸� ���   2. ���� �׸� ����\n");
		printf("�׸��� �����ϼ��� : ");
		scanf("%d", &Select);

		if (Select == 1) {

			if (initalizing("ITEM") == -1) {
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}

			if (_select("*", "item_NUMBER", &select_result_str) == -1) {
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

			file_column_free();

			printf("\n");
			result_print(_result, result_count);
			printf("\n");

			printf("��Ʈ�� ����� ǰ���� �Է��ϼ��� : ");
			scanf("%s", Input_Child_data);
			BOM_AddClidNode(Root, Input_Child_data);

			continue;
		}

		else if (Select == 2) {

			BOMFNode* Fine_Node;

			if (initalizing("ITEM") == -1) {
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}

			if (_select("*", "item_NUMBER", &select_result_str) == -1) {
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

			file_column_free();

			printf("\n");
			result_print(_result, result_count);
			printf("\n");

			printf("�����ų ���� ǰ���� �˻��ϼ��� : ");
			scanf("%s", Find_Parent_data);

			Fine_Node = BOMF_FoundNode(Root, Find_Parent_data);

			printf("�����Ϸ��� ����� ������ �Է��ϼ��� : ");
			scanf("%d", &Node_Num);

			for (int i = 0; i < Node_Num; i++) {

				printf("����� ǰ���� �Է��ϼ��� : ");
				scanf("%s", Input_Child_data);
				BOM_AddClidNode(Fine_Node, Input_Child_data);
			}

			continue;
		}

		else if (Select == 3)
			break;
		
		else {

			printf("�߸��� �Է��Դϴ�.\n");
			getch();

			continue;
		}

	}
	
	system("cls");

	return Root;
}
// Root ��� ����
BOMFNode* BOM_Create_Node(element Sdata[50]) {

	BOMFNode* NewNode = (BOMFNode*)malloc(sizeof(BOMFNode));
	if (NewNode == NULL) {
		printf("Memory Allocation Failed\n");

		return 0;
	}

	NewNode->LeftChild = NULL;
	NewNode->RightSibling = NULL;
	strcpy(NewNode->Data, Sdata);

	return NewNode;
}
// NewNode�� ���� �� NewData[50]�� �����͸� �޾� ���� �־���. 
void BOM_AddClidNode(BOMFNode* Parent, BOMFNode* Child) {

	if (Parent->LeftChild == NULL)
		Parent->LeftChild = Child;
	else {
		BOMFNode* TempNode = Parent->LeftChild;
		while (TempNode->RightSibling != NULL)
			TempNode = TempNode->RightSibling;
		TempNode->RightSibling = Child;
	}

}
BOMFNode* BOMF_FoundNode(BOMFNode* Node, element S_Data) {
	BOMFNode* tmp = 0;
	if (Node->Data == S_Data)
		return Node;
	if (Node->LeftChild != NULL)
		tmp = BOMF_FoundNode(Node->LeftChild, S_Data);
	if (Node->RightSibling != NULL)
		tmp = BOMF_FoundNode(Node->RightSibling, S_Data);
	return tmp;
}
// Ư�� ������ ������ ������ִ� �Լ�
void BOM_PrintNodesAtLevel(BOMFNode* Root, int Level) {

	if ((Root->LeftChild != NULL) && (Level >= 0))
		BOM_PrintNodesAtLevel(Root->LeftChild, Level - 1);

	if ((Root->RightSibling != NULL) && (Level >= 0))
		BOM_PrintNodesAtLevel(Root->RightSibling, Level);

	if (Level == 0)
	{
		printf("%s\n", Root->Data);
		return;
	}
}
// ������ ��ǰ���� �׸���� ������ִ� �Լ�
void Print_Select_BOM(){

	int i = 0;
	result* _result;
	result* find;
	int result_count;

	char Print_Parent_BOM[SIZE] = { NULL };

	if (initalizing("ITEM") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_select("*", "item_NUMBER", &select_result_str) == -1) {
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

	file_column_free();

	result_print(_result, result_count);
	printf("\n");

	printf("��ǰ���� �Է����ּ��� : ");
	scanf("%s", Print_Parent_BOM);

	if (initalizing(Print_Parent_BOM) == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	printf("\n");
	float Total = print_BOM_Total();

	printf("=========================================================\n");
	printf("                                 �����հ� : %.3f\n", Total);
	printf("\n");
	getch();

	file_column_free();

}
// ITEM ���̺� ���
void Print_ITEM_File() {

	if (initalizing("ITEM") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	printf("======================================= ǰ�� ��� ===========================================\n");
	print_ITEM();
	printf("\n");
	file_column_free();

}
