#include <stdio.h>
#include <windows.h>
#include <string.h>
#pragma warning(disable:4996)

//void Compare(int x, int y)
//{
//	if (x > y)
//		printf("�ϴ�����ǣ�%d\n", x);
//	else if (x < y)
//		printf("�ϴ�����ǣ�%d\n", y);
//	else
//		printf("�������\n");
//}
//
//int MyAdd(int x, int y)
//{
//	return x + y;
//}
//
//int MySub(int x, int y)
//{
//	return x - y;
//}
//
//int MyMul(int x, int y)
//{
//	return x * y;
//}
//
//int MyDiv(int x, int y)
//{
//	return x / y;
//}
//
//int main()
//{
//	int x = 0;
//	int y = 0;
//	char op = 'x';
//	while (1)
//	{
//		printf("please enter two data:\n");
//		scanf("%d %d", &x, &y);
//		//Compare(x, y);
//		printf("please enter your op <+-*/>:\n");
//		scanf(" %c", &op);
//		if (op == '+')
//		{
//			printf("%d + %d = %d\n", x, y, MyAdd(x, y));
//		}
//		else if (op == '-')
//		{
//			printf("%d + %d = %d\n", x, y, MySub(x, y));
//		}
//		else if (op == '*')
//		{
//			printf("%d + %d = %d\n", x, y, MyMul(x, y));
//		}
//		else if (op == '/')
//		{
//			if (y)
//				printf("%d + %d = %d\n", x, y, MyDiv(x, y));
//			else
//				printf("��ĸΪ��");
//		}
//		else
//		{
//			printf("�Ƿ�����!");
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}

int main()
{
	//int a = 100;
	//int *p = &a;
	//printf("a��ֵ��%d\n", *p);
	//printf("a�ĵ�ַ��0x%p\n", p);
	//*p = 200;
	//printf("�޸ĺ�a��ֵ��%d\n", a);

	//int *i = &p;
	//printf("ָ�����p�ĵ�ַ��%p\n", &p);
	//printf("ָ�����p�ĵ�ַ��%p\n", i);
	int a = 100;
	int *p = &a;
	*p = 200;
	int **q = &p;
	printf("a��ֵ��%d\n", a);
	printf("p�����ã�%d\n", *p);
	printf("q��˫�ؽ����ã�%d\n\n", **q);

	printf("a�ĵ�ַ��0x%p\n", &a);
	printf("p��ֵ��0x%p\n", p);
	printf("q�Ľ����ã�0x%p\n\n", *q);

	printf("p�ĵ�ַ��0x%p\n", &p);
	printf("q��ֵ��0x%p\n\n", q);
	

	//printf("a�ĵ�ַ��%d\n", &a);
	//printf("%d\n", *p);
	//printf("%p\n", &p);
	//printf("%p\n", *q);
	system("pause");
	return 0;
}