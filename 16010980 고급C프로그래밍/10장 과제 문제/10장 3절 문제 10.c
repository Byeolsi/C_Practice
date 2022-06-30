# include <stdio.h>
# include <string.h>

int main(){
	char str1[50], str2[50], str3[100];

	scanf("%s", str1);
	scanf("%s", str2);

	if (strcmp(str1, str2) == 1){
		strcpy(str3, str1);
		strcat(str3, str2);
	}

	else {
		strcpy(str3, str2);
		strcat(str3, str1);
	}

	printf("%s", str3);

	return 0;
}