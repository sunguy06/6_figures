
#include "TXLib.h"

void BACKGROUND ();
void CAR (int x, int y, int Zoom);
void SUN (int x);
void SKY_DIVER (int x, int y, int Zoom,
                int HandUp, int Legs);
void PLANE (int x, int y, int Zoom, int Fire, int Krylia);
void HOUSE ();
void BIG_TREE ();
void SMALL_TREE ();
void Subtitles_Nachalo (int y);
void Subtitles_The_End (int y);
void CIKL ();
void FUNKSIA ();

int main()
{
    txCreateWindow (800, 600);
    txTextCursor (false);

    CIKL ();

    txClear ();
    int x = 900;
    int xcar = 570;
    int ycar = 460;
    int Zoom_car = 1;
    int yskydiver1 = 600, xskydiver1 = -100;
    int yskydiver2 = 600, xskydiver2 = -100;
    int yskydiver3 = 600, xskydiver3 = -100;
    int score = 0;

    while (!GetAsyncKeyState (VK_ESCAPE))
    {

        txClear ();
        BACKGROUND();
        HOUSE();
        BIG_TREE();
        SMALL_TREE();
        SUN(5);
        PLANE(x, 80, 1, 255, 1);

        if (GetAsyncKeyState (VK_LEFT))
        {
            xcar-=3;
        }

        if (GetAsyncKeyState (VK_RIGHT))
        {
            xcar+=3;
        }

        if (x < 0) x = 800;           // бесконечный полёт самолётика

        if (x/4 == rand() % 800/4 && yskydiver1 >= 600)
        {
            xskydiver1 = x+70; yskydiver1 = 200;
        }
        if (x/4 == rand() % 800/4 && yskydiver2 >= 600)
        {
            xskydiver2 = x+70; yskydiver2 = 200;
        }
        if (x/4 == rand() % 800/4 && yskydiver3 >= 600)
        {
            xskydiver3 = x+70; yskydiver3 = 200;
        }

        if (abs (xskydiver1 - xcar) <= 100 && abs (yskydiver1 - ycar) <= 50)
        {
            yskydiver1 = 600; score++; FUNKSIA ();
        }
        if (abs (xskydiver2 - xcar) <= 100 && abs (yskydiver2 - ycar) <= 50)
        {
            yskydiver2 = 600; score++; FUNKSIA ();
        }
        if (abs (xskydiver3 - xcar) <= 100 && abs (yskydiver3 - ycar) <= 50)
        {
            yskydiver3 = 600; score++; FUNKSIA ();
        }

        SKY_DIVER (xskydiver1, yskydiver1, 1, 1, 1);
        SKY_DIVER (xskydiver2, yskydiver2, 1, 1, 1 );
        SKY_DIVER (xskydiver3, yskydiver3, 1, 1, 1 );

        yskydiver1 += 1;
        yskydiver2 += 1;
        yskydiver3 += 1;

        CAR (xcar, ycar, Zoom_car);
        txSleep (10);

        x -= 4;
        if (GetAsyncKeyState (VK_ESCAPE)) break;

    }

    int ySubtitles = 850;

    while (true)
    {
        txBegin ();

        txSetFillColor (RGB (64, 0, 0));
        txClear ();

        Subtitles_The_End (ySubtitles);

        txEnd ();

        txSleep (10);
        if(ySubtitles == 170)
        {
            txSleep (3000);
        }

        ySubtitles -= 2;
    }
return 0;
}

