# include <stdio.h>
# include <stdlib.h>
# include <math.h>

struct point {
	float x, y, l;
};

int main(){
	int i, N;
	struct point P;
	struct point *point_arr, *min;

	scanf("%d", &N);

	point_arr = (struct point *)malloc(N * sizeof(struct point));

	for (i = 0 ; i < N ; i++){
		scanf("%f %f", &(point_arr[i].x), &(point_arr[i].y));
	}

	scanf("%f %f", &(P.x), &(P.y));

	for (i = 0 ; i < N ; i++){
		point_arr[i].l = sqrt(pow(point_arr[i].x - P.x, 2) + pow(point_arr[i].y - P.y, 2));
	}
	min = point_arr;
	for (i = 1 ; i < N ; i++){
		if (min->l > point_arr[i].l){
			min = point_arr+i;
		}
	}

	printf("%.1f %.1f", min->x, min->y);

	return 0;
}