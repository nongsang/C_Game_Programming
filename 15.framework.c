#include <stdio.h>
#include <conio.h>
#include <time.h>
#include "Screen.h"

void Init()
{

}

void Update()
{

}

void Render()
{
	ScreenClear();		// 화면 지우기
	// 출력 코드

	ScreenFlipping();	// 화면 전환
}

void Release()
{

}

int main()
{
	int nKey;
	clock_t CurTime, OldTime;
	Init();						// 초기화
	ScreenInit();				// 화면 초기화
	OldTime = clock();
	while (1)
	{
		if (_kbhit())			// 키보드 입력이 있으면
		{
			nKey = _getch();	// 입력한 값을 저장하고
			if ('q' == nKey)	// q면 게임 종료
				break;
			switch (nKey)		// 그게 아니라면 switch로 행동 정의
			{
			case 'j':
				break;
			case 'l':
				break;
			}
		}

		Update();		// 업데이트
		Render();		// 화면에 그려주기
		while (1)
		{
			CurTime = clock();
			if ((double)(CurTime - OldTime) > 16.67)
			{
				OldTime = CurTime;
				break;
			}
		}
	}
	Release();					// 메모리 해제
	ScreenRelease();			// 화면 해제
}

// 코드를 작성하기 위해서 제공되는 프로그래밍 틀인 프레임워크를 만든다.

// 34행
// 화면을 초기화 해준다.

// 16 ~ 22행
// 그리기 함수가 불리면 화면을 지우고 화면에 출력후 화면을 스위칭해준다.

// 65행
// 게임이 종료되면 생성한 화면을 없앤다.

// 화면에 관한 함수들은 Screen.h에 선언이 되어있고, Screen.c에 정의가 되어있다.