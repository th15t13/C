#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <assert.h>

#pragma warning(disable:4996)

int MyStrLen(char* str){
	if (str == NULL){
		return 0;
	}
	int ret = 0;
	while (*str != '\0'){
		ret++;
		str++;
	}
	return ret;
}

char *myStrStr1(char* haystack, char* needle){
	if (haystack == NULL || needle == NULL) {
		return NULL;
	}
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

const char* myStrStr(const char* haystack, const char* needle) {
	if (haystack == NULL || needle == NULL) {
		return NULL;
	}

	const char* patrolHay = haystack;
	while (*patrolHay != '\0') {
		const char* patrolNee = patrolHay;
		const char* patrolSub = needle;
		while (*patrolNee != '\0' && *patrolSub != '\0' &&
			*patrolNee == *patrolSub){
			patrolNee++;
			patrolSub++;
		}
		if (*patrolSub == '\0'){
			return patrolHay;
		}
		patrolHay++;
	}
	return NULL;
}

char* myStrCpy(char* dest, const char* src){
	if (dest == NULL || src == NULL) {
		return NULL;
	}
	while (*src != '\0'){
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return dest;
}

char* myStrCat(char* dest, const char* src){
	char* patrol = dest;
	while (*patrol != '\0'){
		patrol++;
	}
	while (*src != '\0'){
		*patrol = *src;
		src++;
		patrol++;
	}
	*patrol = '\0';
	return dest;
}

int myStrCmp(const char* str1, const char* str2){
	assert(str1 != NULL && str2 != NULL);
	int ret = 0;
	while (*str1 != '\0' && *str2 != '\0'){
		ret = *str1 - *str2;
		if (ret != 0){
			if (ret > 0){
				ret = 1;
				return ret;
			}
			if (ret < 0){
				ret = -1;
				return ret;
			}
		}
		str1++;
		str2++;
	}
	if (*str1 == '\0' && *str2 == '\0'){
		if (ret == 0){//若长度一样，且ret为零，则两字符串相等。
			return ret;
		}
	}
	if (*str1 == '\0'){
		ret = -1;
		return ret;
	}
	if (*str2 == '\0'){
		ret = 1;
		return ret;
	}
	return ret;
}

int main()
{
	//myStrStr
	//char haystack[20] = "Just a test";
	//char needle[10] = "st";
	//char notFound[10] = "notFound";
	//const char* ret;

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
	//char str2[15] = "acdef";

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