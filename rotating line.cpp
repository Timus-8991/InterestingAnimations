#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
void linem(int x1,int x2,int y1,int y2,int color)
{
    int dy=y2-y1;
    int dx=x2-x1;
    int d=dy-dx/2;
    int x=x1,y=y1;
    putpixel(x,y,color);
    if(dy<dx)
    {
        while(x<x2)
        {
            x++;
            if(d<0)
                d+=dy;
            else
                {
                    d=d+dy-dx;
                    y++;
                }
                putpixel(x,y,color);
        }
    }
}
int  main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"E:\\TC\\BGI");
   /* int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    for(int i=0;i<300;i++)
    {

        //line(x1+i,y1,x2+i,y2);
        linem(x1+i,x2+i,y1,y2,WHITE);
        delay(150);
        cleardevice();
     //   linem(x1+i+1,x2+i+1,y1,y2,WHITE);
       // linem(x1+i+2,x2+i+2,y1,y2,WHITE);
        //linem(x1+i,x2+i,y1,y2,BLACK);
    }
*/
   //int Xbig_c = 400,Ybig_c = 400;

    double angle = 0;
    double angle2 = angle + 180;
    int R = 40;
    int X_c = 300,Y_c = 300;
    double PI = 3.14;
    double theta = 0,theta2;
    int x = 300,y = 300 - R;
    int x2 = 300,y2 = 300 + R;
    int arr[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int rand_color;
    while(true)
    {
        rand_color = (rand()%15);
        setcolor(arr[rand_color]);
        line(X_c,Y_c,x,y);
        int rand_color = (rand()%15);
        setcolor(arr[rand_color]);
        line(X_c,Y_c,x2,y2);
        delay(50);
       // cleardevice();
        theta = (angle * PI)/180;
        theta2 = (angle2 * PI) / 180;
        x = X_c + R*cos(theta);
        y = Y_c + R*sin(theta);
        x2 = X_c + R*cos(theta2);
        y2 = Y_c + R*sin(theta2);

        angle += 2;
        angle2 = angle + 180;
        //X_c = (rand()%getmaxx() - R) + R;
        //Y_c = (rand()%getmaxy() - R) + R;
        X_c += 1;
    }
    getch();
    closegraph();
    return 0;

}
