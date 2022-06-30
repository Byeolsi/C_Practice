# include <stdio.h>
# include <stdlib.h>

// ��� ����ü
typedef struct Node {
	char item;
	struct Node *p_next;
} NODE;
//

// ��� �߰� �Լ�
void Add(NODE *list, int pos, char item){
	int i;
	
	// �߰��� ���� ��� ������
	NODE *ADD_NODE, *P_NODE = list;
	
	// �߰��� ��� �޸� �Ҵ�
	ADD_NODE = (NODE *)malloc(sizeof(NODE));
	ADD_NODE->item = item;
	
	// �ش� pos ���� P_NODE �� �̵�
	for (i = 1 ; i < pos ; i++){
		P_NODE = P_NODE->p_next;
	}
	//
	
	// P_NODE ������ ADD_NODE ����
	ADD_NODE->p_next = P_NODE->p_next;
	P_NODE->p_next = ADD_NODE;
	//
}
//

// ��� ���� �Լ�
void Delete(NODE *list, int pos){
	int i;
	
	// ������ ��带 ����ų �����Ϳ� ��� ������
	NODE *DELETE_NODE, *P_NODE = list;
	
	// �ش� pos ���� P_NODE �� �̵�
	for (i = 1 ; i < pos ; i++){
		P_NODE = P_NODE->p_next;
	}
	//
	
	// P_NODE �� ���� ��带 ������ ���(DELETE_NODE) �ν� ����
	DELETE_NODE = P_NODE->p_next;
	// DELETE_NODE �� ����Ʈ ������ �и�
	P_NODE->p_next = DELETE_NODE->p_next;
	
	// �޸� ����
	free(DELETE_NODE);
}
//

// ����Ʈ Ž�� �Լ�
char Get_entry(NODE *list, int pos){
	int i;
	
	NODE *P_NODE = list;
	
	// �ش� pos ���� P_NODE �� �̵�
	for (i = 0 ; i < pos ; i++){
		P_NODE = P_NODE->p_next;
	}
	//
	
	// item �� return
	return P_NODE->item;
}
//

// ����Ʈ ��� �Լ�
void Print(NODE *list){
	NODE *P_NODE = list->p_next;
	
	// ������ ������ �̵��ϸ� item �� ���
	while (P_NODE != NULL){
		printf("%c", P_NODE->item);
		P_NODE = P_NODE->p_next;
	}
	//
	printf("\n");
}
//

// ����Ʈ ���� �Լ�
void Clear(NODE *list){
	// ����Ʈ �� ��尡 �������� ���� ������ ����ؼ� ù��° ��� ����
	while(list->p_next != NULL){
		Delete(list, 1);
	}
	//
}
//

// main �Լ�
int main(){
	char order, item, entry;
	int i, n, pos, list_n = 0;
	
	// ����Ʈ ���
	NODE *list;
	
	// ����Ʈ ��� �޸� �Ҵ�
	list = (NODE *)malloc(sizeof(NODE));
	list->p_next = NULL;
	
	// ���� ��� Ƚ��
	scanf("%d", &n);
	
	for (i = 0 ; i < n ; i++){
		getchar();
		scanf("%c", &order);
		if (order == 'A'){
			scanf("%d %c", &pos, &item);
			// ���� ó��
			if (pos <= 0 || list_n + 1 < pos){
				printf("invalid position\n");
			}
			//
			else {
				Add(list, pos, item);
				list_n++;
			}
		}
		else if (order == 'D'){
			scanf("%d", &pos);
			// ���� ó��
			if (pos <= 0 || list_n < pos){
				printf("invalid position\n");
			}
			//
			else {
				Delete(list, pos);
				list_n--;
			}
		}
		else if (order == 'G'){
			scanf("%d", &pos);
			// ���� ó��
			if (pos <= 0 || list_n < pos){
				printf("invalid position\n");
			}
			//
			else {
				entry = Get_entry(list, pos);
				printf("%c\n", entry);
			}
		}
		else if (order == 'P'){
			Print(list);
		}
	}
	
	// ����Ʈ �޸� ����
	Clear(list);
	
	return 0;
}
//