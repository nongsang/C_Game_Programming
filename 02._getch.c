#include <stdio.h>
#include <conio.h>

int main()
{
	int ch;

	while (1)
	{
		ch = _getche();		// 문자 입력
		if (ch == 'q')
			break;
		printf("%c", ch);	// 문자 출력
	}
	
	return 0;
}

// 10행
// _getch()는 문자를 입력받되 화면에 입력값을 출력하지 않는다.
// 그러므로 printf()를 사용하여 화면에 출력해줘야 한다.
// getch()가 있지만 비표준이므로 _getch()를 사용하자.
// _getche()는 화면에 보여주지만 출력화면을 덮어서 보여준다.
// getchar()는 문자를 입력받는 표준함수이다.
// getchar()를 제외한 함수는 conio.h에 정의되어 있다.
