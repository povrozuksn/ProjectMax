#include "TXLib.h"

struct Button
{
    int x;
    const char* name;

    void DrawButton()
    {
        //тень
        txSetColor(TX_TRANSPARENT);             //цвет
        txSetFillColor(TX_BLM);                 //цвет(заливки)
        txRectangle (x+5, 25, x+185, 75);       //прямоугольник

        //кнопка
        txSetColor(TX_BLM, 3);                  //цвет
        txSetFillColor(TX_GRAY);                //цвет(заливки)
        txRectangle (x, 20, x+180, 70);         //прямоугольник
        txSetColor(TX_BLM);                     //цвет текста
        txSelectFont("Times New Roman", 35);    //шрифт+размер
        txDrawText (x, 20, x+180, 70, name);    //сам  текст
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

    Button btn1 = {40, "Персонаж"};
    Button btn2 = {250, "Одежда"};

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

        //область рисование объектов
        //рисование кнопок
        btn1.DrawButton();
        btn2.DrawButton();
        //рисование картинок меню
        if(menu_pic1.visible)
        {
            menu_pic1.DrawPictire();
        }

         if(menu_pic2.visible)
        {
            menu_pic2.DrawPictire();
        }
        //рисование картинок в центре
        if(centr_pic1.visible)
        {
            centr_pic1.DrawPictire();
        }

         if(centr_pic2.visible)
        {
            centr_pic2.DrawPictire();
        }


        //область взаимодействия объектов
        //клик на кнопка1
        if(ClickButton(40))
        {
            menu_pic1.visible = true;
            menu_pic2.visible = true;
        }
        //клик на 1 картинку меню
        if(ClickPicture(50, 100))
        {
            centr_pic1.visible = true;
        }
        //клик на 2 картинку меню
        if(ClickPicture(50, 350))
        {
            centr_pic2.visible = true;
        }


        //кнопка2
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
