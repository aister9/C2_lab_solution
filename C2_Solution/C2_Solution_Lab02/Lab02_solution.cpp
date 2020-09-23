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
	//��� ī�� ü��(index = 2) - �� ī�� ���ݷ�(index = 4)
	//�� ī�� ü��(index = 2) - ��� ī�� ���ݷ�(index = 4)

	bool mycarddead = false, enemycarddead = false;

	if (getData(myData, 2) - getData(enemyData, 4) <= 0) // ���� �׾��°�?
		mycarddead = true;
	if (getData(enemyData, 2) - getData(myData, 4) <= 0) // ��밡 �׾��°�?
		enemycarddead = true;

	if (mycarddead && enemycarddead) // �� �� �׾���
		printf("�� ī�� ��� �ı��Ǿ� ���º��Դϴ�.\n");
	else if (!mycarddead && enemycarddead) // �� ī��� ��Ұ�, ��� ī��� �׾���
		printf("�� ī�尡 �¸��߽��ϴ�.\n");
	else if (mycarddead && !enemycarddead) // ���ī��� ��Ұ�, �� ī��� �׾���
		printf("��� ī�尡 �¸��߽��ϴ�.\n");
	else if (!mycarddead && !enemycarddead) // �� �� ���� �ʾ���
		printf("�� ī�尡 ��� �ı����� �ʾ����� ���º��Դϴ�.\n");
}