# include <stdio.h>
# include <stdlib.h>
# include <Windows.h>

// 구조체 스택 
typedef struct Stack {
	int num;
	// 원소 next 
	struct Stack *p_enext;
	// 최소값 next 
	struct Stack *p_mnext;
} NODE;

// push 함수 
/*
	원소 스택에 노드를 넣는다.
	넣을 때는 헤더 다음 (Top) 에 넣는다.
	넣을 때마다 노드의 원소가 최소값인지 확인한다.
	최소값이라면 최소값 스택에도 노드를 넣는다. 
*/ 
int push(int InputN, NODE *PEH, NODE *PMH){
	// PUSH 노드 
	NODE *PUSH_NODE;

	PUSH_NODE = (NODE *)malloc(sizeof(NODE));
	
	// 입력 값을 PUSH 노드의 원소로 넣는다. 
	PUSH_NODE->num = InputN;
	// PUSH 노드가 처음 넣어지는 노드일 경우, 최소값 스택에 PUSH 노드를 넣는다. 
	if (PEH->p_enext == NULL){
		PUSH_NODE->p_mnext = PMH->p_mnext;
		PMH->p_mnext = PUSH_NODE;
	}
	//
	// PUSH 노드의 원소가 최소값 스택의 Top의 원소보다 작을 경우, 최소값 스택에 PUSH 노드를 넣는다. 
	else if (PUSH_NODE->num < (PMH->p_mnext)->num){
		PUSH_NODE->p_mnext = PMH->p_mnext;
		PMH->p_mnext = PUSH_NODE;
	}
	//
	// PUSH 노드를 원소 스택에 넣는다. 
	PUSH_NODE->p_enext = PEH->p_enext;
	PEH->p_enext = PUSH_NODE;
	//

	return PUSH_NODE->num;
}

// pop 함수 
/*
	 원소 스택에서 Top 노드를 제거한다.
	 만약, 제거할 노드가 최소값 스택의 Top 노드라면 최소값 스택에서도 제거한다. 
*/ 
int pop(NODE *PEH, NODE *PMH){
	// POP 노드의 원소 
	int POP_N;
	
	// POP 노드 
	NODE *POP_NODE = PEH->p_enext;
	
	// 만일, POP 노드가 최소값 스택의 Top 노드일 경우, 두번째 최소값을 가지는 노드를 Top으로 변경한다. 
	if (POP_NODE == PMH->p_mnext){
		PMH->p_mnext = POP_NODE->p_mnext;
	}
	//
	// 원소 스택에서 POP 노드를 제거한다. 
	PEH->p_enext = POP_NODE->p_enext;
	
	// return 을 위해 POP_N 에 POP_NODE 의 원소를 저장한다. 
	POP_N = POP_NODE->num;
	
	// POP_NODE 를 해제시킨다. 
	free(POP_NODE);
	
	return POP_N;
}

// findMin 함수 
/*
	최소값의 Top 노드의 원소를 return 한다.
*/ 
int findMin(NODE *PMH){
	return (PMH->p_mnext)->num;
}

// pushMillion 함수 
/*
	push 함수를 백만번 반복한다.
	입력값은 랜덤으로 하되, 범위는 1000 ~ 9999 이다.
*/ 
void pushMillion(NODE *PEH, NODE *PMH){
	int i, InputN;

	for (i = 0 ; i < 1000000 ; i++){
		InputN = (rand() % 9000) + 1000;
		push(InputN, PEH, PMH);
	}
}

// popMillion 함수 
/*
	pop 함수를 백만번 반복한다.
*/ 
void popMillion(NODE *PEH, NODE *PMH){
	int i;

	for (i = 0 ; i < 1000000 ; i++){
		pop(PEH, PMH);
	}
}

// DeleteAll 함수 
/*
	프로그램 종료 전에 두 스택의 모든 노드를 해제 한다. 
*/
void DeleteAll(NODE *PEH, NODE *PMH){
	NODE *POP_NODE;

	while (PEH->p_enext != NULL){
		POP_NODE = PEH->p_enext;
		if (POP_NODE == PMH->p_mnext){
			PMH->p_mnext = POP_NODE->p_mnext;
		}
		PEH->p_enext = POP_NODE->p_enext;

		free(POP_NODE);
	}
	free(PEH);
	free(PMH); 
}

