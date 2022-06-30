# include <stdio.h>
# include <stdlib.h>

// �׷� ��� ��, ���� ���� ����
# define NG 5
# define NE 4
//

// ����ü ���
typedef struct node {
	char member;
	int coupon;
	
	// �׷��� ���� ��带 ����Ŵ.
	struct node *p_gnext;
	// ������ ���� ��带 ����Ŵ.
	struct node *p_enext;
} NODE;
//

// Insert �Լ�
void Insert(NODE *PGH, NODE *PEH){
	NODE *PN;
	NODE *InsertN;

	InsertN = (NODE *)malloc(sizeof(NODE));

	scanf("%d %c", &(InsertN->coupon), &(InsertN->member));
	// ���� ���� �Է��� �޾Ҵ��� Ȯ��
	if ((InsertN->coupon < 1 || InsertN->coupon > 4) || (InsertN->member < 'A' || InsertN->member > 'E')){
		printf("ERROR ! - Exceed a permitted limit.\n");
		free(InsertN);
		return;
	}
	//

	// �׷� ����Ʈ�� �� ��带 ����
	PN = &(PGH[InsertN->member - 'A']);
	while (PN->p_gnext != NULL){
		// �̹� ������ ������ ���,
		if (InsertN->coupon == (PN->p_gnext)->coupon){
			printf("ERROR ! - Already have this coupon\n");
			free(InsertN);
			return;
		}
		//
		if (InsertN->coupon < (PN->p_gnext)->coupon){
			break;
		}
		PN = PN->p_gnext;
	}

	InsertN->p_gnext = PN->p_gnext;
	PN->p_gnext = InsertN;
	//

	// ���� ����Ʈ�� �� ��带 ����
	PN = &(PEH[InsertN->coupon - 1]);
	while (PN->p_enext != NULL){
		if (InsertN->member < (PN->p_enext)->member){
			break;
		}
		PN = PN->p_enext;
	}

	InsertN->p_enext = PN->p_enext;
	PN->p_enext = InsertN;
	//

	printf("OK\n");
}
//

// Remove �Լ�
void Remove(NODE *PGH, NODE *PEH){
	char member;
	int coupon;
	
	NODE *PN;
	NODE *RemoveN;

	scanf("%d %c", &coupon, &member);
	// ���� ���� �Է��� �޾Ҵ��� Ȯ��
	if ((coupon < 1 || coupon > 5) || (member < 'A' || member > 'E')){
		printf("ERROR ! - Exceed a permitted limit.\n");
		return;
	}
	//

	// �ش��ϴ� ��� ����
	PN = &(PGH[member - 'A']);
	while (PN->p_gnext != NULL){
		if (coupon == (PN->p_gnext)->coupon){
			break;
		}
		PN = PN->p_gnext;
	}
		// �ش��ϴ� ��� ����
	if (PN->p_gnext == NULL){
		printf("ERROR ! - Haven't this coupon\n");
		return;
	}
		//
	
		// �ش��ϴ� ���
	RemoveN = PN->p_gnext;

	PN->p_gnext = RemoveN->p_gnext;
	
	PN = &(PEH[coupon - 1]);
	while (PN->p_enext != NULL){
		if (member == (PN->p_enext)->member){
			break;
		}
		PN = PN->p_enext;
	}

	PN->p_enext = RemoveN->p_enext;

	free(RemoveN);
	//

	printf("OK\n");
}
//

// traverseShareElements �Լ�
void traverseShareElements(NODE *PGH){
	char member;

	NODE *PN;

	scanf(" %c", &member);
	// ���� ���� �Է��� �޾Ҵ��� Ȯ��
	if (member < 'A' || member > 'E'){
		printf("ERROR ! - Exceed a permitted limit.\n");
		return;
	}
	//

	// member �� ������ ��� coupon �� ���
	PN = &(PGH[member - 'A']);
		// ��尡 �������� ���� ���,
	if (PN->p_gnext == NULL){
		printf("%d\n", 0);
		return;
	}
		//
	while (PN->p_gnext != NULL){
		printf("%d ", (PN->p_gnext)->coupon);
		PN = PN->p_gnext;
	}
	printf("\n");
	//
}
//

// traverseShareGroups �Լ�
void traverseShareGroups(NODE *PEH){
	int coupon;
	
	NODE *PN;

	scanf("%d", &coupon);
	// ���� ���� �Է��� �޾Ҵ��� Ȯ��
	if (coupon < 1 || coupon > 5){
		printf("ERROR ! - Exceed a permitted limit.\n");
		return;
	}
	//
	
	// coupon �� ������ ��� member �� ���
	PN = &(PEH[coupon - 1]);
		// ��尡 �������� ���� ���,
	if (PN->p_enext == NULL){
		printf("%d\n", 0);
		return;
	}
		//
	while (PN->p_enext != NULL){
		printf("%c ", (PN->p_enext)->member);
		PN = PN->p_enext;
	}
	printf("\n");
	//
}
//

// Exit �Լ�
void Exit(NODE *PGH, NODE *PEH){
	int i;

	NODE *FreeN;

	// ����� ������ ��� ��带 free ��Ŵ
	for (i = 0 ; i < NG ; i++){
		while (PGH[i].p_gnext != NULL){
			FreeN = PGH[i].p_gnext;
			PGH[i].p_gnext = FreeN->p_gnext;
			free(FreeN);
		}
	}
	free(PGH);
	free(PEH);
	//
}
//

// main �Լ�
int main(){
	char order;
	int i;

	NODE *PGH;
	NODE *PEH;

	// ����� �迭�� �����Ҵ���
	PGH = (NODE *)malloc(NG * sizeof(NODE));
	PEH = (NODE *)malloc(NE * sizeof(NODE));
	//
	// ����� ��� next �� NULL�� �ʱ�ȭ��
	for (i = 0 ; i < NG ; i++){
		PGH[i].p_gnext = NULL;
		PGH[i].p_enext = NULL;
	}
	for (i = 0 ; i < NE ; i++){
		PEH[i].p_gnext = NULL;
		PEH[i].p_enext = NULL;
	}
	//

	do {
		scanf("%c", &order);
		switch (order){
		case 'i' :
			Insert(PGH, PEH);
			break;
		case 'r' :
			Remove(PGH, PEH);
			break;
		case 'e' :
			traverseShareElements(PGH);
			break;
		case 'g' :
			traverseShareGroups(PEH);
			break;
		case 'q' :
			Exit(PGH, PEH);
			break;
		}
	} while (order != 'q');

	return 0;
}
//