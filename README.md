# coding-standards
  
### A. 네이밍

 **1.** **define, namespace, enum class, const, constexpr, goto** : **대문자** 와 **밑줄** 을 사용합니다.  
*    ` #define DEBUG_MODE `
*    ` #define _NODISCARD [[nodiscard]]   `
*    ` namespace CONVERT_UTIL {...} `  
*    ` enum class BUFF_STATE_BIT : BYTE { ... }; `
*    ` enum WEAPON_PRICE : int { ... }; `
*    ` constexpr int SERVER_PORT_NUMBER = 9000; `
*    ` const int HANDGUN_PRICE = 1000; `
*    ` goto  `
 
 **2.** **using, typedef** : 첫 글자를 **밑줄**로, 각 단어의 첫 글자를 **대문자** 로 사용합니다.
*    ` using _UserIter = std::map< int, UserData >::iterator; `
*    ` typedef std::list< MonsterData > _MonsterCont; `

 **3.** **class, struct** : 시작 글자와 각 단어의 첫 글자를 **대문자**로 사용합니다. 
*    ` class LobbyScene; `
*    ` struct SocketInfo; `
> **a.** 다만, 해당 클래스가 추상클래스일 경우, 클래스 앞에 **Base**를 붙여줍니다.
>*    ` class BaseWeapon abstract {...}; `
> **b.** 또 해당 클래스가 인터페이스일 경우, 클래스 앞에 **InterFace**를 붙여줍니다.
>*    ` __interface class InterFaceBaseWeapon {...}; `

 **4.** **함수** : 시작 글자와 각 단어의 첫 글자를 **대문자**로 사용합니다. (private, public 멤버 함수 동일)
*    ` bool EnterUserWithNickname(const string& inNickname) {...}; `
*    ` int GetSpeed() {...}; `
> **a.** Get, Set, Ref 함수를 제외하고는 **함수의 기능을 명확하게 묘사할 수 있는 이름**을 사용하도록 노력합니다.
>*    ` bool CheckBossMonster(const BossMonster&); -> bool IsSpawnBossMonster(const BossMonster&); `

 **5.** **변수** : 시작 글자를 **소문자**로, 각 단어의 첫 글자를 **대문자**로 사용합니다. (private, public 멤버 변수 동일)
*    ` float equipedItemWeight; `
*    ` bool isPlayerDead; `
*    ` BossMonster bossMonster; `
> **a.** 예외적으로 원시 포인터를 사용할 경우, **p**를 사용합니다.
>*    ` NpcController* pNpcController; `	
> **b.** 변수 이름을 지을 때, **변수를 명확하게 묘사할 수 있는 이름을 사용하도록** 노력합니다.
>*    ` bool is(const BossMonster&); -> bool IsSpawnBossMonster(const BossMonster&); `
> **c.** 변수 이름을 지을 때, 길어지더라도 **불필요한 약자를 사용하지 않도록** 노력합니다.

 **6.** **매개변수와 반환값** : 용도에 따라, **in**, **out**, **ret**을 접두어로, 이후 각 단어의 첫 글자를 **대문자**로 사용합니다.
*    ` void SetMoney( const int inMoney ); `
*    ` bool TakeDamage( UserData& outUserData ); `
*    ` std::shared_ptr<Room> CreateRoom() { std::shared_ptr<Room> retNewRoom = make_shared<Room>(); ...; return retNewRoom; } `
  
 **7.** **템플릿** : 추후 규정
  
----

### B. 중괄호, 줄바꿈 

