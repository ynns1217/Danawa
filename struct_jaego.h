#ifndef __STRUCT_H__
#define __STRUCT_H__

// 재고조회에 사용될 구조체

void Create(void);
void Init_SampleData(void);
void Insert(void);
void edit_minus_table(void);		////생산 넘겨주며 수량 하나씩 빼고 넘겨주기
void edit_plus_table(void);			////입고한 수량만큼 더해주기
void jaego_print1(void);			////최종 재고 수량 출력해서 조회


typedef struct jaego					// 재고 조회 구조체
{
	int num_Jaego;					// 재고순번
	char name_warehouse[20];		// 창고이름
	int num_warehouse;				// 창고번호
	char name_item[20];				// 품목이름
	char num_item[20];				// 품목번호
	char LOT_number[20];			// 품목 루트넘버
	int date;						// 입고날짜
	char name_responsible[20];		// 담당자이름
	int num_responsible;			// 담당자번호
	int num_chogi_item;				// 초기수량
	int num_in;						// 입고수량
	int num_chulgo_item;			// 출고수량
	int num_jaego_item;				// 최종 재고 수량


}Jaego;

#endif