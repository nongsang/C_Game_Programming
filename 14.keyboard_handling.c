#include <stdio.h>
#include <conio.h>
#include <time.h>

void Init()
{
}

void Update()
{
}

void Render()
{
}

void Release()
{
}

int main()
{
	int nKey;
	clock_t CurTime, OldTime;
	Init();						// �ʱ�ȭ
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
	return 0;
}

// Ű���� ó���� ���� �ڵ��̴�.

// 29 ~ 40��
// Ű���� �Է��� ������ ó���ϴ� �����̴�.
// Ű���� �Է��� ������ �ٷ� Update() �� Render()�� ȣ���ϴ� ����.
// �� ������ callback�̶�� �Ѵ�.
// �ʿ��� ��쿡�� ȣ���ϰ� �׷��� �ʴٸ� ���� ������ ��� �����ϴ� ��.