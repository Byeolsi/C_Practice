# include <stdio.h>
# include <stdlib.h>

typedef struct Node {
	int key;
	int height;
	struct Node *parent;
	struct Node *p_left;
	struct Node *p_right;
} NODE;

NODE *restructure(NODE **R, NODE *x){
	NODE *a, *b, *c, *T0, *T1, *T2, *T3;
	NODE *y = x->parent;
	NODE *z = y->parent;

	if (z->key < y->key && y->key < x->key){
		a = z;
		b = y;
		c = x;
		T0 = a->p_left;
		T1 = b->p_left;
		T2 = c->p_left;
		T3 = c->p_right;
	}
	else if (x->key < y->key && y->key < z->key){
		a = x;
		b = y;
		c = z;
		T0 = a->p_left;
		T1 = a->p_right;
		T2 = b->p_right;
		T3 = c->p_right;
	}
	else if (z->key < x->key && x->key < y->key){
		a = z;
		b = x;
		c = y;
		T0 = a->p_left;
		T1 = b->p_left;
		T2 = b->p_right;
		T3 = c->p_right;
	}
	else {
		a = y;
		b = x;
		c = z;
		T0 = a->p_left;
		T1 = b->p_left;
		T2 = b->p_right;
		T3 = c->p_right;
	}

	if (z == *R){
		*R = b;
		b->parent = NULL;
	}
	else if ((z->parent)->p_left == z){
		(z->parent)->p_left = b;
		b->parent = z->parent;
	}
	else {
		(z->parent)->p_right = b;
		b->parent = z->parent;
	}

	b->p_left = a;
	a->parent = b;

	a->p_left = T0;
	if (T0 != NULL){
		T0->parent = a;
	}
	a->p_right = T1;
	if (T1 != NULL){
		T1->parent = a;
	}

	b->p_right = c;
	c->parent = b;

	c->p_left = T2;
	if (T2 != NULL){
		T2->parent = c;
	}
	c->p_right = T3;
	if (T3 != NULL){
		T3->parent = c;
	}

	return b;
}

// heightUpdateAndBalanceCheck 함수
/*
	노드의 높이 업데이트 및 균형검사
*/
int heightUpdateAndBalanceCheck(NODE *P){
	int balance = 0;

	NODE *l, *r;
	
	if (P == NULL){
		return 1;
	}

	l = P->p_left;
	r = P->p_right;

	if (l != NULL){
		if (l->p_left != NULL || l->p_right != NULL){
			if (l->p_left == NULL){
				l->height = (l->p_right)->height + 1;
			}
			else if (l->p_right == NULL){
				l->height = (l->p_left)->height + 1;
			}
			else if ((l->p_left)->height > (l->p_right)->height){
				l->height = (l->p_left)->height + 1;
			}
			else {
				l->height = (l->p_right)->height + 1;
			}
		}
		else {
			l->height = 1;
		}
	}
	if (r != NULL){
		if (r->p_left != NULL || r->p_right != NULL){
			if (r->p_left == NULL){
				r->height = (r->p_right)->height + 1;
			}
			else if (r->p_right == NULL){
				r->height = (r->p_left)->height + 1;
			}
			else if ((r->p_left)->height > (r->p_right)->height){
				r->height = (r->p_left)->height + 1;
			}
			else {
				r->height = (r->p_right)->height + 1;
			}
		}
		else {
			r->height = 1;
		}
	}

	if (l == NULL && r == NULL){
		balance = 0;
	}
	else if (l == NULL){
		balance = r->height;
	}
	else if (r == NULL){
		balance = l->height;
	}
	else {
		if (l->height > r->height){
			balance = l->height - r->height;
		}
		else {
			balance = r->height - l->height;
		}
	}

	return balance < 2;
}

