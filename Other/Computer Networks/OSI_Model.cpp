
#include <bits/stdc++.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    initwindow(1600, 900);
    setcolor(RED);
    settextstyle(10, 0, 20);
    outtextxy(300, 400, " OSI MODEL ");
    delay(900);
    cleardevice();
    settextstyle(8, 0, 4);
    setcolor(14);
    outtextxy(210, 60, " SENDER 1");
    setcolor(RED);
    rectangle(200, 100, 400, 50);
    setcolor(14);
    outtextxy(1110, 60, " SENDER 2");
    setcolor(RED);
    rectangle(1100, 100, 1300, 50);

    //sender 1 boxes
    setcolor(10);
    delay(1000);
    rectangle(150, 200, 450, 150);
    setcolor(1);
    settextstyle(8, 0, 4);
    outtextxy(160, 160, " APPLICATION");
    delay(100);
    setcolor(5);
    rectangle(500, 190, 600, 160);
    setcolor(3);
    settextstyle(8, 0, 2);
    outtextxy(510, 165, "H7");
    line(550, 200, 550, 240);
    line(540, 230, 550, 240);
    line(560, 230, 550, 240);

    // line(540,170,540,220);
    // line(510,200,530,230);
    //  line(550,200,530,230);
    setcolor(10);
    delay(100);
    rectangle(150, 300, 450, 250);
    setcolor(1);
    settextstyle(8, 0, 4);
    outtextxy(160, 260, " PRESENTATION");
    delay(100);
    setcolor(5);
    rectangle(500, 290, 600, 260);
    setcolor(3);
    settextstyle(8, 0, 2);
    outtextxy(510, 265, "H6");
    line(550, 300, 550, 340);
    line(540, 330, 550, 340);
    line(560, 330, 550, 340);
    setcolor(10);
    delay(100);
    rectangle(150, 400, 450, 350);
    setcolor(1);
    settextstyle(8, 0, 4);
    outtextxy(200, 360, " SESSION ");

    delay(100);
    setcolor(5);
    rectangle(500, 390, 600, 360);
    setcolor(3);
    settextstyle(8, 0, 2);
    outtextxy(510, 365, "H5");
    line(550, 400, 550, 440);
    line(540, 430, 550, 440);
    line(560, 430, 550, 440);

    setcolor(10);
    delay(100);
    rectangle(150, 500, 450, 450);
    setcolor(1);
    settextstyle(8, 0, 4);
    outtextxy(190, 460, " TRANSPORT ");

    delay(100);
    setcolor(5);
    rectangle(500, 490, 600, 460);
    setcolor(3);
    settextstyle(8, 0, 2);
    outtextxy(510, 465, "H4");
    line(550, 500, 550, 540);
    line(540, 530, 550, 540);
    line(560, 530, 550, 540);

    setcolor(10);
    delay(100);
    rectangle(150, 600, 450, 550);
    setcolor(1);
    settextstyle(8, 0, 4);
    outtextxy(200, 560, " NETWORK ");

    delay(100);
    setcolor(5);
    rectangle(500, 590, 600, 560);
    setcolor(3);
    settextstyle(8, 0, 2);
    outtextxy(510, 565, "H3");
    line(550, 600, 550, 640);
    line(540, 630, 550, 640);
    line(560, 630, 550, 640);

    setcolor(10);
    delay(100);
    rectangle(150, 700, 450, 650);
    setcolor(1);
    settextstyle(8, 0, 4);
    outtextxy(180, 660, " DATA LINK ");
    delay(100);
    setcolor(5);
    rectangle(500, 690, 600, 660);
    setcolor(3);
    settextstyle(8, 0, 2);
    outtextxy(510, 665, "H2 T2");
    line(550, 700, 550, 740);
    line(540, 730, 550, 740);
    line(560, 730, 550, 740);

    setcolor(10);
    delay(100);
    rectangle(150, 800, 450, 750);
    setcolor(1);
    settextstyle(8, 0, 4);
    outtextxy(200, 760, " PHYSICAL ");

    delay(100);
    setcolor(5);
    rectangle(500, 790, 600, 760);
    setcolor(3);
    settextstyle(8, 0, 2);
    outtextxy(510, 765, "H1  T2");

    delay(100);
    line(630, 810, 870, 810);
    line(860, 800, 870, 810);
    line(860, 820, 870, 810);

    // sender 2 boxes
    delay(100);
    setcolor(10);
    rectangle(1050, 800, 1350, 750);
    setcolor(1);
    settextstyle(8, 0, 4);
    outtextxy(1100, 760, " PHYSICAL ");

    setcolor(5);
    delay(100);
    rectangle(900, 790, 1000, 760);
    setcolor(3);
    settextstyle(8, 0, 2);
    outtextxy(910, 765, "H1 ");
    line(950, 700, 950, 740);
    line(940, 710, 950, 700);
    line(960, 710, 950, 700);

    setcolor(10);
    delay(100);
    rectangle(1050, 700, 1350, 650);
    setcolor(1);
    settextstyle(8, 0, 4);
    outtextxy(1080, 660, " DATA LINK ");

    setcolor(5);
    delay(100);
    rectangle(900, 690, 1000, 660);
    setcolor(3);
    settextstyle(8, 0, 2);
    outtextxy(910, 665, "H2 T2");
    line(950, 600, 950, 640);
    line(940, 610, 950, 600);
    line(960, 610, 950, 600);
    setcolor(10);
    delay(100);
    rectangle(1050, 600, 1350, 550);
    setcolor(1);
    settextstyle(8, 0, 4);
    outtextxy(1100, 560, " NETWORK ");
    setcolor(5);
    delay(100);
    rectangle(900, 590, 1000, 560);
    setcolor(3);
    settextstyle(8, 0, 2);
    outtextxy(910, 565, "H3");
    line(950, 500, 950, 540);
    line(940, 510, 950, 500);
    line(960, 510, 950, 500);
    setcolor(10);
    delay(100);
    rectangle(1050, 500, 1350, 450);
    setcolor(1);
    settextstyle(8, 0, 4);
    outtextxy(1090, 460, " TRANSPORT ");
    setcolor(5);
    delay(100);
    rectangle(900, 490, 1000, 460);
    setcolor(3);
    settextstyle(8, 0, 2);
    outtextxy(910, 465, "H4");
    line(950, 400, 950, 440);
    line(940, 410, 950, 400);
    line(960, 410, 950, 400);
    setcolor(10);
    delay(100);
    rectangle(1050, 400, 1350, 350);

    setcolor(1);
    settextstyle(8, 0, 4);
    outtextxy(1100, 360, " SESSION ");

    setcolor(5);
    delay(100);
    rectangle(900, 390, 1000, 360);
    setcolor(3);
    settextstyle(8, 0, 2);
    outtextxy(910, 365, "H5");
    line(950, 300, 950, 340);
    line(940, 310, 950, 300);
    line(960, 310, 950, 300);

    setcolor(10);
    delay(100);
    rectangle(1050, 300, 1350, 250);

    setcolor(1);
    settextstyle(8, 0, 4);
    outtextxy(1060, 260, " PRESENTATION");

    setcolor(5);
    delay(100);
    rectangle(900, 290, 1000, 260);
    setcolor(3);
    settextstyle(8, 0, 2);
    outtextxy(910, 265, "H6");
    line(950, 200, 950, 240);
    line(940, 210, 950, 200);
    line(960, 210, 950, 200);

    setcolor(10);
    delay(100);
    rectangle(1050, 200, 1350, 150);
    setcolor(1);
    settextstyle(8, 0, 4);
    outtextxy(1060, 160, " APPLICATION");

    delay(100);
    setcolor(5);
    rectangle(900, 190, 1000, 160);
    setcolor(3);
    settextstyle(8, 0, 2);
    outtextxy(910, 165, "H7 ");
    getch();
    closegraph();
    return 0;
}
