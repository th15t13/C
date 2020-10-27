#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

int main(){

	int a, b, c, tmp;
	scanf("%d %d %d", &a, &b, &c);
	if (b > a){
		tmp = a;
		a = b;
		b = tmp;
	}
	if (c > a){
		tmp = a;
		a = c;
		c = tmp;
	}
	if (c > b){
		tmp = b;
		b = c;
		c = tmp;
	}
	printf("从大到小排序为：%d %d %d\n",a,b,c );

	//int i = 1;
	//for (; i <= 100; i++){
	//	if (i % 3 == 0){
	//		printf("%d\n", i);
	//	}
	//}

	system("pause");
	return 0;
}