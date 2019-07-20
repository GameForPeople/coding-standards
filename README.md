# coding-standards
  
### A. 네이밍


 **0.** 파일명은 시작 글자와 각 단어의 첫 글자를 **대문자**로 사용합니다.
*    ` NetworkManager.cpp `  
*    ` MemoryUnit.h ` 
> **a.** 소스파일은 ".cpp"를, 헤더 파일은 ".h"의 확장자를 갖으며, 대부분의 경우 한 쌍으로 이루어집니다.
>*    ` BaseItem.cpp <=> BaseItem.h `
>
> **b.** 다만 템플릿과 관련된, 소스파일은 ".hpp"의 확장자를 사용합니다. 이는 h에 포함되는 cpp이기 때문입니다.
>*    ` CustomContainer.h  <=>  CustomContainer.hpp, CustomContainer.cpp `
>
> **c.** 헤더에 포함되는 헤더파일의 경우 ".hh"의 확장자를 사용합니다. 이는 h에 포함되는 h이기 때문입니다.
>*    ` ConstexprDefine.hh `

 **1.** **define, namespace, enum class, const, constexpr, goto(?)** : **대문자** 와 **밑줄** 을 사용합니다.  
*    ` #define DEBUG_MODE `
*    ` #define _NODISCARD [[nodiscard]]   `
*    ` namespace CONVERT_UTIL {...} `  
*    ` enum class BUFF_STATE_BIT : BYTE { ... }; `
*    ` enum WEAPON_PRICE : int { ... }; `
*    ` constexpr int SERVER_PORT_NUMBER = 9000; `
*    ` const int HANDGUN_PRICE = 1000; `
*    ` goto LIKE_RECURSION;`
 
 **2.** **using, typedef** : 첫 글자를 **밑줄**로, 각 단어의 첫 글자를 **대문자** 로 사용합니다.
*    ` using _UserIter = std::map< int, UserData >::iterator; `
*    ` typedef std::list< MonsterData > _MonsterCont; `

 **3.** **class, struct** : 시작 글자와 각 단어의 첫 글자를 **대문자**로 사용합니다. 
*    ` class LobbyScene; `
*    ` struct SocketInfo; `
> **a.** 다만, 해당 클래스가 추상클래스일 경우, 클래스 앞에 **Base**를 붙여줍니다.
>*    ` class BaseWeapon abstract {...}; `
>         
> **b.** 또 해당 클래스가 인터페이스일 경우, 클래스 앞에 **InterFace**를 붙여줍니다.
>*    ` __interface class InterFaceBaseWeapon {...}; `

 **4.** **함수** : 시작 글자와 각 단어의 첫 글자를 **대문자**로 사용합니다. (private, public 멤버 함수 동일)
*    ` bool EnterUserWithNickname(const string& inNickname) {...}; `
*    ` int GetSpeed() {...}; `     
> **a.** Get, Set, Ref 함수를 제외하고는 **함수의 기능을 명확하게 묘사할 수 있는 이름**을 사용하도록 노력합니다.
>*    ` (BAD) bool CheckBossMonster(const BossMonster&); => (GOOD) bool IsSpawnBossMonster(const BossMonster&); `

 **5.** **변수** : 시작 글자를 **소문자**로, 각 단어의 첫 글자를 **대문자**로 사용합니다. (private, public 멤버 변수 동일)
*    ` float equipedItemWeight; `
*    ` bool isPlayerDead; `
*    ` BossMonster bossMonster; `
> **a.** 예외적으로 원시 포인터를 사용할 경우, **p**를 사용합니다.
>*    ` NpcController* pNpcController; `	
>
> **b.** 변수 이름을 지을 때, **변수를 명확하게 묘사할 수 있는 이름을 사용하도록** 노력합니다.        
>
>*    ` bool isRunBossMonster(const BossMonster&); -> bool IsSpawnBossMonster(const BossMonster&); `      
>  
> **c.** 변수 이름을 지을 때, 길어지더라도 **불필요한 약자를 사용하지 않도록** 노력합니다.
>
> **d.** 다만 일시적인 로컬 변수를 사용할 때는, **temp**를 접두어로, 이후 각 단어의 첫 글자를 **대문자**로 사용합니다.

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

### C. 주석 활용

**1.** 적절한 네이밍, 리뷰하기 쉬운 코드 작성 등 이상적인 프로그래밍을 통해, 주석 작성을 최소화합니다.   
다만 협업 시 공유되는 코드나, 주석이 필요할 것으로 보이는 부분에는 항상 주석을 작성합니다.

