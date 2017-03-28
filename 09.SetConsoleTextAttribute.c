#include <stdio.h>
#include <windows.h>

int main()
{
	int i;
	printf("원하는 글짜 색깔(1. 검정 2. 회색 3. 밝은 회색 4. 흰색) : ");
	scanf("%d", &i);

	switch (i)
	{
	case 1:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		printf("C를 이용한 게임프로그래밍\n");
		break;
	case 2:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
		printf("C를 이용한 게임프로그래밍\n");
		break;
	case 3:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		printf("C를 이용한 게임프로그래밍\n");
		break;
	case 4:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		printf("C를 이용한 게임프로그래밍\n");
		break;
	default:
		break;
	}
}

// 13, 17, 21, 25행
// 글자색을 바꿔주는 함수다.
// 커서의 핸들을 받아서 텍스트의 색깔을 원하는 색으로 바꿔준다.
// foreground에 빛의 3원색 기법을 사용하여 색깔을 바꿔준다.
//
// 13행
// 0을 넣어주면 가장 기본색, 검정으로 설정한다.
//
// 17행
// FOREGROUND_INTENSITY를 넣어주면 명도가 강할 때의 흰색을 출력해준다.
// 결과적으로 어두운 회색을 나타낸다.
//
// 21행
// FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN를 해주면 채도만으로 섞인 흰색을 출력해준다.
// 결과적으로 밝은 회색을 나타낸다.
// 가장 기본 텍스트 색
//
// 25행
// FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY를 해주면 명도, 채도 전부 섞인 흰색을 출력한다.
// 결과적으로 제일 밝은 흰색을 출력한다.