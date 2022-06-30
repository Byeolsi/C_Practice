# include <stdio.h>
# include <stdlib.h>

// 그룹 멤버 수, 쿠폰 갯수 정의
# define NG 5
# define NE 4
//

// 구조체 노드
typedef struct node {
	char member;
	int coupon;
	
	// 그룹의 다음 노드를 가리킴.
	struct node *p_gnext;
	// 원소의 다음 노드를 가리킴.
	struct node *p_enext;
} NODE;
//

// Insert 함수
void Insert(NODE *PGH, NODE *PEH){
	NODE *PN;
	NODE *InsertN;

	InsertN = (NODE *)malloc(sizeof(NODE));

	scanf("%d %c", &(InsertN->coupon), &(InsertN->member));
	// 범위 밖의 입력을 받았는지 확인
	if ((InsertN->coupon < 1 || InsertN->coupon > 4) || (InsertN->member < 'A' || InsertN->member > 'E')){
		printf("ERROR ! - Exceed a permitted limit.\n");
		free(InsertN);
		return;
	}
	//

	// 그룹 리스트의 새 노드를 삽입
	PN = &(PGH[InsertN->member - 'A']);
	while (PN->p_gnext != NULL){
		// 이미 구매한 쿠폰인 경우,
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

	// 원소 리스트의 새 노드를 삽입
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

// Remove 함수
void Remove(NODE *PGH, NODE *PEH){
	char member;
	int coupon;
	
	NODE *PN;
	NODE *RemoveN;

	scanf("%d %c", &coupon, &member);
	// 범위 밖의 입력을 받았는지 확인
	if ((coupon < 1 || coupon > 5) || (member < 'A' || member > 'E')){
		printf("ERROR ! - Exceed a permitted limit.\n");
		return;
	}
	//

	// 해당하는 노드 삭제
	PN = &(PGH[member - 'A']);
	while (PN->p_gnext != NULL){
		if (coupon == (PN->p_gnext)->coupon){
			break;
		}
		PN = PN->p_gnext;
	}
		// 해당하는 노드 없음
	if (PN->p_gnext == NULL){
		printf("ERROR ! - Haven't this coupon\n");
		return;
	}
		//
	
		// 해당하는 노드
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

// traverseShareElements 함수
void traverseShareElements(NODE *PGH){
	char member;

	NODE *PN;

	scanf(" %c", &member);
	// 범위 밖의 입력을 받았는지 확인
	if (member < 'A' || member > 'E'){
		printf("ERROR ! - Exceed a permitted limit.\n");
		return;
	}
	//

	// member 가 구매한 모든 coupon 을 출력
	PN = &(PGH[member - 'A']);
		// 노드가 존재하지 않을 경우,
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

// traverseShareGroups 함수
void traverseShareGroups(NODE *PEH){
	int coupon;
	
	NODE *PN;

	scanf("%d", &coupon);
	// 범위 밖의 입력을 받았는지 확인
	if (coupon < 1 || coupon > 5){
		printf("ERROR ! - Exceed a permitted limit.\n");
		return;
	}
	//
	
	// coupon 을 구매한 모든 member 를 출력
	PN = &(PEH[coupon - 1]);
		// 노드가 존재하지 않을 경우,
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

// Exit 함수
void Exit(NODE *PGH, NODE *PEH){
	int i;

	NODE *FreeN;

	// 헤더를 포함한 모든 노드를 free 시킴
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

// main 함수
int main(){
	char order;
	int i;

	NODE *PGH;
	NODE *PEH;

	// 헤더를 배열로 동적할당함
	PGH = (NODE *)malloc(NG * sizeof(NODE));
	PEH = (NODE *)malloc(NE * sizeof(NODE));
	//
	// 헤더의 모든 next 를 NULL로 초기화함
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