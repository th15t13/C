#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

int main()
{
	//int a = 100;
	//for (; a <= 200; a++){
	//	int b = a-1;
	//	for (; b > 1;b--){
	//		if (a%b == 0){
	//			break;
	//		}
	//	}
	//	if (b == 1){
	//		printf("%d\n", a);
	//	}
	//}
	//int count = 0;
	//for (int i = 1; i <= 100; i++){
	//	if (i % 10 == 9){
	//		count++;
	//	}
	//	if (i / 10 == 9){
	//		count++;
	//	}
	//}
	//printf("%d\n", count);

	double result = 0;
	for (int i = 1; i <= 100; i++){
		if (i % 2 != 0){
			result += 1 / (double)i;
		}
		else{
			result -= 1 / (double)i;
		}
	}
	printf("%f\n", result);

	system("pause");
	return 0;
}