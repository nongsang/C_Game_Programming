#include <stdio.h>
#include <conio.h>
#include <time.h>
#include "Screen.h"

void Init()
{

}

void Update()
{

}

void Render()
{
	ScreenClear();		// ȭ�� �����
	// ��� �ڵ�

	ScreenFlipping();	// ȭ�� ��ȯ
}

void Release()
{

}

int main()
{
	int nKey;
	clock_t CurTime, OldTime;
	Init();						// �ʱ�ȭ
	ScreenInit();				// ȭ�� �ʱ�ȭ
	OldTime = clock();
	while (1)
	{
		if (_kbhit())			// Ű���� �Է��� ������
		{
			nKey = _getch();	// �Է��� ���� �����ϰ�
			if ('q' == nKey)	// q�� ���� ����
				break;
			switch (nKey)		// �װ� �ƴ϶�� switch�� �ൿ ����
			{
			case 'j':
				break;
			case 'l':
				break;
			}
		}

		Update();		// ������Ʈ
		Render();		// ȭ�鿡 �׷��ֱ�
		while (1)
		{
			CurTime = clock();
			if ((double)(CurTime - OldTime) > 16.67)
			{
				OldTime = CurTime;
				break;
			}
		}
	}
	Release();					// �޸� ����
	ScreenRelease();			// ȭ�� ����
}

// �ڵ带 �ۼ��ϱ� ���ؼ� �����Ǵ� ���α׷��� Ʋ�� �����ӿ�ũ�� �����.

// 34��
// ȭ���� �ʱ�ȭ ���ش�.

// 16 ~ 22��
// �׸��� �Լ��� �Ҹ��� ȭ���� ����� ȭ�鿡 ����� ȭ���� ����Ī���ش�.

// 65��
// ������ ����Ǹ� ������ ȭ���� ���ش�.

// ȭ�鿡 ���� �Լ����� Screen.h�� ������ �Ǿ��ְ�, Screen.c�� ���ǰ� �Ǿ��ִ�.