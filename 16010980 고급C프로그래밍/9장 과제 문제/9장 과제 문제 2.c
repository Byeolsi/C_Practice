# include <stdio.h>

void fib(int arr[]){
	*arr = *(arr+1);
	*(arr+1) = *(arr+2);
	*(arr+2) = *(arr+1) + *arr;
}

int main(){
	int i, N, arr[3] = {1, 1, 1};
	int *pi = &i, *pN = &N;

	scanf("%d", pN);

	for (*pi = 2 ; *pi < *pN ; (*pi)++){
		fib(arr);
	}

	printf("%d", *(arr+2));

	return 0;
}