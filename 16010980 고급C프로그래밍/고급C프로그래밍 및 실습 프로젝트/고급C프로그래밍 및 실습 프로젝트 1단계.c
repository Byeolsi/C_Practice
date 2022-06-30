# include <stdio.h>
# include <string.h>

#define MAX_NUM 100
struct tel {
	char name[21];
	char tel_no[16];
	char birth[9];
};

void Menu(){
	printf("*****Menu*****\n");
	printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
	printf("Enter_the_menu_number:");
}

int Registration(struct tel tel_list[], int count){
	char input_name[21];
	int i, smaller_than = 0;

	if (count > 99){
		printf("OVERFLOW\n");
	}
	else {
		printf("Name:");  // 고정 
		scanf("%s", input_name);

		for (i = 0 ; i < count ; i++){
			if (strcmp(input_name, tel_list[i].name) == 1){
				smaller_than++;
			}
		}

		for (i = count ; i > smaller_than ; i--){
			*tel_list[i].name = NULL;
			*tel_list[i].tel_no = NULL;
			*tel_list[i].birth = NULL;
			strcpy(tel_list[i].name, tel_list[i-1].name);
			strcpy(tel_list[i].tel_no, tel_list[i-1].tel_no);
			strcpy(tel_list[i].birth, tel_list[i-1].birth);
		}
		*tel_list[smaller_than].name = NULL;
		strcpy(tel_list[smaller_than].name, input_name);

		printf("Phone_number:");  // 고정 
		scanf("%s", tel_list[smaller_than].tel_no);
		printf("Birth:");  // 고정 
		scanf("%s", tel_list[smaller_than].birth);
		
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
				*tel_list[i-1].name = NULL;
				*tel_list[i-1].tel_no = NULL;
				*tel_list[i-1].birth = NULL;
				strcpy(tel_list[i-1].name, tel_list[i].name);
				strcpy(tel_list[i-1].tel_no, tel_list[i].tel_no);
				strcpy(tel_list[i-1].birth, tel_list[i].birth);
			}
			count--;
			*tel_list[count].name = NULL;
			*tel_list[count].tel_no = NULL;
			*tel_list[count].birth = NULL;
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
	int Select, count = 0;
	struct tel tel_list[MAX_NUM];

	while(1){
		Menu();
		scanf("%d", &Select);
		if(Select == 1){
			count = Registration(tel_list, count);
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