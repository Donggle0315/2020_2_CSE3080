#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void pmatch_delete(char *);
void pmatch(char *,char*,int [],char*);
void fail(char *,int []);

int main() {
	//matching 되는 부분이 삭제되고 남은 string 출력
	//삭제된 부분이 없다면 입력한 그대로 string 출력

	//pmatch()를 수정하여 string과 pattern이 matching되는 모든 부분을 찾아 string에서 삭제
	//삭제된 결과를 pmatch_delete에서 출력
	//단 string에서 매칭되는 모든 부분의 starting index를 기준으로 삭제
	char string[100];
	char pattern[100];
	char *result;
	int *failure;
	
	
	gets(string, 100);
	gets(pattern, 100);
	if (strlen(string) > 30 || strlen(string) < 1) {
		fprintf(stderr, "string size error");
		return 1;
	}
	if (strlen(pattern) > 30 || strlen(pattern) < 1) {
		fprintf(stderr, "pattern size error");
		return 1;
	}
	if (strlen(string) < strlen(pattern)) {
		fprintf(stderr, "string is shorter than patternr");
		return 1;
	}
	
	failure=(int*)malloc(strlen(pattern)*sizeof(int));
	result = (char*)malloc(strlen(string) * sizeof(char));
	fail(pattern,failure);
	pmatch(string, pattern, failure, result);
	pmatch_delete(result);
	
	free(failure);
	free(result);

	return 0;
}

void pmatch(char *string, char *pat, int failure[], char *result){
	int i=0,j=0,index,correct=0;
	int* match;
	int lens=strlen(string);
	int lenp=strlen(pat);
	match = (int*)calloc(strlen(string), sizeof(int));
	
	do {
		i = correct;
		j=0;
		while (i < lens && j < lenp) {
			if (string[i] == pat[j]) {
				i++;
				j++;
			}
			else if (j == 0) {
				i++;
			}
			else {
				j = failure[j - 1] + 1;
			}
		}
		index = ((j == lenp) ? (i - lenp) : -1);
		if (index == -1) {
			correct++;
		}
		else {
			for (i = 0; i < strlen(pat); i++) {
				match[index + i] = 1;
			}
			correct = index + 1;
		}
	} while (correct < strlen(string) - strlen(pat));
	
	j = 0;
	for (i = 0; i < strlen(string); i++) {
		if (match[i] == 1) {
			continue;
		}
		result[j++] = string[i];
	
	}
	result[j] = '\0';

	free(match);
}

void fail(char *pat, int failure[]){
	int i,j,n=strlen(pat);
	failure[0]=-1;
	for(j=1;j<n;j++){
		i=failure[j-1];
		while((pat[j]!=pat[i+1])&&(i>=0)){
			i=failure[i];
		}
		if(pat[j]==pat[i+1]){
			failure[j]=i+1;
		}
		else{
			failure[j]=-1;
		}
	}
	
}

void pmatch_delete(char *result) {
	printf("%s\n", result);
}
