# include <stdio.h>
# include <string.h>

int main(){
	int N;
	char str1[40], str2[20];

	scanf("%s", str1);
	scanf("%s", str2);
	scanf("%d", &N);

	strcat(str2, str1+N);
	strcpy(str1+N, str2);

	printf("%s\n", str1);

	return 0;
}