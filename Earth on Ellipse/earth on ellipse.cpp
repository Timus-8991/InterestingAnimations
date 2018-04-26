#include<iostream>
#include <graphics.h>
#include <conio.h>
#include<math.h>

using namespace std;

void Earth_Revolution(int R)
{

     double angle = 0,theta = 0,pi = 3.14;
     double r,a = 150,b = 100;  // r = radius of ellipse
     int rand_color,x_circle,y_circle;
     double angle2 = 0, theta2 = 0;

     while(1)
     {

         theta = (angle*pi) / 180;
         r = (a*b)/sqrt( a*a*sin(theta)*sin(theta) + b*b*cos(theta)*cos(theta));

        x_circle = getmaxx()/2 + r * cos(theta);
         y_circle = getmaxy()/2 + r*sin(theta);

         theta2 = (angle2*pi) / 180;

         rand_color = rand()%15;
         setcolor(rand_color);
         circle( x_circle, y_circle, R);
         ellipse(getmaxx()/2, getmaxy()/2, 0,360, 150, 100);
         line(x_circle,y_circle,x_circle + R*cos(theta2),y_circle + R*sin(theta2));
         line(x_circle,y_circle,x_circle - R*cos(theta2),y_circle - R*sin(theta2));


         delay(50);
         cleardevice();
         angle += 1;
         angle2 += 2;

     }


}
int main()
{
   int gd = DETECT, gm, x = 25, y = 25, font = 0;

   initgraph(&gd,&gm,nullptr);

    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);



    int r;
    cout<<"Enter Radius of Circle:";
    cin>>r;

    Earth_Revolution(r);
    getch();
    closegraph();
    return 0;
}

