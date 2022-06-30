# include <stdio.h>
# include <stdlib.h>

typedef struct Stack {
	int elem;
	struct Stack *p_next;
} NODE;

void push (NODE *ACC, int n){
	NODE *ADD_NODE;

	ADD_NODE = (NODE *)malloc(sizeof(NODE));

	ADD_NODE->elem = n;

	ADD_NODE->p_next = ACC->p_next;
	ACC->p_next = ADD_NODE;
}

int pop (NODE *ACC){
	int n;
	
	NODE *POP_NODE = ACC->p_next;

	n = POP_NODE->elem;

	ACC->p_next = POP_NODE->p_next;

	free(POP_NODE);

	return n;
}

int calc (int a, int b, char oper){
	if (oper == '+')
		return b+a;
	else if (oper == '-')
		return b-a;
	else if (oper == '*')
		return b*a;
	else if (oper == '/')
		return b/a;
	else 
		return -1;
}

int main(){
	char Modify[100];
	int i, j, N, inputN, a, b;
	
	NODE *ACC;

	ACC = (NODE *)malloc(sizeof(NODE));

	ACC->p_next = NULL;

	scanf("%d", &N);
	for (i = 0 ; i < N ; i++){
		scanf("%s", Modify);
		for (j = 0 ; Modify[j] != '\0' ; j++){
			if ('0' <= Modify[j] && Modify[j] <= '9'){
				push(ACC, Modify[j] - '0');
			}
			else {
				a = pop(ACC);
				b = pop(ACC);
				push(ACC, calc(a, b, Modify[j]));
			}
		}
		printf("%d\n", pop(ACC));
	}

	return 0;
}