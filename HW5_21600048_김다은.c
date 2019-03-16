#include <stdio.h>
#include <stdlib.h>

typedef struct listnode *listptr;
typedef struct listnode {
	int data;
	listptr link;
};

listptr top = NULL;

void push();
void pop();
void search();

int main() {
	int x;

	while (1) {
		printf(" [(1)���� �߰�] \n [(2)���� ����] \n [(3)Top ���� ��ȸ] \n [(4)����] \n =>��ɾ� ��ȣ�� �Է��Ͻÿ�: ");
		scanf_s("%d", &x);

		if (x == 1)
			push();
		else if (x == 2)
			pop();
		else if (x == 3)
			search();
		else if (x == 4)
			return;
		else printf("�Է��Ͻ� ���ڰ� �����ϴ�.\n \n");

	}
	return;
}

void push() {
	int x;
	printf("�߰��Ͻ� ������ ���� �Է��Ͻÿ�.");
	scanf_s("%d", &x);

	listptr temp;

	temp = (struct listnode*)malloc(sizeof(struct listnode));

	temp->data = x;
	temp->link = top; 
	top = temp;
	
	return;
}

void pop() {
	listptr temp = top; //stack ���� �� �� ����ֱ�  

	if (temp == NULL) {
		printf("������ ���Ұ� �����ϴ�.\n\n");
		return;
	}
	else {
		top = temp->link; //���ο� top
		free(temp);

		return;
	}
}

void search() {
	if (top == NULL) {
		printf("���Ұ� �����ϴ�.\n\n");
		return;
	}
	printf("top ���Ҵ� %d �Դϴ�. \n\n", top->data);
} 