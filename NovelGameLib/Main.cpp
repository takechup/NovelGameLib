#include "DxLib.h"
#include "TextViewer.hpp"

//�m�x���Q�[���p���C�u����

//�e�X�g�e�L�X�g
char test[20 * 29] = "�������Ă�������������������������������������������������������ZSI��������DF��TIGK";
//�e�X�g���b�Z�[�W�摜
int MassageBoxGraphics = LoadGraph("img/sea.jpg");


int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    
    //��ʃT�C�Y���̏����ݒ�
    ChangeWindowMode (TRUE), DxLib_Init (), SetDrawScreen (DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

    //�G���[���N�����瑦�I��
    if (DxLib_Init () == -1)
    {
        return -1;
    }

    TextViewer tView;
    int cursor = 0;
    int LineCursor = 0;
    int a = LoadGraph ("img/messageBox.png");


    // while(����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A, �L�[�̍X�V)
    while (ScreenFlip () == 0 && ProcessMessage () == 0 && ClearDrawScreen () == 0)
    {

        DrawGraph (70, 280, a, TRUE);

        if (test[cursor] != '\0')
        {
            cursor++;
        }

        //��ʂ�
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