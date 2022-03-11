#include "product.h"

int main()
{
	int select;
	initCreate();
	initSampledata();

	while (1) {
		printf("(1)작업실적등록 (2)생산품창고입고처리 : ");
		scanf("%d", &select);
		switch (select) {
		case 1:
			Registration_work_performance();
			break;
		case 2: Production_warehousing();
			break;

		}
	}
}