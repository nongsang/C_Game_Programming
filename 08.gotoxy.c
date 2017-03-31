#include <stdio.h>
#include <conio.h>
#include <windows.h>

void gotoxy(int x, int y)
{
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

int main()
{
	gotoxy(5, 5);			// 새로운 커서의 위치 설정
	printf("C를 이용한 게임프로그래밍\n");
	_getch();
}

// 5 ~ 9행
// 콘솔 커서의 위치를 정하는 함수이다.
// 게임을 대상으로 한다면 플레이어 캐릭터의 위치를 설정하게끔 사용할 수 있겠다.
// 기본으로 설정해주는 함수가 존재하지 않으므로 직접 만들었다.
//
// 7행
// 값을 받아서 좌표값을 저장한다.
// x, y값을 받아서 저장한 구조체라고 생각하면 된다.
//
// 8행
// 콘솔에서 커서의 위치를 설정하는 실질적인 함수다.
// 프로그램을 실행했을 때 표준 출력을 담당하는 화면(현재 보여주고 있는 콘솔화면)의 핸들을 가져온다.
// 그리고 화면핸들에 설정한 위치로 커서의 위치를 새롭게 설정한다.

// 13행
// 특정 위치값을 인수에 넣고 커서 위치를 설정하는 함수를 호출한다.
// 콘솔 커서는 5, 5로 바뀌고 출력이 된다.

// 콘솔 커서의 위치를 바꾸는 모든 구조체 및 함수는 Windows.h에 정의되어 있다.