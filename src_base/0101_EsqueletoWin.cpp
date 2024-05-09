/*
Ventana Base

25/04/2024
*/

#include <windows.h>
#include <cwchar>
#include <stdio.h>
#include "0101_CWindow.h"
// #include "0101_CDIBitmap.h"

int WINAPI WinMain(
    HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PSTR szCmdLine, int iCmdShow ) {

    // 1) Crear Recurso
    // FILE* archivo = fopen( ".\\Parcial_03\\0501_Bitmap.bmp", "rb" ); // r: read, b: binary
    // if( archivo == NULL ){
    //     return 0;
    // }

    // 2) Usar Recurso
    // CDIBitmap bitmap;
    // bitmap.Cargar( archivo );

    // 3) Liberar Recurso
    // fclose( archivo );

    //Crear la ventana
    CWindow::Create( hInstance, iCmdShow );
    return 0; 
}