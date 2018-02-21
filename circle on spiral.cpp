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
   double Xbig_c = getmaxx()/2,Ybig_c = getmaxy()/2,Rbig = 20;

    double angle = 0;
    double angle2 = angle + 180;
    double anglebig = 0;
    double R = 10;
    double X_c = Xbig_c,Y_c = Ybig_c - R;
    double PI = 3.14;
    double theta = 0,theta2,thetabig;
    double x = X_c,y = Y_c - R;
    double x2 = X_c,y2 = Y_c + R;
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

        angle += 4;
        angle2 = angle + 180;
        //X_c = (rand()%getmaxx() - R) + R;
        //Y_c = (rand()%getmaxy() - R) + R;
        //X_c += 1;

        thetabig = (anglebig * PI)/180;
        X_c = Xbig_c + Rbig*cos(thetabig);
        Y_c = Ybig_c + Rbig*sin(thetabig);
        anglebig += 0.4;
        Rbig += 0.2;

       }
 //
    getch();
    closegraph();
    return 0;

}
