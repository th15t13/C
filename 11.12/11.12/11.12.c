#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

int isSpin(char str1[], char str2[]){
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 != len2){
		return 0;
	}
	char tmp = ' ';
	if (!strcmp(str1, str2)){
		return 1;
	}
	for (int count = 0; count < len1 - 1; count++){//�����������������
		for (int i = 0; i < 1; i++){//����k�κ�����len-k�εõ����ַ�������ͬ�ģ�
			tmp = str1[0];			//���û�б�Ҫ��д�����Ĵ���
			for (int j = 0; j < len1 - 1; j++){
				str1[j] = str1[j + 1];
			}
			str1[len1 - 1] = tmp;
		}
		if (!strcmp(str1, str2)){
			return 1;
		}
	}
		return 0;
}


int main(){

	char str1[] = "ABCDE";
	char str2[] = "CDEAB";
	//int len = sizeof(str) / sizeof(str[0]);
	//leftSpin(str, 3);
	//for (int i = 0; i < len; i++){
	//	printf("%c", str[i]);
	//}
	//printf("\n");

	if (isSpin(str1, str2)){
		printf("str2��str1����ת\n");
	}
	else
	{
		printf("������ת\n");
	}
	

	system("pause");
	return 0;
}