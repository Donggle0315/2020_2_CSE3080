#include <stdio.h>

int rtile(int, int);

int main(){
	int N,M;
	int count;
	scanf("%d %d",&N,&M);
	if(N/10000000000>1||M/10000000000>1){
		printf("input error");
		return 1;
	}
	count=rtile(N,M);

	printf("%d\n", count);

	return 0;
}

int rtile(int N, int M){
	int n,m,i,count;
	for(i=1;i<=N&&i<=M;i*=2){
		;
	}
	if(i>1){
		i/=2;
	}
	count=(N/i)*(M/i);
	n=(N/i)*i;
	m=(M/i)*i;

	if(N-n<=1){
		if(M-m<=1){
			count+=(N-n)*(M-m);
			count+=(N-n)*m;
			count+=n*(M-m);
			return count;
		}
		else{
			count+=(N-n)*M;
			return count + rtile(n,M-m);
		}
	}
	else if(M-m<=1){
		count+=N*(M-m);
		return count+rtile(N-n,m);
	}
	else{
		return count+rtile(N-n,M)+rtile(n,M-m);
	}
}
