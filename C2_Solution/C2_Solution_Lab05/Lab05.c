#include <stdio.h>

int main() {
	const char* inputMessage = "Welcome to C2 lecture";

	printf("%s\n", inputMessage);

	int wordTable[1000][2];
	memset(wordTable, -1, sizeof(int)*1000*2);

	// write your code here

	char c = ' '; int i = 0, wordsize = 0, len = 0;
	for(;;) {
		c = inputMessage[i];
		if (c == ' ' || c=='\0') {
			wordTable[wordsize++][1] = len;
			len = 0;
			i++;
			if (c == '\0') break;
			else continue;
		}
		else if (wordTable[wordsize][0] == -1) {
			wordTable[wordsize][0] = i;
		}
		i++;
		len++;
	}

	//
	printf("�� �ܾ� ���� %d\n", wordsize);
	for (int cc = 0; cc < wordsize; cc++) {
		printf("�� �ܾ��� ù��° �ڸ� : %d, �ܾ��� ���� : %d\t", wordTable[cc][0], wordTable[cc][1]);
		
		for (int ci = 0; ci < wordTable[cc][1]; ci++) {
			printf("%c", inputMessage[wordTable[cc][0] + ci]);
		}
		printf("\n");
	}

	return 0;
}