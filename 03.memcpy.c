#include <stdio.h>
#include <string.h>
//#include <memory.h>

int main(void)
{
	char src[] = "1234";
	char dest[] = "###########";

	memcpy(dest, src, 4);	// �޸� ī��
	printf("%s\n", dest);
	
}

// 10��
// memcpy()�� �޸𸮸� �����Ͽ� ���̴� ������ �Ѵ�.
// src���� 4����ŭ dest '��'�� ���δ�.
// ����� 1234#########
// memory.h, string.h�� ���ǵǾ��ִ�.
// �̰Ͱ� ����� strcpy()�� string.h�� �ִ�.
// �Ѵ� ��� �Ѵٸ� string.h�� ����