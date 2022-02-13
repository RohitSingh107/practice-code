#include <bits/stdc++.h>
#include <graphics.h>
#include <math.h>


void dda(int x1, int y1, int x2, int y2){
    int dx = x2 - x1;
    int dy = y2 - y1;

    int step = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xi = dx / (float) step;
    float yi = dy / (float) step;

    float x = x1;
    float y = y1;
    for(int i =0; i<= step; i++){
        putpixel(round(x), round(y), RED);
        x += xi;
        y += yi;
        delay(100);
    }
}

int main(){

    int  x1, y1, x2, y2;

    int gdriver=DETECT,gmode;

    initgraph(&gdriver, &gmode, NULL);

    x1 = 350;
    x2 = 200;
    y1 = 50;
    y2 = 30;

    dda(x1,x2,y1,y2);
    getch();
    closegraph();
    return 0;
}
