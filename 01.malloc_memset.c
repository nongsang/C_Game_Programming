#include <stdio.h>
#include <stdlib.h>
//#include <malloc.h>
#include <memory.h>
//#include <string.h>

int main()
{
	char * ch = (char*)malloc(sizeof(char) * 2);	// 동적할당을 배열형태로

	memset(ch, '*', sizeof(char) * 2);		// num이 가리키는 객체를 char의 크기의 2배만큼 *로 설정한다.

	printf("%c %c \n", ch[0], ch[1]);

	free(ch);
}

// C를 이용한 게임 프로그래밍을 한다.
// 내용은 'C를 이용한 게임프로그래밍'을 참고한다.

// 9행
// C에서 동적할당하는 방법
// char의 배열형태로 동적할당한다.
// 라이브러리는 stdlib.h, malloc.h에 정의되어있다.
// 둘 중 어느걸 써도 상관없다.

// 11행
// 배열형태로 동적할당된 객체에 값을 초기화하는 함수이다.
// 라이브러리는 memory.h, string.h에 정의되어있다.
// 둘 중 어느걸 써도 상관없다.