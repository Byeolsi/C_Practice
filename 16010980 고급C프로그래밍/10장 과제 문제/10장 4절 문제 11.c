# include <stdio.h>

int main(){
	char *strnum[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	char *strdigit[] = {"", "TEN", "HUN", "THO"};
	int N, num, digit = 3, divide = 1000;

	scanf("%d", &N);

	while (N != 0){
		num = N / divide;
		N %= divide;
		divide /= 10;
		if (num != 0){
			printf("%s %s ", *(strnum+num-1), *(strdigit+digit));
		}
		digit--;
	}

	return 0;
}