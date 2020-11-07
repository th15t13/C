#include <stdio.h>
#include <Windows.h>

#pragma warning(disable:4996)

int main(){
	
	//不同位个数
	//int a = 0;
	//int b = 0;
	//int result = 0;
	//int count = 0;
	//printf("请输入两个数# ");
	//scanf("%d %d", &a, &b);
	//result = a ^ b;
	//while (result){
	//	if (result & 1 == 1){
	//		count++;
	//	}
	//	result >>= 1;
	//}
	//printf("%d\n", count);

	//打印奇数位和偶数位
	//int a = 0;
	//int b = 0;
	//printf("请输入一个数# ");
	//scanf("%d", &a);
	//b = a;
	////打印奇数位
	//printf("奇数位：");
	//while (b != 0){
	//	printf("%d ", b & 1);
	//	b >>= 2;
	//}
	//printf("\n偶数位：");
	//b = a;
	////打印偶数位
	//b >>= 1;
	//while (b != 0){
	//	printf("%d ", b & 1);
	//	b >>= 2;
	//}
	//printf("\n");

	//1的个数
	int a = 0;
	int count = 0;
	printf("请输入一个数# ");
	scanf("%d", &a);
	while (a){
		if (a & 1 == 1){
			count++;
		}
		a >>= 1;
	}
	printf("%d\n", count);

	//交换两数（不创建临时变量）
	//int a = 0;
	//int b = 0;
	//printf("请输入两个数# ");
	//scanf("%d %d", &a, &b);
	//printf("交换前：%d %d\n", a, b);
	//a = a ^ b;
	//b = a ^ b;
	//a = a ^ b;
	//printf("交换后：%d %d\n", a, b);

	system("pause");
	return 0;
}