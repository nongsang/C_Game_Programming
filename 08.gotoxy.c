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
	gotoxy(5, 5);			// ���ο� Ŀ���� ��ġ ����
	printf("C�� �̿��� �������α׷���\n");
	_getch();
}

// 5 ~ 9��
// �ܼ� Ŀ���� ��ġ�� ���ϴ� �Լ��̴�.
// ������ ������� �Ѵٸ� �÷��̾� ĳ������ ��ġ�� �����ϰԲ� ����� �� �ְڴ�.
//
// 7��
// ���� �޾Ƽ� ��ǥ���� �����Ѵ�.
// x, y���� �޾Ƽ� ������ ����ü��� �����ϸ� �ȴ�.
//
// 8��
// �ֿܼ��� Ŀ���� ��ġ�� �����ϴ� �������� �Լ���.
// Ư�� Ŀ��(���⼭�� �⺻ Ŀ��)�� �ڵ��� �����ͼ� CursorPosition�� ��ġ�� �ڵ��� ���Ӱ� �����Ѵ�.

// 13��
// Ư�� ��ġ���� �μ��� �ְ� Ŀ�� ��ġ�� �����ϴ� �Լ��� ȣ���Ѵ�.
// �ܼ� Ŀ���� 5, 5�� �ٲ�� ����� �ȴ�.