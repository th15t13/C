#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

int main(){
	//int arr[] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 100 };
	//int toFind = 42;
	//int left = 0;
	//int right = (sizeof(arr) / sizeof(arr[0]))-1;
	//while (left <= right){
	//	int mid = (left + right) / 2;
	//	if (toFind > arr[mid]){
	//		left = mid + 1;
	//	}
	//	else if (toFind < arr[mid]){
	//		right = mid - 1;
	//	}
	//	else{
	//		printf("找到了，下标为：%d\n", mid);
	//		break;
	//	}
	//		
	//}
	//if (left>right)
	//	printf("没找着\n");

	char *p = "hello";
	printf("%d\n", sizeof (p));
	
	system("pause");
	return 0;
}