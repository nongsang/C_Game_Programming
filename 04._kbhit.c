#include <stdio.h>
#include <conio.h>

int main(void)
{
	int ch;

	while (1)
	{
		if (_kbhit())		// Ű���� �Է�
		{
			ch = _getch();
			if (ch == 'q')
				break;
			printf("%c", ch);
		}
	}
}

// 10��
// _kbhit()�� Ű���� �Է¿��θ� Ȯ���Ѵ�.
// �Է��� ������ 1, ������ 0�� ��ȯ.
// Ű���� �Է��� �ִٸ� if�� ������ �ϰ�, ���ٸ� if���� �����ϹǷ� �������� �ڿ��� ���� ���� �� �ִ�.
// _getch()�� �����Ͽ� ����ϸ� ����.
// conio.h�� ���ǵǾ��ִ�.