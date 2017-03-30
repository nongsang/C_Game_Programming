#include <stdio.h>
#include <time.h>

int g_nFrameCount;

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

int main(void)
{
	clock_t CurTime, OldTime;
	Init();						// 초기화
	OldTime = clock();
	while (1)
	{
		Update();				// 데이터 갱신
		Render();				// 화면 출력
		while (1)				// 대기 상태 진입
		{
			CurTime = clock();
			if ((double)(CurTime - OldTime) > 16.67)
			{
				OldTime = CurTime;
				break;
			}
		}
		g_nFrameCount++;
	}
	Release();					// 메모리 해제
	return 0;
}

// 플레이어는 유저의 입력에 따라 움직인다.
// 하지만 그외의 요소들(상호작용 가능한 객체, 적 등)은 자체적으로 설정된 값, 혹은 설정된 시간에 따라 스스로 움직이다.
// 만약 각 객체간의 움직임을 표현하는 기준이 다르다면 버그가 발생할 수 있다.
// 따라서 동기화는 게임에서 필수적이다.
// 그 중 하나인 프레임 값을 기준으로 동기화 하는 방법이다.

// 4행
// 전역으로 프레임을 세는 변수를 전역으로 선언하였다.

// 40행
// 한 프레임이 지나가면 지나간 프레임 갯수를 하나씩 누적하여 저장한다.

// 프레임 수를 저장한 값을 기준으로 적이 출현하는 시간을 정한다.
// 잘 사용하는 방법은 아니다.