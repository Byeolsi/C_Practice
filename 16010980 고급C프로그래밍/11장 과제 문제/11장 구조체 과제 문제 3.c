# include <stdio.h>

struct Student {
	char name[10];
	int score;
};

struct Student *select_min(struct Student std[]){
	int i, j, order;

	for (i = 0 ; i < 5 ; i++){
		order = 0;
		for (j = 0 ; j < 5 ; j++){
			if (std[i].score <= std[j].score){
				order++;
			}
		}
		if (order == 5){
			return &std[i];
		}
	}
	return 0;
}

int main(){
	char input_name[10];
	int i;
	struct Student std[5];
	struct Student *min_std;

	for (i = 0 ; i < 5 ; i++){
		scanf("%s %d", std[i].name, &(std[i].score));
	}

	min_std = select_min(std);

	printf("%s %d", min_std->name, min_std->score);

	return 0;
}