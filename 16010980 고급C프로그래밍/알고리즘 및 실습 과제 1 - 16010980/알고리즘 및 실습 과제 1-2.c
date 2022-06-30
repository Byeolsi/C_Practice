# include <stdio.h>
# include <stdlib.h>

// 트리 구조체
typedef struct Tree {
	int data;
	struct Tree *left;
	struct Tree *right;
} NODE;
//

// 노드 추가 함수
/*
	트리를 생성하는 함수.
	왼쪽 데이터 값과 오른쪽 데이터 값이 0 일 때까지 함수를 재귀호출하여 트리를 생성.
	전위순회 방식을 통해 트리를 생성.
*/
NODE *Add(){
	int data, left, right;

	// 추가할 노드
	NODE *ADD_NODE;

	// 추가할 노드를 할당
	ADD_NODE = (NODE *)malloc(sizeof(NODE));
	ADD_NODE->left = NULL;
	ADD_NODE->right = NULL;

	scanf("%d %d %d", &data, &left, &right);
	
	ADD_NODE->data = data;
	// 왼쪽 데이터 값이 0 일 경우
	if (left != 0){
		// 함수를 재귀하여 호출, 그리고 그 함수의 return 값이 추가할 노드의 left 노드가 된다.
		ADD_NODE->left = Add();
	}
	//
	// 오른쪽 데이터 값이 0 일 경우
	if (right != 0){
		// 함수를 재귀하여 호출, 그리고 그 함수의 return 값이 추가할 노드의 right 노드가 된다.
		ADD_NODE->right = Add();
	}
	//

	return ADD_NODE;
}
//

// 트리 탐색 함수
/*
	문자열의 입력받은 문자대로 트리를 탐색하는 함수.
	트리를 순회해가면서 거치게 된 노드의 데이터 값을 출력한다.
*/
void Find(NODE *P_NODE){
	char str[100];
	int i;

	scanf("%s", str);

	// 문자열 끝까지 반복
	for (i = 0 ; str[i] != '\0' ; i++){
		// 트리 노드의 data 를 출력
		printf(" %d", P_NODE->data);
		// 문자열이 'L' 일 경우
		if (str[i] == 'L'){
			// P_NODE 가 left 노드를 가리킴.
			P_NODE = P_NODE->left;
		}
		//
		// 문자열이 'R' 일 경우
		else if (str[i] == 'R'){
			// P_NODE 가 right 노드를 가리킴.
			P_NODE = P_NODE->right;
		}
		//
	}
	//
	// 마지막(최종 도착) 노드를 출력
	printf(" %d\n", P_NODE->data);
}
//

// 트리 해제 함수
/*
	트리 내에 있는 모든 노드를 메모리 해제시키는 함수.
	후위순회 방식을 통해 끝에 있는 노드부터 차례대로 메모리 해제시킨다.
*/
void Clear(NODE *Tree){
	// 트리의 왼쪽 노드가 존재할 경우
	if (Tree->left != NULL){
		// Clear 함수를 재귀하여 호출함으로써 마지막 노드까지 이동
		Clear(Tree->left);
	}
	//
	// 트리의 오른쪽 노드가 존재할 경우
	if (Tree->right != NULL){
		// Clear 함수를 재귀하여 호출함으로써 마지막 노드까지 이동
		Clear(Tree->right);
	}
	//
	// 메모리 해제
	free(Tree);
}
//

// main 함수
int main(){
	int i, n;

	NODE *Tree;

	scanf("%d", &n);

	// 트리 구성
	Tree = Add();

	scanf("%d", &n);
	// 트리 탐색
	for (i = 0 ; i < n ; i++){
		Find(Tree);
	}
	//

	// 트리 메모리 해제
	Clear(Tree);

	return 0;
}
//