#include "Lab03.h"

int hash[100] = { 0 };

int main() {
	//1~100까지의 수를 크기가 30~100인 배열에 랜덤으로 값을 생성하기
	//이때 수의 중복이 있어서는 안된다
	srand(time(NULL));
	int a[30] = { 0 };

	randomGenerate(a, 30);
	printArray(a, 30);

	int n = 30;
	printf("%d가 a 배열에 존재하는지 확인\n", n);
	
	(find(a, 30, n) == -1) ? printf("찾을 수 없습니다.\n") : printf("배열의 %d번째 인덱스에 존재 : a[%d] = %d\n", find(a,30,n), find(a, 30, n), a[find(a, 30, n)]);
	(hash[n-1] == 0)? printf("찾을 수 없습니다.\n") : printf("배열의 %d번째 인덱스에 존재 : a[%d] = %d\n", hash[n-1], hash[n-1], a[hash[n-1]]);
}


void randomGenerate(int a[], int size) {

	for (int i = 0; i < size; i++) {
		int number;
		do {
			number = (rand() % 100);
		} while (hash[number] != 0);

		hash[number] = i;
		a[i] = number + 1;
	}
}

void printArray(int a[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int find(int a[], int size, int value) {
	for (int i = 0; i < size; i++) {
		if (a[i] == value) return i;
	}
	return -1;
}