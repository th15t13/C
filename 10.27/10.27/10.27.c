#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

int MyStrlen(char* str){
	int ret = 0;
	while (*str != '\0'){
		ret++;
		str++;
	}
	return ret;
}

int MyStrlenRec(char* str){
	if (*str != '\0'){
		return 1+MyStrlenRec(str + 1);
	}
	else{
		return 0;
	}
}

void reverse_string(char * string){
	if (*string != '\0'){
		reverse_string(string+1);
		printf("%c", *string);
	}
}

int DigitSum(int n){
	if (n > 9){
		return (n % 10) + DigitSum(n / 10);
	}
	else
		return n;
}

int Power(int n, int k){
	if (k > 0){
		return n*Power(n, k - 1);
	}
	else{
		return 1;
	}
}

int Fibonacci(int n){
	int num1 = 1;
	int num2 = 1;
	int tmp = 0;
	if ((n == 1) || (n == 2)){
		return 1;
	}
	if (n > 2){
		for (int i = 3; i <= n; i++){
			tmp = num2;
			num2 += num1;
			num1 = tmp;
			tmp = 0;
		}
	}
	return num2;
}

int FibonacciRec(int n){
	int num1 = 1;
	int num2 = 1;
	int tmp = 0;
	if ((n == 1) || (n == 2)){
		return 1;
	}
	if (n > 2){
		return FibonacciRec(n - 1)+FibonacciRec(n - 2);
	}
}


int main(){

	////strlen递归非递归实现
	//char arr[] = "just a test";
	//printf("%d\n", strlen(arr));
	//printf("%d\n", MyStrlen(arr));
	//printf("%d\n", MyStrlenRec(arr));

	char arr[] = "just a test";
	printf("%s\n",arr);
	reverse_string(arr);
	printf("\n");

	////每位数之和
	//int n = 1729;
	//n = DigitSum(n);
	//printf("%d\n", n);

	////n的k次方
	//int n, k;
	//printf("请输入n和k# ");
	//scanf("%d %d", &n, &k);
	//printf("%d\n", Power(n, k));

	////斐波那契数列
	//int n;
	//printf("请输入n# ");
	//scanf("%d", &n);
	//printf("%d\n", Fibonacci(n));
	//printf("%d\n", FibonacciRec(n));

	system("pause");
	return 0;
}