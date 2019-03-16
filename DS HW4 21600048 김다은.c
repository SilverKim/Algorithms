#include <stdio.h>
#include <string.h>

#define size 10
#define yes 1
#define no 0

int queue[size];
int front = 0;
int rear = 0;

void add();
void delete();
void peek();

int main() {
	int x;

	while (1) {
		printf(" [(1)���� �߰�] \n [(2)���� ����] \n [(3)front ���� ��ȸ] \n [(4)����] \n =>��ɾ� ��ȣ�� �Է��Ͻÿ�: ");
		scanf_s("%d", &x);

		if (x == 1)
			add();
		else if (x == 2)
			delete();
		else if (x == 3)
			peek();
		else if (x == 4)
			return;
		else printf("�Է��Ͻ� ���ڰ� �����ϴ�. \n\n");

	}

	return;
}

int queue_empty() {
	if (front == rear)
		return yes;
	else
		return no;
}

int queue_full() {
	if (front == (rear + 1) % size)
		return yes;
	else
		return no;
}


void add() {
	int x;

	printf("�߰��Ͻ� ���Ҹ� �Է��Ͻʽÿ�: ");
	scanf_s("%d", &x);

	if (queue_full == yes) {
		printf("���� ������ �����ϴ�. \n\n");
		return;
	}

	else {
		queue[rear] = x;
		rear = (rear + 1) % size;
		return ;
	}
}

void delete() {
	if (queue_empty() == yes) {
		printf("���Ұ� �ƹ��͵� �����ϴ�. ���� �߰� ���� ���ּ���. \n\n");
		return;
	}
	else {
		front = (front + 1) % size;
		return queue[front];
	}
}

void peek() {
	printf("front ���Ҵ� %d �Դϴ�. \n\n", queue[front]);
	return;
}