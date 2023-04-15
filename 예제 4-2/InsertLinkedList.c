#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>		//inculde.h 를 만들어서 #include "include.h" 하면 편함
#include "InsertLinkedList.h"


//공백 연결 리스트를 생성하는 연산
linkedList_h* createLinkedList_h(void) {
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;
	if (L == NULL) return;
	return L;
}

//연결 리스트의 전체 메모리를 해제하는 연산
void freeLinkedList_h(linkedList_h* L) {
	listNode* p;
	if (L == NULL) return;
	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}

//연결 리스트를 순서대로 출력하는 연산
void printList(linkedList_h* L) {
	listNode* p;

	if (L == NULL) return;

	printf("L=(");
	p = L->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->link;
		if (p != NULL) printf(", ");
	}
	printf(") \n");
}


//malloc, strcpy, newNode->link 반복되는 부분을 새로운 함수로 정의
listNode* createNode(char* x) {
	listNode* newN;


	newN = (listNode*)malloc(sizeof(listNode));
	strcpy(newN->data, x);
	newN->link = NULL;

	return newN;		//insert함수의 newNode와 다르지만 그 함수로 들어감
}


//첫 번째 노드로 삽입하는 연산
void insertFirstNode(linkedList_h* L, char* x) {
	listNode* newNode;

	if (L == NULL) return;

	/*newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = L->head;*/		//createNode함수로 대체

	newNode = createNode(x);

	L->head = newNode;
}

//노드를 pre 뒤에 삽입하는 연산		//middle함수라 생략
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);

	newNode->link = NULL;

	if (L == NULL) return;

	if (L->head == NULL) {
		//newNode->link = NULL;		48번 줄에서 초기화를 했기 때문에 생략 가능
		L->head = newNode;
		//return					if만 있을땐 return해야하지만 뒤에 else if 나 else가 있기때문에 생략 가능
	}
	else if (pre == NULL) {
		newNode->link = L->head;	//58번 59번줄은 바꾸면 안됨 - L->head의 값이 바뀌기 때문
		L->head = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

//마지막 노드로 삽입하는 연산
void insertLastNode(linkedList_h* L, char* x) {
	
	if (L == NULL) return;

	listNode* newNode;
	listNode* temp;
	/*newNode = (listNode*)malloc(sizeof(newNode));
	strcpy(newNode->data, x);
	newNode->link = NULL;*/			//createNode함수로 대체

	newNode = createNode(x);

	if (L->head == NULL) {
		L->head = newNode;
		return;				//뒤에 else같은게 없어서 return 반환, else문 있으면 생략 가능
	}

	//현재리스트가 공백이 아닌경우
	temp = L->head;
	while (temp->link != NULL)
		temp = temp->link;
	temp->link = newNode;
}

//리스트에서 노드 p를 삭제하는 연산
void deleteNode(linkedList_h* L, listNode* p) {
	listNode* pre;

	if (L == NULL) return;

	if (L->head == NULL)
		return;

	if (L->head->link == NULL) {
		free(L->head);
		L->head = NULL;
		return;
	}
	else if (p == NULL)
		return;
	else {
		pre = L->head;
		while (pre->link != p) {
			pre = pre->link;
		}
		pre->link = p->link;
		free(p);
	}
}

listNode* searchNode(linkedList_h* L, char* x) {
	listNode* temp;

	if (L == NULL) return;

	temp = L->head;
	while (temp != NULL) {
		if (strcmp(temp->data, x) == 0)
			return temp;
		else
			temp = temp->link;
	}
	return temp;
}