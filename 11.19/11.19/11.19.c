#define  _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* myMemcpy(void* dest, const void* src, size_t num){
	assert(dest != NULL && src != NULL);
	char* pSrc = (char*)src;
	char* pDest = (char*)dest;
	for (size_t i = 0; i < num; i++){
		*(pDest + i) = *(pSrc + i);
	}
	return dest;
}

void* myMemmove(void* dest, const void* src, size_t num) {
	assert(dest != NULL && src != NULL);
	char* pDest = (char*)dest;
	char* pSrc = (char*)src;
	if (pSrc < pDest && pDest < pSrc + num){
		for (size_t i = 0; i < num; i++){
			*(pDest + i) = *(pSrc + i);
		}
		return dest;
	}
	else{
		return myMemcpy(dest, src, num);
	}
}


int main(){

	int arr1[4] = { 1, 2, 3, 4 };
	int arr2[4] = { 0 };
	myMemcpy(arr2, arr1, sizeof(arr1));
	for (int i = 0; i < 4; i++) {
		printf("%d\n", arr2[i]);
	}

	system("pause");
	return 0;
}