#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

int combination(m, n){//组合数公式的实现
	int ret = 0;
	int numerator = m;
	int denominator = n;
	if (n == 0){
		ret = 1;
		return ret;
	}
	for (; n > 1; n--,m--){
		numerator = numerator*(m - 1);
		denominator = denominator*(n - 1);
	}
	ret = numerator / denominator;
	return ret;
}

void yangHuiTriangle(int row){
	for (int i = 1; i <= row; i++){
			for (int j = 0; j <= i - 1; j++){
				printf("%d\t", combination(i - 1, j));//利用组合数公式算三角中每一项的值
			}
			printf("\n");
	}
}

int checkData(int* p){
	int tmp[6] = { 0 };
	for (int i = 0; i < 5; i++){
		if (tmp[p[i]]){
			return 0;
		}
		tmp[p[i]] = 1;
	}
	return 1;
}


int main(){

	//int row = 7;
	//yangHuiTriangle(row);

	//猜凶手
	//int murderer[4] = { 0 };
	//for (int i = 0; i < 4; i++){
	//	murderer[i] = 1;
	//	if ((murderer[0] != 1) + (murderer[2] == 1) + 
	//		(murderer[3] == 1) + (murderer[3] != 1) == 3){
	//		printf("the murderer is %c\n", 'A' + i);
	//		break;
	//	}
	//	else{
	//		murderer[i] = 0;
	//	}
	//}

	//猜名次
	int player[5] = { 0 };
	int flag = 0;
	for (player[0] = 1; player[0] <= 5; player[0]++){
		for (player[1] = 1; player[1] <= 5; player[1]++){
			for (player[2] = 1; player[2] <= 5; player[2]++){
				for (player[3] = 1; player[3] <= 5; player[3]++){
					for (player[4] = 1; player[4] <= 5; player[4]++){
						if ((player[1] == 2) + (player[0] == 3) == 1 && //a满足题意
							(player[1] == 2) + (player[4] == 4) == 1 && //b满足题意
							(player[2] == 1) + (player[3] == 2) == 1 && //c满足题意
							(player[2] == 5) + (player[3] == 3) == 1 && //d满足题意
							(player[4] == 4) + (player[0] == 1) == 1 && //e满足题意
							checkData(player)){
							printf("the rank is\nA:%d\nB:%d\nC:%d\nD:%d\nE:%d\n",
								player[0], player[1], player[2]
								, player[3], player[4]);
							flag = 1;
							break;
						}
					}
					if (flag){
						break;
					}
				}
				if (flag){
					break;
				}
			}
			if (flag){
				break;
			}
		}
		if (flag){
			break;
		}
	}

	system("pause");
	return 0;
}