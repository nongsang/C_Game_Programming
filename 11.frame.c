﻿#include <stdio.h>
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

void Relese()
{

}

int main()
{
	clock_t OldTime, CurTime;	// 시간 개념을 넣는다.

	Init();			// 객체 초기화

	//OldTime = clock();		// 시간을 구한다.
	//while (1)
	//{
	//	Update();			// 업데이트 하고
	//	Render();			// 화면에 그려준다.
	//	while (1)
	//	{
	//		CurTime = clock();	// 업데이트 하고 화면에 그려주기까지의 시간을 구한다.
	//		if ((double)(CurTime - OldTime) > 16.7)		// 현재 시간에서 처음 시간을 빼서 1frame을 그리는 시간보다 늦어지면
	//			OldTime = CurTime;					// 처음 시간에 현재 시간을 저장한다.
	//		break;
	//	}
	//}

	while (1)
	{
		OldTime = clock();

		Update(); // 데이터 갱신
		Render(); // 화면 출력
		while (1) // 대기 상태 진입
		{
			CurTime = clock();
			if ((double)(CurTime - OldTime) > 16.67)
				break;
		}
	}

	Relese();				// 메모리 해제
}

// 기본 게임 구조에서 치명적인 문제는 화면이 너무 깜박인다는 것이다.
// 이 문제는 Render()에서 나오는 문제로, 화면에 그려주는 속도가 너무 빨라서 화면에 그려주고, 지워주는 과정이 눈에 보이는 것.
// 여기서 시간개념이 도입이 되면 해결된다.
// 업데이트를 하고 화면을 그려주는 것까지의 시간이 30frame이상이면 자연스러워 보인다.
// 1초에 30frame을 화면에 그린다면 0.033333..초 안에 화면을 그리면 된다.
// 나는 게임을 더 부드럽게 하기 위해서 60frame으로 하겠다.
// 그러면 0.01666666...초 안에 화면을 그리게끔 해주면 된다.

// 30행
// 객체를 초기화하고 Update를 하기 직전의 시간을 기억해 둔다.

// 35 ~ 41행
// Render를 하고 난 후의 시간을 저장한다.
// Render후 측정한 시간 CurTime에 Update전에 측정한 시간 OldTime을 뺀다.
// 두 변수는 long형이므로 정수형이다.
// 하지만 1초당 60frame을 화면에 그려주기 위해서는 1frame당 16.6666..밀리세컨드인 실수와 비교를 해줘야 한다.
// 실수의 비교를 할때는 ==를 사용하면 안된다.
// 컴퓨터는 실수를 정확하게 표현할 수 없기 때문에 오류가 생길 수 있다.
// 따라서 두 값을 빼고난 결과를 double형으로 형변환 후 실수 비교를 해줘야 하는 것.
// 만약 1프레임을 표현하는 시간, 즉, 16.666..밀리세컨드 이내라면 clock()으로 현재 시간을 계속 측정한다.
// 현재 시간을 측정하는 동안은 Render()상태가 유지되는 상태다.
// 한마디로 새롭게 화면을 갱신하지 않는다는 뜻.
// 그리고 2프레임째를 그리는 시간인 16.666...밀리세컨드를 넘긴 시간이라면 업데이트 전 시간인 OldTime을 16.666..밀리세컨드의 시간으로 설정한다.
// 그리고 다시 Update를 수행하는 방식이다.

// 44 ~ 56행
// 조금 더 쉽게, 시간을 새로운 시간으로 설정하는 쓸데없는 작업은 없애고 간결하게 바꿨다.
// while()문 안에서 Update()전에 시간을 측정한다.
// Render()까지 끝낸 시점의 시간을 측정하고 두 시간의 차가 16.666...밀리세컨드보다 큰지 계속 계산한다.
// 16.6666..밀리세컨드를 넘어갔다는 것은 다음 프레임으로 넘어간다는 뜻.
// 바로 while()을 빠져나가서 Update를 다시 수행한다.