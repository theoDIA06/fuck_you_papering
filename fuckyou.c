#define _CRT_OBSOLETE_NO_WARNINGS
#include <Windows.h>
#include <stdbool.h>
#include <stdlib.h>

POINT ptMouse;
HINSTANCE g_inst;
MSG msg;
WNDCLASSA WndClass;
HANDLE fuckyou;
bool fuckyoutoogle = false;
LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
#define start 100
#define stop  200

DWORD WINAPI autoF5(void* lpVoid)
{
	while (true)
	{
		if (fuckyoutoogle)
		{
			keybd_event(0x46, 0, 0x22, 0);
			keybd_event(0x46, 0, 0x00, 0);
			keybd_event(0x55, 0, 0x22, 0);
			keybd_event(0x55, 0, 0x00, 0);
			keybd_event(0x43, 0, 0x22, 0);
			keybd_event(0x43, 0, 0x00, 0);
			keybd_event(0x4B, 0, 0x22, 0);
			keybd_event(0x4B, 0, 0x00, 0);
			keybd_event(VK_SPACE, 0, 0x22, 0);
			keybd_event(VK_SPACE, 0, 0x00, 0);
			keybd_event(0x59, 0, 0x22, 0);
			keybd_event(0x59, 0, 0x00, 0);
			keybd_event(0x4F, 0, 0x22, 0);
			keybd_event(0x4F, 0, 0x00, 0);
			keybd_event(0x55, 0, 0x22, 0);
			keybd_event(0x55, 0, 0x00, 0);
			keybd_event(VK_RETURN, 0, 0x22, 0);
			keybd_event(VK_RETURN, 0, 0x00, 0);
			Sleep(5);
		}
	}
}


int CALLBACK WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WndClass.lpszClassName = "win"; // CreateWindowA�� ù ��° ���ڿ��� ������ �̸��� ���ƾ���.
	WndClass.hInstance = hinstance;
	WndClass.lpfnWndProc = WndProc; // ���� ���α׷� �޽��� ť���� ������ ó���ϴ� ������ ���α׷��Ӱ� ���� �������� �ϴµ� �ٷ� �̷��� ����� �ϴ� �Լ��̴�.
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.lpszMenuName = NULL;




	RegisterClassA(&WndClass);


	// �����츦 ����
	CreateWindowA("win", "fuck_you!", WS_VISIBLE | WS_OVERLAPPEDWINDOW | WS_BORDER, 300, 200, 400, 100, NULL, NULL, hinstance, NULL);

	while (GetMessageA(&msg, 0, 0, 0)) // �޽����� �ݺ������� ������. �� �Լ��� ��� �޽���ť���� �޽����� ���� ���� �ִ�.
	{
		TranslateMessage(&msg);
		DispatchMessageA(&msg); // �޽����� �� ������ ������ �Ʒ� �޽��� ó�� �Լ��� ȣ��� �� �ֵ��� Dispatch ���ش�.
	}
	return 0;

}
LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) // �޽����� �� ������ �Լ�ó���� �� �ִ� �Լ�
{
	if (uMsg == WM_HOTKEY)
	{
		if (wParam == 1)
		{
			fuckyoutoogle = true;
		}
		else if (wParam == 0)
		{
			fuckyoutoogle = false;
		}
	}
	switch (uMsg)
	{
	case WM_CLOSE:
		CloseHandle(fuckyou);
		PostQuitMessage(0);
		break;
	case WM_CREATE:
		fuckyou = CreateThread(NULL, 0, autoF5, &fuckyoutoogle, 0, NULL);
		RegisterHotKey(hwnd, 1, 0, VK_F1);
		RegisterHotKey(hwnd, 0, 0, VK_F2);
		CreateWindowA("button", "F5���� Ŭ�� ����(F1)", WS_VISIBLE | WS_CHILD, 30, 15, 200, 30, hwnd, (HMENU)start, g_inst, NULL);
		CreateWindowA("button", "�ߴ�(F2)", WS_VISIBLE | WS_CHILD, 250, 15, 100, 30, hwnd, (HMENU)stop, g_inst, NULL);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case start:
			fuckyoutoogle = true;
			break;
		case stop:
			fuckyoutoogle = false;
			break;
		default:
			break;
		}
	default:
		break;
	}
	return DefWindowProcA(hwnd, uMsg, wParam, lParam); //�⺻���� �޽���(�ִ�, �ּ�ȭ ��)�� �����찡 ��� ���ִ� �Լ�
}