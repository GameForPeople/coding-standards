#pragma once

// -----------------------------------
#define _DEBUG_MODE_
// -----------------------------------
/*
	#define _DEBUG_MODE_

		#0. 해당 매크로는 개발용 로그를 출력하기 위해 선언되며, 릴리즈 시에는 Off 처리가 필요합니다.
		
		#1. 그러나, 일부 치명적인 오류 발생 시 등 출력되는 로그는 항상 출력됩니다.
		
		#2. 기타 단위 이슈 개발을 위해 존재한 Log는 삭제 혹은 주석 처리(필요 시, 테스트)를 원칙으로 합니다.
		
		#3. _DEBUG_MODE_ 의 Define여부와 상관없이 출력되는 Log 목록
			0.
			1.

		#4. _DEBUG_MODE_ 의 Define시, 출력되는 Log 목록
			0.
			1.

		!0. int main()에서 _DEBUG_MODE_가 Define일 때, 이를 경고하는 출력문을 항상 포함해야합니다.
*/

//Basic
#include <iostream>

#define		_NORETURN			[[noreturn]]
#define		_NODISCARD			[[nodiscard]]
#define		_DEPRECATED			[[deprecated]]
#define		_MAYBE_UNUSED		[[maybe_unused]]
#define		_FALLTHROUGH		[[fallthrough]]

// 아래 매크로 삭제 예정
//#define		_INLINE				__inline
//#define		_ABSTRACT			abstract
//#define		_INTERFACE			__interface
//#define		_NOEXCEPT			noexcept