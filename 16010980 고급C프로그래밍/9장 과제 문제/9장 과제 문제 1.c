# include <stdio.h>

int main(){
	int i, N, sn;
	int *pi = &i, *pN = &N, *psn = &sn;

	scanf("%d", pN);

	while (*pN != 0){
		*psn = *pN % 10;
		*pN /= 10;
		for (*pi = 0 ; *pi < *psn ; (*pi)++){
			printf("*");
		}
		printf("\n");
	}

	return 0;
}