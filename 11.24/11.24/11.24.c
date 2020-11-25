#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int myAtoi(const char* str){
	assert(str != NULL);
	const char* p = str;
	int ret = 0;
	int flag = 0;
	while (*p != '\0'){
		if (*p >= '0' && *p <= '9'){
			flag = 1;
			ret = ret * 10 + (int)(*p - '0');
		}
		p++;
		if ((*p < '0' || *p > '9') && flag == 1 ){
			return ret;
		}
	}
	return ret;
}

char* myStrncpy(char* destination, const char* source, size_t num){
	assert(destination != NULL && source != NULL);
	const char* pSrc = source;
	char *pDest = destination;
	size_t i = 0;
	for (; i < num && *pSrc != '\0'; i++){
		*pDest = *pSrc;
		pSrc++;
		pDest++;
	}
	if (i < num && *pSrc == '\0'){
		while (i < num){
			*pDest = '0';
			pDest++;
			i++;
		}
	}
	return destination;
}

int* lonelyNum(const int* arr,int size,int* ret){
	assert(arr != NULL && ret != NULL);
	int currentNum = 0;
	int count = 0;
	const int* pArr = arr;
	int* p = ret;
	for (int i = 0; i < size; i++){
		currentNum = *(pArr + i);
		for (int j = 0; j < size; j++){
			if (currentNum == *(pArr + j)){
				count++;
			}
		}
		if (count == 1){
			*p = currentNum;
			p++;
		}
		count = 0;
	}
	return ret;
}

int main(){

	//myAtoi
	//char arr1[] = "123456";
	//char arr2 [] = "a123b456";
	//printf("%d\n", myAtoi(arr1));
	//printf("%d\n", myAtoi(arr2));

	//myStrncpy
	//char source[] = "abcdef";
	//char destination[] = "ghijklmn";
	//printf("%s\n", myStrncpy(destination, source, 3));
	//printf("%s\n", myStrncpy(destination, source, 7));

	//lonelyNum
	int test[] = { 22, 33, 33, 44, 44, 55, 55, 66, 77, 77, 88, 88 };
	int result[1024];
	lonelyNum(test, sizeof(test) / sizeof(test[0]), result);
	printf("%d %d\n", result[0], result[1]);

	system("pause");
	return 0;
}