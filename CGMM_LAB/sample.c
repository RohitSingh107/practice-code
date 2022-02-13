# include <iostream.h>
# include <graphics.h>
# include <conio.h>
# include <math.h>
void show_screen( );
void dda_line(const int,const int,const int,const int);
int main( )
{
int driver=VGA;
int mode=VGAHI;
int x_1=0;
int y_1=0;
int x_2=0;
int y_2=0;
do
{
show_screen( );
gotoxy(8,10);
cout<<"Coordinates of Point-I (x1,y1) :";
gotoxy(8,11);
cout<<"ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ";
gotoxy(12,13);
cout<<"Enter the value of x1 = ";
cin>>x_1;
gotoxy(12,14);
cout<<"Enter the value of y1 = ";
cin>>y_1;
gotoxy(8,18);
cout<<"Coordinates of Point-II (x2,y2) :";
gotoxy(8,19);
cout<<"ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ";
gotoxy(12,21);
cout<<"Enter the value of x2 = ";
cin>>x_2;
gotoxy(12,22);
cout<<"Enter the value of y2 = ";
cin>>y_2;
initgraph(&driver,&mode,"..\\Bgi");
setcolor(15);
dda_line(x_1,y_1,x_2,y_2);
setcolor(15);
outtextxy(110,460,"Press <Enter> to continue or any other key to exit.");
int key=int(getch( ));
if(key!=13)
break;
}
while(1);
return 0;
}
void dda_line(const int x_1,const int y_1,const int x_2,const int y_2)
{
int color=getcolor( );
int x1=x_1;
int y1=y_1;
int x2=x_2;
int y2=y_2;
if(x_1>x_2)
{
x1=x_2;
y1=y_2;
x2=x_1;
y2=y_1;
}
float dx=(x2-x1);
float dy=(y2-y1);
int steps=abs(dy);
if(abs(dx)>abs(dy))
steps=abs(dx);
float x_inc=(dx/(float)steps);
float y_inc=(dy/(float)steps);
float x=x1;
float y=y1;
putpixel(x,y,color);
for(int count=1;count<=steps;count++)
{
x+=x_inc;
y+=y_inc;
putpixel((int)(x+0.5),(int)(y+0.5),color);
}
}
void show_screen( )
{
restorecrtmode( );
textmode(C4350);
cprintf("\n*****************************************************************");
cprintf("******************- -*****************");
cprintf("*------------------ ");
textbackground(1);
cprintf(" Digital Differential Analyzer Algorithm ");
textbackground(8);
cprintf(" -----------------*");
cprintf("*-****************- -***************-*");
cprintf("*-*********************************************************-*");
for(int count=0;count<42;count++)
cprintf("*-* *-*");
gotoxy(1,46);
cprintf("*-***********************************************************-*");
cprintf("*------------------------------------------------------------------------------*");
cprintf("************************************************************");
gotoxy(1,2);
}