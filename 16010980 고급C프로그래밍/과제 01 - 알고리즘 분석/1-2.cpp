# include <stdio.h>
# include <stdlib.h>
# include <windows.h>
# include <time.h>

// ù��° ��� (���� ���� ���)
/*
	A[i][j] �� 1 �� ���, sum �� 1 �� ���Ѵ�.
	A[i][j] �� 0 �� ���, ���� �� (i++) ���� �Ѿ��.
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

// �ι�° ��� (���� ���� ���)
/*
	����, j �� �Ҵ�� �迭�� ���� ���� ū �ε����� ���´�.
	A[i][j] �� 1 �� ���, ���� �״��, ���� �� ĭ ��������. (i++)
	�������鼭 ���� ����, 1 �� ������ ���Ѵ�. (1 �� ������  j + 1)
	A[i][j] �� 0 �� ���, ���� �״��, ���� �� ĭ �������� �̵��Ѵ�. (j--)
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

// main �Լ�
int main(){
	int Loop, i, j, n = 10000, max, result;
	int **A;
	double running_time;	// ���� �ð�
	// �ð��� �����ϱ� ���� �ʿ��� ����, �Լ�, Ŭ����
	LARGE_INTEGER Frequency;
	LARGE_INTEGER BeginTime;
	LARGE_INTEGER EndTime;
	__int64 elapsed;

	QueryPerformanceFrequency(&Frequency);
	//
	
	// �� 3�� �ݺ�
	for (Loop = 0 ; Loop < 3 ; Loop++){
		// ���� �Ҵ�
		A = (int **)malloc(n * sizeof(int *));
		for (i = 0 ; i < n ; i++){
			A[i] = (int *)malloc(n * sizeof(int));
		}
		//
		
		srand(time(NULL));	// �� �� �ٸ� ������ ���� ���� �ϱ� ����
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

		// ù��° ��� ���� �ð� ����
		QueryPerformanceCounter(&BeginTime);
		result = CountOnesButSlow(A, n);
		QueryPerformanceCounter(&EndTime);
		elapsed = EndTime.QuadPart - BeginTime.QuadPart;
		running_time = (double)elapsed / Frequency.QuadPart;
		//

		printf("%d, %lf ms\n", result, running_time);

		// �ι�° ��� ���� �ð� ����
		QueryPerformanceCounter(&BeginTime);
		result = CountOnesFast(A, n);
		QueryPerformanceCounter(&EndTime);
		elapsed = EndTime.QuadPart - BeginTime.QuadPart;
		running_time = (double)elapsed / Frequency.QuadPart;
		//

		printf("%d, %lf ms\n", result, running_time);

		// �޸� ����
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