#include <stdio.h>

int main() {

	int x,i,y=0;

	for (i = 0; i < 5; i++) {
		printf("숫자 입력: ");
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