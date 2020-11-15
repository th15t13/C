#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

int compareIntAsc(const void* a, const void* b){
	return (*(int*)a - *(int*)b);
}

int compareShortAsc(const void* a, const void* b){
	return (*(short*)a - *(short*)b);
}

int compareLongAsc(const void* a, const void* b){
	return (*(long*)a - *(long*)b);
}

int bubbleCompareIntAsc(const void* a, const void* b){
	return (*(int*)a - *(int*)b);
}

int bubbleCompareShortAsc(const void* a, const void* b){
	return (*(short*)a - *(short*)b);
}

int bubbleCompareLongAsc(const void* a, const void* b){
	return (*(long*)a - *(long*)b);
}

void bubbleSort(void *base, int nitems, int size, int(*compar)(const void *, const void*)){
	for (int i = 0; i < nitems - 1; i++){
		for (int j = 0; j < nitems - 1 - i;j++)
		{
				if (compar((char*)base + j*size , (char*)base + (j+1)*size) > 0)
				{
					char tmp = *((char*)base + j*size);
					*((char*)base + j*size) = *((char*)base + (j + 1)*size);
					*((char*)base + (j + 1)*size) = tmp;
				}
		}
	}
}

int main()
{
	int values[] = { 40, 10, 100, 90, 20, 25 };
	short values1[] = { 40, 10, 100, 90, 20, 25, 33 };
	long values2[] = { 40, 10, 100, 90, 20, 25, 33, 44 };
	//qsort(values, sizeof(values)/sizeof(values[0]), sizeof(int), compareInt);
	//qsort(values1, sizeof(values1) / sizeof(values1[0]), sizeof(short), compareShort);
	//qsort(values2, sizeof(values2) / sizeof(values2[0]), sizeof(long), compareLong);
	bubbleSort(values, sizeof(values) / sizeof(values[0]), sizeof(int), bubbleCompareIntAsc);
	bubbleSort(values1, sizeof(values1) / sizeof(values1[0]), sizeof(short), bubbleCompareShortAsc);
	bubbleSort(values2, sizeof(values2) / sizeof(values2[0]), sizeof(long), bubbleCompareLongAsc);
	for (int n = 0; n < sizeof(values) / sizeof(values[0]); n++)
		printf("%d ", values[n]);
	printf("\n");
	for (int n = 0; n < sizeof(values1) / sizeof(values1[0]); n++)
		printf("%d ", values1[n]);
	printf("\n");
	for (int n = 0; n < sizeof(values2) / sizeof(values2[0]); n++)
		printf("%d ", values2[n]);
	printf("\n");

	system("pause");
	return 0;
}