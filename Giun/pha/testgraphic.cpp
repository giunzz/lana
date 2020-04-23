#include<graphics.h>
#include <conio.h>
int main()
{
    int gd = DETECT, gm;
    char dr[] = "C:\\mingw\\bgi";
    initgraph(&gd,&gm, dr);
    circle(300,300,50);
    _getch();
    closegraph();
}
