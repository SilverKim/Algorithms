#include <stdio.h>
#include <string.h>

int array_add(int a[],int b[],int c[],int x);
int max_element(int c[]);

int main() {
	int     a[7] = { 3, 7, 2, 6, 8, 4, 5 };
	int     b[7] = { 1, 2, 2, 1, 3, 4, 2 };
	int     c[10];
	int     max;

	array_add(a, b, c, 7);   /* c�� 7���� ���� ������ a �� b�� ������ ���� �ǵ��� */
	max = max_element(c, 7);  /* c�� 7�� ���� �� ���� ū ���� ã��  */
	printf(" Max = %d\n", max);  /*  11 �� ��µǱ⸦ ��� */
}

int array_add(int a[], int b[], int c[],int x) {
	if (x > 7)
		return array_add(a, b, c, x - 1);
	else
		return c[x] = a[x] + b[x]; array_add(a, b, c, x - 1);
} 

int max_element(int c[]) {
	int i = 1;
	int max;

	for (i = 1; i < 11; i++) {
		if (c[i] < c[i + 1])
			max = c[i + 1];
		else
			max = c[i];
	}
}