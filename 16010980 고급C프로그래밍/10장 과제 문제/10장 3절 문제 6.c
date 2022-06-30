# include <stdio.h>
# include <string.h>

int main(){
	int i, j, eq, result = 0;
	char str1[100], str2[100];

	gets(str1);
	scanf("%s", str2);

	for (i = 0 ; *(str1+i) ; i++){
		eq = 1;
		for (j = 0 ; *(str2+j) && eq == 1 ; j++){
			if (*(str1+i+j) != *(str2+j)){
				eq = 0;
			}
		}
		if (eq == 1){
			result += 1;
			i += strlen(str2) - 1;
		}
	}

	printf("%d", result);

	return 0;
}