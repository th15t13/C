#include <stdio.h>
#include <Windows.h>
#include <math.h>
#pragma warning(disable:4996)

void Prime(){
	for (int num = 101; num < 201; num+=2){//偶数必定不为素数
		if (((num + 1) % 6 == 0) || ((num - 1) % 6 == 0)){
			//大于等于5的质数一定和6的倍数相邻
			for (int i=(num-1); i > 1; i--){
				if (num % i == 0){
					break;
				}
				if (i == 2){
					printf("%d\n", num);
				}
			}
		}
	}
}

void LeapYear(){
	int year;
	printf("请输入一个年份#");
	scanf("%d", &year);
	if (year % 4 == 0){
		if (year % 100 == 0){
			if (year % 400 == 0){
				printf("是闰年\n");
			}
			else{
				printf("不是闰年\n");
			}
		}
		else
			printf("是闰年\n");
	}
	else
		printf("不是闰年\n");
}

void Swap(int* num1,int* num2){//int*是定义整形指针；num1是指针本身，也就是地址

	int tmp = 0;
	printf("*num1解引用:%d\n", *num1);//*num1是解引用
	printf("num1地址:0x%x\n", num1);//num1是指针本身，也就是地址
	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;

}

void MulTable(int num){
	for (int i = 1; i <= num; i++){
		for (int j =1; j <= i; j++)
			printf("%d*%d=%d\t", i, j, i*j);
		printf("\n");
	}
}

int PrintPlace(int num){
	if (num > 0){
		printf("%d\n", num % 10);
		return PrintPlace(num / 10);
	}
}

void PrintPlace1(int num){
	if (num > 9){
		PrintPlace1(num / 10);
	}
	printf("%d\n", num % 10);

}

int Factorial(int num){
	int result=1;
	if (num == 0){
		return result;
	}
	else{
		for (int i = num; i >= 1; i--){
			result *= i;
		}
	}
	return result;
}

int RecFact(int num){
	int result = 1;
	if (num == 0){
		return result;
	}
	else
		return num*RecFact(num - 1);
}

int main(){

	//int num;
	//printf("请输入一个数#");
	//scanf("%d",&num);
	//PrintPlace1(num);
	int num1 = 10;
	int num2 = 20;
	int *p = &num1;
	int *q = &num2;
	printf("before:%d %d\n", num1, num2);
	Swap(p,q);
	printf("after:%d %d\n", num1, num2);

	system("pause");
	return 0;
}