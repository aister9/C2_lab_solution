//C Programing Lv.2
//Lab 01. To Binary
//

#include <stdio.h>
#include <limits.h>

bool testToBinary(char* valid ,const char* answer);
void ToBinary(int input, char answer[32]);

int main() {
	char answer[32];
	
	ToBinary(43, answer);
	ToBinary(7, answer);
	ToBinary(12, answer);
}

void ToBinary(int input, char answer[32]) {
	printf("Input %d : ", input);
	if (input > INT_MAX || input < INT_MIN)
	{
		printf("Error\n");
		return;
	}

	int size = 0;
	//To Binary
	for (int i = 0; i < 32; i++) {
		unsigned int compareBit = 0x01 << i;
		if ((unsigned int)input < compareBit) break;
		answer[i] = (input>>i) & (0x01);
		size++;
	}

	//Array Reverse
	for (int i = 0; i<size/2; i++) {
		//swap answer[i], answer[size-i]
		char tmp = 0;
		tmp = answer[i];
		answer[i] = answer[size - 1 - i]; 
		answer[size - 1 - i] = tmp;
	}

	//Print
	for (int i = 0; i < size; i++) {
		if ((size-i) % 4 == 0 && i != 0) printf(" ");
		printf("%d", answer[i]);
	}
	printf("\n");
}