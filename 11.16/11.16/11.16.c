#include <stdio.h>
#include <string.h>
#include <windows.h>

#pragma warning(disable:4996)

char* myStrStr(char* haystack, char* needle){
	char* ret = NULL;
	for (int i = 0; i < (int)strlen(haystack); i++){
		if (*(haystack + i) == *needle){
			ret = haystack + i;
			for (int j = 0; j < (int)strlen(needle); j++){
				if (*(haystack + i + j) != *(needle + j)){
					ret = NULL;
				}
			}
		}
		if (ret != NULL){
			break;
		}
	}
	return ret;
}

char* myStrCpy(char* dest, char* src){
	for (int i = 0; i <= (int)strlen(src); i++){
		*(dest + i) = *(src + i);
	}
	return dest;
}

int myStrCmp(char* str1, char* str2){
	int ret = 0;
	int i = 0;
	while (*(str1 + i) != '\0' && *(str2 + i) != '\0'){
		ret += *(str1 + i) - *(str2 + i);
		i++;
	}
	if (*(str1 + i) == '\0'){
		while (*(str2 + i) != '\0')
		{
			ret += *(str2 + i);
			i++;
		}
	}
	if (*(str2 + i) == '\0'){
		while (*(str1 + i) != '\0')
		{
			ret += *(str1 + i);
			i++;
		}
	}
	if (ret > 0){
		ret = 1;
	}
	if (ret < 0){
		ret = -1;
	}
	if (ret == 0){
		ret = 0;
	}
	return ret;
}

char* myStrCat(char* dest, const char* src){
	int i = 0;
	while (*(dest + i) != '\0'){
		i++;
	}
	for (int j = 0; j <= (int)strlen(src); j++){
		*(dest + i + j) = *(src + j);
	}
	return dest;
}

int main()
{
	//myStrStr
	//char haystack[20] = "Just a test";
	//char needle[10] = "st";
	//char notFound[10] = "notFound";
	//char *ret;

	//ret = myStrStr(haystack, needle);
	//printf("子字符串是： %s\n", ret);

	//ret = myStrStr(haystack, notFound);
	//printf("子字符串是： %s\n", ret);

	//myStrcpy
	//char src[40] = " ";
	//char dest[100] = " ";

	//myStrCpy(src, "Just a test");
	//printf("src：%s\n", src);
	//myStrCpy(dest, src);
	//printf("dest：%s\n", dest);

	//myStrCmp
	//char str1[15] = "abcdef";
	//char str2[15] = "ABCDEF";

	//printf("strcmp返回值:%d\n", strcmp(str1, str2));
	//printf("myStrCmp返回值:%d\n", myStrCmp(str1, str2));
	//if (myStrCmp(str1, str2) < 0)
	//{
	//	printf("str1 小于 str2\n");
	//}
	//else if (myStrCmp(str1, str2) > 0)
	//{
	//	printf("str1 大于 str2\n");
	//}
	//else
	//{
	//	printf("str1 等于 str2\n");
	//}

	//myStrCat
	char src[50] = "This is source";
	char dest1[50] = "This is destination";
	char dest2[50] = "This is destination";

	printf("strcat：|%s|\n", strcat(dest1, src));
	printf("myStrCat：|%s|\n", myStrCat(dest2, src));

	system("pause");
	return 0;
}