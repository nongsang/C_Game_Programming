#include <stdio.h>
#include <conio.h>

int main(void)
{
	int ch;

	while (1)
	{
		if (_kbhit())		// 키보드 입력
		{
			ch = _getch();
			if (ch == 'q')
				break;
			printf("%c", ch);
		}
	}
}

// 10행
// _kbhit()은 키보드 입력여부를 확인한다.
// 입력이 있으면 1, 없으면 0을 반환.
// 키보드 입력이 있다면 if문 실행을 하고, 없다면 if문을 무시하므로 쓸데없는 자원의 낭비를 막을 수 있다.
// _getch()와 조합하여 사용하면 좋다.
// conio.h에 정의되어있다.