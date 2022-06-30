# include <stdio.h>

int main(){
	char str[1000], Stack[10];
	int i, StackN = 0, bracket = 0, ErrorCheck = 0;

	gets(str);

	for (i = 0 ; str[i] != '\0' ; i++){
		if (str[i] == '[' || str[i] == '{' || str[i] == '(' || str[i] == ')' || str[i] == '}' || str[i] == ']'){
			bracket++;
		}
		if (StackN == 0){
			if (str[i] == '[' || str[i] == '{' || str[i] == '('){
				Stack[StackN] = str[i];
				StackN++;
			}
			else if (str[i] == ')' || str[i] == '}' || str[i] == ']'){
				ErrorCheck = 1;
			}
		}
		else {
			if (Stack[StackN - 1] == '['){
				if (str[i] == ']'){
					StackN--;
				}
				else if (str[i] == '[' || str[i] == '{' || str[i] == '('){
					Stack[StackN] = str[i];
					StackN++;
				}
				else if (str[i] == ')' || str[i] == '}'){
					ErrorCheck = 1;
				}
			}
			else if (Stack[StackN - 1] == '{'){
				if (str[i] == '}'){
					StackN--;
				}
				else if (str[i] == '[' || str[i] == '{' || str[i] == '('){
					Stack[StackN] = str[i];
					StackN++;
				}
				else if (str[i] == ')' || str[i] == ']'){
					ErrorCheck = 1;
				}
			}
			else if (Stack[StackN - 1] == '('){
				if (str[i] == ')'){
					StackN--;
				}
				else if (str[i] == '[' || str[i] == '{' || str[i] == '('){
					Stack[StackN] = str[i];
					StackN++;
				}
				else if (str[i] == '}' || str[i] == ']'){
					ErrorCheck = 1;
				}
			}
		}
	}

	if (StackN != 0){
		ErrorCheck = 1;
	}

	if (ErrorCheck == 0){
		printf("OK_%d\n", bracket);
	}
	else {
		printf("Wrong_%d\n", bracket);
	}

	return 0;
}