// searchAndRepairAfterInsertion 함수
/* 
	균형검사를 수행하고 불균형이 있으면 개조를 통해 높이균형 속성을 회복하여 반환
*/
void searchAndRepairAfterInsertion(NODE **R, NODE *P){
	NODE *x, *y, *z = P;

	while (heightUpdateAndBalanceCheck(z)){
		if (z->parent == NULL){
			return;
		}
		z = z->parent;
	}

	if (z->p_left != NULL && z->p_right != NULL){
		if ((z->p_left)->height > (z->p_right)->height){
			y = z->p_left;
		}
		else {
			y = z->p_right;
		}
	}
	else if (z->p_left == NULL){
		y = z->p_right;
	}
	else {
		y = z->p_left;
	}

	if (y->p_left != NULL && y->p_right != NULL){
		if ((y->p_left)->height > (y->p_right)->height){
			x = y->p_left;
		}
		else {
			x = y->p_right;
		}
	}
	else if (y->p_left == NULL){
		x = y->p_right;
	}
	else {
		x = y->p_left;
	}

	restructure(R, x);
	
	while (heightUpdateAndBalanceCheck(z)){
		if (z->parent == NULL){
			return;
		}
		z = z->parent;
	}
 }

void insertNode(NODE **R, int key){
	NODE *P = *R, *ADD_NODE;

	ADD_NODE = (NODE *)malloc(sizeof(NODE));
	ADD_NODE->key = key;
	ADD_NODE->parent = NULL;
	ADD_NODE->p_left = NULL;
	ADD_NODE->p_right = NULL;

	if (P == NULL){
		*R = ADD_NODE;
	}
	else {
		while (P != NULL){
			if (key > P->key){
				if (P->p_right == NULL){
					P->p_right = ADD_NODE;
					ADD_NODE->parent = P;
					searchAndRepairAfterInsertion(R, ADD_NODE);
					return;
				}
				P = P->p_right;
			}
			else {
				if (P->p_left == NULL){
					P->p_left = ADD_NODE;
					ADD_NODE->parent = P;
					searchAndRepairAfterInsertion(R, ADD_NODE);
					return;
				}
				P = P->p_left;
			}
		}
	}
}

int searchKey(NODE *R, int key){
	NODE *P = R;

	while (P != NULL){
		if (P->key > key){
			P = P->p_left;
		}
		else if (P->key < key){
			P = P->p_right;
		}
		else {
			return P->key;
		}
	}
	return -1;
}

