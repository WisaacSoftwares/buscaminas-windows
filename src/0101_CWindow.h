/*
Ventana Base

25/04/2024
*/

#include <windows.h>

class CWindow{
    private:
        static CWindow* Ventana;
        HWND hWnd;

        static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

        LRESULT OnPaint();

    protected:
        CWindow(){ };

    public:
        ~CWindow();
        static int Create(
            HINSTANCE hInstance,
            int iCmdShow
        );
};