#include <stdio.h>
#include <Windows.h>

#pragma warning(disable:4996)

int main(){
	
	//��ͬλ����
	//int a = 0;
	//int b = 0;
	//int result = 0;
	//int count = 0;
	//printf("������������# ");
	//scanf("%d %d", &a, &b);
	//result = a ^ b;
	//while (result){
	//	if (result & 1 == 1){
	//		count++;
	//	}
	//	result >>= 1;
	//}
	//printf("%d\n", count);

	//��ӡ����λ��ż��λ
	//int a = 0;
	//int b = 0;
	//printf("������һ����# ");
	//scanf("%d", &a);
	//b = a;
	////��ӡ����λ
	//printf("����λ��");
	//while (b != 0){
	//	printf("%d ", b & 1);
	//	b >>= 2;
	//}
	//printf("\nż��λ��");
	//b = a;
	////��ӡż��λ
	//b >>= 1;
	//while (b != 0){
	//	printf("%d ", b & 1);
	//	b >>= 2;
	//}
	//printf("\n");

	//1�ĸ���
	int a = 0;
	int count = 0;
	printf("������һ����# ");
	scanf("%d", &a);
	while (a){
		if (a & 1 == 1){
			count++;
		}
		a >>= 1;
	}
	printf("%d\n", count);

	//������������������ʱ������
	//int a = 0;
	//int b = 0;
	//printf("������������# ");
	//scanf("%d %d", &a, &b);
	//printf("����ǰ��%d %d\n", a, b);
	//a = a ^ b;
	//b = a ^ b;
	//a = a ^ b;
	//printf("������%d %d\n", a, b);

	system("pause");
	return 0;
}