void SKY_DIVER (int x, int y, int Zoom,  int HandUp, int Legs)
{
    txSetColor (TX_BLACK, 3);
    txLine (x,            y,            x,            y + 20*Zoom); // body  rrrrrr
    txLine (x,            y,            x + 10*Zoom,  y + 10*Zoom); // left hand rr
    txLine (x,            y,            x - 10*Zoom,  y + 10*Zoom); // right hand r
    txLine (x - 10*Zoom,  y + 40*Zoom,  x + Legs,     y + 20*Zoom); // left leg rrr
    txLine (x + 10*Zoom,  y + 40*Zoom,  x - Legs,     y + 20*Zoom); // right leg rr
    txLine (x,            y,            x + 40*Zoom,  y - 40*Zoom); // parachut rrr
    txLine (x,            y,            x + 20*Zoom,  y - 40*Zoom); // parachut rrr
    txLine (x,            y,            x - 20*Zoom,  y - 40*Zoom); // parachut rrr
    txLine (x,            y,            x - 40*Zoom,  y - 40*Zoom); // parachut rrr
    txLine (x - 40*Zoom,  y - 40*Zoom,  x + 40*Zoom,  y - 40*Zoom); // parachut rrr

    txSetColor (TX_WHITE);
    txSetFillColor (TX_WHITE);
    txCircle (x, y - 8*Zoom, 5*Zoom);

    txSetColor (TX_RED);
    txSetFillColor (TX_RED);
    txPie (x - 40*Zoom, y - 60*Zoom, x + 40*Zoom, y  - 20*Zoom, 0, 180);
}

void PLANE (int x, int y, int Zoom, int Fire, int Krylia)
{
    txSetColor (TX_NULL);
    txSetFillColor (RGB (118, 10, 107));
    txRectangle (x, y, x + 100*Zoom, y + 40*Zoom);
    POINT triangle1 [3] = {{x - 50*Zoom, Zoom*y + 20}, {x, y + 39*Zoom}, {x, y}};
    txPolygon (triangle1, 3);             // нос

    txSetColor (TX_BLACK);
    txSetFillColor (TX_WHITE);
    POINT triangle2 [3] = {{x + 10*Zoom, y - 1*Zoom}, {x + 80*Zoom, y - 40*Zoom}, {x + 80*Zoom, y - 1*Zoom}};
    txPolygon (triangle2, 3);             // верхнее крыло
    POINT triangle3 [3] = {{x + 10*Zoom, y + 39*Zoom}, {x + 80*Zoom, y + 39*Zoom}, {x + 80*Zoom, y + 80*Zoom*Krylia}};
    txPolygon (triangle3, 3);             // нижнее крыло

    txSetFillColor (TX_LIGHTBLUE);
    txCircle (x + 20*Zoom, y + 20*Zoom, 10*Zoom);
    txCircle (x + 60*Zoom, y + 20*Zoom, 10*Zoom);

    txSetColor (TX_BLACK);
    txSetFillColor (TX_YELLOW);
    txRectangle (x + 80*Zoom, y - 30*Zoom, x + 90*Zoom, y - 10*Zoom);
    txRectangle (x + 80*Zoom, y + 50*Zoom, x + 90*Zoom, y + 70*Zoom);

    txSetColor (RGB (Fire, 0, 0));
    txSetFillColor (RGB (Fire, 0, 0));   //сопла
    POINT triangle4 [3] = {{x + 100*Zoom, y}, {x + 130*Zoom, y + 20*Zoom}, {x + 100*Zoom, y + 38*Zoom}};
    txPolygon (triangle4, 3);

}

void SUN (int x)
{
    txSetColor (TX_YELLOW);
    txSetFillColor (TX_YELLOW);
    txCircle (700, 100, 50);
    POINT triangle5 [3] = {{670, 10}, {660, 60}, {610, 70}};
    txPolygon (triangle5, 3);

    POINT triangle6 [3] = {{610, 140}, {640, 120}, {640, 160}};
    txPolygon (triangle6, 3);

    POINT triangle7 [3] = {{670, 150}, {650, 190}, {680, 180}};
    txPolygon (triangle7, 3);

    POINT triangle8 [3] = {{730, 150}, {720, 180}, {750, 190}};
    txPolygon (triangle8, 3);

    POINT triangle9 [3] = {{750, 140}, {780, 110}, {790, 170}};
    txPolygon (triangle9, 3);

    POINT triangle10 [3] = {{730, 10}, {740, 60}, {790, 70}};
    txPolygon (triangle10, 3);

    //  for smile and eyes of the sun
    txSetColor (TX_BLACK);
    txSetFillColor (TX_BLUE);
    txCircle (680, 80, 10);
    txCircle (720, 80, 10);
    txPie (670, 90, 730, 130, 180, 180);

}

