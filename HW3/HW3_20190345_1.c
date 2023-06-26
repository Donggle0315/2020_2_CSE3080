#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void push();
char pop();

char* string;
char* stack;
int i = 0;
int top = -1;

int main() {
	char ch;
	string = (char*)malloc(100 * sizeof(char));
	stack = (char*)malloc(20 * sizeof(char));

	scanf("%s",string);
	if (strlen(string) < 2 || strlen(string) > 20) {
		printf("string size error\n");
		return 1;
	}
	while (string[i]!='\0') {
		if (string[i] != '(' && string[i] != ')' && string[i] != '{' && string[i] != '}' && string[i] != '[' && string[i] != ']') {
			printf("string error\n");
			return 1;
		}
		i++;
	}
	
	i = 0;
	while (string[i] != '\0') {
		if (string[i] == '(' || string[i] == '{' || string[i] == '[') {
			push();
		}
		else {
			ch=pop();
			if (ch == '(') {
				if (string[i++] != ')') {
					printf("false\n");
					return 0;
				}
			}
			else if (ch == '{') {
				if (string[i++] != '}') {
					printf("false\n");
					return 0;
				}
			}
			else {
				if (string[i++] != ']') {
					printf("flase\n");
					return 0;
				}
			}
		}
	}
	if(top==-1){
		printf("true\n");
	}
	else{
		printf("false\n");
	}
	
	free(string);
	free(stack);
	return 0;
}

void push() {
	stack[++top]=string[i++];
}

char pop() {
	return stack[top--];
}
