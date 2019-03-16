#include <stdio.h>

int main() {

	int x, i;
	int y = 0;
	unsigned char arr[4];
	int temp;

	scanf("%d", &x);

	for (i = 0; i < 4; i++) {
		scanf("%d", &temp);
		arr[i] = (unsigned char*)temp;
	}

	for (i = 0; i < 4; i++)
	{
		printf("%d\n", *((unsigned char*)(&x) + i));
	}

	printf("%d \n", *((int*)arr));
	return 0;
} 

