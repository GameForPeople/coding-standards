#pragma once

// -----------------------------------
#define _DEBUG_MODE_
// -----------------------------------
/*
	#define _DEBUG_MODE_

		#0. �ش� ��ũ�δ� ���߿� �α׸� ����ϱ� ���� ����Ǹ�, ������ �ÿ��� Off ó���� �ʿ��մϴ�.
		
		#1. �׷���, �Ϻ� ġ������ ���� �߻� �� �� ��µǴ� �α״� �׻� ��µ˴ϴ�.
		
		#2. ��Ÿ ���� �̽� ������ ���� ������ Log�� ���� Ȥ�� �ּ� ó��(�ʿ� ��, �׽�Ʈ)�� ��Ģ���� �մϴ�.
		
		#3. _DEBUG_MODE_ �� Define���ο� ������� ��µǴ� Log ���
			0.
			1.

		#4. _DEBUG_MODE_ �� Define��, ��µǴ� Log ���
			0.
			1.

		!0. int main()���� _DEBUG_MODE_�� Define�� ��, �̸� ����ϴ� ��¹��� �׻� �����ؾ��մϴ�.
*/

//Basic
#include <iostream>

#define		_NORETURN			[[noreturn]]
#define		_NODISCARD			[[nodiscard]]
#define		_DEPRECATED			[[deprecated]]
#define		_MAYBE_UNUSED		[[maybe_unused]]
#define		_FALLTHROUGH		[[fallthrough]]

// �Ʒ� ��ũ�� ���� ����
//#define		_INLINE				__inline
//#define		_ABSTRACT			abstract
//#define		_INTERFACE			__interface
//#define		_NOEXCEPT			noexcept