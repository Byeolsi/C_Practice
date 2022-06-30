# include <stdio.h>

int main(){
	int i, j, N, tmp, arr[10];
	int *pi = &i, *pj = &j, *pN = &N, *ptmp = &tmp;

	scanf("%d", pN);

	for (*pi = 0 ; *pi < *pN ; (*pi)++){
		scanf("%d", arr+*pi);
	}

	for (*pi = 1 ; *pi < *pN ; *pi += 2){
		for (*pj = *pN - 1 ; *pj > *pi ; (*pj)--){
			*ptmp = *(arr+*pj-1);
			*(arr+*pj-1) = *(arr+*pj);
			*(arr+*pj) = *ptmp;
		}
	}

	for (*pi = 0 ; *pi < *pN ; (*pi)++){
		printf(" %d", *(arr+*pi));
	}

	return 0;
}