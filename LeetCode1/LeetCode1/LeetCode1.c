#include <stdio.h>
#include <Windows.h>

#pragma warning (disable:4996)

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	for (int i = 0; i < numsSize; i++){
		for (int j = (i + 1); j < numsSize; j++){
			if (*(nums + i) + *(nums + j) == target){
				int *ret = (int *)malloc(sizeof(int)* 2);
				*ret = i;
				*(ret + 1) = j;
				*returnSize = 2;
				return ret;
			}
		}
	}
	*returnSize = 2;
	return NULL;
}

int main(){

	int arr[] = { 2, 7, 11, 15 };
	//int arr1[2] = { 0 };
	int returnSize = -1;
	int* p = &returnSize;
	int* result = twoSum(arr, 4, 9, p);
	printf("%d %d\n", *result, *(result + 1));
	
	system("pause");
	return 0;
}