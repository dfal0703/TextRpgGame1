#pragma once

class status
{
public://public ���� �ؾ� ������ ������ �� ����.
	int hp = 0;
	int atk = 0;
	int def = 0;
	int spd = 0;

	
	status(int hp1, int atk1, int def1, int spd1)
	{
		this->hp = hp1;//����� ���� ���� ���ο��� �����ϰ� �μ��� ������ ��뺯����.HP���� ����.
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
	*a = (int)*a % 99;//�����Լ� �κ�. 99 �̳��� ǥ����
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
	std::cout << "-�ƹ��ϵ� �Ͼ�� �ʾҴ�.." << std::endl;
}

void event_rest()
{
	std::cout << "-�޽��Ҹ��� ��Ҹ� �߰��ߴ�. HP�� 30�ۼ�Ʈ �����ߴ�." << std::endl;
	player->hp = player->hp * 1.3;
	std::cout << "-���� hp=" << player->hp << std::endl;
}

void event_training()
{
	std::cout << "-���ڱ� �Ʒ��� �ϰ�;�����!! ��� �������ͽ��� �����ߴ�." << std::endl;
	player->hp = player->hp + 10;
	player->atk = player->atk + 2;
	player->def = player->def + 1;
	player->spd = player->spd + 2;
	std::cout << "-���� �������ͽ�-" << std::endl;
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
		std::cout << "-������ �߰��ߴ�. 100�������� �������� �̰ڽ��ϱ�?" << std::endl;
		std::cout << "-1�� �Է��ϸ� ��. 2�� �Է��ϸ� �ƴϿ�." << std::endl;//iostream���� ����ϴ� �Լ�. printf�� ���� ���.endl�� ����Ű.
		std::cin >> choose;//���� ����, scanf�� ���� ���.��,using name space�� ��������.

		if (choose == 1)
		{
			if (coin < 100)
			{
				std::cout << "-������ �����մϴ�. �������� �����ϴ�." << std::endl;
				break;
			}
			else
			{
				coin = coin - 100;
				random_item();
				std::cout << "-100������ �Ҹ��߽��ϴ�. ���� ���� ������ " << coin; std::cout << "�Դϴ�" << std::endl;
			}
		}
		else if (choose == 2)
		{
			std::cout << "-�������� �����ϴ�." << std::endl;
			break;
		}
		else {
			std::cout << "-�߸��� ���� �Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���" << std::endl;
			break;
		}
	}
}

//���⼭���� ���� ������.h�κ��̴�.---------------------------------------------------------------------------------------
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
	std::cout << "-ü�� ȸ���� ����� �߰��ߴ�.hp�� 15 �����ߴ�." << std::endl;
	player->hp = player->hp + 15;
}

void item_hpup2()
{
	std::cout << "-hp�� 20 �����ߴ�." << std::endl;
	player->hp = player->hp + 15;
}

void item_atkup1()
{
	std::cout << "-atk�� 3 �����ߴ�." << std::endl;
	player->atk = player->atk + 3;
}

void item_atkup2()
{
	std::cout << "-atk�� 5 �����ߴ�." << std::endl;
	player->atk = player->atk + 5;

}

void item_defup1()
{
	std::cout << "-def�� 2 �����ߴ�." << std::endl;
	player->def = player->def + 3;
}


void item_defup2()
{
	std::cout << "-def�� 4 �����ߴ�." << std::endl;
	player->def = player->def + 4;
}

void item_spdup1()
{
	std::cout << "-spd�� 3 �����ߴ�." << std::endl;
	player->spd = player->spd + 3;
}

void item_spdup2()
{
	std::cout << "-spd�� 5 �����ߴ�." << std::endl;
	player->spd = player->spd + 5;
}

void item_shield1()
{
	guard = guard + 3;
	std::cout << "-���尡 3�� �����Ǿ����ϴ�." << std::endl;
}

void item_shield2()
{
	guard = guard + 5;
	std::cout << "-���尡 5�� �����Ǿ����ϴ�." << std::endl;
}

void item_shield3()
{
	guard = guard + 7;
	std::cout << "-���尡 7�� �����Ǿ����ϴ�." << std::endl;
}