**2.** 파일, 클래스 및 함수 수준에서 작성되는 모든 주석에는 기본적으로 __-__, __#__, __!__, __?__ 와 __숫자__ 를 사용합니다.   
> **a.** 파일, 클래스 및 함수의 기본적인 설명을 작성 시에는 __-__ 를 사용합니다.        
> **b.** 파일, 클래스 및 함수의 부가적인 설명을 작성 시에는 __#__ 를 사용합니다.     
> **c.** 파일, 클래스 및 함수의 주의할 부분을 작성 시에는 __!__ 를 사용합니다.      
> **d.** 파일, 클래스 및 함수의 구현 시, 명확하지 않은 부분, 추후 개선사항이 있다면 __?__ 를 사용합니다.           

**3.** 클래스, 구조체에 대한 주석 작성 시, 헤더파일(.h)에서 해당 선언 위에 작성해줍니다.
```cpp
/*
	RedBlackTreeNode
		- 레드 블랙 트리 (적흑나무) 를 구성하는 단위(Node)입니다.
		
	#0. DATA는 보관할 데이터, KEY_TYPE은 GetKey()의 반환되는 자료형입니다.
		
	!0. DATA는 의무적으로 GetKey() 함수를 제공해야합니다.
	!1. KEY_TYPE이 기초 자료형이 아닐 경우 일부 연산자를 요구합니다. (TestKey Class를 참고해주세요!)
		- 키 값 크기 비교에 사용될 연산자 operator<()를 제공(오버로딩)해야합니다.
		- 키 값이 동일한지 검사할때 사용될 연산자 operator==()를 제공(오버로딩)해야합니다.
		- 출력에 사용될 연산자 operator<<()를 제공(오버로딩)해야합니다.
	!2. DATA와 KEY_TYPE은 기본 생성자를 요구합니다.
		- rbTree는 pNullNode(NIL)를 생성하는데, 이때 사용될 기본생성자를 요구합니다.

	?0. 이동 연산자가 구현이 될 경우 성능적인 이점이 있는 지, 문제는 발생하지 않는 지에 대한 테스트 필요.
*/
template <typename DATA, typename KEY_TYPE>
class RedBlackTreeNode { ... };
```

**4.** 함수에 대한 주석 작성 시, 코드파일(.cpp)에서 해당 함수 정의 위에 작성해줍니다.

```cpp
/*
	Node* Pop()
		- 스택의 Top Pointer에서 노드를 꺼내 반환합니다.

	#0. 인자 : void
	#1. 출력 : Pop되는 Node의 포인터

	!1. 스택이 비어 있을 때 Pop을 호출한 경우, Warning Log를 출력하며, nullptr를 반환합니다. ( Stack Underflow )
*/
SIMPLE_STACK::Node* SIMPLE_STACK::SimpleStack::Pop() {...};
```

**5.** n줄의 코드에 대해 주석이 필요할 경우, __//__ 으로 해당 코드가 시작되기 전에 작성합니다.    
     
**6.** if-else 문에서, 마지막 else를 설명할 수 있을 때, 최적화와 코드 리뷰를 위해, 주석을 사용합니다.
```cpp
	if(inCharacterType == CHARACTER_TYPE::ENGLISH) std::cout<< "영어입니다. \n";
	else if(inCharacterType == CHARACTER_TYPE::KOREAN) std::cout<< "한글입니다. \n";
	else if(inCharacterType == CHARACTER_TYPE::NUMBER) std::cout<< "숫자입니다. \n";
	else /* if(inCharacterType == CHARACTER_TYPE::OTHER) */ std::cout<< "기타 문자 타입입니다. \n";
```

----

### D. 클래스, 구조체에 관하여

**1. 클래스 혹은 구조체의 선정** : 멤버 변수, 생성자, 소멸자, 연산자만으로 구성될 경우 구조체로, 이외에는 클래스를 사용합니다.

**2. 생성자**

> **a.** 생성자의 초기화리스트는 모든 멤버 변수를 포함해야합니다. 

> **b.** 예외를 발생시키지 않는 생성자는 성능과 예외 완전성 보증을 위해 noexcept 지정자를 사용합니다.

> **c.** 모든 기본생성자에 대해, 사용할 경우 default를, 사용하지 않을 경우 delete를 명시합니다.

> **d.** 모든 기본생성자에 대해, 사용할 경우 default를, 사용하지 않을 경우 delete를 명시합니다.
