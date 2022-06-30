# include <stdio.h>
# include <stdlib.h>

// Graph, Vertex, Incidence, Edge 구조체 선언
typedef struct Incidence {
	int index;
	struct Incidence *next;
} INC;

typedef struct Vertex {
	int num, minWeight, isCheck;
	INC *toHeader;
} VER;

typedef struct Edge {
	int l, r, weight, isCheck;
} EDG;

typedef struct Graph {
	VER *Ver;
	EDG *Edg;
} GRP;
//

// makeHeader 함수
/*
	Vertex 구조체 배열 원소 하나마다 헤더를 만들고 연결시킴.
*/
void makeHeader(VER *P, int index){
	INC *Header;

	Header = (INC *)malloc(sizeof(INC));
	Header->next = NULL;

	P->toHeader = Header;
}
//

// init_Graph 함수
/*
	Graph 의 내용을 초기화 해준다.
	Vertex 의 num 을 알맞게 초기화해주고, isCheck 또한 0으로 초기화 한다.
	makeHeader 함수를 사용하여 Header 를 만들어준다.

	Edge 의 isCheck 를 0으로 초기화 해준다.
*/
void init_Graph(GRP *graph, int N, int M){
	int i;

	for (i = 0 ; i < N ; i++){
		graph->Ver[i].num = i + 1;
		graph->Ver[i].isCheck = 0;
		makeHeader(&(graph->Ver[i]), i);
	}
	for (i = 0 ; i < M ; i++){
		graph->Edg[i].isCheck = 0;
	}
}
//

// init_Weight 함수
/*
	Vertex 의 minWeigt 을 모두 현재 그래프에서 가능한 최대 무게로 초기화 해준다.
*/
int init_Weight(GRP *graph, int N, int M){
	int i, maxWeight;

	maxWeight = graph->Edg[0].weight;
	// Edg 배열에서 원소의 weight 을 모두 방문하면서 가장 큰 값을 탐색
	for (i = 1 ; i < M ; i++){
		if (maxWeight < graph->Edg[i].weight){
			maxWeight = graph->Edg[i].weight;
		}
	}
	//

	// Ver 배열에서 원소의 minWeight 을 모두 maxWeight + 1로 초기화
	for (i = 0 ; i < N ; i++){
		graph->Ver[i].minWeight = maxWeight + 1;
	}
	//

	return maxWeight + 1;
}
//

// addInc 함수
/*
	Incidence (인접 관계) 를 헤더 노드 다음에 추가한다.
*/
void addInc(INC *H, int index){
	INC *addInc;

	addInc = (INC *)malloc(sizeof(INC));
	addInc->index = index;

	addInc->next = H->next;
	H->next = addInc;
}
//

// deleteInc 함수
/*
	동적 할당한 Incidence 를 해제 한다.
*/
void deleteInc(INC *H){
	INC *deleteInc = H->next;

	H->next = deleteInc->next;
	
	free(deleteInc);
}
//

// renewMinWeight 함수
/*
	현재 Vertex P 와 간선으로 연결된 다른 Vertex 의 minWeight 을 갱신한다.
*/
void renewMinWeight(GRP *graph, VER *P){
	// indexVer 은 minWeight 을 갱신할 Vertex 의 index
	// indexEdg 은 P와 연결된 Edge 중 하나의 index
	int indexVer, indexEdg;

	// 첫 번째 INC 노드를 가리킴
	INC *forReferInc = P->toHeader->next;

	while (forReferInc != NULL){
		indexEdg = forReferInc->index;
		// isCheck 가 0 인 경우,
		if (!graph->Edg[indexEdg].isCheck){
			graph->Edg[indexEdg].isCheck = 1;
			
			// Edg[indexEdg].l 이 P->num 인 경우,
			if (graph->Edg[indexEdg].l == P->num){
				indexVer = graph->Edg[indexEdg].r-1;
			}
			//
			// 아닌 경우,
			else {
				indexVer = graph->Edg[indexEdg].l-1;
			}
			//

			// 현재 minWeight 보다 간선의 weight 이 더 작은 경우,
			if (graph->Ver[indexVer].minWeight > graph->Edg[indexEdg].weight){
				graph->Ver[indexVer].minWeight = graph->Edg[indexEdg].weight;
			}
			//
		}
		forReferInc = forReferInc->next;
	}
}
//

