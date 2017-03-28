#include <stdio.h>
#include <conio.h>

int main()
{
	int ch;				// 자료형은 상관없다.

	while (1)
	{
		ch = _getch();		// 키보드 입력
		if (ch == 'q')
			break;
		printf("%c", ch);	// 입력값 출력
	}
}

// 6행
// 키보드 입력을 받을 변수 설정
// _getch()로 입력받을 것이다.
// 결과를 보면 알겠지만 자료형은 상관없다.

// 10행
// _getch()는 문자를 입력받되 화면에 입력값을 출력하지 않는다.
// 그러므로 printf()를 사용하여 화면에 출력해줘야 한다.
// getch()가 있지만 비표준이므로 _getch()를 사용하자.
// _getche()는 화면에 보여주지만 출력화면을 덮어서 보여준다.
// getchar()는 문자를 입력받는 표준함수이다.
// getchar()를 제외한 함수는 conio.h에 정의되어 있다.
// getchar()는 stdio.h에 정의되어있다.
