#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *pi;
	int count = 0;
	int pr[10];
	int i = 0, j, z;

	pi = (int*)malloc(5 * sizeof(int));



	while (1) {

		scanf("%d", &pi[count]);

		if (count % 5 == 0)
			pi = realloc(pi, (count+5) * sizeof(int));
		

		if (pi[count] == -1) {
			for (j = 0; j < 10; j++) {
				scanf("%d", &pr[j]);

				for (i = 0; i < count; i++) {
					if (pi[i] == pr[j])
						printf("Yes");

				}
				if (i = count)
					printf("No");
			} 
			break;
		}
		count++;
	}

	free(pi);
	return 0;
}