#ifndef __STRUCT_H__
#define __STRUCT_H__


typedef struct jaego					// ��� ��ȸ ����ü
{
	int num_Jaego;					// ������
	char name_warehouse[20];		// â���̸�
	int num_warehouse;				// â���ȣ
	char name_item[20];				// ǰ���̸�
	char num_item[20];				// ǰ���ȣ
	char LOT_number[20];			// ǰ�� ��Ʈ�ѹ�
	int date;						// �԰�¥
	char name_responsible[20];		// ������̸�
	int num_responsible;			// ����ڹ�ȣ
	int num_chogi_item;				// �ʱ����
	int num_in;						// �԰����
	int num_chulgo_item;			// ������
	int num_jaego_item;				// ���� ��� ����


}Jaego;

#endif