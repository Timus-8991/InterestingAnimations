#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

using namespace std;


double prism[4][5] = {-25 ,25 , 25, -25,0,  25, 25, -25, -25,0, 0, 0, 0, 0,100, 1, 1, 1, 1,1};
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

//Rotation about X-axis
void Rotation_X()
{
    double r_x_matrix[4][4] = { 1, 0, 0, 0, 0, cos(theta), -sin(theta), 0, 0, sin(theta), cos(theta), 0, 0, 0, 0, 1};
    mult(r_x_matrix,prism);
}

//Rotation about Y-axis
void Rotation_Y()
{

    double r_y_matrix[4][4] = {cos(theta),0,sin(theta),0,0,1,0,0,-sin(theta),0,cos(theta),0,0,0,0,1};
    mult(r_y_matrix,prism);
}

//Rotation about Z-axis
void Rotation_Z()
{
   double r_z_matrix[4][4] = {cos(theta),-sin(theta),0,0,sin(theta),cos(theta),0,0,0,0,1,0,0,0,0,1};
   mult(r_z_matrix,prism);
}



void Front_View_Projection()
{
    setcolor(15);
    line(213,0,213,479);
    line(426,0,426,479);
    line(0,238,639,238);

    rand_color = 1 + rand()%15;
    setcolor(rand_color);
    line(319 + prism[0][0] , 119 + prism[1][0], 319 + prism[0][1], 119 + prism[1][1]); // A-B
    line( 319 + prism[0][1], 119 + prism[1][1], 319 + prism[0][2], 119 + prism[1][2]); //B - C
    line(319 + prism[0][2], 119 + prism[1][2], 319 + prism[0][3], 119 + prism[1][3]); // C - D
    line(319 + prism[0][3], 119 + prism[1][3], 319 + prism[0][0], 119 + prism[1][0]); // D - A
    line(319 + prism[0][3], 119 + prism[1][3], 319 + prism[0][4], 119 + prism[1][4]); // D - E
    line(319 + prism[0][4], 119 + prism[1][4] , 319 + prism[0][0] , 119 + prism[1][0]); // E - A
    line(319 + prism[0][4], 119 + prism[1][4] , 319 + prism[0][1] , 119 + prism[1][1]); // E - B
    line(319 + prism[0][4], 119 + prism[1][4] , 319 + prism[0][2] , 119 + prism[1][2]); // E - C

}


void Top_View_Projection()
{
    rand_color = 1 + rand()%15;
    setcolor(rand_color);

    line(106 + prism[0][0] , 119 + prism[2][0], 106 + prism[0][1], 119 + prism[2][1]); // A-B
    line( 106 + prism[0][1], 119 + prism[2][1], 106 + prism[0][2], 119 + prism[2][2]); //B - C
    line(106 + prism[0][2], 119 + prism[2][2], 106 + prism[0][3], 119 + prism[2][3]); // C - D
    line(106 + prism[0][3], 119 + prism[2][3], 106 + prism[0][0], 119 + prism[2][0]); // D - A
    line(106 + prism[0][3], 119 + prism[2][3], 106 + prism[0][4], 119 + prism[2][4]); // D - E
    line(106 + prism[0][4], 119 + prism[2][4] , 106 + prism[0][0] , 119 + prism[2][0]); // E - A
    line(106 + prism[0][4], 119 + prism[2][4] , 106  + prism[0][1] , 119 + prism[2][1]); // E - B
    line(106 + prism[0][4], 119 + prism[2][4] , 106 + prism[0][2] , 119 + prism[2][2]); // E - C

}

void Side_View_Projection()
{
    rand_color = 1 + rand()%15;
    setcolor(rand_color);

    line(532 + prism[2][0] , 119 + prism[1][0], 532 + prism[2][1], 119 + prism[1][1]); // A-B
    line(532 + prism[2][1], 119 + prism[1][1], 532 + prism[2][2], 119 + prism[1][2]); //B - C
    line(532 + prism[2][2], 119 + prism[1][2], 532 + prism[2][3], 119 + prism[1][3]); // C - D
    line(532 + prism[2][3], 119 + prism[1][3], 532 + prism[2][0], 119 + prism[1][0]); // D - A
    line(532 + prism[2][3], 119 + prism[1][3], 532 + prism[2][4], 119 + prism[1][4]); // D - E
    line(532 + prism[2][4], 119 + prism[1][4] , 532 + prism[2][0] , 119 + prism[1][0]); // E - A
    line(532 + prism[2][4], 119 + prism[1][4] , 532 + prism[2][1] , 119 + prism[1][1]); // E - B
    line(532 + prism[2][4], 119 + prism[1][4] , 532 + prism[2][2] , 119 + prism[1][2]); // E - C
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

    rand_color = 1 + rand()%15;
    setcolor(rand_color);

    line(106 + temp[0][0] , 357 + temp[1][0], 106 + temp[0][1], 357 + temp[1][1]); // A-B
    line(106 + temp[0][1], 357 + temp[1][1], 106 + temp[0][2], 357 + temp[1][2]); //B - C
    line(106 + temp[0][2], 357 + temp[1][2], 106 + temp[0][3], 357 + temp[1][3]); // C - D
    line(106 + temp[0][3], 357 + temp[1][3], 106 + temp[0][0], 357 + temp[1][0]); // D - A
    line(106 + temp[0][3], 357 + temp[1][3], 106 + temp[0][4], 357 + temp[1][4]); // D - E
    line(106 + temp[0][4], 357 + temp[1][4] , 106 + temp[0][0] , 357 + temp[1][0]); // E - A
    line(106 + temp[0][4], 357 + temp[1][4] , 106  + temp[0][1] ,357 + temp[1][1]); // E - B
    line(106 + temp[0][4], 357 + temp[1][4] , 106 + temp[0][2] , 357 + temp[1][2]); // E - C
}