void CAR (int x, int y, int Zoom)
{
    txSetColor (TX_BLACK, 2);
    txSetFillColor (TX_RED);
    txRectangle (x, y, x + 170*Zoom, y + 30*Zoom);

    txSetFillColor (TX_LIGHTBLUE);
    txRectangle (x + (50*Zoom), y - 20*Zoom, x + 110*Zoom, y + 1*Zoom);

    POINT triangle11 [3] = {{x + 50*Zoom, y - 21*Zoom}, {x + 30*Zoom, y}, {x + 50*Zoom, y}};
    txPolygon (triangle11, 3);

    POINT triangle12 [3] = {{x + 110*Zoom, y - 21*Zoom}, {x + 150*Zoom,y}, {x + 110*Zoom, y}};
    txPolygon (triangle12, 3);

    txLine (x + (80*Zoom), y - 20*Zoom, x + 80*Zoom, y);
    txLine (x + (30*Zoom), y, x + 30*Zoom, y + 15*Zoom);

    txSetFillColor (TX_YELLOW);
    txRectangle (x, y, x + 20*Zoom, y + 10*Zoom);
    txRectangle (x + 160*Zoom, y, x + 170*Zoom, y + 20*Zoom);

    txSetFillColor (TX_BROWN);
    txCircle (x + 130*Zoom, y + 30*Zoom, 15*Zoom);
    txCircle (x + 30*Zoom, y + 30*Zoom, 15*Zoom);
    txSetFillColor (TX_YELLOW);
    txCircle (x + 30*Zoom, y + 30*Zoom, 5*Zoom);
    txCircle (x + 130*Zoom, y + 30*Zoom, 5*Zoom);

}

void BACKGROUND ()
{
    txSetColor (TX_BLUE);
    txSetFillColor (TX_BLUE);
    txRectangle (0, 0, 800, 600);

    txSetColor (TX_GREEN);
    txSetFillColor (TX_GREEN);
    txRectangle (0, 500, 800, 600);

}

void HOUSE ()
{
    txSetColor (TX_WHITE);
    txSetFillColor (TX_WHITE);
    txRectangle (0, 400, 180, 600);

    txSetColor (TX_BROWN);
    txSetFillColor (TX_BROWN);
    txRectangle (130, 510, 180, 600);

    txSetColor (TX_BLACK, 3);
    txSetFillColor (TX_LIGHTBLUE);
    txRectangle (30, 500, 110, 550);

    txSetColor (TX_BLACK,3);
    txSetFillColor (TX_LIGHTBLUE);
    txRectangle (30,420,150,470);
    txCircle (100, 360, 30);

    txSetFillColor (TX_RED);
    POINT triangle [3] = {{0, 400},{90, 300},{180, 400}};
    txPolygon (triangle,3);

    txSetFillColor (TX_LIGHTBLUE);
    txCircle (90, 360, 30);

}

void BIG_TREE ()
{
    txSetColor (TX_BROWN);
    txSetFillColor (TX_BROWN);
    txRectangle (310, 460, 330, 570);

    txLine (310, 490, 270, 440);
    txLine (330, 480, 350, 460);
    txLine (310, 460, 290, 350);
    txLine (320, 500, 350, 340);
    txLine (330, 460, 370, 400);

    txSetColor (TX_GREEN);
    txSetFillColor (TX_GREEN);
    txCircle (270, 440, 50);
    txCircle (350, 460, 20);
    txCircle (290, 350, 40);
    txCircle (350, 340, 30);
    txCircle (370, 400, 40);

}

