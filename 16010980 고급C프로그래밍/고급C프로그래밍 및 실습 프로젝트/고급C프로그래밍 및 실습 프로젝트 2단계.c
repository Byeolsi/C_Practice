# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct tel {
	char *name;
	char *tel_no;
	char *birth;
}TEL;

void Menu(){
	printf("*****Menu*****\n");
	printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
	printf("Enter_the_menu_number:");
}

int Registration(struct tel tel_list[], int count, int max_num){
	char tmp_name[100], tmp_tel_no[100], tmp_birth[100];
	int i, smaller_than = 0;

	if (count >= max_num){
		printf("OVERFLOW\n");
	}
	else {
		printf("Name:");  // 고정 
		scanf("%s", tmp_name);

		for (i = 0 ; i < count ; i++){
			if (strcmp(tmp_name, tel_list[i].name) > 0){
				smaller_than++;
			}
		}

		for (i = count ; i > smaller_than ; i--){
			tel_list[i].name = (char *)malloc((strlen(tel_list[i-1].name) + 1) * sizeof(char));
			tel_list[i].tel_no = (char *)malloc((strlen(tel_list[i-1].tel_no) + 1) * sizeof(char));
			tel_list[i].birth = (char *)malloc((strlen(tel_list[i-1].birth) + 1) * sizeof(char));
			*tel_list[i].name = NULL;
			*tel_list[i].tel_no = NULL;
			*tel_list[i].birth = NULL;
			strcpy(tel_list[i].name, tel_list[i-1].name);
			strcpy(tel_list[i].tel_no, tel_list[i-1].tel_no);
			strcpy(tel_list[i].birth, tel_list[i-1].birth);
		}

		printf("Phone_number:");  // 고정 
		scanf("%s", tmp_tel_no);

		printf("Birth:");  // 고정 
		scanf("%s", tmp_birth);

		tel_list[smaller_than].name = (char *)malloc((strlen(tmp_name) + 1) * sizeof(char));
		*tel_list[smaller_than].name = NULL;
		strcpy(tel_list[smaller_than].name, tmp_name);
		tel_list[smaller_than].tel_no = (char *)malloc((strlen(tmp_tel_no) + 1) * sizeof(char));
		*tel_list[smaller_than].tel_no = NULL;
		strcpy(tel_list[smaller_than].tel_no, tmp_tel_no);
		tel_list[smaller_than].birth = (char *)malloc((strlen(tmp_birth) + 1) * sizeof(char));
		*tel_list[smaller_than].birth = NULL;
		strcpy(tel_list[smaller_than].birth, tmp_birth);
		
		count++;

		printf("<<%d>>\n", count);
	}

	return count;
}

void ShowAll(struct tel tel_list[], int count){
	int i;

	for (i = 0 ; i < count ; i++){
		printf("%s %s %s\n",tel_list[i].name, tel_list[i].tel_no, tel_list[i].birth);
	}
}

int Delete(struct tel tel_list[], int count){
	char delete_name[21];
	int i, find = 0, delete_p;
	
	if (count == 0){
		printf("NO MEMBER\n");
	}
	else {
		printf("Name:");  // 고정 
		scanf("%s", delete_name);

		for (i = 0 ; i < count ; i++){
			if (strcmp(delete_name, tel_list[i].name) == 0){
				find = 1;
				delete_p = i+1;
			}
		}

		if (find){
			for (i = delete_p ; i < count ; i++){
				tel_list[i-1].name = (char *)malloc((strlen(tel_list[i].name) + 1) * sizeof(char));
				tel_list[i-1].tel_no = (char *)malloc((strlen(tel_list[i].tel_no) + 1) * sizeof(char));
				tel_list[i-1].birth = (char *)malloc((strlen(tel_list[i].birth) + 1) * sizeof(char));
				*tel_list[i-1].name = NULL;
				*tel_list[i-1].tel_no = NULL;
				*tel_list[i-1].birth = NULL;
				strcpy(tel_list[i-1].name, tel_list[i].name);
				strcpy(tel_list[i-1].tel_no, tel_list[i].tel_no);
				strcpy(tel_list[i-1].birth, tel_list[i].birth);
			}
			count--;
			free(tel_list[count].name);
			free(tel_list[count].tel_no);
			free(tel_list[count].birth);
		}
	}

	return count;
}

void FindByBirth(struct tel tel_list[], int count){
	char Month[3];
	int i;

	printf("Birth:");
	scanf("%s", Month);

	for (i = 0 ; i < count ; i++){
		if (strlen(Month) == 1){
			if (tel_list[i].birth[4] == '0' && tel_list[i].birth[5] == Month[0]){
				printf("%s %s %s\n", tel_list[i].name, tel_list[i].tel_no, tel_list[i].birth);
			}
		}
		else {
			if (tel_list[i].birth[4] == Month[0] && tel_list[i].birth[5] == Month[1]){
				printf("%s %s %s\n", tel_list[i].name, tel_list[i].tel_no, tel_list[i].birth);
			}
		}
	}
}

int main(){
	int max_num, Select, count = 0;
	TEL *tel_list;

	printf("Max_num:");
	scanf("%d", &max_num);

	tel_list = (TEL *)malloc(max_num * sizeof(TEL));

	while(1){
		Menu();
		scanf("%d", &Select);
		if(Select == 1){
			count = Registration(tel_list, count, max_num);
		}
		else if(Select == 2){
			ShowAll(tel_list, count);
		}
		else if(Select == 3){
			count = Delete(tel_list, count);
		}
		else if(Select == 4){
			FindByBirth(tel_list, count);
		}
		else {
			break;
		}
	}

	return 0;
}