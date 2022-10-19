텍스트 주사위 RPG게임 계획

1. 게임의 목표.
스테이지를 깨서 다양한 방법으로 강해지고 최종보스까지 깨는것이 목표.

2-1. 게임 룰(스테이터스)
기본적으로 플레이어와 적의 스테이터스는
HP, ATK , DEF, SPD 가 있다.

HP는 체력이다. 플레이어의 HP가 0이하가 되면 게임오버가 되며 종료된다. 
모든 적의 HP가 0이하가 되면 게임을 클리어한다.
최대체력 까지는 생각하기 힘들고 회복을 통해 계속 HP를 올릴수 있게 만들 것이다.

ATK는 공격력이다. 플레이어의 ATK만큼 적의 HP를 깎을 수 있고,
적 또한 ATK 만큼 플레이어의 HP를 깎을 수 있다.

DEF는 방어력이다. DEF만큼 적의 공격을 상쇄할 수 있다. 적또한 마찬가지다.

SPD는 속도이다. 속도가 빠르면 적에게 선공을 가할 수 있다.

2-2 게임 룰(플레이어)
플레이어는 초반에 낮은 스테이터스로 시작한다.
기본 스테이터스는 HP 30 ATK 3 DEF 0 SPE 3 정도로 고민중이며 만들면서 밸런스를 조정할수도 있다.
레벨업을 통해 스테이터스가 오른다. 
지금 레벨업을 어떻게 구현할지는 정확히 떠오르지 않는다.. 
매 스테이지마다 경험치를 측정하여 레벨을 지정해줘야 하려나? 더 쉬운 방법이 있을지도 모르겠다.
정 어려우면 레벨업 시스템을 삭제할 수도 있겠다.
아이템을 통해서도 스테이터스를 보충할 수 있다.
플레이어가 얻는 재화로는 경험치와 GOLD 정도만 생각중이다.

2-3 게임 룰(스테이지의 구조)
스테이지 하나당 여러마리의 몬스터가 있을 수 있다. 추후 지정.
초반에는 몬스터의 마릿수가 적고 스테이터스가 낮다. 

공격 방식은 주사위를 굴려 빗맞음, 적중, 크리티컬 이 세개 중 하나로 적을 타격하는 것으로 정했다.
이는 아이템을 통해 확률을 조정할 수 있다.
적과의 대결중에서 자신의 턴에 scanf로 번호를 입력받아 
1번은 공격, 2번은 스테이터스 확인, 3번은 아이템 확인 으로 하는 것으로 생각하고 있다.

스테이지 하나를 클리어하면 주사위를 굴려 랜덤한 이벤트를 발생시킨다.
크게는 스킵, 쉼터, 상점, 수련 정도를 구상하고 있다.
스킵- 아무일도 일어나지 않고 넘어간다.
쉼터- 주사위를 굴려 HP회복이 가능하다.
상점- GOLD를 소모해 주사위를 굴려 랜덤한 아이템을 획득 가능하다. 상점에서는 계속 돈을 투입하여 아이템을 뽑을 수 있다.
수련- HP를 제외한 스테이터스를 랜덤으로 소량 올릴 수 있다.

3. 아이템 종류
확률 증가 아이템-공격을 했을때의 크리티컬 확률을 늘려주거나 빗맞힘 확률을 줄여준다.
또는 상점or쉼터or수련의 확률을 증가시키거나 스킵의 확률을 줄여준다.

스테이터스 증가 아이템- 정해진 양의 스테이터스를 높여준다.(HP회복 포함)

흡혈 아이템 - 공격시 HP를 1씩 회복한다.

리턴 아이템 - 뽑기에 쓴 돈 이상의 돈을 돌려준다.

막기 아이템- 적의 공격을 무조건 일정횟수 막아주고 사라진다.

요정도가 있고 스테이터스 증가 아이템의 종류를 가장 많게 할 예정이다.

4.몬스터 종류
추후 구상

5.프로젝트 기한
1개월


이 프로젝트는 2로 넘어가며 전면 갈아 엎었음.
