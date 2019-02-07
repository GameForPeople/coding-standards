# coding-standards
  
  
### A. 네이밍 규칙 

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
>*    ` class BaseWeapon; `
>*    ` struct SocketInfo; `

> **4.** **함수** : 시작 글자와 각 단어의 첫 글자를 **대문자**로 사용합니다. (private, public 동일)
>*    ` bool EnterUserWithNickname(const string& inNickname) {...}; `
>*    ` int GetSpeed() {...}; `

> **5.** **변수** : 시작 글자를 **소문자**로, 각 단어의 첫 글자를 **대문자**로 사용합니다. (private, public 동일)
>*    ` float equipedItemWeight{}; `
>*    ` bool isPlayerDead{}; `
>*    ` BossMonster bossMonster; `

