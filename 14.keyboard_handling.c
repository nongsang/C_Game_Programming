#include <stdio.h>
#include <conio.h>
#include <time.h>

void Init()
{
}

void Update()
{
}

void Render()
{
}

void Release()
{
}

int main()
{
	int nKey;
	clock_t CurTime, OldTime;
	Init();						// 초기화
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
	return 0;
}

// 키보드 처리에 관한 코드이다.

// 29 ~ 40행
// 키보드 입력이 있으면 처리하는 문장이다.
// 키보드 입력이 없으면 바로 Update() 및 Render()를 호출하는 구조.
// 이 구조를 callback이라고 한다.
// 필요한 경우에만 호출하고 그렇지 않다면 기존 문장을 계속 실행하는 것.