#include<stdio.h>

typedef struct listnode *listptr;
typedef struct listnode {
	listptr leftside, rightside;
	int data;
};

void inorder(listptr x) {
	if (x) {
		inorder(x->leftside);
		printf("%d", x->data);
		inorder(x->rightside);
	}
}

void preorder(listptr x) {
	if (x) {
		printf("%d", x->data);
		preorder(x->leftside);
		preorder(x->rightside);
	}
}

void postorder(listptr x) {
	if (x) {
		postorder(x->leftside);
		postorder(x->rightside);
		printf(x->data);
	}
}

void level(listptr x) {
	if (!x)
		return;
	for (;;) {
		x = deleteq();
		if (x) {
			printf("%d", x->data);
			if (x->leftside)
				addq(x->leftside);
			if (x->rightside)
				add(x->rightside);
		}
		break;
	}
}

listptr copy(listptr x) {
	listptr temp;
	temp = (struct listnode*)malloc(sizeof(struct listnode));
	if (x) {
		temp->data = copy(x->data);
		temp->leftside = copy(x->leftside);
		temp->rightside = copy(x->rightside);
		return temp;
	} return;

}

int equal(listptr x, listptr y) {
		return (x == NULL&&y == NULL) || (x != NULL&&y != NULL) &&
		(x->data == y->data) && equal(x->leftside,y->leftside) && equal(x->rightside,y->rightside);
}