// main 함수 
int main(){
	char order;
	int N = 0, InputN, PUSH_N, POP_N, Min;
	// 최종 CPU 실행 시간 
	double CpuTime;
	
	// 원소 스택의 헤더와 최소값 스택의 헤더 
	NODE *PEH, *PMH;
	
	// CPU 실행 시간을 측정하기 위해 필요한 변수 
	__int64 Frequency, BeginTime, EndTime, elapsed;
	
	QueryPerformanceFrequency(&Frequency);

	PEH = (NODE *)malloc(sizeof(NODE));
	PMH = (NODE *)malloc(sizeof(NODE));

	PEH->p_enext = NULL;
	PEH->p_mnext = NULL;

	PMH->p_enext = NULL;
	PMH->p_mnext = NULL;

	do {
		scanf("%c", &order);
		switch (order){
		// push
		case 'p' :
			scanf("%d", &InputN);
			
			QueryPerformanceCounter((LARGE_INTEGER *)&BeginTime); 
			
			PUSH_N = push(InputN, PEH, PMH);
			
			QueryPerformanceCounter((LARGE_INTEGER *)&EndTime);
			elapsed = EndTime - BeginTime;
			CpuTime = (double)elapsed / Frequency;
			
			N++;
			
			printf("push %d (%d), cpu time = %lf\n", PUSH_N, N, CpuTime);
			
			break;
		// pop
		case 'o' :
			// 스택에 노드가 존재하지 않을 경우, 예외 처리한다. 
			if (N == 0){
				printf("ERROR!!!\n");
			}
			//
			else {
				QueryPerformanceCounter((LARGE_INTEGER *)&BeginTime);
				
				POP_N = pop(PEH, PMH);
				
				QueryPerformanceCounter((LARGE_INTEGER *)&EndTime);
				elapsed = EndTime - BeginTime;
				CpuTime = (double)elapsed / Frequency;
				
				N--;
				
				printf("pop %d (%d), cpu time = %lf\n", POP_N, N, CpuTime);
			}
			break;
		// findMin
		case 'f' :
			// 스택에 노드가 존재하지 않을 경우, 예외 처리한다. 
			if (N == 0){
				printf("ERROR!!!\n");
			}
			//
			else {
				QueryPerformanceCounter((LARGE_INTEGER *)&BeginTime);
				
				Min = findMin(PMH);
				
				QueryPerformanceCounter((LARGE_INTEGER *)&EndTime);
				elapsed = EndTime - BeginTime;
				CpuTime = (double)elapsed / Frequency;
				
				printf("min %d (%d), cpu time = %lf\n", Min, N, CpuTime);
			}
			break;
		// pushMillion
		case 'P' :
			QueryPerformanceCounter((LARGE_INTEGER *)&BeginTime);
			
			pushMillion(PEH, PMH);
			
			QueryPerformanceCounter((LARGE_INTEGER *)&EndTime);
			elapsed = EndTime - BeginTime;
			CpuTime = (double)elapsed / Frequency;
			
			N += 1000000;
			
			printf("pushMillion (%d), cpu time = %lf\n", N, CpuTime);
			
			break;
		// popMillion
		case 'O' :
			// 스택에 노드가 백만개 이상 존재하지 않을 경우, 예외 처리한다. 
			if (N < 1000000){
				printf("ERROR!!!\n");
			}
			else {
				QueryPerformanceCounter((LARGE_INTEGER *)&BeginTime);
				
				popMillion(PEH, PMH);
				
				QueryPerformanceCounter((LARGE_INTEGER *)&EndTime);
				elapsed = EndTime - BeginTime;
				CpuTime = (double)elapsed / Frequency;
				
				N -= 1000000;
				
				printf("popMillion (%d), cpu time = %lf\n", N, CpuTime);
			}
			break;
		}
	} while (order != 'q');

	DeleteAll(PEH, PMH);

	return 0;
}
