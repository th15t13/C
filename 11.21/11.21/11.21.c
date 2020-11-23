#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person{
	char name[1024];
	char tel[1024];
	char gender[1024];
	int age;
	char address[1024];
}Person;

#define MAX_SIZE 1000
typedef struct AddressBook{
	Person persons[MAX_SIZE];
	int size;
}AddressBook;

int menu(){
	printf("=================\n");
	printf("1.添加联系人\n");
	printf("2.查找联系人\n");
	printf("3.删除联系人\n");
	printf("4.修改联系人\n");
	printf("5.查看所有联系人\n");
	printf("6.清空所有联系人\n");
	printf("7.按姓名排序\n");
	printf("0.退出\n");
	printf("=================\n");
	printf("请输入选项# ");
	int option = 0;
	scanf("%d", &option);
	return option;
}

void init(AddressBook* addressBook){
	addressBook->size = 0;
}

void addPerson(AddressBook* addressBook){
	int currentSize = addressBook->size;
	if (currentSize >= MAX_SIZE){
		printf("通讯录已经满了!\n");
		return;
	}
	else{
		printf("请输入姓名# ");
		scanf("%s", addressBook->persons[currentSize].name);
		printf("请输入号码# ");
		scanf("%s", addressBook->persons[currentSize].tel);
		printf("请输入性别# ");
		scanf("%s", addressBook->persons[currentSize].gender);
		printf("请输入年龄# ");
		scanf("%d", &addressBook->persons[currentSize].age);
		printf("请输入住址# ");
		scanf("%s", addressBook->persons[currentSize].address);
		printf("OK!\n");
		addressBook->size++;
	}
}

void searchPerson(AddressBook* addressBook){
	char name[1024] = { 0 };
	printf("请输入要查找的姓名# ");
	scanf("%s", &name);
	for (int i = 0; i < addressBook->size; i++){
		if (strcmp(name, addressBook->persons[i].name) == 0){
			printf("[%d]\t\t%s\t\t%s\t\t%s\t\t%d\t\t%s\n", i, addressBook->persons[i].name,
				addressBook->persons[i].tel, addressBook->persons[i].gender,
				addressBook->persons[i].age, addressBook->persons[i].address);
		}
	}
}

void delPerson(AddressBook* addressBook){
	int id = 0;
	printf("请输入要删除的编号# ");
	scanf("%d", &id);
	if (id >= addressBook->size || id < 0){
		printf("输入有误!\n");
		return;
	}
	else if (id == addressBook->size - 1){
		addressBook->size--;
		printf("Done!\n");
		return;
	}
	else{
		addressBook->persons[id] = addressBook->persons[addressBook->size - 1];
		addressBook->size--;
		printf("Done!\n");
		return;
	}
}

void editPerson(AddressBook* addressBook){
	int id = 0;
	printf("请输入要编辑的编号# ");
	scanf("%d", &id);
	if (id >= addressBook->size || id < 0){
		printf("输入有误!\n");
		return;
	}
	else{
		printf("请输入姓名# ");
		scanf("%s", addressBook->persons[id].name);
		printf("请输入号码# ");
		scanf("%s", addressBook->persons[id].tel);
		printf("请输入性别# ");
		scanf("%s", addressBook->persons[id].gender);
		printf("请输入年龄# ");
		scanf("%d", &addressBook->persons[id].age);
		printf("请输入住址# ");
		scanf("%s", addressBook->persons[id].address);
		printf("OK!\n");
		printf("Done!\n");
		return;
	}
}

void list(AddressBook* addressBook){
	for (int i = 0; i < addressBook->size; i++){
		printf("[%d]\t\t%s\t\t%s\t\t%s\t\t%d\t\t%s\n", i, addressBook->persons[i].name,
			addressBook->persons[i].tel, addressBook->persons[i].gender,
			addressBook->persons[i].age, addressBook->persons[i].address);
	}
}

void empty(AddressBook* addressBook){
	char option;
	printf("确定要清空联系人吗？(Y/N)# ");
	getchar();
	scanf("%c",&option);
	if (option == 'Y'){
		addressBook->size = 0;
		strcpy(addressBook->persons[0].name, "");
		strcpy(addressBook->persons[0].tel, "");
		strcpy(addressBook->persons[0].gender, "");
		strcpy(addressBook->persons[0].address, "");
		addressBook->persons[0].age = 0;
		printf("Done!\n");
		return;
	}
	else if (option == 'N'){
		return;
	}
	else
	{
		printf("输入有误!\n");
		return;
	}
}

void sortByName(AddressBook* addressBook){
	Person tmp;
	for (int i = 0; i < addressBook->size - 1; i++){
		for (int j = 0; j < addressBook->size - i - 1; j++){
			if (strcmp(addressBook->persons[j].name,
				addressBook->persons[j + 1].name) > 0){
				tmp = addressBook->persons[j + 1];
				addressBook->persons[j + 1] = addressBook->persons[j];
				addressBook->persons[j] = tmp;
			}
		}
	}
}

typedef void(*Table)(AddressBook*);
AddressBook	addressBook;

int main(){
	Table table[] = {
		NULL,
		addPerson,
		searchPerson,
		delPerson,
		editPerson,
		list,
		empty,
		sortByName
	};
	init(&addressBook);
	while (1){
		int option = menu();
		if (option == 0){
			printf("goodbye!\n");
			break;
		}
		else if (option < 0 || option > sizeof(table) / sizeof(table[0])){
			printf("输入有误!\n");
			continue;
		}
		table[option](&addressBook);
	}
	system("pause");
	return 0;
}