int deleteNode(NODE **R, int key){
	int result;

	NODE *P = *R, *DELETE_NODE;

	result = searchKey(*R, key);
	if (result == -1){
		return -1;
	}
	else {
		while (P->key != key){
			if (P->key > key){
				P = P->p_left;
			}
			else if (P->key < key){
				P = P->p_right;
			}
		}

		DELETE_NODE = P;
		// 삭제할 노드 왼쪽 자식이 있을 경우
		if (DELETE_NODE->p_left != NULL){
			// 삭제할 노드 왼쪽 오른쪽 자식이 있을 경우
			if (DELETE_NODE->p_right != NULL){
				// 삭제할 노드 왼쪽 오른쪽 자식이 있고, 오른쪽 자식의 왼쪽 자식이 있을 경우
				if ((DELETE_NODE->p_right)->p_left != NULL){
					P = (P->p_right)->p_left;

					// 왼쪽 자식이 없을 때 까지 P 이동
					while (P->p_left != NULL){
						P = P->p_left;
					}

					// P 의 오른쪽 자식이 있을 경우
					if (P->p_right != NULL){
						(P->p_right)->parent = P->parent;
						(P->parent)->p_left = P->p_right;
					}
					else {
						(P->parent)->p_left = NULL;
					}

					P->parent = DELETE_NODE->parent;
					if (DELETE_NODE != *R){
					// 삭제할 노드가 parent 의 왼쪽 자식일 경우
						if ((DELETE_NODE->parent)->p_left == DELETE_NODE){
							(DELETE_NODE->parent)->p_left = P;
						}
						// 삭제할 노드가 parent 의 오른쪽 자식일 경우
						else if ((DELETE_NODE->parent)->p_right == DELETE_NODE){
							(DELETE_NODE->parent)->p_right = P;
						}
					}
					else {
						*R = P;
					}
					P->p_left = DELETE_NODE->p_left;
					(P->p_left)->parent = P;
					P->p_right = DELETE_NODE->p_right;
					(P->p_right)->parent = P;
				}
				// 왼쪽 자식과 오른쪽 자식이 있지만, 오른쪽 자식의 왼쪽 자식이 없는 경우
				else {
					P = P->p_right;
					
					P->parent = DELETE_NODE->parent;
					if (DELETE_NODE != *R){
						if ((DELETE_NODE->parent)->p_left == DELETE_NODE){
							(DELETE_NODE->parent)->p_left = P;
						}
						else if ((DELETE_NODE->parent)->p_right == DELETE_NODE){
							(DELETE_NODE->parent)->p_right = P;
						}
					}
					else {
						*R = P;
					}
					P->p_left = DELETE_NODE->p_left;
					(P->p_left)->parent = P;
				}
			}
			// 왼쪽 자식만 있는 경우
			else {
				P = P->p_left;

				P->parent = DELETE_NODE->parent;
				if (DELETE_NODE != *R){
					if ((DELETE_NODE->parent)->p_left == DELETE_NODE){
						(DELETE_NODE->parent)->p_left = P;
					}
					else if ((DELETE_NODE->parent)->p_right == DELETE_NODE){
						(DELETE_NODE->parent)->p_right = P;
					}
				}
				else {
					*R = P;
				}
			}
		}
		// 왼쪽 자식은 없지만, 오른쪽 자식이 있는 경우
		else if (P->p_right != NULL){
			P = P->p_right;

			P->parent = DELETE_NODE->parent;
			if (DELETE_NODE != *R){
				if ((DELETE_NODE->parent)->p_left == DELETE_NODE){
					(DELETE_NODE->parent)->p_left = P;
				}
				else if ((DELETE_NODE->parent)->p_right == DELETE_NODE){
					(DELETE_NODE->parent)->p_right = P;
				}
			}
			else {
				*R = P;
			}
		}
		// 자식이 없는 경우
		else {
			if (DELETE_NODE != *R){
				if ((DELETE_NODE->parent)->p_left == DELETE_NODE){
					(DELETE_NODE->parent)->p_left = NULL;
				}
				else if ((DELETE_NODE->parent)->p_right == DELETE_NODE){
					(DELETE_NODE->parent)->p_right = NULL;
				}
			}
			else {
				*R = P;
			}
		}
		free(DELETE_NODE);

		return result;
	}
}

void printTree(NODE *P){

	printf(" %d", P->key);
	if (P->p_left != NULL){
		printTree(P->p_left);
	}
	if (P->p_right != NULL){
		printTree(P->p_right);
	}
}

void clear(NODE **R, NODE *P){
	if (P->p_left != NULL){
		clear(R, P->p_left);
	}
	if (P->p_right != NULL){
		clear(R, P->p_right);
	}
	deleteNode(R, P->key);
}

int main(){
	char order;
	int key, result;
	
	NODE *R = NULL;

	scanf("%c", &order);
	while (order != 'q'){
		switch (order){
		case 'i':
			scanf("%d", &key);
			insertNode(&R, key);
			break;
		/*
		case 'd':
			scanf("%d", &key);
			result = deleteNode(&R, key);
			if (result == -1){
				printf("X\n");
			}
			else {
				printf("%d\n", result);
			}
			break;
		*/
		case 's':
			scanf("%d", &key);
			result = searchKey(R, key);
			if (result == -1){
				printf("X\n");
			}
			else {
				printf("%d\n", result);
			}
			break;
		case 'p':
			printTree(R);
			printf("\n");
			break;
		}
		scanf("%c", &order);
	}

	clear(&R, R);

	return 0;
}