#include "TextViewer.hpp"
#include "DxLib.h"

char mStringBuf[20][29];

char mString[][256] =
{
    "　ああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああああゲームプログラムを習得するための一番の近道はとにかく沢山プログラムを組む",
    "ことである。B" ,
    "@　プログラムの参考書にはゲームのプログラムの方法なんて何も書かれていない、B",
    "変数、B配列、B関数、Bループ、B条件分岐…Bこれらすべての説明はゲームで何に使うか",
    "なんてどこにも書半角は使えない問題があるわけねいていない、Bせいぜい住所録を題材にした例がある程度である。B" ,
    "C　プログラムは習うより慣れろなのでプログラムを組むに当たって少しでも知識が",
    "つけば後はそこからは掘り下げ、広げていけば良いわけで、Bプログラムの参考書を",
    "読んでいて少しでも何か出来るような気がしたらそこでとにかくプログラム",
    "を打ってみることが大事である。E",
};
//-------------------------------------------------------------------------------
//コンストラクタ
TextViewer::TextViewer ()
{
    mTextSpeed = 1000;
}

//-------------------------------------------------------------------------------
//テキストをセットする
void TextViewer::setText ()
{

}


//文字サイズのセット
/*
void TextViewer::setTextSize (int aSize)
{
mFontSize = aSize;
}*/

//フォントのセット
//void setFont()


//-------------------------------------------------------------------------------
//文字列が日本語か判定
bool TextViewer::isJapaneseCharacter (unsigned char code) const
{
    if ((code >= 0x81 && code <= 0x9F) || (code >= 0xE0 && code <= 0xFC))
    {
        return true;
    }

    return false;
}


//-------------------------------------------------------------------------------
//
void TextViewer::writeSubstring (char* message, int start, int len, int posX, int posY, int bufferLine) const
{
    int i;
    //文字数
    int maxLen = strlen (message);

    //文字列の判定
    for (i = 0; i < start && message[i] != '\0';)
    {
        if (isJapaneseCharacter (message[i]))
        {
            i += 2;
            start++;
        }
        else
        {
            i++;
        }
    }
    // s t a r t の 位 置 が 表 示 し た い 最 大 文 字 数 よ り 大 き い 場 合
    if (start >= maxLen)
    {
        return;

    }

    //指定した位置から l e n 文 字 分 表 示 す る
    for (i = 0; i < len && message[start + i] != '\0'; )
    {
      
        if (isJapaneseCharacter (message[start + i]))
        {
            //printf ("%c%c", message[start + i], message[start + i + 1]);
            mStringBuf[bufferLine][i] = message[start + i];
            mStringBuf[bufferLine][i + 1] = message[start + i + 1];
            ++len;
            i += 2;
        }
        else
        {
            mStringBuf[bufferLine][i] = message[start + i];
            //printf ("%c", message[start + i]);
            ++i;
        }

    }
    //printf ("\n");
    mStringBuf[bufferLine][i] = '\0';

    DrawString (posX, posY, mStringBuf[bufferLine], GetColor (255, 255, 255));
}


//-------------------------------------------------------------------------------
//描画速度のセット
void TextViewer::setTextSpeed (int aSpeed)
{
    mTextSpeed = aSpeed;
}
