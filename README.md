# coding-standards
  
  
### A. 네이밍

> **1.** **define, namespace, enum class, const, constexpr** : **대문자** 와 **밑줄** 을 사용합니다.  
>*    ` #define DEBUG_MODE `
>*    ` #define _NODISCARD [[nodiscard]]   `
>*    ` namespace CONVERT_UTIL {...} `  
>*    ` enum class BUFF_STATE_BIT : BYTE { ... }; `
>*    ` enum WEAPON_PRICE : int { ... }; `
>*    ` constexpr int SERVER_PORT_NUMBER = 9000; `
>*    ` const int HANDGUN_PRICE = 1000; `
 
> **2.** **using, typedef** : 첫 글자를 **밑줄**로, 각 단어의 첫 글자를 **대문자** 로 사용합니다.
>*    ` using _UserIter = std::map< int, UserData >::iterator; `
>*    ` typedef std::list< MonsterData > _MonsterCont; `

> **3.** **class, struct** : 시작 글자와 각 단어의 첫 글자를 **대문자**로 사용합니다. 
>*    ` class LobbyScene; `
>*    ` struct SocketInfo; `
>> **a.** 다만, 해당 클래스가 추상클래스일 경우, 클래스 앞에 Base를 붙여줍니다.
>*    ` class BaseWeapon _ABSTRACT /* == abstract */ {...}; `
>> **b.** 또 해당 클래스가 인터페이스일 경우, 클래스 앞에 InterFace를 붙여줍니다.
>*    ` _INTERFACE /* == __interface */ class InterFaceBaseWeapon {...}; `

> **4.** **함수** : 시작 글자와 각 단어의 첫 글자를 **대문자**로 사용합니다. (private, public 멤버 함수 동일)
>*    ` bool EnterUserWithNickname(const string& inNickname) {...}; `
>*    ` int GetSpeed() {...}; `

> **5.** **변수** : 시작 글자를 **소문자**로, 각 단어의 첫 글자를 **대문자**로 사용합니다. (private, public 멤버 변수 동일)
>*    ` float equipedItemWeight; `
>*    ` bool isPlayerDead; `
>*    ` BossMonster bossMonster; `

> **6.** **매개변수와 반환값** : 용도에 따라, **in**, **out**, **ret**을 접두어로, 이후 각 단어의 첫 글자를 **대문자**로 사용합니다.
>*    ` void SetMoney( const int inMoney ); `
>*    ` bool TakeDamage( UserData& outUserData ); `
>*    ` std::shared_ptr<Room> CreateRoom() { std::shared_ptr<Room> retNewRoom = make_shared<Room>(); ...; return retNewRoom; } `
  
  
  
### B. 중괄호, 줄바꿈 

> **1.** **namespace, enum class, class, struct** : 중괄호 전 개행해줍니다.
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

> **2.** **함수 정의** : 동일하게, 중괄호 전 개행해줍니다.
```cpp
void BaseSpawner::SpawnNewActor(const Position& inPosition, const ActorState& inActorState)
{
}
```
>> **a.** 다만, inline함수와 연산자의 함수 정의가 1줄에 해당할 경우, 개행하지 않음. 
```cpp
class BaseActor
{
  _NODISCARD _inline Position GetPosition() const noexcept { return position; };
  _inline void SetPosition(const Position& inPosition) noexcept { position = inPosition; };

  void operator()() { std::cout << position.x <<" "<< position.y << std::endl; };
};
```
>> **b.** 생성자의 초기화 리스트에서는, 각 멤버변수마다 개행합니다. 
```cpp
UserData::UserData(const string& inId, const int inPw, const int inWinCount, const int inLoseCount, const int inMoney) noexcept
  : id(inId)
  , pw(inPw)
  , winCount(inWinCount)
  , loseCount(inLoseCount)
  , money(inMoney)
 {};
```
>> **c.** 함수의 인자 목록이 길 경우, 의미 단위 혹은 적합한 길이에 따라 개행합니다.
```cpp
bool RoomManager::GetRoomGameDataWithIndex(const int inRoomIndex, const bool inIsHost, 
    int& outPlayerMissionIndex, int& outEnemyMissionIndex, int& outSubMissionIndex, int& outEnemyCharacterIndex, 
    Type_Nickname& outEnemyNickname)
	{
		...
	}
```

> **3.** **if-else, for, while** : 동일하게, 중괄호 전 개행해줍니다.
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
>> **a.** if-else 의 모든 실행문이 한 줄일 경우, 해당 실행문은 개행과 중괄호를 사용하지 않음.
```cpp
if (isLogin)  std::cout << "로그인한 유저입니다." << std::endl;
else  std::cout << "로그인하지 않은 유저입니다." << std::endl;
```
>> **b.** 다만 if-else 의 일부 실행문이 한 줄일 경우, 해당 실행문은 중괄호를 사용하지 않음.
```cpp
if (isBugGenerated)   
  std::cout << "버그가 발생했습니다. 정상입니다." << std::endl;
else
(
  std::cout << "버그가 발생하지 않았습니다. 비정상입니다." << std::endl;
  PrintDebugLog();
}
```
>> **c.** if조건문 내에 변수를 생성할 때(if-init), 함수를 포함할 경우, 항상 개행해줍니다.
```cpp
if (DAMAGE_TYPE damageType = inEnemy.GetDamageType()
  ; damageType == DAMAGE_TYPE::FIRE) std::cout << "앗 뜨거!" << std::endl;
else if (damageType == DAMAGE_TYPE::WATER) std::cout << "앗 차거!" << std::endl;
else if (damageType == DAMAGE_TYPE::THUNDER) std::cout << "앗 따거!" << std::endl;
else std::cout << "엄살입니다." << std::endl;
```
>> **d.** for문에서 함수를 사용할 경우, 항상 개행해줍니다.
```cpp
for (auto iter = userData->RefFriendCont().begin()
  ; iter != userData->RefFriendCont().end()
  ; ++iter)
  {
    ...
  }
```

> **4.** **switch** : 중괄호를 사용하지 않습니다.
>> **a.** 모든 switch문에는, 항상 Default: Break; 가 존재해야합니다. 
>> **b.** 해당 조건에 따른 실행문이 존재하지 않고, fallthrough할 때는, fallthrough를 명시하지 않아도 됩니다.
>> **c.** 해당 조건에 따른 실행문이 존재하며, fallthrough할 때는, fallthrough를 명시해야 합니다.
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

### F. 클래스, 구조체 

> **1.** private 멤버를 사용하지 않고, 생성자, 소멸자만 필요할 때는 구조체를, 이외의 경우에서는 클래스를 사용한다.

