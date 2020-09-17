//C Programing Lv.2
//Lab 02. Card Battle Game
//
#include "Lab02.h"

const char* cardName[5] = { "이즈리얼", "유미", "아리", "피오라", "이블린" };
int cardData[5] = { 0x33331, 0x11222, 0x22221, 0x55333, 0x44222 };
//현재 공격력 - 기본 공격력 - 현재 체력 - 기본 체력 - 가격
//4-3-2-1-0 index

int main() {

	printf("모든 카드 정보 \n");
	for (int i = 0; i < 5; i++) {
		printf("%s : 공격력 %d, 체력 %d, 가격 %d\n", cardName[i] ,getData(cardData[i], 3), getData(cardData[i], 1), getData(cardData[i], 0));
	}
	printf("--------------------------------------------------\n");

	int mycardNumber = 3; //내 카드가 어떤 카드인지
	int mycardData = getCardData(mycardNumber); //내 카드의 기본 정보를 불러옵니다
	printf("내가 가지고 있는 카드는 [%s] 입니다. \n", cardName[mycardNumber]);

	int enemycardNumber = 1; //상대 카드가 어떤 카드인지
	int enemycardData = getCardData(enemycardNumber); //상대 카드의 기본 정보를 불러옵니다
	printf("상대가 가지고 있는 카드는 [%s] 입니다. \n", cardName[enemycardNumber]);

	printf("--------------------------------------------------\n");
	printf("전투 결과 [%s] vs [%s] \n", cardName[mycardNumber], cardName[enemycardNumber]);
	battleResult(mycardData, enemycardData); //전투 결과 출력

	mycardData =updateData(mycardData, 2, getData(mycardData, 2) - getData(enemycardData, 4)); // 내 카드의 상태를 업데이트 합니다. 마이너스 체력도 출력합니다
	printf("%s : 현재공격력 %d, 현재체력 %d, 가격 %d\n", cardName[mycardNumber], getData(mycardData, 4), getData(mycardData, 2), getData(mycardData, 0));
}