void item_absorb1()
{
	absorb = absorb + 2;
	std::cout << "-�������� �η��� �̻��� ȹ���߽��ϴ�. ������ 2 �߰��Ǿ����ϴ�." << std::endl;
}

void lucky()
{
	coin = coin + 200;
	std::cout << "-��Ű! 200������ �����޾ҽ��ϴ�." << std::endl;
}

//���⼭���ʹ� ������ ���� �κ��̴�.--------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------

void random_attack(status *a)//a=��
{
	int rands = 0;
	int damage = 0;
	random(&rands);
	if (rands >= 0 && rands <= 9)
	{
		std::cout << "-���S�Ҵ�.. ������ ������ �������� �����ϴ�." << std::endl;
		damage = player->atk / 2;
		a->hp = a->hp - (damage-a->def);
		std::cout << "-���� ���� hp = "<<a->hp << std::endl;
	}
	else if (rands >= 10 && rands <= 79)
	{
		std::cout << "-������ �������� �����ϴ�." << std::endl;
		damage = player->atk;
		a->hp = a->hp - (damage - a->def);
		std::cout << "-���� ���� hp = " << a->hp << std::endl;
	}
	else
	{
		std::cout << "-ũ��Ƽ��! ������ �ι��� �������� �����ϴ�!" << std::endl;
		damage = player->atk * 2;
		a->hp = a->hp - (damage - a->def);
		std::cout << "-���� ���� hp = " << a->hp << std::endl;
	}
	if (absorb > 0)
	{
		std::cout << "-������ hp�� " << absorb;
		std::cout << " ȸ���մϴ�." << std::endl;
		player->hp = player->hp + absorb;
	}

}

void enemy_attack(status *a)//a=��
{
	if (a->hp < 1)
	{
		
	}
	else if (guard > 0)
	{
		std::cout << "-���� ������ ���ҽ��ϴ�!" << std::endl;
		std::cout << "-�÷��̾��� ���� hp = " << player->hp << std::endl;
	}
	else
	{
	player->hp = player->hp - (a->atk - player->def);
	std::cout << "-������ ���ݴ��߽��ϴ�." << std::endl;
	std::cout << "-�÷��̾��� ���� hp = " << player->hp << std::endl;
	}
}

void status_print()
{
	std::cout << "-�÷��̾��� ���� ����â :" << std::endl;
	std::cout << "-hp = " << player->hp;
	std::cout << " atk = " << player->atk;
	std::cout << " def = " << player->def;
	std::cout << " hp = " << player->spd << std::endl;
	std::cout << "-���� = " <<guard ;
	std::cout << " ������ = " <<absorb;
	std::cout << " ���� = " << coin;
	std::cout << " ���� = " << lv;
	std::cout << " ���� �������� ����" << next_lv;
	std::cout << " ȸ ����. = " << std::endl;
}

void battle(status *a)//a=��
{
	int rands;
	int any;
	std::cout << "�����Ϸ��� 1, �ڽ��� ����â�� Ȯ���Ϸ��� 2�� ��������." << std::endl;
	std::cin >> any;
	enter();
	if (any == 1)
	{
		if (player->spd > a->spd)
		{
			std::cout << "-�÷��̾��� ����." << std::endl;
			random(&rands);
			random_attack(a);
			enter();
			enemy_attack(a);
			std::cout << "" << std::endl;
		}
		else if (player->spd < a->spd)
		{
			std::cout << "-���� ����. " << std::endl;
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
		std::cout << "-�������߽��ϴ�!!" << std::endl;
		std::cout << "-ü���� 10 �����ǰ� ��� �������ͽ��� 2 �����մϴ�." << std::endl;
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
		std::cout << "-�¸��߽��ϴ�! 30������ ȹ���մϴ�." << std::endl;
		next_lv -= 1;
		lvup();
		system("pause");
		enter();
	}
	else
	{
		std::cout << "-����� �й��߽��ϴ�.. ������ ����� �ϼ���." << std::endl;
		system("pause");
		enter();
		exit(0);
	}
}

void enter()
{
	std::cout << " " << std::endl;
}
