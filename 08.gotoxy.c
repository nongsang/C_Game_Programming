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
//
// 7행
// 값을 받아서 좌표값을 저장한다.
// x, y값을 받아서 저장한 구조체라고 생각하면 된다.
//
// 8행
// 콘솔에서 커서의 위치를 설정하는 실질적인 함수다.
// 특정 커서(여기서는 기본 커서)의 핸들을 가져와서 CursorPosition의 위치로 핸들을 새롭게 설정한다.

// 13행
// 특정 위치값을 인수에 넣고 커서 위치를 설정하는 함수를 호출한다.
// 콘솔 커서는 5, 5로 바뀌고 출력이 된다.