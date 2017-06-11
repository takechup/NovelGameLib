#include "DxLib.h"
#include "TextViewer.hpp"

//ノベルゲーム用ライブラリ

//テストテキスト
char test[20 * 29] = "あいうてｆｋｄｚｓｆｈｊｋｄｆｂｋｘｄｈｇｊヴｊｋｄｘｋｘｚｋじZSIうざいｙDFｇTIGK";
//テストメッセージ画像
int MassageBoxGraphics = LoadGraph("img/sea.jpg");


int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    
    //画面サイズ等の初期設定
    ChangeWindowMode (TRUE), DxLib_Init (), SetDrawScreen (DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定

    //エラーが起きたら即終了
    if (DxLib_Init () == -1)
    {
        return -1;
    }

    TextViewer tView;
    int cursor = 0;
    int LineCursor = 0;
    int a = LoadGraph ("img/messageBox.png");


    // while(裏画面を表画面に反映, メッセージ処理, 画面クリア, キーの更新)
    while (ScreenFlip () == 0 && ProcessMessage () == 0 && ClearDrawScreen () == 0)
    {

        DrawGraph (70, 280, a, TRUE);

        if (test[cursor] != '\0')
        {
            cursor++;
        }

        //画面の
        //ClearDrawScreen ();

        if (cursor % 29 == 0)
        {
            if (test[cursor] != '\0')
            {
                LineCursor++;
            }
        }

        for (int i = 0; i < 5; ++i)
        {
            if (i == LineCursor)
            {
                tView.writeSubstring (test, i * 29, cursor - 29 * i, 100, 310 + 20 * i, i);
                break;
            }
            else
            {
                tView.writeSubstring (test, i * 29, 29, 100, 310 + 20 * i, i);
              

            }
        }
        Sleep (100);
    }

    WaitKey ();


    DxLib_End ();



    return 0;
}