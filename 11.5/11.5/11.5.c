#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

void PrintArr(int arr[],int len){
	int *p = arr;
	for (int i = 0; i < len; i++){
		printf("%d ", *(p + i));
	}
	printf("\n");
}

void ReverseString(char string[]){
	int count = 0;
	char *p = string;
	int i = 0;
	while (*(p + i) != '\0'){
		i++;
	}
	for (i--; i >= 0; i--){
		printf("%c", *(p + i));
	}
	printf("\n");
}

int SnSum(int num,int* p){
	int ret = 0;
	for (int i = 0; i < 5; i++){
		ret += num;
		num = num * 10 + *p;
	}
	return ret;
}

int main(){

	//指针打印数组元素
	//int arr[5] = { 1, 2, 3, 4, 5 };
	//int len = sizeof(arr) / sizeof(arr[0]);
	//PrintArr(arr, len);

	//指针字符串逆序
	//char string[] = "just a test";
	//ReverseString(string);

	int num = 0;
	printf("请输入一个数：");
	scanf("%d", &num);
	int result = SnSum(num,&num);
	printf("Sn = %d\n", result);

	system("pause");
	return 0;
}