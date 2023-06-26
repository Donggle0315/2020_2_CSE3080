#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char string[100];
	char pattern[100];
	int* matching;
	int* start_index; //패턴과 anagram이 매칭되는 부분의 starting index
	int count = 0; //starting index에 저장된 정수의 개수
	int i,j,k;


	gets(string, 100);
	gets(pattern, 100);
	
	if(strlen(string)>10||strlen(string)<1){
		fprintf(stderr, "string size error");
		return 1;
	}
	if (strlen(pattern) > 10 || strlen(pattern) < 1) {
		fprintf(stderr, "pattern size error");
		return 1;
	}
	if (strlen(string) < strlen(pattern)) {
		fprintf(stderr, "string is shorter than pattern");
		return 1;
	}

	matching = (int*)calloc(strlen(pattern), sizeof(int));
	start_index = (int*)malloc(strlen(string) * sizeof(int));

	for (i = 0; i <= strlen(string) - strlen(pattern); i++) {
		for (j = i; j < i + strlen(pattern); j++) {
			for (k = 0; k < strlen(pattern); k++) {
				if (string[j] == pattern[k] && matching[k] == 0) {
					matching[k] = 1;
				}
			}
		}
		for (k = 0; k < strlen(pattern); k++) {
			if (matching[k] == 0) {
				break;
			}
		}
		if (k == strlen(pattern)) {
			start_index[count++] = i;
		}
		for (k = 0; k < strlen(pattern); k++) {
			matching[k] = 0;
		}
	}

	printf("[");
	for (i = 0; i < count; i++) {
		printf("%d", start_index[i]);
		if (i != count - 1) {
			printf(", ");
		}
	}
	printf("]\n");

	free(matching);
	free(start_index);

	return 0;
}
