#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

void bresenhamAlgo(int x1, int y1, int x2, int y2){
    int dy = y2 - y1;
    int dx = x2 - x1;
    float slope = dy/dx;
    int p = 2*dy - dx;
    int x = x1;
    int y = y1;
    while(x <= x2){
        if(slope>=1){
            if(p>=0){
                // putpixel(x,y, RED);
                cout<<x<<" "<<y<<endl;
                x++;
                y++;
                p += 2*dx - 2*dy;
            }
            else{
                // putpixel(x,y, RED);
                cout<<x<<" "<<y<<endl;
                y++;
                p += 2*dx;
            }
            // delay(20);
        }
        else{
            if(p>=0){
                // putpixel(x,y, YELLOW);
                cout<<x<<" "<<y<<endl;
                x++;
                y++;
                p += 2*dy - 2*dx;
            }
            else{
                // putpixel(x,y, YELLOW);
                cout<<x<<" "<<y<<endl;
                x++;
                p += 2*dy;
            }
            // delay(20);
        }
    }
}

int main(){
    
    int  x1, y1, x2, y2;

    int gdriver=DETECT,gmode;

    // initgraph(&gdriver, &gmode, NULL);

    x1 = 350;
    x2 = 400;
    y1 = 50;
    y2 = 30;

    bresenhamAlgo(x1,x2,y1,y2);
    // getch();
    // closegraph();

    return 0;
}