 #include<iostream>
 #include<cmath>
 #include<conio.h>
 #include<graphics.h>

using namespace std;

int arr[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
int rand_color;

void Mid_Point_Theorem(int x1, int y1, int x2, int y2)
{
        float x = x1,y = y1;
        float d =2*(y2 - y1) - (x2 - x1);
        float dy = y2 - y1,dx = x2 - x1;
        float m  = (y2 - y1)/(x2 - x1);

        if(abs(m) <= 1)
        {
            while(x < x2)
            {    rand_color = rand()%15;
                 putpixel(x,y,rand_color);
                if(d <= 0)
                {
                    d += 2*dy;
                }
                else
                {
                    d+=2*(dy - dx);
                    y++;
                }
                x++;
            }
        }
        else
        {

            while(y < y2)
            {   rand_color = rand()%15;
                putpixel(x,y,rand_color);
                if(d <= 0)
                {
                    d+=2*dx;
                }
                else
                {
                    d+=2*(dy - dx);
                    x++;
                }

                y++;
            }
        }
}


int main()
{

     int gd = DETECT, gm;

     initgraph(&gd, &gm, nullptr);

     int x1,x2,y1,y2;
     cout<<"Coordinate of first point:";
     cin>>x1>>y1;

     cout<<"\nCoordinate of second point:";
     cin>>x2>>y2;

     Mid_Point_Theorem(x1,y1,x2,y2);

     getche();
     closegraph();
}
