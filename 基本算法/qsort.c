//qsort()的原型：void qsort(void *base, size_t nmemb, size_t size, int (*compar) (const void *, const void *));
#include <stdio.h>
#include <stdlib.h>

int a[10] = {6, 9, -7, 106, 99, 888,};

int mycomp(const void *p1, const void *p2){
	const int *a1 = (const int *) p1;
	const int *a2 = (const int *) p2;

	if(*a1 < *a2)
		return -1;
	else if (*a1 == *a2)
		return 0;
	else
		return 1;
}

int main() {
	qsort(a, 6, sizeof(int), mycomp);
	for(int i = 0; i <= 5; i++)
		printf("%d\n", a[i]);
}