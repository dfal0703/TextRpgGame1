#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "status.h"

extern int coin , guard , absorb , lv, next_lv, next_lv1 ;//전역변수 받아옴

int main(void)
{
	srand((unsigned int)time(NULL));//srand의 시드값 재설정
	int rands = 0;
	int any;
	
	std::cout << "-텍스트 주사위 RPG게임-" << std::endl;
	std::cout << "-스테이지를 깨고 강해져서 최종보스를 물리치세요!" << std::endl;
	system("pause");
	enter();
	std::cout << "stage 1 초원" << std::endl;
	std::cout << "-당신은 기사입니다." << std::endl;
	std::cout << "-임무를 마치고 성으로 돌아가는 중에 고블린들의 공격으로 마차가 부숴졌습니다." << std::endl;
	std::cout << "-고블린 3마리와 싸워 이기세요." << std::endl;
	enter();
	std::cout << "-당신의 기본 스테이터스" << std::endl;
	std::cout << "-hp = 30, atk = 3, def = 0, spd = 3 "<< std::endl;
	system("pause");
	enter();
	std::cout << "-고블린과 마주쳤다." << std::endl;
	enter();
	std::cout << "-고블린의 스테이터스 " << std::endl;
	std::cout << "-hp = 10, atk = 2, def = 0, spd = 2 " << std::endl;

	while (player->hp > 0 && gob->hp > 0)
	{
		battle(gob);
	}
	battle_result();

	std::cout << "-다음 고블린과 마주쳤다." << std::endl;
	enter();
	std::cout << "-고블린의 스테이터스 " << std::endl;
	std::cout << "-hp = 10, atk = 2, def = 0, spd = 2 " << std::endl;

	while (player->hp > 0 && gob2->hp > 0)
	{
		battle(gob2);
	}
	battle_result();

	std::cout << "-마지막 고블린과 마주쳤다." << std::endl;
	enter();
	std::cout << "-고블린의 스테이터스 " << std::endl;
	std::cout << "-hp = 10, atk = 2, def = 0, spd = 2 " << std::endl;

	while (player->hp > 0 && gob3->hp > 0)
	{
		battle(gob3);
	}
	battle_result();

	std::cout << "-스테이지 1 초원 클리어." << std::endl;
	std::cout << "-랜덤한 이벤트가 발생합니다." << std::endl;
	system("pause");
	enter();
	random(&rands);
	event1(rands);
	return 0;
}


