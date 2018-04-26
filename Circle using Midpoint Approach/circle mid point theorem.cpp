 #include<iostream>
 #include<cmath>
 #include<conio.h>
 #include<graphics.h>

using namespace std;

void Print_Symmetric_Points(int x, int y)
{
    putpixel(x + getmaxx()/2,y + getmaxy()/2,2);
    putpixel(-x + getmaxx()/2,y + getmaxy()/2,4);
    putpixel(x + getmaxx()/2,-y + getmaxy()/2,14);
    putpixel(-x + getmaxx()/2,-y + getmaxy()/2,15);
    putpixel(y + getmaxx()/2,x + getmaxy()/2,4);
    putpixel(y + getmaxx()/2,-x + getmaxy()/2,15);
    putpixel(-y + getmaxx()/2,x + getmaxy()/2,2);
    putpixel(-y + getmaxx()/2,-x + getmaxy()/2,14);
}

void Circle_MPT(int r)
{
    int x = 0,y = r;
    int d = 1 - r;
    while(y >= x)
    {   Print_Symmetric_Points(x,y);
        if(d <= 0)
        {
            d+=2*x + 3;
        }
        else
        {
            d+=2*(x - y) + 5;
            y--;
        }
        x++;
    }
}


int main()
{

     int gd = DETECT, gm;

     initgraph(&gd, &gm, nullptr);

    int r;
    cout<<"Enter Radius of Circle:";
    cin>>r;

     Circle_MPT(r);

     getche();
     closegraph();
}
