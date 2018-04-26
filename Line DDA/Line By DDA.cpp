 #include<iostream>
 #include<cmath>
 #include<conio.h>
 #include<graphics.h>

using namespace std;

int arr[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
int rand_color;

void  DDA(float x1,float y1, float x2, float y2)
 {
     float m = (y2 - y1) / (x2 - x1);

     if( abs(m) <= 1)
     {
         while(x1 < x2)
         {  rand_color = rand()%15;
             putpixel(x1,y1,rand_color);
             x1 = x1 + 1;
             y1 = y1 + m;
         }
     }
     else
     {
         while(y1 < y2)
         {   rand_color = rand()%15;
             putpixel(x1,y1,rand_color);
             y1 = y1 + 1;
             x1 = x1 + (1/m);
         }
     }

 }

  int main()
  {

     int gd = DETECT, gm;

     initgraph(&gd, &gm, nullptr);

     float x1,x2,y1,y2;
     cout<<"Coordinate of first point:";
     cin>>x1>>y1;

     cout<<"\nCoordinate of second point:";
     cin>>x2>>y2;

     DDA(x1,y1,x2,y2);

     getche();
     closegraph();
  }
