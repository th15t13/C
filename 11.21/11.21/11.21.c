#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person{
	char name[1024];
	char tel[1024];
}Person;

#define MAX_SIZE 1024
typedef struct AddressBook{
	Person persons[MAX_SIZE];
	int size;
}AddressBook;

int menu(){
	printf("=================\n");
	printf("1.�����ϵ��\n");
	printf("2.������ϵ��\n");
	printf("3.ɾ����ϵ��\n");
	printf("4.�޸���ϵ��\n");
	printf("5.�鿴������ϵ��\n");
	printf("6.���������ϵ��\n");
	printf("0.�˳�\n");
	printf("=================\n");
	printf("������ѡ��# ");
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
		printf("ͨѶ¼�Ѿ�����!\n");
		return;
	}
	else{
		printf("����������# ");
		scanf("%s", addressBook->persons[currentSize].name);
		printf("���������# ");
		scanf("%s", addressBook->persons[currentSize].tel);
		printf("OK!\n");
		addressBook->size++;
	}

}

void searchPerson(AddressBook* addressBook){
	char name[1024] = { 0 };
	printf("������Ҫ���ҵ�����# ");
	scanf("%s", &name);
	for (int i = 0; i < addressBook->size; i++){
		if (strcmp(name, addressBook->persons[i].name) == 0){
			printf("[%d]\t\t%s\t\t%s\n", i, addressBook->persons[i].name,
				addressBook->persons[i].tel);
		}
	}
}

void delPerson(AddressBook* addressBook){
	int id = 0;
	printf("������Ҫɾ���ı��# ");
	scanf("%d", &id);
	if (id >= addressBook->size || id < 0){
		printf("��������!\n");
		return;
	}
	else if (id = addressBook->size - 1){
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
	printf("������Ҫ�༭�ı��# ");
	scanf("%d", &id);
	if (id >= addressBook->size || id < 0){
		printf("��������!\n");
		return;
	}
	else{
		printf("����������# ");
		scanf("%s", addressBook->persons[id].name);
		printf("���������# ");
		scanf("%s", addressBook->persons[id].tel);
		printf("OK!\n");
		printf("Done!\n");
		return;
	}
}

void list(AddressBook* addressBook){
	for (int i = 0; i < addressBook->size; i++){
		printf("[%d]\t\t%s\t\t%s\n", i, addressBook->persons[i].name,
			addressBook->persons[i].tel);
	}
}

void empty(AddressBook* addressBook){
	char option;
	printf("ȷ��Ҫ�����ϵ����(Y/N)# ");
	getchar();
	scanf("%c",&option);
	if (option == 'Y'){
		addressBook->size = 0;
		strcpy(addressBook->persons[0].name, "");
		strcpy(addressBook->persons[0].tel, "");
		printf("Done!\n");
		return;
	}
	else if (option == 'N'){
		return;
	}
	else
	{
		printf("��������!\n");
		return;
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
		empty
	};
	init(&addressBook);
	while (1){
		int option = menu();
		if (option == 0){
			printf("goodbye!\n");
			break;
		}
		else if (option < 0 || option > sizeof(table) / sizeof(table[0])){
			printf("��������!\n");
			continue;
		}
		table[option](&addressBook);
	}
	system("pause");
	return 0;
}
