#include "TXLib.h"

//=============================================================================

void Go_Ball ();
void Draw_Ball (   double x,      double y,      COLORREF color);
void Move_Ball (   double* x,     double* y,     double* Vx,        double* Vy, double* dt);
void Drow_Lines (  double x,      double y,      double x2,         double y2,  double x3, double y3, COLORREF color);
void Control_Ball (double* Vx, double* Vy);

//=============================================================================


int main()
    {
    txCreateWindow (1500, 1000);
    txTextCursor (false);

    Go_Ball ();
    return 0;
    }


//=============================================================================


void Go_Ball ()
    {
    double Red   = rand () %255;
    double Blue  = rand () %255;
    double Green = rand () %255;

    double First_x  = 100, First_y  = 50;
    double First_Vx =   1, First_Vy =  1;
    double First_t = 2;

    double Second_x = 400;
    double Second_y = 900;
    double Second_Vx = 1;
    double Second_Vy = 1;
    double Second_t = 2;

    double Third_Vx = 1;
    double Third_Vy = 1;
    double Third_t = 2;
    double Third_x = 800;
    double Third_y = 350;

    while (!GetAsyncKeyState (VK_ESCAPE))
        {

        Red   = rand () % 255;
        Blue  = rand () % 255;
        Green = rand () % 255;

        Control_Ball (&First_Vx ,&First_Vy);

        Draw_Ball (First_x,  First_y,  RGB (Red, Blue, Green));
        Draw_Ball (Second_x, Second_y, RGB (Red, Blue, Green));
        Draw_Ball (Third_x,  Third_y,  RGB (Red, Blue, Green));

        Drow_Lines (First_x,  First_y, Second_x, Second_y, Third_x, Third_y, RGB (Red, Blue, Green));

        Move_Ball (&First_x,  &First_y,  &First_Vx,  &First_Vy,  &First_t);
        Move_Ball (&Second_x, &Second_y, &Second_Vx, &Second_Vy, &Second_t);
        Move_Ball (&Third_x,  &Third_y,  &Third_Vx,  &Third_Vy,  &Third_t);

        if (abs(First_y - Second_y) <= 40 && abs(First_x - Second_x) <= 40)
            {
            int xCopy = First_Vx; First_Vx = Second_Vx; Second_Vx = xCopy;
            int yCopy = First_Vy; First_Vy = Second_Vy; Second_Vy = yCopy;
            }

        if(abs(Second_y - Third_y) <= 40 && abs(Second_x - Third_x) <= 40)
            {
            int xCopy = Second_Vx; Second_Vx = Third_Vx; Third_Vx = xCopy;
            int yCopy = Second_Vy; Second_Vy = Third_Vy; Third_Vy = yCopy;
            }

        if(abs(First_y - Third_y) <= 40 && abs(First_x - Third_x) <= 40)
            {
            int xCopy = First_Vx; First_Vx = Third_Vx; Third_Vx = xCopy;
            int yCopy = First_Vy; First_Vy = Third_Vy; Third_Vy = yCopy;
            }

        txSleep (1);
        txSetFillColor (TX_BLACK);
        txClear ();
        }
    }


//=============================================================================


void Draw_Ball (double x, double y, COLORREF color)
    {
    txSetFillColor (color);
    txSetColor (color);
    txCircle (x, y, 20);
    }


//=============================================================================


void Move_Ball (double* x, double* y, double* Vx, double* Vy, double* dt)
    {
    *x += *Vx*(*dt);
    *y += *Vy*(*dt);

    if (*x > 1480)
        {
        *Vx = -(*Vx);
        *x = 1480;
        }

    if (*y > 980)
        {
        *Vy = -(*Vy);
        *y = 980;
        }

    if (*x < 20)
        {
        *Vx = -(*Vx);
        *x = 20;
        }

    if (*y < 20)
        {
        *Vy = -(*Vy);
        *y = 20;
        }
}


//=============================================================================


void Drow_Lines (double x1, double y1, double x2, double y2, double x3, double y3, COLORREF color)
    {
    txSetColor (color);
    txLine (x1, y1, x2, y2);
    txLine (x2, y2, x3, y3);
    txLine (x1, y1, x3, y3);
    }

//=============================================================================

void Control_Ball (double* Vx, double* Vy)
    {
    if (GetAsyncKeyState (VK_RIGHT))
        {
        *Vx += 0.1;
        }

    if (GetAsyncKeyState (VK_LEFT))
        {
        *Vx -= 0.1;
        }

    if (GetAsyncKeyState (VK_UP))
        {
        *Vy -= 0.1;
        }

    if (GetAsyncKeyState (VK_DOWN))
        {
        *Vy += 0.1;
        }
    if (GetAsyncKeyState (VK_SPACE))
        {
        *Vx = 0;
        *Vy = 0;
        }

    if (GetAsyncKeyState (VK_SHIFT))
        {
        *Vx += 0.1;
        *Vy += 0.1;
        }

    if (GetAsyncKeyState (VK_MENU))
        {
        *Vx -= 0.1;
        *Vy -= 0.1;
        }

    }

