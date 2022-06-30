# include <stdio.h>
# include <stdlib.h>

typedef struct Stack {
	char elem;
	struct Stack *p_next;
} NODE;

void push(NODE *Oper, char ch){
	NODE *PUSH_NODE;

	PUSH_NODE = (NODE*)malloc(sizeof(NODE));
	
	PUSH_NODE->elem = ch;
	PUSH_NODE->p_next = Oper->p_next;
	Oper->p_next = PUSH_NODE;
}

char pop(NODE *Oper){
	char ch;

	NODE *POP_NODE = Oper->p_next;
	
	Oper->p_next = POP_NODE->p_next;

	ch = POP_NODE->elem;
	
	free(POP_NODE);

	return ch;
}

char peek(NODE *Oper){
	return (Oper->p_next)->elem;
}

void print(char ch){
	if (ch == '|'){
		printf("||");
	}
	else if (ch == '&'){
		printf("&&");
	}
	else if (ch == '@'){
		printf("+");
	}
	else if (ch == '#'){
		printf("-");
	}
	else {
		printf("%c", ch);
	}
}

int Return_prior(char ch1, char ch2, int n){
	if (ch1 == '|'){
		return 1;
	}
	else if (ch1 == '&'){
		return 2;
	}
	else if (ch1 == '<' || ch1 == '>'){
		return 3;
	}
	else if ((ch1 == '+' || ch1 == '-') && (n != 0 && ('A' <= ch2 && ch2 <= 'Z') || ch2 == ')')){
		return 4;
	}
	else if (ch1 == '*' || ch1 == '/'){
		return 5;
	}
	else if (ch1 == '!' || ch1 == '@' || ch1 == '#' || ch1 == '+' || ch1 == '-'){
		return 6;
	}
	else {
		return -1;
	}
}

int main(){
	char Modify[100];
	int i, j, N;

	NODE *Oper;

	Oper = (NODE *)malloc(sizeof(NODE));
	
	Oper->p_next = NULL;

	scanf("%d", &N);

	for (i = 0 ; i < N ; i++){
		scanf("%s", Modify);
		for (j = 0 ; Modify[j] != '\0' ; j++){
			// A ~ Z
			if ('A' <= Modify[j] && Modify[j] <= 'Z'){
				printf("%c", Modify[j]);
			}
			//
			// ! A ~ Z
			else {
				// 중괄호 
				if (Modify[j] == '('){
					push(Oper, Modify[j]);
				}
				else if (Modify[j] == ')'){
					while (peek(Oper) != '('){
						print(pop(Oper));
					}
					pop(Oper);
				}
				//
				// 연산자
				else {
					// | || &
					if (Modify[j] == '|' || Modify[j] == '&'){
						while (Oper->p_next != NULL && Return_prior(Modify[j], 'A', j) <= Return_prior(peek(Oper), 'A', j)){
							print(pop(Oper));
						}
						push(Oper, Modify[j]);
						j++;
					}
					// < || > || * || /
					else if (Modify[j] == '<' || Modify[j] == '>' || Modify[j] == '*' || Modify[j] == '/'){
						while (Oper->p_next != NULL && Return_prior(Modify[j], 'A', j) <= Return_prior(peek(Oper), 'A', j)){
							print(pop(Oper));
						}
						push(Oper, Modify[j]);
					}
					else if (Modify[j] == '!' || Modify[j] == '+' || Modify[j] == '-'){
						if (j == 0){
							if (Modify[j] == '!'){
								push(Oper, '!');
							}
							else if (Modify[j] == '+'){
								push(Oper, '@');
							}
							else if (Modify[j] == '-'){
								push(Oper, '#');
							}
						}
						else {
							if (Return_prior(Modify[j], Modify[j-1], j) == 6){
								while (Oper->p_next != NULL && Return_prior(Modify[j], Modify[j-1], j) < Return_prior(peek(Oper), 'A', j)){
									print(pop(Oper));
								}
								if (Modify[j] == '!'){
									push(Oper, '!');
								}
								else if (Modify[j] == '+'){
									push(Oper, '@');
								}
								else if (Modify[j] == '-'){
									push(Oper, '#');
								}
							}
							else if (Return_prior(Modify[j], Modify[j-1], j) == 4){
								while (Oper->p_next != NULL && Return_prior(Modify[j], Modify[j-1], j) <= Return_prior(peek(Oper), 'A', j)){
									print(pop(Oper));
								}
								push(Oper, Modify[j]);
							}
						}
					}
				}
			}
		}
		while (Oper->p_next != NULL){
			print(pop(Oper));
		}
		printf("\n");
	}

	return 0;
}