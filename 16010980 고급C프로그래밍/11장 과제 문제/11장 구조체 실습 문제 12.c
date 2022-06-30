# include <stdio.h>

struct Student {
	char name[10];
	int score_A, score_B, score_C;
	float avg;
};

void read_data(struct Student std[]){
	int i;

	for (i = 0 ; i < 10 ; i++){
		scanf("%s %d %d %d", std[i].name, &(std[i].score_A), &(std[i].score_B), &(std[i].score_C));
	}
}

void cal_avg(struct Student std[]){
	int i;

	for (i = 0 ; i < 10 ; i++){
		std[i].avg = (std[i].score_A + std[i].score_B + std[i].score_C) / 3.0;
	}
}

void sort(struct Student std[]){
	int i, j;
	struct Student tmp_std;

	for (i = 0 ; i < 9 ; i++){
		for (j = 0 ; j < 9 - i ; j++){
			if (std[j].avg < std[j+1].avg){
				tmp_std = std[j];
				std[j] = std[j+1];
				std[j+1] = tmp_std;
			}
		}
	}
}

void print_score(struct Student std[]){
	printf("%s %.2f\n", std[0].name, std[0].avg);
	printf("%s %.2f\n", std[9].name, std[9].avg);
	printf("%s %.2f\n", std[7].name, std[7].avg);
	printf("%s %.2f\n", std[8].name, std[8].avg);
	printf("%s %.2f\n", std[9].name, std[9].avg);
}

int main(){
	struct Student std[10];

	read_data(std);
	cal_avg(std);
	sort(std);
	print_score(std);

	return 0;
}