# include <stdio.h>
# include <string.h>

int check(char *pstr){
	int i, eq = 1;

	for (i = 0 ; i < (float)strlen(pstr) / 2 ; i++){
		if (*(pstr+i) != *(pstr-i+strlen(pstr)-1)){
			eq = 0;
		}
	}

	if (eq == 0){
		return 0;
	}

	else {
		return 1;
	}
}

int main(){
	int result;
	char str[30];

	scanf("%s", str);

	result = check(str);

	printf("%d %d", strlen(str), result);

	return 0;
}