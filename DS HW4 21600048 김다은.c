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
		printf(" [(1)원소 추가] \n [(2)원소 삭제] \n [(3)front 원소 조회] \n [(4)종료] \n =>명령어 번호를 입력하시오: ");
		scanf_s("%d", &x);

		if (x == 1)
			add();
		else if (x == 2)
			delete();
		else if (x == 3)
			peek();
		else if (x == 4)
			return;
		else printf("입력하신 숫자가 없습니다. \n\n");

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

	printf("추가하실 원소를 입력하십시오: ");
	scanf_s("%d", &x);

	if (queue_full == yes) {
		printf("넣을 공간이 없습니다. \n\n");
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
		printf("원소가 아무것도 없습니다. 원소 추가 먼저 해주세요. \n\n");
		return;
	}
	else {
		front = (front + 1) % size;
		return queue[front];
	}
}

void peek() {
	printf("front 원소는 %d 입니다. \n\n", queue[front]);
	return;
}