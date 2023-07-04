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
	while (L->head != NULL) {		//head가 null이 될 때 까지 뒤의 노드를 앞으로 옮기면서 free시킴
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
	while (p != NULL) {			//head가 null이 될 때 까지 뒤로가면서 data를 차례대로 출력함
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

//노드를 pre 뒤에 삽입하는 연산
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);

	newNode->link = NULL;

	if (L == NULL) return;

	if (L->head == NULL) {
		//newNode->link = NULL;		80번 줄에서 초기화를 했기 때문에 생략 가능
		L->head = newNode;
		//return					if만 있을땐 return해야하지만 뒤에 else if 나 else가 있기때문에 생략 가능
	}
	else if (pre == NULL) {
		newNode->link = L->head;	//이 두줄은 바뀌면 안됨 - L->head의 값이 바뀌기 때문
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
	while (temp->link != NULL)		//link가 null이 될 때 까지
		temp = temp->link;			//다음 노드로 옮김
	temp->link = newNode;			//마지막 노드에 도착하면 삽입
}

//리스트에서 노드 p를 삭제하는 연산
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

	if (L->head == p) {				//이 코드를 쓰면 133~141번째 줄은 필요가 없음
		L->head = L->head->link;
		free(p);
	}

	else {
		pre = L->head;
		while (pre->link != p) {		//head가 삭제할 p가 될 때 까지
			pre = pre->link;			//뒤로 계속 넘어가면서 찾음
		}
		pre->link = p->link;			//삭제할 노드의 링크를 해당 위치의 링크에 대입함
		free(p);
	}
}

listNode* searchNode(linkedList_h* L, char* x) {
	listNode* temp;

	if (L == NULL) return;

	temp = L->head;
	while (temp != NULL) {					//head가 null이 될 때 까지
		if (strcmp(temp->data, x) == 0)		//data와 x를 비교하여 같으면
			return temp;					//리턴
		else
			temp = temp->link;				//뒤로 넘어가면서 찾기
	}
	return temp;
}