**1.** **namespace, enum class, class, struct** : 중괄호 전 개행해줍니다.
```cpp
namespace NPC_UTIL
{
}

enum class WEAPON_TYPE : BYTE
{
}

class BaseCharacter
{
}

struct Position2D
{
}
```
  
  
**2.** **함수 정의** : 동일하게, 중괄호 전 개행해줍니다.
```cpp
void BaseSpawner::SpawnNewActor(const Position& inPosition, const ActorState& inActorState)
{
}
```
> **a.** 다만, inline함수와 연산자의 함수 정의가 1줄에 해당할 경우, 개행하지 않음. 
```cpp
class BaseActor
{
  _NODISCARD _inline Position GetPosition() const noexcept { return position; };
  _inline void SetPosition(const Position& inPosition) noexcept { position = inPosition; };

  void operator()() { std::cout << position.x <<" "<< position.y << std::endl; };
};
```
> **b.** 생성자의 초기화 리스트에서는, 각 멤버변수마다 개행합니다. 
```cpp
UserData::UserData(const string& inId, const int inPw, const int inWinCount, const int inLoseCount, const int inMoney) noexcept
  : id(inId)
  , pw(inPw)
  , winCount(inWinCount)
  , loseCount(inLoseCount)
  , money(inMoney)
 {};
```
> **c.** 함수의 인자 목록이 길 경우, 의미 단위 혹은 적합한 길이에 따라 개행합니다.
```cpp
bool RoomManager::GetRoomGameDataWithIndex(const int inRoomIndex, const bool inIsHost, 
    int& outPlayerMissionIndex, int& outEnemyMissionIndex, int& outSubMissionIndex, int& outEnemyCharacterIndex, 
    Type_Nickname& outEnemyNickname)
	{
		...
	}
```
  
  
**3.** **if-else, for, while** : 동일하게, 중괄호 전 개행해줍니다.
```cpp
if (7)
{
}
else
{
}

for (int i = 0; i < 1; ++i)
{
}

while(7)
{
}
```
> **a.** if-else 의 모든 실행문이 한 줄일 경우, 해당 실행문은 개행과 중괄호를 사용하지 않음.
```cpp
if (isLogin)  std::cout << "로그인한 유저입니다." << std::endl;
else  std::cout << "로그인하지 않은 유저입니다." << std::endl;
```
> **b.** 다만 if-else 의 일부 실행문이 한 줄일 경우, 해당 실행문은 중괄호를 사용하지 않음.
```cpp
if (isBugGenerated)   
  std::cout << "버그가 발생했습니다. 정상입니다." << std::endl;
else
(
  std::cout << "버그가 발생하지 않았습니다. 비정상입니다." << std::endl;
  PrintDebugLog();
}
```
> **c.** if조건문 내에 변수를 생성할 때(if-init), 함수를 포함할 경우, 항상 개행해줍니다.
```cpp
if (DAMAGE_TYPE damageType = inEnemy.GetDamageType()
  ; damageType == DAMAGE_TYPE::FIRE) std::cout << "앗 뜨거!" << std::endl;
else if (damageType == DAMAGE_TYPE::WATER) std::cout << "앗 차거!" << std::endl;
else if (damageType == DAMAGE_TYPE::THUNDER) std::cout << "앗 따거!" << std::endl;
else std::cout << "엄살입니다." << std::endl;
```
> **d.** for문에서 함수를 사용할 경우, 항상 개행해줍니다.
```cpp
for (auto iter = userData->RefFriendCont().begin()
  ; iter != userData->RefFriendCont().end()
  ; ++iter)
  {
    ...
  }
```
  
  
 **4.** **switch** : 중괄호를 사용하지 않습니다.
> **a.** 모든 switch문에는, 항상 default: Break; 가 존재해야합니다.   
> **b.** 해당 조건에 따른 실행문이 존재하지 않고, fallthrough할 때는, fallthrough를 명시하지 않아도 됩니다.  
> **c.** 해당 조건에 따른 실행문이 존재하며, fallthrough할 때는, fallthrough를 명시해야 합니다.  
```cpp
switch (grade)
    {
        case USER_GRADE::Diamond:
          PresentItem();
          _FALLTHROUGH /* == [[fallthrough]] */     //c
        case USER_GRADE::GOLD:
          PresentMoney();
          break;
        case USER_GRADE::BRONZE:                    //b
        case USER_GRADE::IRON:  
          DeleteUserData();
          break;
        default:                                    //a
          break;
    }       
```

----

### C. 주석 달기 

**1.** 적절한 네이밍을 통해, 주석 작성을 최소화합니다. 다만 협업 시 공유되는 코드나, 주석이 필요할 것으로 보이는 부분에는 항상 주석을 작성합니다.

**2.** 파일, 클래스 및 함수 수준에서 작성되는 모든 주석에는 기본적으로 __-__, __#__, __!__, __?__ 와 __숫자__ 를 사용합니다.
> **a.** 파일, 클래스 및 함수의 기본적인 설명을 작성 시에는 __-__ 를 사용합니다.   
> **b.** 파일, 클래스 및 함수의 부가적인 설명을 작성 시에는 __#__ 를 사용합니다.
> **c.** 파일, 클래스 및 함수의 주의할 부분을 작성 시에는 __!__ 를 사용합니다. 
> **d.** 능력의 무족으로 파일, 클래스 및 함수의 명확하지 않은 부분, 추후 개선사항이 있다면 __?__ 를 사용합니다. 


