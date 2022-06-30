# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main(){
	char str[100];
	int i, j, k, l, N, M;
	int **parr;

	scanf("%s", str);

	N = 0;
	for (i = 0 ; i < strlen(str) ; i++){
		if ('A' <= str[i] && str[i] <= 'Z'){
			N++;
		}
	}
	parr = (int **)malloc(N * sizeof(int *));

	M = 0;
	j = 0;
	for (i = 0 ; i < strlen(str) ; i++){
		M++;
		if ('A' <= str[i] && str[i] <= 'Z'){
			l = i;
		}
		if ('A' <= str[i+1] && str[i+1] <= 'Z'){
			parr[j] = (int *)malloc(M * sizeof(int));
			j++;
			for (k = 0 ; k < M ; k++){
				parr[j][k] = str[l];
				l++;
			}
			M = 0;
		}
	}

	for (i = 0 ; i < N ; i++){
		for (j = 0 ; j < strlen(&(parr[i])) ; j++){
