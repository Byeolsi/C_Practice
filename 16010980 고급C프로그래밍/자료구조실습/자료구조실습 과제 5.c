// 16010980 이우석
# include <stdio.h>
# include <stdlib.h>

// Tree 구조체
typedef struct Tree {
	struct Tree *left;
	struct Tree *right;
} NODE;
//

// Queue 구조체
typedef struct Queue {
	// Tree 노드를 가리키는 구조체 포인터
	struct Tree *p_NODE;
	struct Queue *p_next;
} Q;
//

// initTree 함수
/*
	고정된 트리를 생성한다.
*/
NODE *initTree(){
	int i;
	
	// 노드를 할당하는데 헷갈리지 않도록 포인터 배열로 초기화
	NODE *T, *T0[19], *T1[9];

	T = (NODE *)malloc(sizeof(NODE));
	T->left = NULL;
	T->right = NULL;
	for (i = 0 ; i < 19 ; i++){
		T0[i] = (NODE *)malloc(sizeof(NODE));
		T0[i]->left = NULL;
		T0[i]->right = NULL;
	}
	for (i = 0 ; i < 9 ; i++){
		T1[i] = (NODE *)malloc(sizeof(NODE));
		T1[i]->left = NULL;
		T1[i]->right = NULL;
	}

	// T
	T->left = T0[0];
	T->right = T1[0];
	//

	// T0[0]
	T0[0]->left = T0[1];
	T0[0]->right = T0[2];
	//
	// T0[1]
	T0[1]->left = T0[3];
	T0[1]->right = T0[4];
	//
	// T0[2]
	T0[2]->left = T0[5];
	T0[2]->right = T0[6];
	//
	// T0[3]
	T0[3]->left = T0[7];
	T0[3]->right = T0[8];
	//
	// T0[4]
	T0[4]->left = NULL;
	T0[4]->right = NULL;
	//
	// T0[5]
	T0[5]->left = T0[9];
	T0[5]->right = T0[10];
	//
	// T0[6]
	T0[6]->left = T0[11];
	T0[6]->right = T0[12];
	//
	// T0[7]
	T0[7]->left = NULL;
	T0[7]->right = NULL;
	//
	// T0[8]
	T0[8]->left = T0[13];
	T0[8]->right = T0[14];
	//
	// T0[9]
	T0[9]->left = NULL;
	T0[9]->right = NULL;
	//
	// T0[10]
	T0[10]->left = NULL;
	T0[10]->right = NULL;
	//
	// T0[11]
	T0[11]->left = NULL;
	T0[11]->right = NULL;
	//
	// T0[12]
	T0[12]->left = NULL;
	T0[12]->right = NULL;
	//
	// T0[13]
	T0[13]->left = NULL;
	T0[13]->right = NULL;
	//
	// T0[14]
	T0[14]->left = T0[15];
	T0[14]->right = T0[16];
	//
	// T0[15]
	T0[15]->left = T0[17];
	T0[15]->right = T0[18];
	//
	// T0[16]
	T0[16]->left = NULL;
	T0[16]->right = NULL;
	//
	// T0[17]
	T0[17]->left = NULL;
	T0[17]->right = NULL;
	//
	// T0[18]
	T0[18]->left = NULL;
	T0[18]->right = NULL;
	//

	// T1[0]
	T1[0]->left = T1[1];
	T1[0]->right = T1[2];
	//
	// T1[1]
	T1[1]->left = NULL;
	T1[1]->right = NULL;
	//
	// T1[2]
	T1[2]->left = T1[3];
	T1[2]->right = T1[4];
	//
	// T1[3]
	T1[3]->left = T1[5];
	T1[3]->right = T1[6];
	//
	// T1[4]
	T1[4]->left = T1[7];
	T1[4]->right = T1[8];
	//
	// T1[5]
	T1[5]->left = NULL;
	T1[5]->right = NULL;
	//
	// T1[6]
	T1[6]->left = NULL;
	T1[6]->right = NULL;
	//
	// T1[7]
	T1[7]->left = NULL;
	T1[7]->right = NULL;
	//
	// T1[8]
	T1[8]->left = NULL;
	T1[8]->right = NULL;
	//

	return T;
}
//

