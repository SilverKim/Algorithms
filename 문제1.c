#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr[4][4]; int bingo[4][4] = {0};
	int rand_num[16];
	int rand_temp, is_exist;
	int i,j,x,k;
	int count=0;
	
	// ���� 16�� �Է¹ް� �迭�� �ֱ� 
	for (i = 0; i <4; i++) {
		for (j = 0; j < 4; j++) {
			scanf("%d", &x);
			arr[i][j] = x;
		}
	}

	//���� ����
	for (i = 0; i < 16;) {
		is_exist = 0;
		rand_temp = (rand() % 16) + 1;
		for (j = 0; j < i; j++) {
			if (rand_num[j] == rand_temp) {
				is_exist = 1;
			}
		}
		if (is_exist == 0) {
			rand_num[i++] = rand_temp;
		}
	}
	
	//�� ���� �ֱ� 
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 16; k++) {
				if (rand_num[k] == arr[i][j])
					bingo[i][j] == arr[i][j];
			}
		}
	}
   
   //����üũ (count �Ἥ)
	for (i = 0; i < 4; i++) {
		if ((bingo[i][0] && arr[i][0]) && (bingo[i][1] && arr[i][1]) && (bingo[i][2] && arr[i][2]) && (bingo[i][3] && arr[i][4]))
			count++;
		if (count >= 3)
			break;
		else count = 0;
	}

	return 0;
} 