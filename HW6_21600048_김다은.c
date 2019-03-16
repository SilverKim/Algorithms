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
		printf(" [(1)원소 추가] \n [(2)원소 삭제] \n [(3)Top 원소 조회] \n [(4)종료] \n =>명령어 번호를 입력하시오: ");
		scanf_s("%d", &x);

		if (x == 1)
			add();
		else if (x == 2)
			del();
		else if (x == 3)
			search();
		else if (x == 4)
			return;
		else printf("입력하신 숫자가 없습니다.\n \n");

	}
	return;
}

void add() {
	listptr temp;
	int x;

	printf("원하는 원소를 입력하세요. ");
	scanf_s("%d", &x);

	temp = (struct listnode*)malloc(sizeof(struct listnode));
	temp->data = x;
	temp->link = NULL; //rear에 추가하니까 

	if (front == NULL) {
		front = temp;
		rear = temp;
	} //temp가 첫 node일 때 

	else {
		rear->link = temp;
		rear = temp;
	}
}

void del() {
	listptr temp = front;

	if (temp == NULL) {
		printf("삭제할 원소가 없습니다. \n\n");
		return;
	} //경우1 queue에 아무것도 없을 때

	if (temp->link == NULL) {
		rear = NULL;
		free(front); //free(temp)해도 가능 
		front = NULL;
		return;
	} //경우2 queue에 원소가 딱 1개 => 그 나머지 1개 삭제 

	temp=front->link; //temp는 front가 가리키는 node의 link가 가르키고 있는 node를 받는다! 
	free(front);
	front = temp;

	return ;
}

void search() {
	if (front == NULL) {
		printf("front할 원소 값이 없습니다. \n\n");
		return; 
	}
	printf("front 원소는 %d입니다. \n\n",front->data); 
}
