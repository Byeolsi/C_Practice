#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char **stc, wrd[21];
	int N, i, j, k, wi;

	scanf("%d", &N);
	fflush(stdin);

	stc = (char **)malloc(N * sizeof(char *));
	for (i = 0 ; i < N ; i++){
		stc[i] = (char *)malloc(1000 * sizeof(char));
	}

	for (i = 0 ; i < N ; i++){
		fgets(stc[i], strlen(stc[i]), stdin);
		stc[i][strlen(stc[i])-1] = '\0';
	}

	for (i = 0 ; i < N ; i++){
		j = 0;
		while (stc[i][j] != '\0'){
			if (stc[i][j+1] == ' ' || stc[i][j+1] == '\0'){
				k = j;
				wi = 0;
				while (stc[i][k] != ' '){
					wrd[wi] = stc[i][k];
					wi++;
					k--;
					if (k < 0){
						break;
					}
				}
				if (stc[i][k] == ' '){
					printf(" ");
				}
				wrd[wi] = '\0';
				printf("%s", wrd);
			}
			j++;
		}
		printf("\n");
	}

	for (i = 0 ; i < N ; i++){
		free(stc[i]);
	}
	free(stc);

	return 0;
}