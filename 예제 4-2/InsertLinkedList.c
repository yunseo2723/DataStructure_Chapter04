#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>		//inculde.h �� ���� #include "include.h" �ϸ� ����
#include "InsertLinkedList.h"


//���� ���� ����Ʈ�� �����ϴ� ����
linkedList_h* createLinkedList_h(void) {
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;
	if (L == NULL) return;
	return L;
}

//���� ����Ʈ�� ��ü �޸𸮸� �����ϴ� ����
void freeLinkedList_h(linkedList_h* L) {
	listNode* p;
	if (L == NULL) return;
	while (L->head != NULL) {		//head�� null�� �� �� ���� ���� ��带 ������ �ű�鼭 free��Ŵ
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}

//���� ����Ʈ�� ������� ����ϴ� ����
void printList(linkedList_h* L) {
	listNode* p;

	if (L == NULL) return;

	printf("L=(");
	p = L->head;
	while (p != NULL) {			//head�� null�� �� �� ���� �ڷΰ��鼭 data�� ���ʴ�� �����
		printf("%s", p->data);
		p = p->link;
		if (p != NULL) printf(", ");
	}
	printf(") \n");
}


//malloc, strcpy, newNode->link �ݺ��Ǵ� �κ��� ���ο� �Լ��� ����
listNode* createNode(char* x) {
	listNode* newN;


	newN = (listNode*)malloc(sizeof(listNode));
	strcpy(newN->data, x);
	newN->link = NULL;

	return newN;		//insert�Լ��� newNode�� �ٸ����� �� �Լ��� ��
}


//ù ��° ���� �����ϴ� ����
void insertFirstNode(linkedList_h* L, char* x) {
	listNode* newNode;

	if (L == NULL) return;

	/*newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = L->head;*/		//createNode�Լ��� ��ü

	newNode = createNode(x);

	L->head = newNode;
}

//��带 pre �ڿ� �����ϴ� ����
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);

	newNode->link = NULL;

	if (L == NULL) return;

	if (L->head == NULL) {
		//newNode->link = NULL;		80�� �ٿ��� �ʱ�ȭ�� �߱� ������ ���� ����
		L->head = newNode;
		//return					if�� ������ return�ؾ������� �ڿ� else if �� else�� �ֱ⶧���� ���� ����
	}
	else if (pre == NULL) {
		newNode->link = L->head;	//�� ������ �ٲ�� �ȵ� - L->head�� ���� �ٲ�� ����
		L->head = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

//������ ���� �����ϴ� ����
void insertLastNode(linkedList_h* L, char* x) {
	
	if (L == NULL) return;

	listNode* newNode;
	listNode* temp;
	/*newNode = (listNode*)malloc(sizeof(newNode));
	strcpy(newNode->data, x);
	newNode->link = NULL;*/			//createNode�Լ��� ��ü

	newNode = createNode(x);

	if (L->head == NULL) {
		L->head = newNode;
		return;				//�ڿ� else������ ��� return ��ȯ, else�� ������ ���� ����
	}

	//���縮��Ʈ�� ������ �ƴѰ��
	temp = L->head;
	while (temp->link != NULL)		//link�� null�� �� �� ����
		temp = temp->link;			//���� ���� �ű�
	temp->link = newNode;			//������ ��忡 �����ϸ� ����
}

//����Ʈ���� ��� p�� �����ϴ� ����
void deleteNode(linkedList_h* L, listNode* p) {
	listNode* pre;

	if (L == NULL) return;

	if (L->head == NULL)
		return;

	/*if (L->head->link == NULL) {
		if (L->head == p) {
			free(L->head);
			L->head = NULL;
			return;
		}
		else
			return;
	}*/

	if (p == NULL)
		return;

	if (L->head == p) {				//�� �ڵ带 ���� 133~141��° ���� �ʿ䰡 ����
		L->head = L->head->link;
		free(p);
	}

	else {
		pre = L->head;
		while (pre->link != p) {		//head�� ������ p�� �� �� ����
			pre = pre->link;			//�ڷ� ��� �Ѿ�鼭 ã��
		}
		pre->link = p->link;			//������ ����� ��ũ�� �ش� ��ġ�� ��ũ�� ������
		free(p);
	}
}

listNode* searchNode(linkedList_h* L, char* x) {
	listNode* temp;

	if (L == NULL) return;

	temp = L->head;
	while (temp != NULL) {					//head�� null�� �� �� ����
		if (strcmp(temp->data, x) == 0)		//data�� x�� ���Ͽ� ������
			return temp;					//����
		else
			temp = temp->link;				//�ڷ� �Ѿ�鼭 ã��
	}
	return temp;
}