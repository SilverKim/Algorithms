#include <stdio.h>

int main() {

	int x,i,y=0;

	for (i = 0; i < 5; i++) {
		printf("���� �Է�: ");
		scanf("%d", &x);
	}
	
	unsigned char*ptr=&x;

	//printf("%d", *(unsigned char*)(&x)+1);

	for (i = 0; i < 4; i++) {
		printf("%d\n",*ptr+i);
	}
	*ptr = y;

	printf("%d", *(int*)y);

	return 0;
} 