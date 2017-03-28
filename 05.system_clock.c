#include <stdio.h>
#include <stdlib.h>
//#include <process.h>
#include <time.h>

int main()
{
	while (1)
	{
		system("cls");			// 콘솔 명령어
		printf("초 : %d", clock() / 1000);	// 시간 출력
	}
	return 0;
}

// 10행
// 콘솔 명령어를 사용하는 system() 함수이다.
// "cls"는 화면을 지워주는 명령어이며, "dir"는 현재 프로그램이 실행되는 파일의 위치를 알려준다.
// stdlib.h, process.h에 정의되어있다.
// 보통 stdlib.h를 사용한다.

// 11행
// 시간을 계산하는 clock() 함수이다.
// millisecond단위이므로 1000으로 나누면 초단위를 구할 수 있다.
// time_t, clock_t 형 변수 2개를 선언하여 프로그램이 실행된 시간을 구할 수 있다.
// time_t는 1970년 1월 1일 0시 0분 0초를 기준으로 시간을 계산하고, clock_t는 processor가 실행되는 tick을 기준으로 계산한다.