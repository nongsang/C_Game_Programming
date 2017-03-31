#include <stdio.h>
#include <conio.h>
#include <time.h>

void Init()
{
}

void Update()
{
	//CurTime = clock(); // 현재 시각

	//if (CurTime - OldMoveTime > 2000)
	//{
	//	OldTime = CurTime;
	//	// 캐릭터 이동
	//	nX++;
	//	nY++;
	//}
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
	Init();					// 초기화
	OldTime = clock();
	while (1)
	{
		Update();		// 데이터 갱신
		Render();		// 화면 출력
		while (1)		// 대기 상태 진입
		{
			CurTime = clock();
			if ((double)(CurTime - OldTime) > 16.67)
			{
				OldTime = CurTime;
				break;
			}
		}
	}
	Release();			// 해제
}

// 시간을 통해서 게임 객체 동기화를 해준다.
// 프레임을 계산하여 동기화를 해준다면 성능이 낮은 컴퓨터는 프레임을 빨리 그리지 못하므로 타이밍이 어긋나게 된다.
// 그렇기 때문에 시간 간격을 이용해서 동기화를 한다면 어떤 컴퓨터든 동일한 경험을 제공할 수 있을 것이다.

// 9 ~ 20행
// update에서 일정 시간이 지날 때 마다 객체의 상태를 바꿔준다.
// main()에서 화면을 그려주는 동작과 비슷하다.
// 2초의 시간이 지날떄 마다 객체의 x, y위치가 조금씩 앞으로 이동한다.

// 앞으로 자주 쓰일 방법이므로 잘 기억해두도록