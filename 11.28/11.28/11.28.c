#include <stdio.h>
#include <windows.h>

#define swapBit(num) ((num & 0x55555555) << 1 ) | ((num & 0xaaaaaaaa) >> 1 )


int main(){

	int num = 0xb3;
	printf("0x%x\n",swapBit(num));

	system("pause");
	return 0;
}