# include <stdio.h>
# include <string.h>

struct Student {
	char name[10];
	int score;
};

int main(){
	char input_name[10];
	int i;
	struct Student std[5];

	for (i = 0 ; i < 5 ; i++){
		scanf("%s %d", std[i].name, &(std[i].score));
	}

	scanf("%s", input_name);

	for (i = 0 ; i < 5 ; i++){
		if (strcmp(input_name, std[i].name) == 0){
			printf("%d", std[i].score);
		}
	}

	return 0;
}