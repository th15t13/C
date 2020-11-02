#include <stdio.h>
#include <Windows.h>

#pragma warning(disable:4996)

void BubbleSort(int arr[],int len){
	for (int i = 0; i < len; i++){
		for (int j = 0; j < (len-i); j++){
			int tmp = 0;
			if (arr[j]>arr[j + 1]){
				tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

void init(int arr[],int len){
	for (int i = 0; i < len; i++){
		arr[i] = 0;
	}
}

void print(int arr[], int len){
	for (int i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void reverse(int arr[], int len){
	for (int i = 0; i < (len / 2); i++){
		int tmp = 0;
		tmp = arr[i];
		arr[i] = arr[len - 1 - i];
		arr[len - 1 - i] = tmp;
	}
}

int SwapArray(int arr1[], int arr2[], int len ){
	for (int i = 0; i < len; i++){
		int tmp = 0;
		tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}
}

int main(){
	////冒泡排序
	//int arr[] = { 12, 45, 68, 46, 74, 34, 84, 42, 15, 34 };
	//int len = sizeof(arr) / sizeof(arr[0]);
	//BubbleSort(arr,len);
	//for (int i = 0; i < len; i++){
	//	printf("%d ", arr[i]);
	//}
	//printf("\n");

	////数组初始化0、打印元素、元素逆置
	//int arr1[10];
	//int len1 = sizeof(arr1) / sizeof(arr1[0]);
	//init(arr1,len1);
	//print(arr1,len1);

	//int arr2[] = { 12, 45, 68, 46, 74, 34, 84, 42, 15, 34 };
	//int len2 = sizeof(arr2) / sizeof(arr2[0]);
	//reverse(arr2,len2);
	//print(arr2, len2);

	////交换数组
	int arr1[10] = { 0 };
	int arr2[] = { 12, 45, 68, 46, 74, 34, 84, 42, 15, 34 };
	int len = sizeof(arr1) / sizeof(arr1[0]);
	SwapArray(arr1, arr2, len);
	print(arr1, len);
	print(arr2, len);

	system("pause");
	return 0;
}