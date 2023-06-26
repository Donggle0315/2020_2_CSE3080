#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *num;
int tail=-1;
int head=0;
int *queue;
int j;

void push();
int pop();


int main(){
	char *string;
	int *tmp;
	int *result;
	char *token;
	int count=0;
	int i,k,t,q;
	
	string=(char *)malloc(50*sizeof(char));
	result=(int *)malloc(20*sizeof(int));
	num=(int*)malloc(20*sizeof(int));
	tmp=(int *)malloc(20*sizeof(int));
	gets(string,50);
	token=strtok(string," ");
	while(token!=NULL){
		num[count++]=atoi(token);
		token=strtok(NULL," ");
	}
	//count is num of number in the list

	for(i=0;i<count;i++){
		queue=(int*)malloc(20*sizeof(int));
		head=0;
		tail=-1;
		for(j=0;j<count-i;j++){
			push();
			for(k=head;k<tail;k++){
				if(queue[tail]>queue[k]){
					t=pop();
				}
				else{
					break;
				}
			}
		}
		t=pop();
		result[i]=t;
		
		for(j=0;j<count-i;j++){
			if(num[j]==result[i]){
				break;
			}
		}
		//j번쨰 빼고 j+1번째부터 넣고, 처음부터 넣고
		q=0;
		for(k=j+1;k<count-i;k++){
			tmp[q++]=num[k];
		}
		for(k=0;k<j;k++){
			tmp[q++]=num[k];
		}
		for(k=0;k<count-i;k++){
			num[k]=tmp[k];
		} 
	
		for(j=0;j<=i;j++){
			printf("%d ",result[j]);
		}
		printf("/ ");
		for(j=0;j<count-i-1;j++){
			printf("%d ",num[j]);
		}
		printf("\n");
		free(queue);
	}
	free(tmp);
	free(string);
	free(result);
	free(num);
	return 0;
}

void push(){
	queue[++tail]=num[j];
}

int pop(){
	int n;
	n=queue[head++];
	return n;
}

