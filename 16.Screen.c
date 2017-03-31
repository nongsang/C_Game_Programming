#include <Windows.h>

static int g_nScreenIndex;		// 화면을 가리키는 index변수
static HANDLE g_hScreen[2];		// 2개의 화면에서 사용할 핸들 생성

void ScreenInit()		// 화면 초기화
{
	CONSOLE_CURSOR_INFO cci;	// 콘솔 커서의 정보를 담고 있는 변수 생성

	// 화면 버퍼 2개를 만든다
	g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0,
		NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0,
		NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	cci.dwSize = 1;			// 커서의 크기는 1, 커서는 안보이게 할꺼라 의미는 없지만
	cci.bVisible = FALSE;	// 커서를 안보이게한다.
	SetConsoleCursorInfo(g_hScreen[0], &cci);	// 저장한 커서의 정보를 출력할 화면에 저장한다.
	SetConsoleCursorInfo(g_hScreen[1], &cci);	// 저장한 커서의 정보를 출력할 화면에 저장한다.
}

void ScreenFlipping()	// 화면 전환
{
	SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);	// 콘솔 화면 활성화
	g_nScreenIndex = !g_nScreenIndex;	// 콘솔 화면 전환
}

void ScreenClear()		// 화면 지우기
{
	COORD Coor = { 0, 0 };
	DWORD dw;
	FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], ' ', 80 * 25, Coor, &dw);
}

void ScreenRelease()	// 화면 삭제
{
	CloseHandle(g_hScreen[0]);		// 화면 삭제
	CloseHandle(g_hScreen[1]);		// 화면 삭제
}

void ScreenPrint(int x, int y, char* string)	// 대기화면 x, y위치에 문자열 출력
{
	DWORD dw;
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
	WriteFile(g_hScreen[g_nScreenIndex], string, strlen(string), &dw, NULL);
}

void SetColor(unsigned short color)		// 텍스트의 색깔 설정
{
	SetConsoleTextAttribute(g_hScreen[g_nScreenIndex], color);
}

// 3행
// 생성한 화면을 가리키는 index를 생성한다.
// index를 사용하여 화면에 보여줄 화면이 어떤것인지 가리키게 한다.

// 4행
// 전면버퍼, 후면버퍼의 정보를 가질 핸들을 2개 생성한다.
// 핸들은 포인터정도라고 생각하면 된다.

// 8행
// 화면에 나타나는 커서의 정보를 담고있는 변수를 생성.

// 11 ~ 14행
// 각 핸들은 콘솔 생성이라는 정보를 담고 있다.
// 콘솔화면 접근 방식은 GENERIC_READ, 곧 일반적인 읽기 방식
// 콘솔화면에 사용할 버퍼에 접근하는 방식은 GENERIC_WRITE, 곧 일반적인 쓰기 방식
// 보안속성은 사용 안하므로 0
// 콘솔화면 버퍼의 속성은 유일하게 CONSOLE_TEXTMODE_BUFFER만 지원
// 곧바로 출력할 내용은 없으니 NULL

// 16행
// 커서의 크기를 바꾼다.
// 어차피 안보이게 할거라서 의미는 없다.

// 17행
// 커서를 안보이게 한다.
// TRUE는 커서를 보이게 한다.

// 18, 19행
// 각 화면에 설정한 커서 정보를 전달하여 설정한다.

// 24행
// 지정된 콘솔화면을 현재 표시된 콘솔화면으로 설정
// 한마디로 지정된 화면을 활성화한다.

// 25행
// g_nScreenIndex는 전역변수이므로 초기값은 0이다.
// 24행에서 활성화가 된 화면은 0번이므로, 화면전환이 이루어져 1번의 화면을 불러오게 된다.
// 그리고 다시 24행에서 1번 화면이 호출이 된다.

// 30행
// 화면의 좌표를 저장하는 변수 생성
// gotoxy()함수에서도 사용되었다.

// 31행
// 화면에 출력된 문자수를 기록할 변수 생성

// 32행
// 화면을 설정한 문자로 채우는 함수이다.
// 문자를 채워넣을 화면을 설정하고,
// 공백(whitespace)를 채워넣는데,
// 80 * 25개만큼,
// 0, 0에서부터 채워넣는다.
// 그리고 화면에 출력된 문자수를 기록할 변수에 대한 포인터를 설정해놓는다.

// 37, 38행
// 각 화면들을 삭제한다.

// 44, 45행
// gotoxy()함수처럼 출력을 시작할 위치를 설정한다.

// 43, 46행
// 파일 또는 입출력장치에 데이터를 기록한다.
// 처음 설정한 화면에,
// 입력받은 문자열을,
// 문자열의 길이만큼 출력한다.
// 출력한 문자열의 길이는 기록해두고,
// 오프셋은 사용안하니까 NULL.

// 51행
// 텍스트의 색깔을 설정할 수 있다.
// 1 ~ 15의 수를 집어넣으면 색깔이 바뀐다.