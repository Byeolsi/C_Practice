# include <stdio.h>
# include <stdlib.h>

// 노드 구조체
typedef struct Node {
	char item;
	struct Node *p_next;
} NODE;
//

// 노드 추가 함수
void Add(NODE *list, int pos, char item){
	int i;
	
	// 추가할 노드와 노드 포인터
	NODE *ADD_NODE, *P_NODE = list;
	
	// 추가할 노드 메모리 할당
	ADD_NODE = (NODE *)malloc(sizeof(NODE));
	ADD_NODE->item = item;
	
	// 해당 pos 까지 P_NODE 가 이동
	for (i = 1 ; i < pos ; i++){
		P_NODE = P_NODE->p_next;
	}
	//
	
	// P_NODE 다음에 ADD_NODE 삽입
	ADD_NODE->p_next = P_NODE->p_next;
	P_NODE->p_next = ADD_NODE;
	//
}
//

// 노드 삭제 함수
void Delete(NODE *list, int pos){
	int i;
	
	// 삭제할 노드를 가리킬 포인터와 노드 포인터
	NODE *DELETE_NODE, *P_NODE = list;
	
	// 해당 pos 까지 P_NODE 가 이동
	for (i = 1 ; i < pos ; i++){
		P_NODE = P_NODE->p_next;
	}
	//
	
	// P_NODE 의 다음 노드를 삭제할 노드(DELETE_NODE) 로써 지정
	DELETE_NODE = P_NODE->p_next;
	// DELETE_NODE 를 리스트 내에서 분리
	P_NODE->p_next = DELETE_NODE->p_next;
	
	// 메모리 해제
	free(DELETE_NODE);
}
//

// 리스트 탐색 함수
char Get_entry(NODE *list, int pos){
	int i;
	
	NODE *P_NODE = list;
	
	// 해당 pos 까지 P_NODE 가 이동
	for (i = 0 ; i < pos ; i++){
		P_NODE = P_NODE->p_next;
	}
	//
	
	// item 을 return
	return P_NODE->item;
}
//

// 리스트 출력 함수
void Print(NODE *list){
	NODE *P_NODE = list->p_next;
	
	// 마지막 노드까지 이동하며 item 값 출력
	while (P_NODE != NULL){
		printf("%c", P_NODE->item);
		P_NODE = P_NODE->p_next;
	}
	//
	printf("\n");
}
//

// 리스트 해제 함수
void Clear(NODE *list){
	// 리스트 내 노드가 존재하지 않을 때까지 계속해서 첫번째 노드 삭제
	while(list->p_next != NULL){
		Delete(list, 1);
	}
	//
}
//

// main 함수
int main(){
	char order, item, entry;
	int i, n, pos, list_n = 0;
	
	// 리스트 헤더
	NODE *list;
	
	// 리스트 헤더 메모리 할당
	list = (NODE *)malloc(sizeof(NODE));
	list->p_next = NULL;
	
	// 받을 명령 횟수
	scanf("%d", &n);
	
	for (i = 0 ; i < n ; i++){
		getchar();
		scanf("%c", &order);
		if (order == 'A'){
			scanf("%d %c", &pos, &item);
			// 예외 처리
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
			// 예외 처리
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
			// 예외 처리
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
	
	// 리스트 메모리 해제
	Clear(list);
	
	return 0;
}
//