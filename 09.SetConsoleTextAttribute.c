#include <stdio.h>
#include <windows.h>

int main()
{
	int i;
	printf("���ϴ� ��¥ ����(1. ���� 2. ȸ�� 3. ���� ȸ�� 4. ���) : ");
	scanf("%d", &i);

	switch (i)
	{
	case 1:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		printf("C�� �̿��� �������α׷���\n");
		break;
	case 2:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
		printf("C�� �̿��� �������α׷���\n");
		break;
	case 3:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		printf("C�� �̿��� �������α׷���\n");
		break;
	case 4:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		printf("C�� �̿��� �������α׷���\n");
		break;
	default:
		break;
	}
}

// 13, 17, 21, 25��
// ���ڻ��� �ٲ��ִ� �Լ���.
// Ŀ���� �ڵ��� �޾Ƽ� �ؽ�Ʈ�� ������ ���ϴ� ������ �ٲ��ش�.
// foreground�� ���� 3���� ����� ����Ͽ� ������ �ٲ��ش�.
//
// 13��
// 0�� �־��ָ� ���� �⺻��, �������� �����Ѵ�.
//
// 17��
// FOREGROUND_INTENSITY�� �־��ָ� ���� ���� ���� ����� ������ش�.
// ��������� ��ο� ȸ���� ��Ÿ����.
//
// 21��
// FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN�� ���ָ� ä�������� ���� ����� ������ش�.
// ��������� ���� ȸ���� ��Ÿ����.
// ���� �⺻ �ؽ�Ʈ ��
//
// 25��
// FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY�� ���ָ� ��, ä�� ���� ���� ����� ����Ѵ�.
// ��������� ���� ���� ����� ����Ѵ�.