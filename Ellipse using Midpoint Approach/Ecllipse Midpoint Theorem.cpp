
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
}

void Ecllipse_MPT(int a, int b)
{

    float x = 0, y = b;
    float d = b * b  - a*a*b + 0.25*a*a;
    while(abs((-b*b*x)/(a*a*y)) <= 1)
          {
              Print_Symmetric_Points(x,y);
              if(d <= 0)
            {
                d += 2*b*b*(x) + (b*b);
            }
            else
            {
                d+= 2*b*b*(x) + (b*b) - 2*a*a*(y - 1);
                y--;
            }
            x++;
          }

         Print_Symmetric_Points(x,y);
          d = b*b*(x + 0.5)*(x+0.5) + a*a*(y - 1)*(y-1) - a*a*b*b;
          while(y > 0)
          {
              Print_Symmetric_Points(x,y);
              if(d < 0)
              {
                  d += 2*b*b*(x + 1) - 2*a*a*(y) + a*a;
                  x++;
              }
              else if(d >= 0)
              {
                  d += a*a - 2*a*a*(y);
              }
              y--;
          }
}

int main()
{

     int gd = DETECT, gm;

     initgraph(&gd, &gm, nullptr);

    int a,b;
   while(1){
    cout<<"Enter a and b:";
    cin>>a>>b;

    Ecllipse_MPT(a,b);
   }
     getche();
     closegraph();
}

