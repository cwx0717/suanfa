//链表
//一.链表储存结构
/*
#include <stdlib.h>
typedef int ElemType;
typedef struct node {        //结构体的名为：sturct node 链表‘节点’结构体
	ElemType data;                //data 用来存储链表节点的实际数据
	struct node* next;      //next :指针变量。作用：用来表示链表的‘下一个节点’。
}Node;
//单链表 ：初始化
Node* initList() {               //定义一个initList函数，返回值为Node*。作用：创造并初始化一个链表的‘头节点’，完成链表的初始化
	Node* head = (Node*)malloc(sizeof(Node));         //malloc：c语言中的内存分配函数
	head->data = 0;           //data:头节点赋值为0
	if (head == NULL) {
		printf("内存分配失败！\n");
		return NULL;
	}
	head->next = NULL;              //NULL:c语言中的空指针变量“不指向任何内存地址”。把head节点的next指针设置为NULL，说明除了头节点，无下一个节点
	return head;
}*/
/*int main() {
	Node* List = initList();     //调用initList函数
	return 0;
}
//头插法.与排列顺序相反
int insertHead(Node* L, ElemType e) {
	Node* p = (Node*)malloc(sizeof(Node)); //创建一个新节点，准备存数据；
	if (p == NULL) {
		printf("内存分配失败！\n");
		return -1;
	}
	p->data = e;                             //给新节点p赋值为e
	p->next = L->next;                        //p的next指针指向头节点L原本向下的下一个节点
	L->next = p;               //让L节点的next指针，指向新节点p
	return 0;
}*/
//遍历
/*void ListNode(Node* L) {
	Node* p = L->next;                  //定义遍历指针p，并让它指向头节点的下一个节点
	while (p != NULL) {                         //p不指向空，继续循环
		printf("%d \n", p->data);            //打印当前p指向的节点data的值
		p = p->next;                          //让遍历指针p向后吧走一步，指向当前节点的下一个节点
	}
	printf("\n");
}
int main() {
	Node* List = initList();                
	insertHead(List, 10);
	insertHead(List, 20);
	return 0;
}*/
//尾插法.与排列顺序相同
/*Node* get_tail(Node* L) {
	Node* p = L;
	while (p->next != NULL) {
		p = p->next;
	}
	return p;
}
Node* insertTail(Node* tail, ElemType e) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	tail->next = p;
	p->next = NULL;
	return p;
}

int main() {
	Node* List = initList();
	Node* tail = get_tail(List);
	tail = insertTail(tail, 10);
	tail = insertTail(tail, 20);
	tail = insertTail(tail, 30);
	ListNode(List);
	return 0;
}*/
