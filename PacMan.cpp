// PacMan.cpp : Определяет точку входа для приложения.
//

#include "stdafx.h"
//#include "PacMan.h"
#include "Level.h"
#include "Graphics.h"

Level level;
ifstream inFile;


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
char szClassName[] = "CG_WAPI_Template";

////////////////////////////////////////////////////////////////////////////////////////////////////
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;
	WNDCLASS wc;

	/*ifstream inFile;*/
	inFile.open("Maze.txt", std::ifstream::in);

	level.InitLevel(inFile);

	// Заполняем структуру класса окна
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = (LPCWSTR)szClassName;

	// Регистрируем класс окна
	if (!RegisterClass(&wc))
	{
		MessageBox(NULL, (LPCWSTR)"Не могу зарегистрировать класс окна!", (LPCWSTR)"Ошибка", MB_OK);
		return 0;
	}

	// Создаем основное окно приложения
	hWnd = CreateWindow(
		(LPCWSTR)szClassName, // Имя класса 
		L"Шаблон WinAPI приложения", // Текст заголовка
		WS_OVERLAPPEDWINDOW, // Стиль окна 
		50, 50, // Позиция левого верхнего угла 
		1000, 1000, // Ширина и высота окна 
		(HWND)NULL, // Указатель на родительское окно NULL 
		(HMENU)NULL, // Используется меню класса окна 
		(HINSTANCE)hInstance, // Указатель на текущее приложение
		NULL); // Передается в качестве lParam в событие WM_CREATE

	if (!hWnd)
	{
		MessageBox(NULL, (LPCWSTR)"Не удается создать главное окно!", (LPCWSTR)"Ошибка", MB_OK);
		return 0;
	}

	// Показываем наше окно
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	// Выполняем цикл обработки сообщений до закрытия приложения
	while (GetMessage(&lpMsg, NULL, 0, 0))
	{
		TranslateMessage(&lpMsg);
		DispatchMessage(&lpMsg);
	}
	return (lpMsg.wParam);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK WndProc(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	RECT Rect;
	HDC hdc, hCmpDC;
	HBITMAP hBmp;

	SetTimer(hWnd, 1, 100, NULL);
	switch (messg)
	{
	case WM_TIMER:
		InvalidateRect(hWnd, NULL, FALSE); //вызов события WM_PAINT
	case WM_KEYDOWN:
		switch (wParam) {
		case VK_LEFT:
			//level.GetPacman().Move(level.GetMaze(), WEST);
			level.GetPacman().ChangeDirection(WEST);
			break;
		case VK_RIGHT:
			//level.GetPacman().Move(level.GetMaze(), EAST);
			level.GetPacman().ChangeDirection(EAST);
			break;
		case VK_UP:
			//level.GetPacman().Move(level.GetMaze(), NORTH);
			level.GetPacman().ChangeDirection(NORTH);
			break;
		case VK_DOWN:
			//level.GetPacman().Move(level.GetMaze(), SOUTH);
			level.GetPacman().ChangeDirection(SOUTH);
			break;
		}
		InvalidateRect(hWnd, NULL, FALSE); //вызов события WM_PAINT
	case WM_PAINT:
		GetClientRect(hWnd, &Rect);
		hdc = BeginPaint(hWnd, &ps);

		// Создание теневого контекста для двойной буферизации
		hCmpDC = CreateCompatibleDC(hdc);
		hBmp = CreateCompatibleBitmap(hdc, Rect.right - Rect.left,
			Rect.bottom - Rect.top);
		SelectObject(hCmpDC, hBmp);

		// Закраска фоновым цветом
		LOGBRUSH br;
		br.lbStyle = BS_SOLID;
		br.lbColor = 0xEECCCC;
		HBRUSH brush;
		brush = CreateBrushIndirect(&br);
		FillRect(hCmpDC, &Rect, brush);
		DeleteObject(brush);


		level.FindPacMan();
		level.GetPacman().Move(level.GetMaze());
		level.EatScores(inFile);
		/*for (auto ghost : level.GetAliveGhosts()) {
			ghost.Move(level.GetMaze());
		}*/
		// Здесь рисуем на контексте hCmpDC
		Display(hCmpDC, level);

		// Копируем изображение из теневого контекста на экран
		SetStretchBltMode(hdc, COLORONCOLOR);
		BitBlt(hdc, 0, 0, Rect.right - Rect.left, Rect.bottom - Rect.top,
			hCmpDC, 0, 0, SRCCOPY);

		// Удаляем ненужные системные объекты
		DeleteDC(hCmpDC);
		DeleteObject(hBmp);
		hCmpDC = NULL;

		EndPaint(hWnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return (DefWindowProc(hWnd, messg, wParam, lParam));
	}
	return (0);
}
