# include <stdio.h>
# include <stdlib.h>

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
	int i, j, n, result;
	int **A;

	scanf("%d", &n);

	// 동적 할당
	A = (int **)malloc(n * sizeof(int *));
	for (i = 0 ; i < n ; i++){
		A[i] = (int *)malloc(n * sizeof(int));
	}
	//

	// 행렬의 값들을 입력
	for (i = 0 ; i < n ; i++){
		for (j = 0 ; j < n ; j++){
			scanf("%d", &A[i][j]);
		}
	}
	//

	result = CountOnesButSlow(A, n);

	printf("%d\n", result);

	result = CountOnesFast(A, n);

	printf("%d\n", result);

	// 메모리 해제
	for(i = 0 ; i < n ;i++){
		free(A[i]);
	}
	free(A);
	//

	return 0;
}