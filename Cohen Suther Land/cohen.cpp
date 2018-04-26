#include<iostream>
#include<graphics.h>
using namespace std;
int xmin=50,xmax=200,ymin=50,ymax=300;
int INSIDE=0;
int LEFT=1;
int RIGHT=2;
int BOTTOM=4;
int TOP=8;

int getcode(int x,int y)
{
int c=0;
if(x<xmin)
    c|=LEFT;
if(x>xmax)
    c|=RIGHT;
if(y<ymin)
    c|=BOTTOM;
if(y>ymax)
    c|=TOP;
return c;

}
int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"E:\\TC\\BGI");
    int x1,y1,x2,y2,done=0;
    cout<<"Enter the end points of the line: ";
    cin>>x1>>y1>>x2>>y2;
    line(xmin,ymin,xmin,ymax);
    line(xmin,ymin,xmax,ymin);
    line(xmax,ymin,xmax,ymax);
    line(xmax,ymax,xmin,ymax);
    line(x1,y1,x2,y2);
    int c1=getcode(x1,y1);
    int c2=getcode(x2,y2);
    delay(5000);

    setcolor(2);
    int t=c1|c2;
    cout<<t;
    while(true)
    {
        if((c1|c2)==0)
            {
                line(x1,y1,x2,y2);
            break;}
        else if((c1&c2)!=0)
            break;
        else{
            int code;
            double x,y;
            if(c1!=0)
                code=c1;
            else
                code=c2;
            if(code&LEFT)
            {
                x=xmin;
                y=y1+(y2-y1)*(xmin-x1)/(x2-x1);
            }
            else if(code&BOTTOM)
            {
                y=ymin;
                x=x1+(x2-x1)*(ymin-y1)/(y2-y1);
            }
            else if(code&RIGHT)
            {
                x=xmax;
                y=y1+(y2-y1)*(xmax-x1)/(x2-x1);
            }
            else if(code&TOP)
            {
                y=ymax;
                x=x1+(x2-x1)*(ymax-y1)/(y2-y1);
            }
            if(code==c1)
            {
                x1=x;
                y1=y;
                c1=getcode(x1,y1);
            }
            else
            {
                x2=x;y2=y;
                c2=getcode(x2,y2);
            }


        }
    }
    getch();
    return 0;
}