// Enqueue 함수
/*
	Tree 노드를 큐에 삽입한다.
	단순하게 삽입하는 것이 아니라 해당 트리 노드를 가리키는 큐 노드를 생성한다.
*/
void Enqueue(Q *QH, NODE *v){
	Q *ADD_Q, *PQ = QH;

	ADD_Q = (Q *)malloc(sizeof(Q));

	while (PQ->p_next != NULL){
		PQ = PQ->p_next;
	}

	ADD_Q->p_NODE = v;
	ADD_Q->p_next = PQ->p_next;
	PQ->p_next = ADD_Q;
}
//

// Dequeue 함수
/*
	큐에서 Tree 노드를 제거한다.
	Tree 노드를 제거하면서 제거한 노드를 Return 한다.
*/
NODE *Dequeue(Q *QH){
	Q *PQ = QH->p_next;
	NODE *R_NODE;

	QH->p_next = PQ->p_next;

	R_NODE = PQ->p_NODE;

	free(PQ);

	return R_NODE;
}
//

// romanSize 함수
/*
	부트리의 크기를 구한다.
*/
int romanSize(NODE *v, int *check){
	int l, r;
	
	// 외부 노드일 경우, 1 을 Return
	if (v->left == NULL && v->right == NULL){
		return 1;
	}
	//

	// 현재 v 노드의 왼쪽 부트리의 크기
	l = romanSize(v->left, check);
	// 현재 v 노드의 오른쪽 부트리의 크기
	r = romanSize(v->right, check);

	// 노드를 순회하면서 로만 노드가 하나라도 아니라면 check 의 값은 0 이 됨
	if (-5 > l-r || l-r > 5){
		*check = 0;
	}
	//

	// 현재 부트리의 총 크기를 Return
	return l+r+1;
}
//

// isEmperor 함수
/*
	Emperor 노드인지 확인한다.
	romanSize 함수를 실행하기 위한 일종의 Driver 함수이다.
	현재 v 노드의 왼쪽 부트리의 크기와 오른쪽 부트리의 크기를 비교하여 v 노드가 로만 노드가 아닌지 검사한다.
	또한, romanSize 함수를 돌고나서도 check 가 1 인지 검사한다.
	만약, 위 두 조건이 성립한다면, 1 을 Return 하고 아니라면, 0 을 Return 한다.
*/
int isEmperor(NODE *v){
	int check = 1, l, r;

	l = romanSize(v->left, &check);
	r = romanSize(v->right, &check);

	if (check == 1 && (-5 > l-r || l-r > 5)){
		return 1;
	}
	else {
		return 0;
	}
}
//

// LevelOrder 함수
/*
	레벨 순회를 수행한다.
	조금 다른 점이라면, 내부 노드만을 순회한다.
*/
void LevelOrder(NODE *v){
	int Order = 0, EmperorN = 0;

	Q *QH;
	NODE *tmp;

	QH = (Q *)malloc(sizeof(Q));
	QH->p_next = NULL;

	Enqueue(QH, v);

	while (QH->p_next != NULL){
		tmp = Dequeue(QH);
		Order++;
		
		// tmp 노드가 Emperor 노드인지 확인
		if (isEmperor(tmp)){
			printf("%d	황제노드\n", Order);
			EmperorN++;
		}
		//

		// 내부 노드만을 순회하기 위해 if 조건문을 다르게 함
		if ((tmp->left)->left != NULL || (tmp->left)->right != NULL){
			Enqueue(QH, tmp->left);
		}
		if ((tmp->right)->left != NULL || (tmp->right)->right != NULL){
			Enqueue(QH, tmp->right);
		}
		//
	}

	printf("방문한 내부 노드 수 %d개, 황제노드 수 %d개\n", Order, EmperorN);
}
//

// main 함수
int main(){
	NODE *T;

	T = initTree();

	LevelOrder(T);

	return 0;
}
//