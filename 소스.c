#include <stdio.h>

typedef struct listnode *listptr;
typedef struct listnode {
	listptr llink;
	int data;
	listptr rlink;
};

void insert() {
	listptr node, newnode;
	node = (struct listnode*)malloc(sizeof(struct listnode));
	newnode = (struct listnode*)malloc(sizeof(struct listnode));

	newnode->llink = node->rlink;
	newnode->rlink = node->rlink->llink;
	node->rlink = newnode;
	node->rlink->llink = newnode;

	return;
}

void delete() {
	listptr node;
	node = (struct listnode*)malloc(sizeof(struct listnode));

	node->llink->rlink = node->rlink;
	node->rlink->llink = node->llink;
	free(node);

	return;
}

int main() {
	int x;
	printf("select number \n number1 is insert node \n number2 is delete node ");
	scanf_s("%d", &x);
	if (x == 1)
		insert();
	if (x == 2)
		delete();
}