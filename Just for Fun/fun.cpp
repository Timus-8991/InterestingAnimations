#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

using namespace std;

int flag =1,y_previous,k;
double x = -150;
double y = x*x*(238/22500);
double prism[4][5] = {-15 ,15 , 15, -15,0,  15, 15, -15, -15,0, 0, 0, 0, 0,30, 1, 1, 1, 1,1};
double theta = 0.1;
int rand_color;

//Multiply Two Matrices
void mult(double a[4][4], double b[4][5])
{

    double temp[4][5] = {0};
     for(int i = 0;i < 4; ++i)
    {
        for(int j = 0;j < 5; ++j)
        {
            for(int k = 0;k < 4; ++k)
            {

                temp[i][j] += a[i][k] * b[k][j] ;
            }
        }
    }

    //Copy new Values into Original Figure
    for(int i = 0;i < 4; i++)
    {
        for(int j = 0;j < 5; j++)
        {
            prism[i][j] = temp[i][j];
        }
    }

}

//Rotation about Z-axis
void Rotation_Z()
{
   double r_z_matrix[4][4] = {cos(theta),-sin(theta),0,0,sin(theta),cos(theta),0,0,0,0,1,0,0,0,0,1};
   mult(r_z_matrix,prism);
}

void Isometric_View_Projection()
{


    double isometric[4][4] = {0.707,0,0.707,0,0.408,0.816,-0.408,0,0,0,0,0,0,0,0,1};

    double temp[4][5] = {0};
     for(int i = 0;i < 4; ++i)
    {
        for(int j = 0;j < 5; ++j)
        {
            for(int k = 0;k < 4; ++k)
            {

                temp[i][j] += isometric[i][k] * prism[k][j] ;
            }
        }
    }

    //rand_color = 1 + rand()%15;
    //setcolor(rand_color);
double x_final;
double y_final;
    if(flag ==1)
    {x += 1;
    y = x*x*(200.0/22500);
     x_final = x + 150;
     y_final = y + 100;
     y_previous = y;
    }

    if(x_final > 300)
    {
        flag = 2;
        x = -100;
        y = x*x*(150.0/10000);
        k = y_previous - y;
    }
    if(flag == 2)
    {
        x +=1;
        y = x*x*(150.0/10000);
        x_final = x + 400;
        y_final = y + k + 100;
        y_previous = y_final;
    }
    if(x_final > 500)
    {
        flag = 3;
        x = -50;
        y = x*x*(100.0/2500);
        k = y_previous-y;
    }
    if(flag == 3)
    {
        x+=1;
        y = x*x*(100.0/2500);
        x_final = x + 550;
        y_final = y + k;
    }

    line(x_final + temp[0][0] ,y_final + temp[1][0], x_final + temp[0][1], y_final + temp[1][1]); // A-B
    line(x_final + temp[0][1], y_final + temp[1][1], x_final + temp[0][2], y_final + temp[1][2]); //B - C
    line(x_final+ temp[0][2], y_final + temp[1][2], x_final + temp[0][3], y_final + temp[1][3]); // C - D
    line(x_final + temp[0][3], y_final + temp[1][3], x_final+ temp[0][0], y_final + temp[1][0]); // D - A
    line(x_final+ temp[0][3], y_final + temp[1][3], x_final + temp[0][4], y_final + temp[1][4]); // D - E
    line(x_final+ temp[0][4], y_final + temp[1][4] , x_final + temp[0][0] , y_final + temp[1][0]); // E - A
    line(x_final + temp[0][4], y_final + temp[1][4] , x_final + temp[0][1] ,y_final + temp[1][1]); // E - B
    line(x_final+ temp[0][4], y_final + temp[1][4] , x_final + temp[0][2] , y_final + temp[1][2]); // E - C
}

void printPrabaola()
{

    double x = -150;
    double y = x*x*(200.0/22500);
    while(x <= 150)
    {

        putpixel(x + 150,y + 100,15);
        x++;
        y = x*x*(200.0/22500);
    }

    double y_prev = y;
    x  = -100;
    y  = x*x*(150.0/10000);
    double k = y_prev - y;
    while(x <= 100)
    {

        putpixel(x + 400, y + k + 100,15);
        x++;
        y = x*x*(150.0/10000);
    }

    y_prev = y;
    x = -50;
    y = x*x*(100.0/2500);
    k = y_prev - y;
    while(x < 50)
    {
        putpixel(x + 550, y + k + 150,15);
        x++;
        y = x*x*(100.0/2500);
    }
}

int main()
{

  int gd,gm,x,y,z,ang,x1,x2,y1,y2;
  detectgraph(&gd,&gm);
  initgraph(&gd,&gm, nullptr);

 char c;
 int random = 0;
 while(1)
 {
    cleardevice();
    Rotation_Z();
    printPrabaola();
   Isometric_View_Projection();
    delay(50);

}

getch();
closegraph();
}

