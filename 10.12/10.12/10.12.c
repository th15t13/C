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
		printf("û�ҵ�\n");
		return NOT_FOUND;
}

int main(){
	////���Լ��
	//int a, b, min, result;
	//printf("��������������#");
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
	//printf("���Լ���ǣ�%d\n",result);
	//
	////����
	//int year = 1000;
	//for (; year <= 2000; year++){
	//	if (year % 4 == 0 && year % 100 != 0){
	//		printf("%d\n", year);
	//	}
	//}

	//���Ч����תȦЧ��������ʱ��������
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

	//�۰����
	//int arr[] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 100 };
	//int num = sizeof(arr) / sizeof(arr[0]);
	//int index = NOT_FOUND;
	//int val;
	//printf("������Ҫ���ҵ�ֵ# ");
	//scanf("%d", &val);
	//index = BinSearch(arr, num, val);
	//if (index !=NOT_FOUND)
	//	printf("�ҵ�Ԫ���±�Ϊ��%d\n", index);

	//��¼
	char name[64];
	char passwd[64];
	int num = 3;
	int count = 5;

	while (1){
		printf("�������û���# ");
		scanf("%s", name);
		printf("����������# ", passwd);
		scanf("%s", passwd);
		num--;
		if (strcmp(name, NAME) == 0 && strcmp(passwd, PASSWD) == 0){
			Spinning();
			printf("\r��¼�ɹ�!\n");
			break;
		}
		else{
			if (num != 0){
				printf("�㻹ʣ%d�λ���!\n\n", num);
			}
			else{
				num = 1;
				for (; count >= 0; count--){
					printf("%d������³��Ե�¼��\r", count);
					Sleep(1000);
				}
				printf("\n\n");
				count = 5;	
			}
		}
	}
	
	//�׳����
	//int num;
	//printf("����������# ");
	//scanf("%d", &num);
	//printf("�׳���ͽ��Ϊ��%d\n", FactSum(num));

	system("pause");
	return 0;
}