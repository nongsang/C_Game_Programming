#include <Windows.h>

static int g_nScreenIndex;		// ȭ���� ����Ű�� index����
static HANDLE g_hScreen[2];		// 2���� ȭ�鿡�� ����� �ڵ� ����

void ScreenInit()		// ȭ�� �ʱ�ȭ
{
	CONSOLE_CURSOR_INFO cci;	// �ܼ� Ŀ���� ������ ��� �ִ� ���� ����

	// ȭ�� ���� 2���� �����
	g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0,
		NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0,
		NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	cci.dwSize = 1;			// Ŀ���� ũ��� 1, Ŀ���� �Ⱥ��̰� �Ҳ��� �ǹ̴� ������
	cci.bVisible = FALSE;	// Ŀ���� �Ⱥ��̰��Ѵ�.
	SetConsoleCursorInfo(g_hScreen[0], &cci);	// ������ Ŀ���� ������ ����� ȭ�鿡 �����Ѵ�.
	SetConsoleCursorInfo(g_hScreen[1], &cci);	// ������ Ŀ���� ������ ����� ȭ�鿡 �����Ѵ�.
}

void ScreenFlipping()	// ȭ�� ��ȯ
{
	SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);	// �ܼ� ȭ�� Ȱ��ȭ
	g_nScreenIndex = !g_nScreenIndex;	// �ܼ� ȭ�� ��ȯ
}

void ScreenClear()		// ȭ�� �����
{
	COORD Coor = { 0, 0 };
	DWORD dw;
	FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], ' ', 80 * 25, Coor, &dw);
}

void ScreenRelease()	// ȭ�� ����
{
	CloseHandle(g_hScreen[0]);		// ȭ�� ����
	CloseHandle(g_hScreen[1]);		// ȭ�� ����
}

void ScreenPrint(int x, int y, char* string)	// ���ȭ�� x, y��ġ�� ���ڿ� ���
{
	DWORD dw;
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
	WriteFile(g_hScreen[g_nScreenIndex], string, strlen(string), &dw, NULL);
}

void SetColor(unsigned short color)		// �ؽ�Ʈ�� ���� ����
{
	SetConsoleTextAttribute(g_hScreen[g_nScreenIndex], color);
}

// 3��
// ������ ȭ���� ����Ű�� index�� �����Ѵ�.
// index�� ����Ͽ� ȭ�鿡 ������ ȭ���� ������� ����Ű�� �Ѵ�.

// 4��
// �������, �ĸ������ ������ ���� �ڵ��� 2�� �����Ѵ�.
// �ڵ��� ������������� �����ϸ� �ȴ�.

// 8��
// ȭ�鿡 ��Ÿ���� Ŀ���� ������ ����ִ� ������ ����.

// 11 ~ 14��
// �� �ڵ��� �ܼ� �����̶�� ������ ��� �ִ�.
// �ܼ�ȭ�� ���� ����� GENERIC_READ, �� �Ϲ����� �б� ���
// �ܼ�ȭ�鿡 ����� ���ۿ� �����ϴ� ����� GENERIC_WRITE, �� �Ϲ����� ���� ���
// ���ȼӼ��� ��� ���ϹǷ� 0
// �ܼ�ȭ�� ������ �Ӽ��� �����ϰ� CONSOLE_TEXTMODE_BUFFER�� ����
// ��ٷ� ����� ������ ������ NULL

// 16��
// Ŀ���� ũ�⸦ �ٲ۴�.
// ������ �Ⱥ��̰� �ҰŶ� �ǹ̴� ����.

// 17��
// Ŀ���� �Ⱥ��̰� �Ѵ�.
// TRUE�� Ŀ���� ���̰� �Ѵ�.

// 18, 19��
// �� ȭ�鿡 ������ Ŀ�� ������ �����Ͽ� �����Ѵ�.

// 24��
// ������ �ܼ�ȭ���� ���� ǥ�õ� �ܼ�ȭ������ ����
// �Ѹ���� ������ ȭ���� Ȱ��ȭ�Ѵ�.

// 25��
// g_nScreenIndex�� ���������̹Ƿ� �ʱⰪ�� 0�̴�.
// 24�࿡�� Ȱ��ȭ�� �� ȭ���� 0���̹Ƿ�, ȭ����ȯ�� �̷���� 1���� ȭ���� �ҷ����� �ȴ�.
// �׸��� �ٽ� 24�࿡�� 1�� ȭ���� ȣ���� �ȴ�.

// 30��
// ȭ���� ��ǥ�� �����ϴ� ���� ����
// gotoxy()�Լ������� ���Ǿ���.

// 31��
// ȭ�鿡 ��µ� ���ڼ��� ����� ���� ����

// 32��
// ȭ���� ������ ���ڷ� ä��� �Լ��̴�.
// ���ڸ� ä������ ȭ���� �����ϰ�,
// ����(whitespace)�� ä���ִµ�,
// 80 * 25����ŭ,
// 0, 0�������� ä���ִ´�.
// �׸��� ȭ�鿡 ��µ� ���ڼ��� ����� ������ ���� �����͸� �����س��´�.

// 37, 38��
// �� ȭ����� �����Ѵ�.

// 44, 45��
// gotoxy()�Լ�ó�� ����� ������ ��ġ�� �����Ѵ�.

// 43, 46��
// ���� �Ǵ� �������ġ�� �����͸� ����Ѵ�.
// ó�� ������ ȭ�鿡,
// �Է¹��� ���ڿ���,
// ���ڿ��� ���̸�ŭ ����Ѵ�.
// ����� ���ڿ��� ���̴� ����صΰ�,
// �������� �����ϴϱ� NULL.

// 51��
// �ؽ�Ʈ�� ������ ������ �� �ִ�.
// 1 ~ 15�� ���� ��������� ������ �ٲ��.