#pragma warning(disable:4996)


int marketing_menu() {
	int choice = 0;
	printf("\n ==== < ���ϴ� �޴����� > ====\n\n");
	printf("\t1. ���ֵ�� \n\t2. ������Ȳ\n\t0. �ڷΰ���\n");
	scanf("%d", &choice);
	getchar();

	return choice;
}