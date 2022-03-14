#ifndef __STRUCT_H__
#define __STRUCT_H__

// ERP �ý��� �԰�ó���� ���� ����ü�� �԰��� ����

void Create_File(void);
int Init_SampleData(void);
void Insert_WarehousingData(void);
void Insert_WarehousingData_from_BuyingList(void);
void print_Warehousing_state(void);
void delete_Warehousing(void);
void Insert(void);
void edit_minus_table(void);		////���� �Ѱ��ָ� ���� �ϳ��� ���� �Ѱ��ֱ�
void edit_plus_table(void);			////�԰��� ������ŭ �����ֱ�
void jaego_print1(void);			////���� ��� ���� ����ؼ� ��ȸ
int Insert_Production_Plan_File(void);
int marketing_menu();
int con_view();
void con_regi_choice();
void Del(void);
void Print_use(void);
void Product(void);
void By_work(void);
void Update_jago(viod);

typedef struct In_WareHouse					// �԰���ü
{
	int num_In_WareHouse;			// �԰����
	char name_warehouse[20];		// â���̸�
	int num_warehouse;				// â���ȣ
	char name_item[20];				// ǰ���̸�
	char num_item[20];					// ǰ���ȣ
	char LOT_number[20];			// ǰ�� ��Ʈ�ѹ�
	int date;						// �԰�¥
	char name_responsible[20];		// ������̸�
	int num_responsible;			// ����ڹ�ȣ
	int num_in;						// �԰����
	int bill;						// �ܰ�
	int pay_in;						// ���ް��� = �԰���� * �ܰ�
	int tax;						// �ΰ��� = ���ް��� * 0.1
	int pay_sum;					// �հ�� = ���ް��� + �ΰ���;
}warehouse;

typedef struct jaego					// ��� ��ȸ ����ü
{
	int num_Jaego;					// ������
	char name_item[20];				// ǰ���̸�
	char num_item[20];				// ǰ���ȣ
	char name_warehouse[20];		// â���̸�
	int num_warehouse;				// â���ȣ
	char LOT_number[20];			// ǰ�� ��Ʈ�ѹ�
	int date;						// �԰�¥
	int num_chogi_item;				// �ʱ����
	int num_in;						// �԰����
	int num_chulgo_item;			// ������
	int num_jaego_item;				// ���� ��� ����


}Jaego;

struct Buy_item						// ���� ����ü
{
	int num_buyList;				// ���ֹ�ȣ
	char name_item[20];				// ����ǰ��
	int num_item;					// ����ǰ��
	int date;						// ���ֳ�¥
	char name_responsible[20];		// ������̸�
	int num_responsible;			// ����ڹ�ȣ
	int num_buy;					// ���ּ���
	int bill;						// �ܰ�
	int pay_in;						// ���ް��� = ���ּ��� * �ܰ�
	int tax;						// �ΰ��� = ���ް��� * 0.1
	int pay_sum;					// �հ�� = ���ް��� + �ΰ���;
	int rest_num_in;				// �������ּ���(���� �԰�ɽ� ���� �԰��������� ����)
};

struct Buy_company					// �ŷ�ó����ü
{
	char name_buy_company[20];		// �ŷ�ó �̸�
	int num_buy_company;			// �ŷ�ó ��ȣ
};

struct Person_responsibe			// ����ڱ���ü
{
	char name_responsible[20];		// ������̸�
	int num_responsible;			// ����ڹ�ȣ
};

struct item							// ǰ����ü
{
	char name_item[20];				// ǰ�� ǰ��
	int num_item;					// ǰ�� ǰ��
	char State[20];					// ��������  - ������)RawMaterial, ����ǰSubsidiary, ��ǰProduct
	int Daily_Output;				// ���� ���귮
	char LOT_number[20];			// RA = ������, SU =	����ǰ, PR = ��ǰ
									// ex) 
};

typedef struct Work_Use			// ���� ���(�۾���) ����ü
{
	char work_order_num[20];	//�۾����ù�ȣ
	char Product_num[20];		// ǰ���ȣ
	char Product_name[20];		// ǰ���̸�
	int Amountused;				//������
	int Performanced_number;	//������ȣ
	char LOT[20];				//lot�ѹ�

}workuse;