void SMALL_TREE ()
{
    txSetColor (TX_BROWN);
    txSetFillColor (TX_BROWN);
    txRectangle (500, 400, 520, 500);

    txSetColor (TX_GREEN);
    txSetFillColor (TX_GREEN);
    txCircle (510, 400, 50);

}

void Subtitles_Nachalo (int y)
{
    txSetColor (TX_RED);
    txSelectFont ("Arial", 100, 20 );
    txDrawText (100, (y - 500) * 5, 700, y + 1399, "Мышиная голова incorporated\n"
                                                   "The Great Cat Studios\n"
                                                   "BigCheese (tm) Media Consortium\n"
                                                   "\n"
                                                   "P R E S E N T S\n"
                                                   "\n"
                                                   "A troubleshooting story\n"
                                                   "On your cinema-boxed head\n"
                                                   "And your thrilling nasty car\n"
                                                   "I don't know what to write more\n"
                                                   "Please help me\n"
                                                   "I'm in the nightmare\n"
                                                   "It's too late\n"
                                                   "I want to go home\n"
                                                   "And want to eat\n"
                                                   "And sleep\n"
                                                   "Too\n"
                                                   "...\n"
                                                   "Lorem ipsum dolor sit amet,\n"              //:), :(, ;), ;(
                                                   "consectetur adipiscing elit.\n"
                                                   "Morbi eu pretium ligula, eu feugiat nisi.\n"
                                                   "Aliquam erat volutpat. Curabitur ut risus\n"
                                                   "in metus imperdiet placerat. Nulla eros\n"
                                                   "lectus, feugiat eu venenatis ac, vestibulum\n"
                                                   "quis felis. Integer in risus mauris. Mauris\n"
                                                   "faucibus leo augue, eget placerat diam tincidunt\n"
                                                   "eget. Lorem ipsum dolor sit amet, consectetur\n"
                                                   "adipiscing elit. \n"
                                                   "\\n"
                                                   "\\n"
                                                   "\\n");

    txSetColor (TX_LIGHTRED);
    txSelectFont ("Arial", 100, 20);
    txDrawText (100, y, 700, y + 399, "Bonk Entertaiment \n представляет...");
}

void Subtitles_The_End (int y)
{
    txSetColor (TX_LIGHTRED);
    txSelectFont ("Arial", 100, 20);
    txDrawText (100, (y - 500)*5, 700, y +1399,"Душа моя озарена неземной радостью,\n"
                                               "как эти чудесные весенние утра,\n"
                                               "которыми я наслаждаюсь от всего сердца.\n"
                                               "Я совсем один и блаженствую в здешнем краю,\n"
                                               "словно созданном для таких, как я.\n"
                                               "Я так счастлив, мой друг, так упоен ощущением покоя,\n"
                                               "что искусство мое страдает от этого.\n"
                                               "Ни одного штриха не мог бы я сделать,\n"
                                               "а никогда не был таким большим художником,\n"
                                               "как в эти минуты.\n");

    txSetColor (TX_LIGHTGREEN);
    txSelectFont ("Arial", 100, 20);
    txDrawText (100, y, 700, y +399, "Bonk Entertaiment\n The End...");


}

void CIKL ()
{
    int ySubtitles = 850;
    while (ySubtitles >= -150)
    {
        txBegin ();

        if(ySubtitles == 170)
        {
            txSleep (3000);
        }

        txSetFillColor (RGB (64, 0, 0));
        txClear ();
        Subtitles_Nachalo (ySubtitles);
        ySubtitles -=2;

        txSleep (10);
        txEnd ();
    }
}

void FUNKSIA ()
{
    int xcar = 570;
    int ycar = 460;
    txSetFillColor (TX_PINK);
    txCircle (xcar+50, ycar, 100);
    txSleep (100);
}










