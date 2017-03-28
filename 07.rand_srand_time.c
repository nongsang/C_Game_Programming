#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	int i;

	srand((unsigned)time(NULL));

	for (i = 0; i < 5; i++)
	{
		printf("%d \n", rand());
	}
}

// 9행
// srand()는 rand()함수의 seed값을 바꿔주는 함수다.
// rand()함수는 seed가 동일하므로 프로그램이 실생될 때 마다 똑같은 패턴의 랜덤값을 출력한다.
// 따라서 srand()를 사용하여 매번 seed값을 바꿔줘야 한다.
// srand()를 사용해도 상수값을 집어넣으면 똑같은 패턴의 랜덤값이 나온다.
// 그러므로 (unsigned)time(NULL)를 인자로 넘겨줘야 매번 다른 seed값을 넘겨줄 수 있다.
//
// time()는 1970년 1월 1일 0시 0분 0초에서 부터 몇초가 흘렀는지 알려준다.
// 따라서 9행은 매 초마다 다른 seed값을 설정해 주고 있는 것.

// 13행
// rand()은 랜덤값을 출력하는 함수다.
// 0 ~ RAND_MAX(32767) 사이의 랜덤값을 출력해준다.
// srand()는 seed를 바꿔주는 함수기 때문에 반환형이 void이므로 값을 출력할 수 없다.

// 두 랜덤함수 모두 stdlib.h에 정의되어 있다.
// time()은 time.h에 정의되어있다.