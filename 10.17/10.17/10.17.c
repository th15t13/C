#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#pragma warning(disable:4996)

void Game(){
	int random_num = rand()%100;
	int input;
	while (1){
		printf("���������֣�");
		scanf("%d", &input);
		if (input > random_num){
			printf("�´���\n");
		}
		else if (input < random_num){
			printf("��С��\n");
		}
		else{
			printf("�¶���\n");
			break;
		}
	}
}

int main()
{
	//int arr[] = { 85, 21, 33, 65, 14, 94, 54, 69, 75, 24 };
	//int max = arr[0];
	//for (int i = 0; i < 10; i++){
	//	if (arr[i]>max)
	//		max = arr[i];
	//}
	//printf("���ֵ�ǣ�%d\n", max);

	//for (int i = 1; i < 10; i++){
	//	for (int j = 1; j <= i; j++){
	//		printf("%d*%d=%d\t", j, i, i*j);
	//		if (j == i)
	//			printf("\n");
	//	}
	//}

	int option = -1;
	srand(time(0));
	while (1)
	{
		printf("***********************\n");
		printf("********1.play*********\n");
		printf("********0.exit*********\n");
		printf("***********************\n");
		scanf("%d", &option);
		if (option == 1){
			Game();
			break;
		}
		else if (option == 0){
			break;
		}
		else{
			printf("��������\n");
			Sleep(300);
			system("cls");
		}
	}

	


	system("pause");
	return 0;
}