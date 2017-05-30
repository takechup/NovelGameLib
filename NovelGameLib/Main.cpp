#include "DxLib.h"

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //エラーが起きたら即終了
    if (DxLib_Init () == -1)
    {
        return -1;
    }

    DrawPixel (320, 240, GetColor (255, 255, 255));

    WaitKey ();

    DxLib_End ();

    return 0;

}