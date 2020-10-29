#include <stdio.h>
#include <windows.h>
#include <string.h>
#pragma warning(disable:4996)

//void Compare(int x, int y)
//{
//	if (x > y)
//		printf("较大的数是：%d\n", x);
//	else if (x < y)
//		printf("较大的数是：%d\n", y);
//	else
//		printf("两数相等\n");
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
//				printf("分母为零");
//		}
//		else
//		{
//			printf("非法输入!");
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
	//printf("a的值：%d\n", *p);
	//printf("a的地址：0x%p\n", p);
	//*p = 200;
	//printf("修改后a的值：%d\n", a);

	//int *i = &p;
	//printf("指针变量p的地址：%p\n", &p);
	//printf("指针变量p的地址：%p\n", i);
	int a = 100;
	int *p = &a;
	*p = 200;
	int **q = &p;
	printf("a的值：%d\n", a);
	printf("p解引用：%d\n", *p);
	printf("q的双重解引用：%d\n\n", **q);

	printf("a的地址：0x%p\n", &a);
	printf("p的值：0x%p\n", p);
	printf("q的解引用：0x%p\n\n", *q);

	printf("p的地址：0x%p\n", &p);
	printf("q的值：0x%p\n\n", q);
	

	//printf("a的地址：%d\n", &a);
	//printf("%d\n", *p);
	//printf("%p\n", &p);
	//printf("%p\n", *q);
	system("pause");
	return 0;
}