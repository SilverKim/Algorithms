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
		printf(" [(1)���� �߰�] \n [(2)���� ����] \n [(3)Top ���� ��ȸ] \n [(4)����] \n =>��ɾ� ��ȣ�� �Է��Ͻÿ�: ");
		scanf_s("%d", &x);

		if (x == 1)
			push();
		else if (x == 2)
			pop();
		else if (x == 3)
			search();
		else if (x == 4)
			return ;
		else printf("�Է��Ͻ� ���ڰ� �����ϴ�. \n\n");

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

	printf("�߰��Ͻ� ���Ҹ� �Է��Ͻʽÿ�: ");
	scanf_s("%d", &x);

	if (stack_full() == yes) {
		printf("���� ������ �����ϴ�. \n\n");
	}
	else {
		stack[top] = x;
		top++;
	}
	return ;
}

void pop() {
	if (stack_empty() == yes) {
		printf("���Ұ� �ƹ��͵� �����ϴ�. ���� �߰� ���� ���ּ���. \n\n");
		return ;
	}

	else {
		top--;
		return stack[top];
	}
}

void search() {
	printf("top ���Ҵ� %d �Դϴ�. \n\n", stack[top-1]);
	return;
}