#include <graphics.h>
// #include <dos.h>

int main()
{
   int i, j = 0, gd = DETECT, gm;

   initgraph(&gd,&gm,NULL);

//    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
   outtextxy(25,240,"Press any key to move car");

   getch();

   for( i = 0 ; i <= 420 ; i = i + 10, j++ )
   {
      outtextxy(75+i, 340, "Rohit");
      rectangle(50+i,275,150+i,400);
      rectangle(161+i,360,188+i,385);
      rectangle(150+i,350,200+i,400);
      circle(75+i,410,10);
      circle(175+i,410,10);
      setcolor(j);
      delay(100);

      if( i == 420 )
         break;
      if ( j == 15 )
         j = 2;

      cleardevice(); // clear screen
   }

   getch();
   closegraph();
   return 0;
}
