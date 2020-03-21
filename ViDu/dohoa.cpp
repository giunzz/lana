#include<bits/stdc++.h>
#include<graphics.h>

main()
{
    int x[107] , y[107];
    int mh = 0 , mode = 0 , i , n ;
    char *p[107];
    
    initgraph(&mh , &mode, "");
    if(graphresult() != 0) exit(1);
    setcolor(RED);
    // Vẽ bầu trời
    for (int i = 1 ; i <= 100 ; i++)
    {
        putpixel (random (getmaxx())),
        random(getmaxy()) , random(getmaxcolor()));
    }
}
