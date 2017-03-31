#pragma once

void ScreenInit();		// ȭ�� �ʱ�ȭ
void ScreenFlipping();	// ȭ�� ��ȯ
void ScreenClear();		// ȭ�� �����
void ScreenRelease();	// ȭ�� ����
void ScreenPrint(int x, int y, char* string);	// ���ȭ�� x, y��ġ�� ���ڿ� ���
void SetColor(unsigned short color);		// �ؽ�Ʈ�� ���� ����

// 1��
// #�� ������ ��ó���⿡�� ó���ϴ� ���ɾ��̴�.
// pragme once�� �ѹ��� �о���̱� ���� ���ɾ��̴�.
//
// #ifndef __SCREEN_H__
// #define __SCREEN_H__
// ...
// #endif
// �̷��� �������־�� �� ���� #pragma once �ϳ��� ó�����ش�.
// #ifndef�� ����� �߰��� �� ���� �о���������� #pragma once�׷��� �����Ƿ� #pragma once�� �ξ� �̵��̴�.
// ����� �ߺ������� �����ϱ� ���ؼ� ���ִ� ����ε� �ֽ� �����Ϸ������� #pragma once�� �����Ѵ�.
// ������ ������ �����Ϸ��� #pragma once�� �������� �����Ƿ� #ifndef�� ��������� �� ���̴�.

// 3��
// ������ۿ� �ĸ���۸� �����س��� �Լ��̴�.
// ȭ���� ǥ���Կ� �־ �������۸��� �������ø��� ����� �����ϴµ�,
// �������۸��� �ĸ���ۿ� �׸��� �׷��ְ� ������۷� �׸��� �����Ͽ� ȭ�鿡 �����ִ� ����̴�.
// ������ۿ��� ȭ�鿡 �����ִ� ���� �ĸ���۴� ���� ����� �׸��� �ְ�, ȭ���� ������ ���� �ൿ�� �ݺ��Ѵ�.
// �������ø����� ������ۿ� �ĸ������ �ּҰ��� �̿��Ͽ� ���� �����ư��鼭 �����ִ� ����̴�.
// ������ �������ø����� �� ���� ����ϹǷ� �����ϱ�

// 4��
// �������ø���ó�� Ȱ��ȭ��� ��Ȱ��ȭ���� ��ȯ�ϴ� �Լ��̴�.

// 5��
// �ϳ��� ȭ����۰� Ȱ��ȭ�Ǿ� ��µǰ� �ִ� ���ȿ� ���� ����� ���� ȭ����۴� ����� �Լ��̴�.

// 6��
// ������ �ΰ��� ȭ���� �����ϴ� �Լ���.

// 7��
// ����ϰ� �ִ� ȭ�� ������ x, y��ġ�� ���ڿ��� ������ش�.

// 8��
// �Լ� ȣ���� �Ǹ� ������ �ؽ�Ʈ�� ������ ������ ��µȴ�.