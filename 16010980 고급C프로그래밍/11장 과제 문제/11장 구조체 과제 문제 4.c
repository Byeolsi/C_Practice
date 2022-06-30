# include <stdio.h>

struct Date {
	int year, month, day;
};

struct Date *select_min(struct Date *d1, struct Date *d2){
	if (d1->year < d2->year){
		return d1;
	}
	else if (d1->year > d2->year){
		return d2;
	}
	else {
		if (d1->month < d2->month){
			return d1;
		}
		else if (d1->month > d2->month){
			return d2;
		}
		else {
			if (d1->day < d2->day){
				return d1;
			}
			else if (d1->day > d2->day){
				return d2;
			}
		}
	}
}

int main(){
	struct Date d1, d2;
	struct Date *min_d;

	scanf("%d/%d/%d", &d1.year, &d1.month, &d1.day);
	scanf("%d/%d/%d", &d2.year, &d2.month, &d2.day);

	min_d = select_min(&d1, &d2);

	printf("%d/%d/%d", min_d->year, min_d->month, min_d->day);

	return 0;
}