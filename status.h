#pragma once

class status
{
public://public 으로 해야 변수를 변경할 수 있음.
	int hp = 0;
	int atk = 0;
	int def = 0;
	int spd = 0;

	
	status(int hp1, int atk1, int def1, int spd1)
	{
		this->hp = hp1;//사용할 변수 명을 메인에서 지정하고 인수를 넣으면 사용변수명.HP값에 저장.
		this->atk = atk1;
		this->def = def1;
		this->spd = spd1;
	}
};

void random(int* a);
void event1(int a);
void event_skip();
void event_rest();
void event_training();
void event_shop();

void random_item();
void item_hpup1();
void item_hpup2();
void item_atkup1();
void item_atkup2();
void item_defup1();
void item_defup2();
void item_spdup1();
void item_spdup2();
void item_shield1();
void item_shield2();
void item_shield3();
void item_absorb1();
void lucky();

void random_attack(status *a);
void enemy_attack(status *a);
void status_print();
void battle(status* a);
void lvup();
void enter();

int hp2 = 0, atk2 = 0, def2 = 0, spd2 = 0;
int coin = 0, guard = 0, absorb = 3, lv = 1, next_lv=2,next_lv1;
status* player = new status(hp2 = 30, atk2 = 3, def2 = 0, spd2 = 3);
status* gob = new status(hp2 = 9, atk2 = 2, def2 = 0, spd2 = 2);
status* gob2 = new status(hp2 = 9, atk2 = 2, def2 = 0, spd2 = 2);
status* gob3 = new status(hp2 = 9, atk2 = 2, def2 = 0, spd2 = 2);

void random(int* a)//a=rands
{
	*a = rand();
	*a = (int)*a % 99;//랜덤함수 부분. 99 이내로 표현함
}

void event1(int a)//a=rands
{
	if (a >= 0 && a <= 9)
		event_skip();
	else if (a >= 10 && a <= 39)
		event_rest();
	else if (a >= 40 && a <= 69)
		event_training();
	else
		event_shop();
}

void event_skip()
{
	std::cout << "-아무일도 일어나지 않았다.." << std::endl;
}

void event_rest()
{
	std::cout << "-휴식할만한 장소를 발견했다. HP가 30퍼센트 증가했다." << std::endl;
	player->hp = player->hp * 1.3;
	std::cout << "-현재 hp=" << player->hp << std::endl;
}

void event_training()
{
	std::cout << "-갑자기 훈련을 하고싶어졌다!! 모든 스테이터스가 증가했다." << std::endl;
	player->hp = player->hp + 10;
	player->atk = player->atk + 2;
	player->def = player->def + 1;
	player->spd = player->spd + 2;
	std::cout << "-현재 스테이터스-" << std::endl;
	std::cout << "- hp = " << player->hp;
	std::cout << " atk = " << player->atk;
	std::cout << " def = " << player->def;
	std::cout << " spd = " << player->spd;
}

void event_shop()
{
	int choose = 0;
	while (1)
	{
		std::cout << "-상점을 발견했다. 100코인으로 아이템을 뽑겠습니까?" << std::endl;
		std::cout << "-1을 입력하면 네. 2를 입력하면 아니오." << std::endl;//iostream에서 사용하는 함수. printf와 같은 기능.endl은 엔터키.
		std::cin >> choose;//위와 같고, scanf와 같은 기능.단,using name space는 쓰지말자.

		if (choose == 1)
		{
			if (coin < 100)
			{
				std::cout << "-코인이 부족합니다. 상점에서 나갑니다." << std::endl;
				break;
			}
			else
			{
				coin = coin - 100;
				random_item();
				std::cout << "-100코인을 소모했습니다. 현재 남은 코인은 " << coin; std::cout << "입니다" << std::endl;
			}
		}
		else if (choose == 2)
		{
			std::cout << "-상점에서 나갑니다." << std::endl;
			break;
		}
		else {
			std::cout << "-잘못된 수를 입력하였습니다. 다시 입력하세요" << std::endl;
			break;
		}
	}
}

//여기서부턴 이전 아이템.h부분이다.---------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------

void random_item()
{
	int rands = 0;
	random(&rands);
	if (rands >= 0 && rands < 5)
		item_hpup1();
	else
		item_absorb1();

}

void item_hpup1()
{
	std::cout << "-체력 회복의 비약을 발견했다.hp가 15 증가했다." << std::endl;
	player->hp = player->hp + 15;
}

void item_hpup2()
{
	std::cout << "-hp가 20 증가했다." << std::endl;
	player->hp = player->hp + 15;
}

void item_atkup1()
{
	std::cout << "-atk가 3 증가했다." << std::endl;
	player->atk = player->atk + 3;
}

void item_atkup2()
{
	std::cout << "-atk가 5 증가했다." << std::endl;
	player->atk = player->atk + 5;

}

void item_defup1()
{
	std::cout << "-def가 2 증가했다." << std::endl;
	player->def = player->def + 3;
}


void item_defup2()
{
	std::cout << "-def가 4 증가했다." << std::endl;
	player->def = player->def + 4;
}

