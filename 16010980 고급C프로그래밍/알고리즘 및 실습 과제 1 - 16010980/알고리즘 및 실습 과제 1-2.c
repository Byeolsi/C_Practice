# include <stdio.h>
# include <stdlib.h>

// Ʈ�� ����ü
typedef struct Tree {
	int data;
	struct Tree *left;
	struct Tree *right;
} NODE;
//

// ��� �߰� �Լ�
/*
	Ʈ���� �����ϴ� �Լ�.
	���� ������ ���� ������ ������ ���� 0 �� ������ �Լ��� ���ȣ���Ͽ� Ʈ���� ����.
	������ȸ ����� ���� Ʈ���� ����.
*/
NODE *Add(){
	int data, left, right;

	// �߰��� ���
	NODE *ADD_NODE;

	// �߰��� ��带 �Ҵ�
	ADD_NODE = (NODE *)malloc(sizeof(NODE));
	ADD_NODE->left = NULL;
	ADD_NODE->right = NULL;

	scanf("%d %d %d", &data, &left, &right);
	
	ADD_NODE->data = data;
	// ���� ������ ���� 0 �� ���
	if (left != 0){
		// �Լ��� ����Ͽ� ȣ��, �׸��� �� �Լ��� return ���� �߰��� ����� left ��尡 �ȴ�.
		ADD_NODE->left = Add();
	}
	//
	// ������ ������ ���� 0 �� ���
	if (right != 0){
		// �Լ��� ����Ͽ� ȣ��, �׸��� �� �Լ��� return ���� �߰��� ����� right ��尡 �ȴ�.
		ADD_NODE->right = Add();
	}
	//

	return ADD_NODE;
}
//

// Ʈ�� Ž�� �Լ�
/*
	���ڿ��� �Է¹��� ���ڴ�� Ʈ���� Ž���ϴ� �Լ�.
	Ʈ���� ��ȸ�ذ��鼭 ��ġ�� �� ����� ������ ���� ����Ѵ�.
*/
void Find(NODE *P_NODE){
	char str[100];
	int i;

	scanf("%s", str);

	// ���ڿ� ������ �ݺ�
	for (i = 0 ; str[i] != '\0' ; i++){
		// Ʈ�� ����� data �� ���
		printf(" %d", P_NODE->data);
		// ���ڿ��� 'L' �� ���
		if (str[i] == 'L'){
			// P_NODE �� left ��带 ����Ŵ.
			P_NODE = P_NODE->left;
		}
		//
		// ���ڿ��� 'R' �� ���
		else if (str[i] == 'R'){
			// P_NODE �� right ��带 ����Ŵ.
			P_NODE = P_NODE->right;
		}
		//
	}
	//
	// ������(���� ����) ��带 ���
	printf(" %d\n", P_NODE->data);
}
//

// Ʈ�� ���� �Լ�
/*
	Ʈ�� ���� �ִ� ��� ��带 �޸� ������Ű�� �Լ�.
	������ȸ ����� ���� ���� �ִ� ������ ���ʴ�� �޸� ������Ų��.
*/
void Clear(NODE *Tree){
	// Ʈ���� ���� ��尡 ������ ���
	if (Tree->left != NULL){
		// Clear �Լ��� ����Ͽ� ȣ�������ν� ������ ������ �̵�
		Clear(Tree->left);
	}
	//
	// Ʈ���� ������ ��尡 ������ ���
	if (Tree->right != NULL){
		// Clear �Լ��� ����Ͽ� ȣ�������ν� ������ ������ �̵�
		Clear(Tree->right);
	}
	//
	// �޸� ����
	free(Tree);
}
//

// main �Լ�
int main(){
	int i, n;

	NODE *Tree;

	scanf("%d", &n);

	// Ʈ�� ����
	Tree = Add();

	scanf("%d", &n);
	// Ʈ�� Ž��
	for (i = 0 ; i < n ; i++){
		Find(Tree);
	}
	//

	// Ʈ�� �޸� ����
	Clear(Tree);

	return 0;
}
//