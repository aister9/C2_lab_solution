#include "Lab02.h"

extern const char* cardName[5];
extern int cardData[5];

int getCardData(int number) {
	return cardData[number];
}

int getData(int data, int index) {
	return (data >> (index * 4)) & 0xf;
}

int updateData(int data, int index, int value) {
	return (data & (~(0xf << (index * 4)))) + (value << (index * 4));
}

void battleResult(int myData, int enemyData) {
	//상대 카드 체력(index = 2) - 내 카드 공격력(index = 4)
	//내 카드 체력(index = 2) - 상대 카드 공격력(index = 4)

	bool mycarddead = false, enemycarddead = false;

	if (getData(myData, 2) - getData(enemyData, 4) <= 0) // 내가 죽었는가?
		mycarddead = true;
	if (getData(enemyData, 2) - getData(myData, 4) <= 0) // 상대가 죽었는가?
		enemycarddead = true;

	if (mycarddead && enemycarddead) // 둘 다 죽었음
		printf("두 카드 모두 파괴되어 무승부입니다.\n");
	else if (!mycarddead && enemycarddead) // 내 카드는 살았고, 상대 카드는 죽었음
		printf("내 카드가 승리했습니다.\n");
	else if (mycarddead && !enemycarddead) // 상대카드는 살았고, 내 카드는 죽었음
		printf("상대 카드가 승리했습니다.\n");
	else if (!mycarddead && !enemycarddead) // 둘 다 죽지 않았음
		printf("내 카드가 모두 파괴되지 않았으며 무승부입니다.\n");
}