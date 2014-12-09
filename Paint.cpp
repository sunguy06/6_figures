#include "TXLib.h"

int main ()
    {
    txCreateWindow (1000, 1000);

    int x = 0, y = 0;

    while (!GetAsyncKeyState (VK_ESCAPE))
        {
        if (txMouseButtons() == 1)
            {
            txSetFillColor (TX_WHITE);
            txSetColor (TX_WHITE);
            txCircle (x, y, 10);
            }

        if (GetAsyncKeyState (VK_SPACE))
            {
            txSetFillColor (TX_BLACK);
            txClear ();
            }

        x = txMouseX();
        y = txMouseY();
        txSleep(1);
        }
    }

