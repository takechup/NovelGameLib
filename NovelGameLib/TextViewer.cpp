#include "TextViewer.hpp"
#include "DxLib.h"

char mStringBuf[20][29];

char mString[][256] =
{
    "�@�������������������������������������������������������������������������������������������������������������������������������������Q�[���v���O�������K�����邽�߂̈�Ԃ̋ߓ��͂Ƃɂ�����R�v���O������g��",
    "���Ƃł���BB" ,
    "@�@�v���O�����̎Q�l���ɂ̓Q�[���̃v���O�����̕��@�Ȃ�ĉ���������Ă��Ȃ��AB",
    "�ϐ��AB�z��AB�֐��AB���[�v�AB��������cB����炷�ׂĂ̐����̓Q�[���ŉ��Ɏg����",
    "�Ȃ�Ăǂ��ɂ������p�͎g���Ȃ���肪����킯�˂��Ă��Ȃ��AB���������Z���^���ނɂ����Ⴊ������x�ł���BB" ,
    "C�@�v���O�����͏K����芵���Ȃ̂Ńv���O������g�ނɓ������ď����ł��m����",
    "���Ό�͂�������͌@�艺���A�L���Ă����Ηǂ��킯�ŁAB�v���O�����̎Q�l����",
    "�ǂ�ł��ď����ł������o����悤�ȋC�������炻���łƂɂ����v���O����",
    "��ł��Ă݂邱�Ƃ��厖�ł���BE",
};
//-------------------------------------------------------------------------------
//�R���X�g���N�^
TextViewer::TextViewer ()
{
    mTextSpeed = 1000;
}

//-------------------------------------------------------------------------------
//�e�L�X�g���Z�b�g����
void TextViewer::setText ()
{

}


//�����T�C�Y�̃Z�b�g
/*
void TextViewer::setTextSize (int aSize)
{
mFontSize = aSize;
}*/

//�t�H���g�̃Z�b�g
//void setFont()


//-------------------------------------------------------------------------------
//�����񂪓��{�ꂩ����
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
    //������
    int maxLen = strlen (message);

    //������̔���
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
    // s t a r t �� �� �u �� �\ �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��
    if (start >= maxLen)
    {
        return;

    }

    //�w�肵���ʒu���� l e n �� �� �� �\ �� �� ��
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
//�`�摬�x�̃Z�b�g
void TextViewer::setTextSpeed (int aSpeed)
{
    mTextSpeed = aSpeed;
}
