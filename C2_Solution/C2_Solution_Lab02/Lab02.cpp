//C Programing Lv.2
//Lab 02. Card Battle Game
//
#include "Lab02.h"

const char* cardName[5] = { "�����", "����", "�Ƹ�", "�ǿ���", "�̺�" };
int cardData[5] = { 0x33331, 0x11222, 0x22221, 0x55333, 0x44222 };
//���� ���ݷ� - �⺻ ���ݷ� - ���� ü�� - �⺻ ü�� - ����
//4-3-2-1-0 index

int main() {

	printf("��� ī�� ���� \n");
	for (int i = 0; i < 5; i++) {
		printf("%s : ���ݷ� %d, ü�� %d, ���� %d\n", cardName[i] ,getData(cardData[i], 3), getData(cardData[i], 1), getData(cardData[i], 0));
	}
	printf("--------------------------------------------------\n");

	int mycardNumber = 3; //�� ī�尡 � ī������
	int mycardData = getCardData(mycardNumber); //�� ī���� �⺻ ������ �ҷ��ɴϴ�
	printf("���� ������ �ִ� ī��� [%s] �Դϴ�. \n", cardName[mycardNumber]);

	int enemycardNumber = 1; //��� ī�尡 � ī������
	int enemycardData = getCardData(enemycardNumber); //��� ī���� �⺻ ������ �ҷ��ɴϴ�
	printf("��밡 ������ �ִ� ī��� [%s] �Դϴ�. \n", cardName[enemycardNumber]);

	printf("--------------------------------------------------\n");
	printf("���� ��� [%s] vs [%s] \n", cardName[mycardNumber], cardName[enemycardNumber]);
	battleResult(mycardData, enemycardData); //���� ��� ���

	mycardData =updateData(mycardData, 2, getData(mycardData, 2) - getData(enemycardData, 4)); // �� ī���� ���¸� ������Ʈ �մϴ�. ���̳ʽ� ü�µ� ����մϴ�
	printf("%s : ������ݷ� %d, ����ü�� %d, ���� %d\n", cardName[mycardNumber], getData(mycardData, 4), getData(mycardData, 2), getData(mycardData, 0));
}
