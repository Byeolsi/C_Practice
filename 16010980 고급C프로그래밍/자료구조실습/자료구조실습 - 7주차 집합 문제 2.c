# include <stdio.h>
# include <stdlib.h>

typedef struct set {
	int num;
	struct set *p_next;
}NODE;

void Add_NODE_Right (int N, NODE *PH){
	NODE *PN, *Add_NODE;

	Add_NODE = (NODE *)malloc(sizeof(NODE));
	PN = PH;

	Add_NODE->num = N;

	while (PN->p_next != NULL){
		PN = PN->p_next;
	}
	Add_NODE->p_next = PN->p_next;
	PN->p_next = Add_NODE;
}

NODE *Union_Set (NODE *PAH, NODE *PBH){
	NODE *PAN = PAH->p_next, *PBN = PBH->p_next, *PUH;

	PUH = (NODE *)malloc(sizeof(NODE));
	PUH->p_next = NULL;

	while (PAN != NULL && PBN != NULL){
		if (PAN->num > PBN->num){
			Add_NODE_Right(PBN->num, PUH);
			PBN = PBN->p_next;
		}
		else if (PAN->num < PBN->num){
			Add_NODE_Right(PAN->num, PUH);
			PAN = PAN->p_next;
		}
		else {
			Add_NODE_Right(PAN->num, PUH);
			PAN = PAN->p_next;
			PBN = PBN->p_next;
		}
	}
	while (PAN != NULL){
		Add_NODE_Right(PAN->num, PUH);
		PAN = PAN->p_next;
	}
	while (PBN != NULL){
		Add_NODE_Right(PBN->num, PUH);
		PBN = PBN->p_next;
	}

	return PUH;
}

NODE *Intersect_Set (NODE *PAH, NODE *PBH){
	NODE *PAN = PAH->p_next, *PBN = PBH->p_next, *PIH;

	PIH = (NODE *)malloc(sizeof(NODE));
	PIH->p_next = NULL;

	while (PAN != NULL && PBN != NULL){
		if (PAN->num > PBN->num){
			PBN = PBN->p_next;
		}
		else if (PAN->num < PBN->num){
			PAN = PAN->p_next;
		}
		else {
			Add_NODE_Right(PAN->num, PIH);
			PAN = PAN->p_next;
			PBN = PBN->p_next;
		}
	}

	return PIH;
}

int main(){
	int i, N, Size;
	NODE *PN, *PAH, *PBH, *PUH, *PIH;

	PAH = (NODE *)malloc(sizeof(NODE));
	PBH = (NODE *)malloc(sizeof(NODE));
	PAH->p_next = NULL;
	PBH->p_next = NULL;


	scanf("%d", &Size);
	for (i = 0 ; i < Size ; i++){
		scanf("%d", &N);
		Add_NODE_Right(N, PAH);
	}

	scanf("%d", &Size);
	for (i = 0 ; i < Size ; i++){
		scanf("%d", &N);
		Add_NODE_Right(N, PBH);
	}

	PUH = Union_Set(PAH, PBH);
	PIH = Intersect_Set(PAH, PBH);

	if (PUH->p_next == NULL){
		printf(" %d", 0);
	}
	else {
		PN = PUH->p_next;
		while (PN != NULL){
			printf(" %d", PN->num);
			PN = PN->p_next;
		}
	}
	printf("\n");

	if (PIH->p_next == NULL){
		printf(" %d", 0);
	}
	else {
		PN = PIH->p_next;
		while (PN != NULL){
			printf(" %d", PN->num);
			PN = PN->p_next;
		}
	}
	printf("\n");

	return 0;
}