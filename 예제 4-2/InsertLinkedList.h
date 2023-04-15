#pragma once
//단순 연결 리스트의 노드 구조를 구조체로 정의

typedef struct ListNode {
	char data[4];
	struct ListNode* link;
} listNode;

//리스트 시작을 나타내는 head 노드를 구조체로 정의
typedef struct {
	listNode* head;
}linkedList_h;

linkedList_h* createLinkedList_h(void);
void freeLinkedList_h(linkedList_h* L);
void printList(linkedList_h* L);
void insertFirstNode(linkedList_h* L, char* x);
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x);
void insertLastNode(linkedList_h* L, char* x);
listNode* createNode(char* x);		//새로 정의한 함수
listNode* searchNode(linkedList_h* L, char* x);
void deleteNode(linkedList_h * L, listNode * p);
