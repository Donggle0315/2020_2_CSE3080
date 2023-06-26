#include <stdio.h>
#include <stdlib.h>

int i;
int *n,*stack;
int top=-1, delete=0;

void push();
void pop();


int main() {
	int num,num_copy,k,count=0,flag=0;
	scanf("%d",&num);
	scanf("%d",&k);
	num_copy=num;
	while(num_copy!=0){
		num_copy/=10;
		count++;
	}
	
	n=(int*)malloc(count*sizeof(int));
	stack=(int*)malloc(count*sizeof(int));
	
	for(i=count-1;i>=0;i--){
		n[i]=num%10;
		num/=10;
	}
	
	for(i=0;i<count;i++){
		while(top!=-1&&delete<k){
			if(stack[top]>n[i]){
				pop();
			}
			else{
				break;
			}
		}
		push();
	}
	
	for(i=0;i<=top;i++){
		if(stack[i]==0&&flag==0){
			continue;
		}
		flag=1;
		printf("%d",stack[i]);
	}
	if(flag==0){
		printf("%d",stack[0]);
	}
	printf("\n");
	
	free(n);
	free(stack);

	return 0;
}

void push(){
	stack[++top]=n[i];
}

void pop(){
	top--;
	delete++;
}
