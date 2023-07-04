#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "DoubleLinkedList.h"

//공백 이중 연결 리스트를 생성하는 연산
linkedList_h* createLinkedList_h(void) {
	linkedList_h* DL;
	DL = (linkedList_h*)malloc(sizeof(linkedList_h));
	DL->head = NULL;
	return DL;
}

//이중 연결 리스트를 순서대로 출력하는 연산
void printList(linkedList_h* DL) {
	listNode* p;
	printf("DL = (");

	p = DL->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->rlink;
		if (p != NULL)
			printf(", ");
	}
	printf(") \n");
}

listNode* createNode(char* x) {
	listNode* newN;

	newN = (listNode*)malloc(sizeof(listNode));
	strcpy(newN->data, x);

	return newN;		//insert함수의 newNode와 다르지만 그 함수로 들어감
}

void insertNode(linkedList_h* DL, listNode* pre, char* x) {
	listNode* newNode;
	newNode = createNode(x);

	if (DL == NULL)
		return;
	if (DL->head == NULL) {
		newNode->rlink = NULL;
		newNode->llink = NULL;
		DL->head = newNode;
	}
	else {
		newNode->rlink = pre->rlink;
		pre->rlink = newNode;
		newNode->llink = pre;
		if (newNode->rlink != NULL)
			newNode->rlink->llink = newNode;
	}
}

void deleteNode(linkedList_h* DL, listNode* old) {
	if (DL == NULL)
		return;
	if (DL->head == NULL)
		return;
	else if (old == NULL)
		return;

	else {
		if (old->llink != NULL)
			old->llink->rlink = old->rlink;
		if (old->rlink != NULL)
			old->rlink->llink = old->llink;
		free(old);
	}
}

listNode* searchNode(linkedList_h* DL, char* x) {
	listNode* temp;
	temp = DL->head;
	while (temp != NULL) {
		if (strcmp(temp->data, x) == 0)
			return temp;
		else
			temp = temp->rlink;
	}
	return temp;
}