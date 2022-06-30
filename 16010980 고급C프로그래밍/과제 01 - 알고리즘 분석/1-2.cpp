# include <stdio.h>
# include <stdlib.h>
# include <windows.h>
# include <time.h>

// 첫번째 방법 (비교적 느린 방법)
/*
	A[i][j] 가 1 일 경우, sum 에 1 씩 더한다.
	A[i][j] 가 0 일 경우, 다음 행 (i++) 으로 넘어간다.
*/
int CountOnesButSlow(int **A, int n){
	int i, j, sum = 0;

	for (i = 0 ; i < n ; i++){
		j = 0;
		while ((j < n) && (A[i][j] == 1)){
			if (A[i][j] == 1){
				sum++;
			}
			j++;
		}
	}

	return sum;
}

// 두번째 방법 (비교적 빠른 방법)
/*
	먼저, j 는 할당된 배열에 따라 가장 큰 인덱스를 갖는다.
	A[i][j] 가 1 일 경우, 열은 그대로, 행은 한 칸 내려간다. (i++)
	내려가면서 열을 통해, 1 의 갯수를 구한다. (1 의 갯수는  j + 1)
	A[i][j] 가 0 일 경우, 행은 그대로, 열은 한 칸 왼쪽으로 이동한다. (j--)
*/
int CountOnesFast(int **A, int n){
	int i = 0, j = n - 1, sum = 0;

	while ((i < n) && (j >= 0)){
		if (A[i][j] == 1){
			sum += j + 1;
			i++;
		}
		else {
			j--;
		}
	}

	return sum;
}

// main 함수
int main(){
	int Loop, i, j, n = 10000, max, result;
	int **A;
	double running_time;	// 실행 시간
	// 시간을 측정하기 위해 필요한 변수, 함수, 클래스
	LARGE_INTEGER Frequency;
	LARGE_INTEGER BeginTime;
	LARGE_INTEGER EndTime;
	__int64 elapsed;

	QueryPerformanceFrequency(&Frequency);
	//
	
	// 총 3번 반복
	for (Loop = 0 ; Loop < 3 ; Loop++){
		// 동적 할당
		A = (int **)malloc(n * sizeof(int *));
		for (i = 0 ; i < n ; i++){
			A[i] = (int *)malloc(n * sizeof(int));
		}
		//
		
		srand(time(NULL));	// 매 번 다른 임의의 수를 갖게 하기 위해
		max = n;
		for (i = 0 ; i < n ; i++){
			if (max > 0){
				max = (rand() % (max + 1));
			}
			for (j = 0 ; j < n ; j++){
				if (j < max){
					A[i][j] = 1;
				}
				else {
					A[i][j] = 0;
				}
			}
		}

		// 첫번째 방법 실행 시간 측정
		QueryPerformanceCounter(&BeginTime);
		result = CountOnesButSlow(A, n);
		QueryPerformanceCounter(&EndTime);
		elapsed = EndTime.QuadPart - BeginTime.QuadPart;
		running_time = (double)elapsed / Frequency.QuadPart;
		//

		printf("%d, %lf ms\n", result, running_time);

		// 두번째 방법 실행 시간 측정
		QueryPerformanceCounter(&BeginTime);
		result = CountOnesFast(A, n);
		QueryPerformanceCounter(&EndTime);
		elapsed = EndTime.QuadPart - BeginTime.QuadPart;
		running_time = (double)elapsed / Frequency.QuadPart;
		//

		printf("%d, %lf ms\n", result, running_time);

		// 메모리 해제
		for (i = 0 ; i < n ; i++){
			free(A[i]);
		}
		free(A);
		//

		n += 5000;
	}
	//

	return 0;
}