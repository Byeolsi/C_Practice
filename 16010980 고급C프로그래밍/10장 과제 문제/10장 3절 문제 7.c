# include <stdio.h>
# include <string.h>

int main(){
	int i, N;
	char str1[100], str2[100];

	scanf("%d", &N);

	for (i = 0 ; i <= N ; i++){
		gets(str2);
		if (i == 1){
			strcpy(str1, str2);
		}
		if (strlen(str1) > strlen(str2)){
			strcpy(str1, str2);
		}
	}

	printf("%s", str1);

	return 0;
}