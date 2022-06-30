# include <stdio.h>

int main(){
	int i, N, M, arr[10];
	int *pi = &i, *pN = &N, *pM = &M;

	scanf("%d", pN);
	for (*pi = 0 ; *pi < *pN ; (*pi)++){
		scanf("%d", arr+*pi);
	}
	scanf("%d", pM);

	*pi = 0;
	while (*pM != 0){
		if (*pi == *pN){
			*pi = 0;
		}
		printf(" %d", *(arr+*pi));
		(*pi)++;
		(*pM)--;
	}

	return 0;
}