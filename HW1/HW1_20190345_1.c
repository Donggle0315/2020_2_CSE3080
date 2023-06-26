#include <stdio.h>

int rBC(int ,int);
int BC(int, int);

int main(){
	int n,m,result;
	scanf("%d %d", &n, &m);
	if(n/10000000000>=1||m/10000000000>=1){
		printf("input error");
		return 0;
	}

	result=rBC(n,m);
	printf("%d ",result);

	result=BC(n,m);
	printf("%d\n", result);

	return 0;
}

int rBC(int n, int m){
	if(n==m||m==0){
		return 1;
	}
	else {
		return rBC(n-1,m)+rBC(n-1,m-1);
	}
}

int BC(int n, int m){
	int a=1;
	int i;
	for(i=n;i>n-m;i--){
		a*=i;
	}
	for(i=m;i>0;i--){
		a/=i;
	}
	
	return a;
}
