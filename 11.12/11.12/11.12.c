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
	for (int count = 0; count < len1 - 1; count++){//遍历所有左旋的情况
		for (int i = 0; i < 1; i++){//左旋k次和右旋len-k次得到的字符串是相同的，
			tmp = str1[0];			//因此没有必要编写右旋的代码
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
		printf("str2是str1的旋转\n");
	}
	else
	{
		printf("不是旋转\n");
	}
	

	system("pause");
	return 0;
}