typedef struct Work_process			// �۾����� �κ� 
{
	char work_order_num[20];	//�۾����ù�ȣ
	char Product_name[20];		//ǰ��
	char Product_num;			//ǰ��
	char client[10];			//�̸�
	int indicated_quantity;		//���ü���
	int performance_quantity;	//��������
	int performance_num;		//������ȣ
	char LOT[20];				//����lot�ѹ�

} Work_process;

typedef struct Work_Productwork		// ��������Ȳ(��ǰ��)
{
	int work_order_num;	//�۾����ù�ȣ(�۾����úκ�)
	int Product_num;		//ǰ���ȣ(�۾����úκ�)
	char Product_name[20];	//ǰ���̸�(�۾����úκ�)
	int LOT;				//lot��ȣ(�۾����úκ�)
	int indicated_quantity;	//���ü���=��������(�۾����úκ�)
	char item_NUMBER[20];	//��ǰ��ȣ(��ǰ��Ϻκ�)
	char item_NAME[20];		//��ǰ��
	char item_LOT[20];		//��ǰ lot��ȣ
	int Amountused;			//������(�Է�)

}Work_Productwork;

typedef struct ITEM			// ��ǰ���
{
	char item_NAME[20];		//��ǰ��
	char item_NUMBER[20];	//��ǰ��ȣ
	char item_TYPE[20];
	int item_GOAL;
	char item_LOT[20];
	char tem_SirealNUMBER[20];
}ITEM;


typedef char element;

typedef struct BOMF_Node {    // BOM Ʈ�� ������ ���� ���

	struct BOMFNode* LeftChild;
	struct BOMFNode* RightSibling;
	element Data[50];

}BOMFNode;

typedef struct bom            // BOM ���
{
	int BOM_Num;              // BOM ���� INT
	char BOM_Code;            // BOM ǰ���ڵ� VARCHAR(10)
	char BOM_Name;            // BOM ǰ�� VARCHAR(20)
	double BOM_Amount;        // BOM ���� DOUBLE

}BOM;

typedef struct BOM_Foward            // BOM ������
{

	int BOM_F_Num;                   // BOM ������ ���� INT
	char BOM_F_Code;                 // BOM ������ ǰ���ڵ� VARCHAR(10)
	char BOM_F_Name;                 // BOM ������ ǰ�� VARCHAR(20)
	char BOM_F_Material;             // BOM ������ ���� VARCHAR(10) 

}BOM_F;

typedef struct BOM_Reverse           // BOM ������
{

	int BOM_R_Num;                   // BOM ������ ���� INT
	char BOM_R_Code;                 // BOM ������ ǰ���ڵ� VARCHAR(10)
	char BOM_R_Name;                 // BOM ������ ǰ�� VARCHAR(20)
	char BOM_R_Material;             // BOM ������ ���� VARCHAR(10)

}BOM_R;


typedef struct _con {
	char con_num[10];
	int con_date;
	char client[30];
	int VAT;
	char in_charge[30];

}con;

typedef struct _con_item {
	char con_num[10];
	int NO;
	char item_num[20];
	char item_name[20];
	int due_date;
	int date_shipment;
	int amount;
	int unit_price;
	int supply_price;
	int tax;
	int total_price;
}con_item;

void createTable();
void Create_BOMFile();
void Cre_BOM_Table();
void Cre_Sampleitem();
void Make_BOM();
void Make_BOM_F(BOMFNode*, int);
void Make_BOM_R(BOMFNode*, int);
BOMFNode* BOM_Tree();
BOMFNode* BOM_Create_Node();
void BOM_AddClidNode(BOMFNode*, element);
void BOM_PrintNodesAtLevel(BOMFNode*, int);
BOMFNode* BOMF_FoundNode(BOMFNode*, element);
void Print_ITEM_File();
float print_BOM_Total();
void Print_Select_BOM();

#endif