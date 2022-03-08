#ifndef __STRUCT_H__
#define __STRUCT_H__

// ERP �ý��� �԰�ó���� ���� ����ü�� �԰��� ����

void Create_File(void);
void Init_SampleData(void);
void Insert_WarehousingData(void);
void Insert_WarehousingData_from_BuyingList(void);
void print_Warehousing_state(void);


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


	// < �԰�ó�� >
		/*
		
		���� - 1. �����԰� 2. �����԰�

		1. �����԰�
		(�����԰�� ��ȭ���ֵ����� ������ ǰ���� �԰� �Է��ϴ� ��)

		�԰�����(�Է�)
		�ŷ�ó(���� - �����κ��� �ŷ�ó����ü����Ʈ�� �޾ƿ�)
		�����(���� - �����κ��� ����� ����ü����Ʈ �޾ƿ�)
		ǰ��(���� - �����κ��� ǰ����ü����Ʈ �޾ƿ�)
		���ּ���(�Է�)
		�ܰ�(�Է�)

		------------���� �Է¹ް�,

		���ް���(�ڵ���� : ���ּ��� * �ܰ�)
		�ΰ���(�ڵ���� : ���ް� * 0.1)
		�հ��(�ڵ���� : �ΰ��� + ���ް���)

		------------�� ����ؼ� ��������� �Է� / ��� ������ ��Ŀ� �°� �����
		����ڷκ��� �Է³����� ������ �Է�(1), Ʋ����(2)�Է¹���

		�´�(1)->�԰���ü�� �� ������ ����(����)

		2. �����԰�

		1) ������Ȳ�� ���(�����κ��� ���ֱ���ü�� �޾ƿ�)�ϰ� ���⼭ � ���ֻ��׿� ���ؼ� �԰����� ����
		2) ������ ���ֻ����� � ǰ���� �԰����� �Է�
		3) �԰������ �Է�(�̶�, �԰������ �������ּ����� �Ѵ��� Ȯ��)
		4) ������� ������ ����� �´��� �����Ȯ���� ���ֱ���ü(����)�� �������ּ��������(�ʱⰪ�� ���ּ���, �԰�ɶ����� �԰������ ����)
		5) �԰���ü�� �������(����)

		*/

#endif