void item_spdup1()
{
	std::cout << "-spd가 3 증가했다." << std::endl;
	player->spd = player->spd + 3;
}

void item_spdup2()
{
	std::cout << "-spd가 5 증가했다." << std::endl;
	player->spd = player->spd + 5;
}

void item_shield1()
{
	guard = guard + 3;
	std::cout << "-가드가 3개 생성되었습니다." << std::endl;
}

void item_shield2()
{
	guard = guard + 5;
	std::cout << "-가드가 5개 생성되었습니다." << std::endl;
}

void item_shield3()
{
	guard = guard + 7;
	std::cout << "-가드가 7개 생성되었습니다." << std::endl;
}

void item_absorb1()
{
	absorb = absorb + 2;
	std::cout << "-흡혈귀의 부러진 이빨을 획득했습니다. 흡혈이 2 추가되었습니다." << std::endl;
}

void lucky()
{
	coin = coin + 200;
	std::cout << "-럭키! 200코인을 돌려받았습니다." << std::endl;
}

//여기서부터는 데미지 관련 부분이다.--------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------

void random_attack(status *a)//a=적
{
	int rands = 0;
	int damage = 0;
	random(&rands);
	if (rands >= 0 && rands <= 9)
	{
		std::cout << "-빗밪았다.. 적에게 절반의 데미지를 입힙니다." << std::endl;
		damage = player->atk / 2;
		a->hp = a->hp - (damage-a->def);
		std::cout << "-적의 남은 hp = "<<a->hp << std::endl;
	}
	else if (rands >= 10 && rands <= 79)
	{
		std::cout << "-적에게 데미지를 입힙니다." << std::endl;
		damage = player->atk;
		a->hp = a->hp - (damage - a->def);
		std::cout << "-적의 남은 hp = " << a->hp << std::endl;
	}
	else
	{
		std::cout << "-크리티컬! 적에게 두배의 데미지를 입힙니다!" << std::endl;
		damage = player->atk * 2;
		a->hp = a->hp - (damage - a->def);
		std::cout << "-적의 남은 hp = " << a->hp << std::endl;
	}
	if (absorb > 0)
	{
		std::cout << "-흡혈로 hp를 " << absorb;
		std::cout << " 회복합니다." << std::endl;
		player->hp = player->hp + absorb;
	}

}

void enemy_attack(status *a)//a=적
{
	if (a->hp < 1)
	{
		
	}
	else if (guard > 0)
	{
		std::cout << "-적의 공격을 막았습니다!" << std::endl;
		std::cout << "-플레이어의 남은 hp = " << player->hp << std::endl;
	}
	else
	{
	player->hp = player->hp - (a->atk - player->def);
	std::cout << "-적에게 공격당했습니다." << std::endl;
	std::cout << "-플레이어의 남은 hp = " << player->hp << std::endl;
	}
}

void status_print()
{
	std::cout << "-플레이어의 현재 상태창 :" << std::endl;
	std::cout << "-hp = " << player->hp;
	std::cout << " atk = " << player->atk;
	std::cout << " def = " << player->def;
	std::cout << " hp = " << player->spd << std::endl;
	std::cout << "-가드 = " <<guard ;
	std::cout << " 흡혈량 = " <<absorb;
	std::cout << " 코인 = " << coin;
	std::cout << " 레벨 = " << lv;
	std::cout << " 다음 레벨까지 전투" << next_lv;
	std::cout << " 회 남음. = " << std::endl;
}

void battle(status *a)//a=적
{
	int rands;
	int any;
	std::cout << "공격하려면 1, 자신의 상태창을 확인하려면 2를 누르세요." << std::endl;
	std::cin >> any;
	enter();
	if (any == 1)
	{
		if (player->spd > a->spd)
		{
			std::cout << "-플레이어의 선공." << std::endl;
			random(&rands);
			random_attack(a);
			enter();
			enemy_attack(a);
			std::cout << "" << std::endl;
		}
		else if (player->spd < a->spd)
		{
			std::cout << "-적의 선공. " << std::endl;
			enemy_attack(a);
			enter();
			random(&rands);
			random_attack(a);
		}
	}
	else if (any == 2)
	{
		status_print();
	}
}

void lvup()
{
	if (next_lv == 0)
	{
		std::cout << "-레벨업했습니다!!" << std::endl;
		std::cout << "-체력이 10 증가되고 모든 스테이터스가 2 증가합니다." << std::endl;
		next_lv1 += 1;
		next_lv = next_lv1 ;
		next_lv1+=1;
		lv += 1;
		player->hp += 10;
		player->atk += 2;
		player->def += 2;
		player->spd += 2;
	}
}

void battle_result()
{
	if (player->hp > 0) {
		std::cout << "-승리했습니다! 30코인을 획득합니다." << std::endl;
		next_lv -= 1;
		lvup();
		system("pause");
		enter();
	}
	else
	{
		std::cout << "-당신은 패배했습니다.. 게임을 재시작 하세요." << std::endl;
		system("pause");
		enter();
		exit(0);
	}
}

void enter()
{
	std::cout << " " << std::endl;
}
