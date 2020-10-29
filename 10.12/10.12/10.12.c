#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)
#define NOT_FOUND -1
#define NAME "TOM"
#define PASSWD "1234"

void Spinning(){
	char sign[] = "|/-\\";
	int i = 0;
	while (i<=3){
		printf("%c\r", sign[i]);
		i++;
		Sleep(300);
	}
}

int Fact(int num){
	int result = 1;
	for (; num >= 1;num--){
		result *= num;
		}
	return result;
}

int FactSum(num){
	int result = 1;
	for (;num>=1;num--){
		result += Fact(num);
	}
	return result;
}

int BinSearch(int arr[], int num, int target){
	int left = 0;
	int right = num - 1;
	
	while (left <= right){
		int mid = (left + right) / 2;
		if (target < arr[mid]){
			right = mid - 1;
		}
		else if (target > arr[mid]){
			left = mid + 1;
		}
		else
			return mid;
	}
		printf("没找到\n");
		return NOT_FOUND;
}

int main(){
	////最大公约数
	//int a, b, min, result;
	//printf("请输入两个整数#");
	//scanf("%d %d",&a,&b);
	//if (a > b){
	//	min = b;
	//}
	//else
	//	min = a;
	//for (; min >= 1; min--){
	//	if (a%min == 0 && b%min == 0){
	//		result = min;
	//		break;
	//	}
	//}
	//printf("最大公约数是：%d\n",result);
	//
	////闰年
	//int year = 1000;
	//for (; year <= 2000; year++){
	//	if (year % 4 == 0 && year % 100 != 0){
	//		printf("%d\n", year);
	//	}
	//}

	//汇聚效果、转圈效果、倒计时、进度条
	//char content[] = "hello world,hello mate";
	//char label[] = "######################";
	//int start = 0;
	//int end = strlen(label)-1;

	//char sign[] = "|/-\\";

	//int i = 0;
	//int perc = 0;

	//char count[] = "3210";
	
	//printf("%s\r", label);
	//for (; start <= end; start++,end--){
	//	label[start] = content[start];
	//	label[end] = content[end];
	//	printf("%s\r", label);
	//	Sleep(300);
	//}
	//printf("\n");

	//while (perc<=100){
	//	if (perc<10)
	//		printf("\b#%d",perc);
	//	else
	//		printf("\b\b#%d", perc);
	//	perc++;
	//	Sleep(200);
	//}
	//printf("\n");

	//while (i<=3){
	//	printf("%c\r", count[i]);
	//	i++;
	//	Sleep(1000);
	//}
	//printf("\n");

	//折半查找
	//int arr[] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 100 };
	//int num = sizeof(arr) / sizeof(arr[0]);
	//int index = NOT_FOUND;
	//int val;
	//printf("请输入要查找的值# ");
	//scanf("%d", &val);
	//index = BinSearch(arr, num, val);
	//if (index !=NOT_FOUND)
	//	printf("找到元素下标为：%d\n", index);

	//登录
	char name[64];
	char passwd[64];
	int num = 3;
	int count = 5;

	while (1){
		printf("请输入用户名# ");
		scanf("%s", name);
		printf("请输入密码# ", passwd);
		scanf("%s", passwd);
		num--;
		if (strcmp(name, NAME) == 0 && strcmp(passwd, PASSWD) == 0){
			Spinning();
			printf("\r登录成功!\n");
			break;
		}
		else{
			if (num != 0){
				printf("你还剩%d次机会!\n\n", num);
			}
			else{
				num = 1;
				for (; count >= 0; count--){
					printf("%d秒后重新尝试登录！\r", count);
					Sleep(1000);
				}
				printf("\n\n");
				count = 5;	
			}
		}
	}
	
	//阶乘求和
	//int num;
	//printf("请输入数字# ");
	//scanf("%d", &num);
	//printf("阶乘求和结果为：%d\n", FactSum(num));

	system("pause");
	return 0;
}