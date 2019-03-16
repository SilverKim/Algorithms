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
		printf(" [(1)원소 추가] \n [(2)원소 삭제] \n [(3)Top 원소 조회] \n [(4)종료] \n =>명령어 번호를 입력하시오: ");
		scanf_s("%d", &x);

		if (x == 1)
			push();
		else if (x == 2)
			pop();
		else if (x == 3)
			search();
		else if (x == 4)
			return;
		else printf("입력하신 숫자가 없습니다.\n \n");

	}
	return;
}

void push() {
	int x;
	printf("추가하실 데이터 값을 입력하시오.");
	scanf_s("%d", &x);

	listptr temp;

	temp = (struct listnode*)malloc(sizeof(struct listnode));

	temp->data = x;
	temp->link = top; 
	top = temp;
	
	return;
}

void pop() {
	listptr temp = top; //stack 제일 위 값 잡아주기  

	if (temp == NULL) {
		printf("삭제할 원소가 없습니다.\n\n");
		return;
	}
	else {
		top = temp->link; //새로운 top
		free(temp);

		return;
	}
}

void search() {
	if (top == NULL) {
		printf("원소가 없습니다.\n\n");
		return;
	}
	printf("top 원소는 %d 입니다. \n\n", top->data);
} 