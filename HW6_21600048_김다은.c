#include <stdio.h>
#include <stdlib.h>

typedef struct listnode *listptr;
typedef struct listnode {
	int data;
	listptr link;
};
listptr front=NULL, rear=NULL;

void add();
void del();
void search();

int main() {
	int x;

	while (1) {
		printf(" [(1)���� �߰�] \n [(2)���� ����] \n [(3)Top ���� ��ȸ] \n [(4)����] \n =>��ɾ� ��ȣ�� �Է��Ͻÿ�: ");
		scanf_s("%d", &x);

		if (x == 1)
			add();
		else if (x == 2)
			del();
		else if (x == 3)
			search();
		else if (x == 4)
			return;
		else printf("�Է��Ͻ� ���ڰ� �����ϴ�.\n \n");

	}
	return;
}

void add() {
	listptr temp;
	int x;

	printf("���ϴ� ���Ҹ� �Է��ϼ���. ");
	scanf_s("%d", &x);

	temp = (struct listnode*)malloc(sizeof(struct listnode));
	temp->data = x;
	temp->link = NULL; //rear�� �߰��ϴϱ� 

	if (front == NULL) {
		front = temp;
		rear = temp;
	} //temp�� ù node�� �� 

	else {
		rear->link = temp;
		rear = temp;
	}
}

void del() {
	listptr temp = front;

	if (temp == NULL) {
		printf("������ ���Ұ� �����ϴ�. \n\n");
		return;
	} //���1 queue�� �ƹ��͵� ���� ��

	if (temp->link == NULL) {
		rear = NULL;
		free(front); //free(temp)�ص� ���� 
		front = NULL;
		return;
	} //���2 queue�� ���Ұ� �� 1�� => �� ������ 1�� ���� 

	temp=front->link; //temp�� front�� ����Ű�� node�� link�� ����Ű�� �ִ� node�� �޴´�! 
	free(front);
	front = temp;

	return ;
}

void search() {
	if (front == NULL) {
		printf("front�� ���� ���� �����ϴ�. \n\n");
		return; 
	}
	printf("front ���Ҵ� %d�Դϴ�. \n\n",front->data); 
}
