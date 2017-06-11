#pragma once
//#include ""
#include <vector>


class TextViewer
{

public:
    ///�R���X�g���N�^
    TextViewer ();
    ///�e�L�X�g���Z�b�g����
    void setText ();
    ///�����T�C�Y�̃Z�b�g
    void setTextSize(int aSize);
    ///�t�H���g�̃Z�b�g
    void setFont (const char* aFont);

    ///���{�ꂩ�A���t�@�x�b�g���m�F����
    bool isJapaneseCharacter (unsigned char code) const;

    ///�`��֐�

    void writeSubstring (char* message, int start, int len, int posX, int posY, int bufferLine) const;
    ///�X�s�[�h�̃Z�b�g
    void setTextSpeed (int aSpeed);


private:
    ///�Q�Ƃ��镶����ԍ��̏����������o�ϐ�
    int mSP;
    ///�Q�Ƃ��镶���񒆂̕����|�C���^
    int mCP;
    ///�`��ʒu���擾������W
    int mCursorX;
    int mCursorY;

    ///���̕�����
    static const int mNumWidth = 29;
    ///�c�̕�����
    static const int mNumHeight = 20;
    ///�����T�C�Y��ێ����郁���o�ϐ�
    static const int mFontSize = 18;
    ///������`�摬�x��ێ����郁���o�ϐ�
    int mTextSpeed;

    //char mString;

};