#include<iostream>
#include <graphics.h>
#include <conio.h>
#include<math.h>

using namespace std;


int rand_color;

void Ying_Yang_Patel(float R)
{
    float small_radius = R/2;
    double angle = 0,theta = 0,pi = 3.14,theta2,angle2 = 90;
    int i = 1;

    while(i)
    {
        small_radius = R/2;
        theta = (angle * pi)/180;
        theta2 = (angle2*pi )/180;

        rand_color = rand()%15;
        setcolor(rand_color);
        cout<<"\nRadius : "<<R;
        circle(getmaxx()/2,getmaxy()/2,R);
        arc(getmaxx()/2 + small_radius*cos(theta),getmaxy()/2 + small_radius*sin(theta),360 - angle, 180 - angle ,small_radius);
        arc(getmaxx()/2 - small_radius*cos(theta),getmaxy()/2 - small_radius*sin(theta),180 - angle,360 - angle,small_radius);
        arc(getmaxx()/2 - small_radius*cos(theta2), getmaxy()/2 - small_radius*sin(theta2), 90 - angle, 270 - angle,small_radius);
        arc(getmaxx()/2 + small_radius*cos(theta2), getmaxy()/2 + small_radius*sin(theta2), 270 - angle, 90 - angle, small_radius);


        delay(50);
        cleardevice();

        if(angle > 360)
            angle = 0;
         if(angle2 > 360)
                angle2 = 0;
        angle += 1;
        angle2 += 1;

       R += 0.5;
    }

}

int main()
{
   int gd = DETECT, gm, x = 25, y = 25, font = 0;

   initgraph(&gd,&gm,nullptr);

    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);

    float r;
    cout<<"Enter Radius of Circle:";
    cin>>r;


    Ying_Yang_Patel(r);

   getch();
   closegraph();
   return 0;
}

