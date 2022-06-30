# include <stdio.h>
# include <stdlib.h>

int main(){
	int i, M, N;
	int arr[10];
	int *pM, *pN;

	scanf("%d %d", &M, &N);

	pM = (int *)calloc(10, sizeof(int));
	pN = (int *)calloc(10, sizeof(int));

	for (i = 0 ; i < M ; i++){
		scanf("%d", pM+i);
	}
	for (i = 0 ; i < N ; i++){
		scanf("%d", pN+i);
	}

	for (i = 0 ; i < (M > N ? M : N) ; i++){
		arr[i] = *(pM+i) + *(pN+i);
	}

	for (i = 0 ; i < (M > N ? M : N) ; i++){
		printf(" %d", arr[i]);
	}

	free(pM);
	free(pN);

	return 0;
}