#include <stdio.h>
#include <stdlib.h>

int main() {
	//
	int cols = 10;
	int rows = 10;

	int array_size = cols * rows;

	int a[100];
	int *as = (int *)malloc(sizeof(int)*array_size);
	int* pa[10];

	for (int i = 0; i < array_size; i++) {
		as[i] = i*2;
		a[i] = i * 2;
	}
	for (int i = 0; i < rows; i+=1) {
		pa[i] = (as + cols * i);
		//pa[i] = (a + cols * i);
		//printf("%x : %d  \n", pa[i], *(pa[i]+1));
	}

	printf("Use Index Calculation\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d\t", as[i*cols+j]);
		}
		printf("\n");
	}

	printf("Use Pointer Array\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d\t", *(pa[i]+j));
		}
		printf("\n");
	}

	free(as);
}