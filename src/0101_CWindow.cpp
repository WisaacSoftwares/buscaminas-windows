/*
Ventana Base

25/04/2024
*/

#include <windows.h>
#include <cwchar>
#include "0101_CWindow.h"
#include "0101_Recursos.h"

// **********************************
// DEFINICION DE LA CLASE CWindow
// **********************************

/* Definir la variable global */
CWindow *CWindow::Ventana;

/* Destructor de CWindow */
CWindow::~CWindow()
{
    delete (Ventana);
}

/* Funcion para la creación de la ventana de windows */
int CWindow::Create(
    HINSTANCE hInstance,
    int iCmdShow)
{

    // Regresa el apuntador si ya existe la ventana
    if (Ventana != NULL)
        return FALSE;

    // Registrar ventana
    static wchar_t nombre[] = L"UG-POO_Buscaminas";
    WNDCLASS wndclass;

    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = WndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;
    wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1)); // asociar el icono con la aplicacion
    // wndclass.hCursor = LoadCursor (NULL, IDC_WAIT) ;                     //cambiar cursor (Cargando)
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);              // cambiar cursor
    wndclass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH); // cambiar el fondo
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = nombre;

    if (!RegisterClass(&wndclass))
        return FALSE; // si la ventana no está registrada-> me salgo

    // Crear instancia del objeto
    Ventana = new CWindow;

    // Crear instancia del objeto
    HWND hWnd = CreateWindow(nombre,              // window class name
                             TEXT("Buscaminas"),  // window caption
                             WS_OVERLAPPEDWINDOW, // window style
                             CW_USEDEFAULT,       // initial x position
                             CW_USEDEFAULT,       // initial y position
                             CW_USEDEFAULT,       // initial x size
                             CW_USEDEFAULT,       // initial y size
                             NULL,                // parent window handle
                             NULL,                // window menu handle
                             hInstance,           // program instance handle
                             NULL);               // creation parameters

    // Muestra la ventana
    Ventana->hWnd = hWnd;
    ShowWindow(hWnd, iCmdShow);
    UpdateWindow(hWnd);

    // Distribución de mensajes
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Destruye la instancia de ventana
    delete (Ventana);
    return TRUE;
}

/* Esta funcion se llama cade vez que windows redibuja la ventana */
LRESULT CWindow::OnPaint()
{

    // Crear un contexto de dibujo
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);

    // Obtiene las dimensiones del area cliente (no menu, no bordes)
    RECT rect;
    GetClientRect(hWnd, &rect);

    // Dibuja el texto centrado en la ventana
    DrawText(hdc, TEXT("Hello Word!"), -1, &rect,
             DT_SINGLELINE | DT_CENTER | DT_VCENTER);

    // Libera el contexto de dibujo
    EndPaint(hWnd, &ps);
    return 0;
}

/* Procedimientos de la ventana CALLBACK */
LRESULT CALLBACK CWindow::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {

    case WM_CREATE:
        return 0;

    case WM_PAINT:
        return Ventana->OnPaint();

    case WM_DESTROY:
        PostQuitMessage (0) ;
        return 0;
    }

    /*  DefWindowProc se encarga de recibir y procesar
        los mensajes que no tengamos definidos en el "switch" y que son
        comunes en ventanas de windows */
    return DefWindowProc(hwnd, message, wParam, lParam);
}
