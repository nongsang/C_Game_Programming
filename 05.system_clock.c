#include <stdio.h>
#include <stdlib.h>
//#include <process.h>
#include <time.h>

int main()
{
	while (1)
	{
		system("cls");			// �ܼ� ��ɾ�
		printf("�� : %d", clock() / 1000);	// �ð� ���
	}
	return 0;
}

// 10��
// �ܼ� ��ɾ ����ϴ� system() �Լ��̴�.
// "cls"�� ȭ���� �����ִ� ��ɾ��̸�, "dir"�� ���� ���α׷��� ����Ǵ� ������ ��ġ�� �˷��ش�.
// stdlib.h, process.h�� ���ǵǾ��ִ�.
// ���� stdlib.h�� ����Ѵ�.

// 11��
// �ð��� ����ϴ� clock() �Լ��̴�.
// millisecond�����̹Ƿ� 1000���� ������ �ʴ����� ���� �� �ִ�.
// time_t, clock_t �� ���� 2���� �����Ͽ� ���α׷��� ����� �ð��� ���� �� �ִ�.
// time_t�� 1970�� 1�� 1�� 0�� 0�� 0�ʸ� �������� �ð��� ����ϰ�, clock_t�� processor�� ����Ǵ� tick�� �������� ����Ѵ�.