#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "status.h"

extern int coin , guard , absorb , lv, next_lv, next_lv1 ;//�������� �޾ƿ�

int main(void)
{
	srand((unsigned int)time(NULL));//srand�� �õ尪 �缳��
	int rands = 0;
	int any;
	
	std::cout << "-�ؽ�Ʈ �ֻ��� RPG����-" << std::endl;
	std::cout << "-���������� ���� �������� ���������� ����ġ����!" << std::endl;
	system("pause");
	enter();
	std::cout << "stage 1 �ʿ�" << std::endl;
	std::cout << "-����� ����Դϴ�." << std::endl;
	std::cout << "-�ӹ��� ��ġ�� ������ ���ư��� �߿� ������� �������� ������ �ν������ϴ�." << std::endl;
	std::cout << "-��� 3������ �ο� �̱⼼��." << std::endl;
	enter();
	std::cout << "-����� �⺻ �������ͽ�" << std::endl;
	std::cout << "-hp = 30, atk = 3, def = 0, spd = 3 "<< std::endl;
	system("pause");
	enter();
	std::cout << "-����� �����ƴ�." << std::endl;
	enter();
	std::cout << "-����� �������ͽ� " << std::endl;
	std::cout << "-hp = 10, atk = 2, def = 0, spd = 2 " << std::endl;

	while (player->hp > 0 && gob->hp > 0)
	{
		battle(gob);
	}
	battle_result();

	std::cout << "-���� ����� �����ƴ�." << std::endl;
	enter();
	std::cout << "-����� �������ͽ� " << std::endl;
	std::cout << "-hp = 10, atk = 2, def = 0, spd = 2 " << std::endl;

	while (player->hp > 0 && gob2->hp > 0)
	{
		battle(gob2);
	}
	battle_result();

	std::cout << "-������ ����� �����ƴ�." << std::endl;
	enter();
	std::cout << "-����� �������ͽ� " << std::endl;
	std::cout << "-hp = 10, atk = 2, def = 0, spd = 2 " << std::endl;

	while (player->hp > 0 && gob3->hp > 0)
	{
		battle(gob3);
	}
	battle_result();

	std::cout << "-�������� 1 �ʿ� Ŭ����." << std::endl;
	std::cout << "-������ �̺�Ʈ�� �߻��մϴ�." << std::endl;
	system("pause");
	enter();
	random(&rands);
	event1(rands);
	return 0;
}