// rfindMST 함수
/*
	minWeight 을 갱신한 후, minWeight 이 가장 작은 Vertex 을 선택해 다시 함수를 실행한다.
*/
int rfindMST(GRP *graph, VER *P, int N){
	int i, minIndex, minWeight, result, existMin = 0;
	
	P->isCheck = 1;
	
	printf(" %d", P->num);

	renewMinWeight(graph, P);

	// 아직 참조되지 않은 Vertex 를 탐색하여 minWeight 과 minIndex 를 초기화
	for (i = 0 ; i < N ; i++){
		if (!graph->Ver[i].isCheck){
			minIndex = i;
			minWeight = graph->Ver[i].minWeight;
			// 최소값이 적어도 하나 존재
			existMin = 1;
			break;
		}
	}
	//

	// 최소값이 적어도 하나 존재하는 경우,
	if (existMin){
		// minWeight 보다 더 작은 값을 Vertex 에서 탐색
		for (i = 0 ; i < N ; i++){
			if (minWeight > graph->Ver[i].minWeight && !graph->Ver[i].isCheck){
				minWeight = graph->Ver[i].minWeight;
				minIndex = i;
			}
		}
		//
	}
	//

	// 최소값이 적어도 하나 존재하는 경우,
	if (existMin){
		result = minWeight;
		return result + rfindMST(graph, graph->Ver + minIndex, N);
	}
	//
	// 없는 경우,
	else {
		return 0;
	}
	//
}
//

// findMST 함수
/*
	rfindMST 함수를 실행시키기 위한 구동 함수.
*/
int findMST(GRP *graph, int N){
	VER *S = graph->Ver;

	S->minWeight = 0;

	return rfindMST(graph, S, N);
}
//

// clearData 함수
/*
	동적 할당한 모든 메모리를 해제 한다.
*/
void clearData(GRP *graph, int N){
	int i;

	for (i = 0 ; i < N ; i++){
		while (graph->Ver[i].toHeader->next != NULL){
			deleteInc(graph->Ver[i].toHeader);
		}
		free(graph->Ver[i].toHeader);
	}
	free(graph->Ver);
	free(graph->Edg);
	free(graph);
}
//

// main 함수
/*
	그래프를 동적 할당하고, 기본적으로 필요한 데이터를 초기화 한다.
	입력을 받아 입력 받은 데이터를 graph 에 저장하고, 함수를 수행해 결과값을 출력한다.
*/
int main(){
	int i, N, M, l, r, weight;
	
	GRP *graph;

	scanf("%d %d", &N, &M);

	graph = (GRP *)malloc(sizeof(GRP));
	graph->Ver = (VER *)malloc(N * sizeof(VER));
	graph->Edg = (EDG *)malloc(M * sizeof(EDG));

	init_Graph(graph, N, M);

	for (i = 0 ; i < M ; i++){
		scanf("%d %d %d", &l, &r, &weight);
		// 입력받은 데이터를 Edge 에 저장
		graph->Edg[i].l = l;
		graph->Edg[i].r = r;
		graph->Edg[i].weight = weight;
		//
		// Vertex 의 Incidence 를 추가
		addInc(graph->Ver[l-1].toHeader, i);
		addInc(graph->Ver[r-1].toHeader, i);
		//
	}

	init_Weight(graph, N, M);

	printf("\n%d", findMST(graph, N));

	// 동적 할당한 메모리 해제
	clearData(graph, N);

	return 0;
}
//