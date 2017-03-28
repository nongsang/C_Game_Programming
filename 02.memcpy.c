#include <stdio.h>
#include <string.h>
//#include <memory.h>

int main(void)
{
	char src[] = "1234";
	char dest[] = "###########";

	memcpy(dest, src, 4);	// 메모리 카피
	printf("%s\n", dest);
}

// 10행
// memcpy()는 메모리를 복사하여 붙이는 역할을 한다.
// src값을 4개만큼 dest '앞'에 붙인다.
// 결과는 1234#########
// memory.h, string.h에 정의되어있다.
// 이것과 비슷한 strcpy() string.h에 있다.
// 둘다 써야 한다면 string.h를 쓰자