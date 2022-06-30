# include <stdio.h>
# include <stdlib.h>

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
	int i, j, n, result;
	int **A;

	scanf("%d", &n);

	// ���� �Ҵ�
	A = (int **)malloc(n * sizeof(int *));
	for (i = 0 ; i < n ; i++){
		A[i] = (int *)malloc(n * sizeof(int));
	}
	//

	// ����� ������ �Է�
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

	// �޸� ����
	for(i = 0 ; i < n ;i++){
		free(A[i]);
	}
	free(A);
	//

	return 0;
}