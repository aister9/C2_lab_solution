#include "Lab03.h"

int hash[100] = { 0 };

int main() {
	//1~100������ ���� ũ�Ⱑ 30~100�� �迭�� �������� ���� �����ϱ�
	//�̶� ���� �ߺ��� �־�� �ȵȴ�
	srand(time(NULL));
	int a[30] = { 0 };

	randomGenerate(a, 30);
	printArray(a, 30);

	int n = 30;
	printf("%d�� a �迭�� �����ϴ��� Ȯ��\n", n);
	
	(find(a, 30, n) == -1) ? printf("ã�� �� �����ϴ�.\n") : printf("�迭�� %d��° �ε����� ���� : a[%d] = %d\n", find(a,30,n), find(a, 30, n), a[find(a, 30, n)]);
	(hash[n-1] == 0)? printf("ã�� �� �����ϴ�.\n") : printf("�迭�� %d��° �ε����� ���� : a[%d] = %d\n", hash[n-1], hash[n-1], a[hash[n-1]]);
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