#pragma once
//#include ""
#include <vector>


class TextViewer
{

public:
    ///コンストラクタ
    TextViewer ();
    ///テキストをセットする
    void setText ();
    ///文字サイズのセット
    void setTextSize(int aSize);
    ///フォントのセット
    void setFont (const char* aFont);

    ///日本語かアルファベットか確認する
    bool isJapaneseCharacter (unsigned char code) const;

    ///描画関数

    void writeSubstring (char* message, int start, int len, int posX, int posY, int bufferLine) const;
    ///スピードのセット
    void setTextSpeed (int aSpeed);


private:
    ///参照する文字列番号の情報を持つメンバ変数
    int mSP;
    ///参照する文字列中の文字ポインタ
    int mCP;
    ///描画位置を取得する座標
    int mCursorX;
    int mCursorY;

    ///横の文字数
    static const int mNumWidth = 29;
    ///縦の文字列
    static const int mNumHeight = 20;
    ///文字サイズを保持するメンバ変数
    static const int mFontSize = 18;
    ///文字列描画速度を保持するメンバ変数
    int mTextSpeed;

    //char mString;

};