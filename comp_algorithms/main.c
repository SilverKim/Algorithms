#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

int max=0; //max is the number of vertex.
char *array[80][80]; //each line on file.
char *text[80][80]; //two-dimention matrix
int text2[80][80]; //it is real!!!!! type is integer

char* trim(char *s); // all of this use to remove empty space
char* ltrim(char *s);
char* rtrim(char *s);

int d[80]; //distance
bool v[80]; //arrived node -> if it is arrived, make true
int INF = 10000;

int p[80][80]; //biggest in Floyd algorithm

void init();
void split(char *x,int num); //making matrix variable of text.
void di(int start);
int small(); //getting smalltest index.
void bell(int start);
void floyd();

char* rtrim(char* s) {
	char t[80];
	char *end;

	strcpy(t, s);
	end = t + strlen(t) - 1;
	while (end != t&&isspace(*end))
		end--;
	*(end + 1) = '\0';
	s = t;

	return s;
}
char* ltrim(char* s) {
	char* begin;
	begin = s;

	while (*begin != '\0') {
		if (isspace(*begin))
			begin++;
		else {
			s = begin;
			break;
		}
	}
	return s;
}
char* trim(char* s) {
	return rtrim(ltrim(s));
}

int main() {
	clock_t start,start2,start3, finish,finish2,finish3;
	double time,time2,time3;
	
	init();

	for (int i = 0; i < max; i++) {
		split(array[i],i); //data structure go go using this! 
	}

	for (int i = 0; i < max; i++) {
		for (int j = 1; j < max + 1; j++) {
			if (strcmp("INF", trim(text[i][j])) == 0)
				text2[i][j - 1] = INF;
			else text2[i][j - 1] = atoi(text[i][j]);
		}
	}

	printf("(1) Dijkstra's algorithm.\n\n");
	for (int i = 0; i < max; i++) {
		if (strcmp("Busan", trim(text[i][0])) == 0)
			printf("		%s ", text[i][0]);
		else printf("%5s   ", text[i][0]);
	}
	printf("\n");

	start = clock();
	for (int i = 0; i < max; i++) {
		printf("%10s ", text[i][0]);
		di(i);
	}

	finish = clock();

	time = difftime(finish, start)/1000;
	printf(" \n=> It took %f seconds to compute shortest path between cities with Dijkstra's algorithm as follows.\n\n",time);

	
	printf("(2) Bellman-Ford's algorithm.\n\n");
	for (int i = 0; i < max; i++) {
		if (strcmp("Busan", trim(text[i][0])) == 0)
			printf("		%s ", text[i][0]);
		else printf("%5s   ", text[i][0]);
	}
	printf("\n");

	start2 = clock();
	for (int i = 0; i < max; i++) {
		printf("%10s ", text[i][0]);
		bell(i);
	}
	finish2 = clock();

	time2 = difftime(finish2, start2)/1000;
	printf(" \n=> It took %f seconds to compute shortest path between cities with Bellman Ford algorithm as follows.\n\n",time2);

	printf("(3) Floyd's algorithm.\n\n");

	start3 = clock();
	floyd();
	finish3 = clock();
	
	time3 = difftime(finish3, start3)/1000;
	printf(" \n=> It took %f seconds to compute shortest path between cities with Floyd algorithm as follows.\n\n",time3);

}

void init() {
	FILE * fp = fopen("hw5..data", "r");
	 
	if (fp == NULL) {
		printf("파일오픈실패!");
	}

	char arr[80];

	fgets(arr, sizeof(arr), fp);

	char x[10];
	char ch;
	int num = 0;

	for (int i = 0; i < strlen(x); i++) {
		ch = x[i];
		
		if (ch >= 'A'&&ch <= 'Z')
			num++;
	}
	max = num;

	//storing each line on array! 
	for (int j = 0; j < max; j++) { 
		fgets(array[j], sizeof(array[80]), fp);
	}

	fclose(fp);
}

void split(char *x,int num) {
	char *token = NULL;
	char str[80] = ",\t\n";

	int j = 0;
	//printf("%s\n", text[num][j]);

	token = strtok(x, str);

	while (token != NULL) {
		//printf("%s\n", token);
		
		text[num][j] = token;
		j++;
		
		token = strtok(NULL, str);
	}
}

void di(int start) {
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			if (text2[i][j] < 0) {
				//printf("\n We cannot run Dijkstra's algorithm, because there is negative edge.\n");
				return 0;
			}
		}
	}
	for (int i = 0; i < max; i++) {
		d[i] = text2[start][i];
	}

	v[start] = true; //true is sign of arriving vertex

	for (int i =0; i < max; i++) { //max-2?
		int cur = small();
		v[cur] = true;
		for (int j = 0; j < max; j++) {
			if (!v[j]) {
				if (d[cur] + text2[cur][j] < d[j]) {
					d[j] = d[cur] + text2[cur][j];
				}
			}
		}
	}

	for (int i = 0; i < max; i++) {
		printf("%8d ", d[i]);
	}
	printf("\n");

	for (int i = 0; i < max; i++) {
		d[i] = 0;
		v[i] = false;
	}
}

int small() { //it is use path of di, it finds smallest index 
	int min = INF;
	int index = 0;
	for (int i = 0; i < max; i++) {
		if (d[i] < min && !v[i]) {
			min = d[i];
			index = i;
		}
	}
	return index;
} 

void bell(int start) {
	int d2[80];

	for (int i = 0; i < max; i++) {
		if (i == start) d2[i] = 0;
		else d2[i] = INF;
	}
	for (int k = 0; k < max; k++) {
		for (int i = 0; i < max; i++) {
			for (int j = 0; j < max; j++) {
				if (text2[i][j] != 0 && text2[i][j] != INF) {
					if (d2[j] > d2[i] + text2[i][j])
						d2[j] = d2[i] + text2[i][j];
				}
			}
		}
	}
	
	for (int i = 0; i < max; i++) {
		printf("%8d ", d2[i]);
	}
	printf("\n");

	for (int i = 0; i < max; i++) {
		d2[i] = 0;
	}
}

void floyd() {
	int d3[80][80];

	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			p[i][j] = -1;
			d3[i][j] = text2[i][j];
		}
	}
	for (int k = 0; k < max; k++) {
		for (int i = 0; i < max; i++) {
			for (int j = 0; j < max; j++) {
				if (d3[i][j] > d3[i][k] + d3[k][j]) {
					d3[i][j] = d3[i][k] + d3[k][j];
					p[i][j] = k;
				}
			}
		}
	}
	
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			printf("%8d ", d3[i][j]);
		}
		printf("\n");
	}
}
