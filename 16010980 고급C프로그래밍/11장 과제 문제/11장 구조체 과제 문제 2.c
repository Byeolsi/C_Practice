# include <stdio.h>

struct Student {
	char name[10];
	int score;
};

int select_N(struct Student std[], int N){
	int i, j, order;

	for (i = 0 ; i < 5 ; i++){
		order = 0;
		for (j = 0 ; j < 5 ; j++){
			if (std[i].score <= std[j].score){
				order++;
			}
		}
		if (N == order){
			return i;
		}
	}
	return 0;
}

int main(){
	char input_name[10];
	int i, N, index_N;
	struct Student std[5];

	for (i = 0 ; i < 5 ; i++){
		scanf("%s %d", std[i].name, &(std[i].score));
	}

	scanf("%d", &N);

	index_N = select_N(std, N);

	printf("%s %d", std[index_N].name, std[index_N].score);

	return 0;
}