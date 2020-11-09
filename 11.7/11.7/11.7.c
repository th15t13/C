#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

int drinkSoda(int money){
	int amount = 0;
	int emptyBottles = 0;
	for (; money > 0; amount++){
		money--;
		emptyBottles++;
		if (emptyBottles == 2){
			emptyBottles = 0;
			money++;
		}
	}
	return amount;
}


int main(){

	int money = 20;
	int amount = drinkSoda(money);
	printf("%d元可以喝%d瓶汽水\n",money,amount);

	system("pause");
	return 0;
}
