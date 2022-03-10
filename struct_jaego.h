#ifndef __STRUCT_H__
#define __STRUCT_H__


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