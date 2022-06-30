# include <stdio.h>
# include <string.h>

int main(){
	int i, N, Order;
	char str1[40], str2[20];

	scanf("%s", str1);
	scanf("%s", str2);
	scanf("%d", &N);
	scanf("%d", &Order);

	if (Order == 0){
		strcat(str2, str1+N);
		strcpy(str1+N, str2);
	}

	else {
		for (i = strlen(str1) + strlen(str2) ; i >= N ; i--){
			*(str1+i) = *(str1+i-strlen(str2));
		}

		for (i = 0 ; *(str2+i) ; i++){
			*(str1+i+N) = *(str2+strlen(str2)-i-1);
		}
	}

	printf("%s\n", str1);

	return 0;
}