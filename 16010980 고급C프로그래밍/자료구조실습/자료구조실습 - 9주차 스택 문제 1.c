# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void push (char *Stack, char input_ch, int i){
	Stack[i] = input_ch;
}

char pop_and_peek (char *Stack, int i){
	return Stack[i - 1];
}

void upRotate (char *Stack, int StackN, int N){
	char tmp = Stack[StackN - 1];
	int i;

	for (i = StackN - 1 ; i > StackN - N ; i--){
		Stack[i] = Stack[i-1];
	}
	Stack[i] = tmp;
}

void downRotate (char *Stack, int StackN, int N){
	char tmp = Stack[StackN - N];
	int i;

	for (i = StackN - N ; i < StackN - 1 ; i++){
		Stack[i] = Stack[i+1];
	}
	Stack[i] = tmp;
}

void print (char *Stack, int N){
	int i;

	for (i = N - 1 ; i >= 0 ; i--){
		printf("%c", Stack[i]);
	}
	printf("\n");
}

int main(){
	char order[6], *Stack, input_ch, output_ch;
	int i, N, orderN, StackN = 0, Rotate;

	scanf("%d", &N);
	Stack = (char *)malloc(N * sizeof(char));

	scanf("%d", &orderN);
	for (i = 0 ; i < orderN ; i++){
		scanf("%s", order);
		if (strcmp(order, "PUSH") == 0){
			getchar();
			scanf("%c", &input_ch);
			if (StackN == N){
				printf("Stack FULL\n");
			}
			else {
				push(Stack, input_ch, StackN);
				StackN++;
			}
		}
		else if (strcmp(order, "POP") == 0){
			if (StackN == 0){
				printf("Stack Empty\n");
			}
			else {
				StackN--;
				pop_and_peek(Stack, StackN);
			}
		}
		else if (strcmp(order, "PEEK") == 0){
			if (StackN == 0){
				printf("Stack Empty\n");
			}
			else {
				output_ch = pop_and_peek(Stack, StackN);
				printf("%c\n", output_ch);
			}
		}
		else if (strcmp(order, "DUP") == 0){
			if (StackN == N){
				printf("Stack FULL\n");
			}
			else {
				input_ch = pop_and_peek(Stack, StackN);
				push(Stack, input_ch, StackN);
				StackN++;
			}
		}
		else if (strcmp(order, "UpR") == 0){
			getchar();
			scanf("%d", &Rotate);
			if (Rotate <= StackN){
				upRotate(Stack, StackN, Rotate);
			}
		}
		else if (strcmp(order, "DownR") == 0){
			getchar();
			scanf("%d", &Rotate);
			if (Rotate <= StackN){
				downRotate(Stack, StackN, Rotate);
			}
		}
		else if (strcmp(order, "PRINT") == 0){
			print(Stack, StackN);
		}
	}

	return 0;
}