void Dimetric_View_Projection()
{

    double dimetric[4][4] = {0.866,0,0.5,0,0.25,0.866,-0.25,0,0,0,0,0,0,0,0,1};

    double temp[4][5] = {0};
     for(int i = 0;i < 4; ++i)
    {
        for(int j = 0;j < 5; ++j)
        {
            for(int k = 0;k < 4; ++k)
            {

                temp[i][j] += dimetric[i][k] * prism[k][j] ;
            }
        }
    }


    rand_color = 1 + rand()%15;
    setcolor(rand_color);


    line(319 + temp[0][0] , 357 + temp[1][0], 319 + temp[0][1], 357 + temp[1][1]); // A-B
    line(319 + temp[0][1], 357 + temp[1][1], 319 + temp[0][2], 357 + temp[1][2]); //B - C
    line(319 + temp[0][2], 357 + temp[1][2], 319 + temp[0][3], 357 + temp[1][3]); // C - D
    line(319 + temp[0][3], 357 + temp[1][3], 319 + temp[0][0], 357 + temp[1][0]); // D - A
    line(319 + temp[0][3], 357 + temp[1][3], 319 + temp[0][4], 357 + temp[1][4]); // D - E
    line(319 + temp[0][4], 357 + temp[1][4] , 319 + temp[0][0] , 357 + temp[1][0]); // E - A
    line(319 + temp[0][4], 357 + temp[1][4] , 319  + temp[0][1] ,357 + temp[1][1]); // E - B
    line(319 + temp[0][4], 357 + temp[1][4] , 319 + temp[0][2] , 357 + temp[1][2]); // E - C
}

void Perspective_View()
{
    double persp[4][4] = {100,0,0,0,
                    0,100,0,0,
                    0,0,-100,-20000,
                    0,0,1,200};

    double temp[4][5] = {0};
     for(int i = 0;i < 4; ++i)
    {
        for(int j = 0;j < 5; ++j)
        {
            for(int k = 0;k < 4; ++k)
            {

                temp[i][j] += persp[i][k] * prism[k][j] ;
            }
        }
    }

     for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            temp[i][j] /= (75+abs(prism[2][j]));
        }
     }

    rand_color = 1 + rand()%15;
    setcolor(rand_color);

    line(532 + temp[0][0] , 357 + temp[1][0], 532 + temp[0][1], 357 + temp[1][1]); // A-B
    line(532 + temp[0][1], 357 + temp[1][1], 532 + temp[0][2], 357 + temp[1][2]); //B - C
    line(532 + temp[0][2], 357 + temp[1][2], 532 + temp[0][3], 357 + temp[1][3]); // C - D
    line(532 + temp[0][3], 357 + temp[1][3], 532 + temp[0][0], 357 + temp[1][0]); // D - A
    line(532 + temp[0][3], 357 + temp[1][3], 532+ temp[0][4], 357 + temp[1][4]); // D - E
    line(532 + temp[0][4], 357 + temp[1][4] , 532 + temp[0][0] , 357 + temp[1][0]); // E - A
    line(532 + temp[0][4], 357 + temp[1][4] , 532  + temp[0][1] ,357 + temp[1][1]); // E - B
    line(532 + temp[0][4], 357 + temp[1][4] , 532 + temp[0][2] , 357 + temp[1][2]); // E - C


}


int main()
{

  int gd,gm,x,y,z,ang,x1,x2,y1,y2;
  detectgraph(&gd,&gm);
  initgraph(&gd,&gm, nullptr);

 char c;
 while(1)
 {

    c = getch();
    if(c == 'x' || c == 'X')
     Rotation_X();
    else if(c == 'y' || c == 'Y')
      Rotation_Y();
    else if(c == 'z' || c == 'Z')
       Rotation_Z();

    cleardevice();
    Front_View_Projection();
    Top_View_Projection();
    Side_View_Projection();
    Isometric_View_Projection();
    Dimetric_View_Projection();
    Perspective_View();

    delay(100);

}

getch();
closegraph();
}
