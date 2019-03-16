#include <stdio.h>
#include <string.h>

#define size 5
#define yes 1
#define no 0

int stack[size];
int top = 0;

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
			return ;
		else printf("입력하신 숫자가 없습니다. \n\n");

	}
	
	return ;
}

int stack_full() {
	if (top == size)
		return yes;
	else
		return no;
}

int stack_empty() {
	if (top == 0)
		return yes;
	else
		return no;
}

void push() {
	int x;

	printf("추가하실 원소를 입력하십시오: ");
	scanf_s("%d", &x);

	if (stack_full() == yes) {
		printf("넣을 공간이 없습니다. \n\n");
	}
	else {
		stack[top] = x;
		top++;
	}
	return ;
}

void pop() {
	if (stack_empty() == yes) {
		printf("원소가 아무것도 없습니다. 원소 추가 먼저 해주세요. \n\n");
		return ;
	}

	else {
		top--;
		return stack[top];
	}
}

void search() {
	printf("top 원소는 %d 입니다. \n\n", stack[top-1]);
	return;
}