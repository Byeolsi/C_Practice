// 16010980 이우석
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// Tree 구조체
typedef struct Tree {
	char data[100];
	struct Tree *left;
	struct Tree *right;
} NODE;
//

// makeExternalNode 함수
/*
	외부 노드를 만드는 함수
	결정 노드를 만든다.
*/
NODE *makeExternalNode(){
	NODE *v;

	v = (NODE *)malloc(sizeof(NODE));

	printf("Enter decision: ");
	gets(v->data);
	
	v->left = NULL;
	v->right = NULL;
	
	return v;
}
//

// makeInternalNode 함수
/*
	내부 노드를 만드는 함수
	질문 노드를 만든다.
*/
NODE *makeInternalNode(int N){
	char answer[4];
	
	NODE *v;

	v = (NODE *)malloc(sizeof(NODE));

	printf("Enter question: ");
	gets(v->data);
	
	// 대답이 yes 일 경우,
	printf("Question if yes to \'%s\'? ", v->data);
	
	// N 을 1 증가시킨다. 이 과정에서 함수를 호출할 때, 더 큰 수로 N 이 인자로 들어간다.
	N++;
	// 질문 갯수가 3 ~ 5 인지 확인한다. 만일, 아니라면 반복한다.
	do {
		gets(answer);
		if (strcmp(answer, "yes") != 0 && N < 3 || strcmp(answer, "yes") == 0 && N > 4){
			printf("need 3 ~ 5 questions\n");
			printf("Question if yes to \'%s\'? ", v->data);
		}
	} while (strcmp(answer, "yes") != 0 && N < 3 || strcmp(answer, "yes") == 0 && N > 4);
	//

	// 재귀 부분
	if (strcmp(answer, "yes") == 0)
		v->left = makeInternalNode(N);
	else
		v->left = makeExternalNode();
	//

	// 대답이 no 일 경우,
	printf("Question if no to \'%s\'? ", v->data);

	// 질문 갯수가 3 ~ 5 인지 확인한다. 만일, 아니라면 반복한다.
	do {
		gets(answer);
		if (strcmp(answer, "yes") != 0 && N < 3 || strcmp(answer, "yes") == 0 && N > 4){
			printf("need 3 ~ 5 questions\n");
			printf("Question if no to \'%s\'? ", v->data);
		}
	} while (strcmp(answer, "yes") != 0 && N < 3 || strcmp(answer, "yes") == 0 && N > 4);

	// 재귀 부분
	if (strcmp(answer, "yes") == 0)
		v->right = makeInternalNode(N);
	else
		v->right = makeExternalNode();
	//

	return v;
}
//

// processNode 함수
/*
	원하는 답을 찾기 위한 함수
*/
void processNode(NODE *v){
	char answer[4];
	
	// 질문 노드인 경우,
	if (v->left != NULL || v->right != NULL){
		printf("%s ", v->data);
		gets(answer);
	}
	//
	// 결정 노드인 경우,
	else {
		printf("%s\n", v->data);
	}
	//

	// 재귀 부분
	if (v->left != NULL || v->right != NULL){
		if (strcmp(answer, "yes") == 0)
			processNode(v->left);
		else
			processNode(v->right);
	}
	//
}
//

// buildDecisionTree 함수
/*
	makeInternalNode 의 Driver
*/
NODE *buildDecisionTree(int N){
	NODE *v;

	printf("***Let's build a dichotomous QA system\n");
	v = makeInternalNode(N);
	return v;
}
//

// runDecisionTree 함수
/*
	processNode 의 Driver
*/
void runDecisionTree(NODE *v){
	printf("***Please answer questions\n");
	processNode(v);
}
//

// main 함수
int main(){
	int i;

	NODE *v;

	v = buildDecisionTree(0);

	// 3 번 찾음
	for (i = 0 ; i < 3 ; i++){
		runDecisionTree(v);
	}
	//
	return 0;
}
//