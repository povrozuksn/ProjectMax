#include "TXLib.h"

struct Button
{
    int x;
    const char* name;

    void DrawButton()
    {
        //����
        txSetColor(TX_TRANSPARENT);             //����
        txSetFillColor(TX_BLM);                 //����(�������)
        txRectangle (x+5, 25, x+185, 75);       //�������������

        //������
        txSetColor(TX_BLM, 3);                  //����
        txSetFillColor(TX_GRAY);                //����(�������)
        txRectangle (x, 20, x+180, 70);         //�������������
        txSetColor(TX_BLM);                     //���� ������
        txSelectFont("Times New Roman", 35);    //�����+������
        txDrawText (x, 20, x+180, 70, name);    //���  �����
    }

};

bool ClickButton(int x)
{
return( txMouseButtons() == 1 &&
       txMouseX() >= x && txMouseX () <= x+180 &&
       txMouseY() >= 35 && txMouseY () <= 75);
}

struct Picture
{
    int x;
    int y;
    int w_scr;
    int h_scr;
    HDC pic;
    int w;
    int h;
    bool visible;

    void DrawPictire()
    {
        Win32::TransparentBlt (txDC(), x, y, w_scr, h_scr, pic, 0, 0, w, h, TX_WHITE);
    }

};




bool ClickPicture(int x, int y)
{
return( txMouseButtons() == 1 &&
       txMouseX() >= x && txMouseX () <= x+80 &&
       txMouseY() >= y && txMouseY () <= y+200);
}


int main()
{
    txCreateWindow (1200, 800);

    Button btn1 = {40, "��������"};
    Button btn2 = {250, "������"};

    Picture menu_pic1 = {50, 100, 80, 200, txLoadImage ("Pictures/Boy.bmp"), 240, 600, false};
    Picture menu_pic2 = {50, 350, 80, 200, txLoadImage ("Pictures/Girl.bmp"), 240, 600, false};


    Picture centr_pic1 = {400, 100, 240, 600, txLoadImage ("Pictures/Boy.bmp"), 240, 600, false};
    Picture centr_pic2 = {700, 100, 240, 600, txLoadImage ("Pictures/Girl.bmp"), 240, 600, false};


    while(!GetAsyncKeyState (VK_ESCAPE))
    {
        txBegin();
        txSetColor(TX_GREEN);
        txSetFillColor(TX_GREEN);
        txClear();

        //������� ��������� ��������
        //��������� ������
        btn1.DrawButton();
        btn2.DrawButton();
        //��������� �������� ����
        if(menu_pic1.visible)
        {
            menu_pic1.DrawPictire();
        }

         if(menu_pic2.visible)
        {
            menu_pic2.DrawPictire();
        }
        //��������� �������� � ������
        if(centr_pic1.visible)
        {
            centr_pic1.DrawPictire();
        }

         if(centr_pic2.visible)
        {
            centr_pic2.DrawPictire();
        }


        //������� �������������� ��������
        //���� �� ������1
        if(ClickButton(40))
        {
            menu_pic1.visible = true;
            menu_pic2.visible = true;
        }
        //���� �� 1 �������� ����
        if(ClickPicture(50, 100))
        {
            centr_pic1.visible = true;
        }
        //���� �� 2 �������� ����
        if(ClickPicture(50, 350))
        {
            centr_pic2.visible = true;
        }


        //������2
        if(ClickButton(250))
        {

        }



        txEnd();
        txSleep(50);
    }

    txDeleteDC (menu_pic1.pic);
    txDeleteDC (menu_pic1.pic);

txDisableAutoPause();
txTextCursor (false);
return 0;
}
