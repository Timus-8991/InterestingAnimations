#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

using namespace std;

class coordinates{
    public:
double x_component;
double y_component;
double z_component;

     coordinates(double x,double y,double z)
     {
         this->x_component = x;
         this->y_component = y;
         this->z_component = z;
     }
     coordinates()
     {
         x_component = 0;
         y_component = 0;
         z_component = 0;
     }

     void setter(double x, double y, double z)
     {

         this -> x_component = x;
         this -> y_component = y;
         this -> z_component = z;
     }
};

coordinates normal[5];
coordinates centroid[5];
coordinates FV_Camera(0,0,300);

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

bool check_samedirection(coordinates n1, coordinates n2);
void Front_View_Projection()
{
    rand_color = 1 + rand()%15;
    setcolor(rand_color);

    //ABCD
    coordinates tempvector1 (centroid[0].x_component - FV_Camera.x_component , centroid[0].y_component - FV_Camera.y_component, centroid[0].z_component - FV_Camera.z_component);
    if(!check_samedirection(normal[0],tempvector1))
    {
    line(319 + prism[0][0] , 119 + prism[1][0], 319 + prism[0][1], 119 + prism[1][1]); // A-B
    line( 319 + prism[0][1], 119 + prism[1][1], 319 + prism[0][2], 119 + prism[1][2]); //B - C
    line(319 + prism[0][2], 119 + prism[1][2], 319 + prism[0][3], 119 + prism[1][3]); // C - D
    line(319 + prism[0][3], 119 + prism[1][3], 319 + prism[0][0], 119 + prism[1][0]); // D - A

    }


    //ABE
    coordinates tempvector2(centroid[1].x_component - FV_Camera.x_component , centroid[1].y_component - FV_Camera.y_component, centroid[1].z_component - FV_Camera.z_component);
    if(check_samedirection(normal[1],tempvector2) == 0)
    {
    line(319 + prism[0][4], 119 + prism[1][4] , 319 + prism[0][0] , 119 + prism[1][0]); // E - A
    line(319 + prism[0][4], 119 + prism[1][4] , 319 + prism[0][1] , 119 + prism[1][1]); // E - B
    line(319 + prism[0][0] , 119 + prism[1][0], 319 + prism[0][1], 119 + prism[1][1]); // A-B
    }


    //BCE
    coordinates tempvector3(centroid[2].x_component - FV_Camera.x_component , centroid[2].y_component - FV_Camera.y_component, centroid[2].z_component - FV_Camera.z_component);
    if( !check_samedirection(normal[2],tempvector3))
    {
     line(319 + prism[0][4], 119 + prism[1][4] , 319 + prism[0][1] , 119 + prism[1][1]); // E - B
    line(319 + prism[0][4], 119 + prism[1][4] , 319 + prism[0][2] , 119 + prism[1][2]); // E - C
    line( 319 + prism[0][1], 119 + prism[1][1], 319 + prism[0][2], 119 + prism[1][2]); //B - C
    }

    //CDE
    coordinates tempvector4(centroid[3].x_component - FV_Camera.x_component , centroid[3].y_component - FV_Camera.y_component, centroid[3].z_component - FV_Camera.z_component);
    if(!check_samedirection(normal[3],tempvector4))
    {
    line(319 + prism[0][2], 119 + prism[1][2], 319 + prism[0][3], 119 + prism[1][3]); // C - D
    line(319 + prism[0][3], 119 + prism[1][3], 319 + prism[0][4], 119 + prism[1][4]); // D - E
    line(319 + prism[0][4], 119 + prism[1][4] , 319 + prism[0][2] , 119 + prism[1][2]); // E - C
    }

    //DAE
    coordinates tempvector5(centroid[4].x_component - FV_Camera.x_component , centroid[4].y_component - FV_Camera.y_component, centroid[4].z_component - FV_Camera.z_component);
    if(!check_samedirection(normal[4],tempvector5))
    {
    line(319 + prism[0][3], 119 + prism[1][3], 319 + prism[0][0], 119 + prism[1][0]); // D - A
    line(319 + prism[0][3], 119 + prism[1][3], 319 + prism[0][4], 119 + prism[1][4]); // D - E
    line(319 + prism[0][4], 119 + prism[1][4] , 319 + prism[0][0] , 119 + prism[1][0]); // E - A
    }
}

bool check_samedirection(coordinates n1,  coordinates n2)
{

    double dot_product= n1.x_component * n2.x_component + n1.y_component * n2.y_component + n1.z_component * n2.z_component;
    if(dot_product > 0)
        return true;
    else return false;
}


void find_Centroid()
{
    //ABCD
    centroid[0].x_component = (prism[0][0] + prism[0][1] + prism[0][2] + prism[0][3])/3;
    centroid[0].y_component = (prism[1][0] + prism[1][1] + prism[1][2] + prism[1][3])/3;
    centroid[0].z_component = (prism[2][0] + prism[2][1] + prism[2][2] + prism[2][3])/3;

    //ABE
    centroid[1].x_component = (prism[0][0] + prism[0][1] + prism[0][4])/3;
    centroid[1].y_component = (prism[1][0] + prism[1][1] + prism[1][4])/3;
    centroid[1].z_component = (prism[2][0] + prism[2][1] + prism[2][4])/3;

    //BCE
    centroid[2].x_component = (prism[0][1] + prism[0][2] + prism[0][4])/3;
    centroid[2].y_component = (prism[1][1] + prism[1][2] + prism[1][4])/3;
    centroid[2].z_component = (prism[2][1] + prism[2][2] + prism[2][4])/3;

    //CDE
    centroid[3].x_component = (prism[0][2] + prism[0][3] + prism[0][4])/3;
    centroid[3].y_component = (prism[1][2] + prism[1][3] + prism[1][4])/3;
    centroid[3].z_component = (prism[2][2] + prism[2][3] + prism[2][4])/3;

    //DAE
    centroid[4].x_component = (prism[0][0] + prism[0][3] + prism[0][4])/3;
    centroid[4].y_component = (prism[1][0] + prism[1][3] + prism[1][4])/3;
    centroid[4].z_component = (prism[2][0] + prism[2][3] + prism[2][4])/3;

}

void find_normals()
{

    //for ABCD
    coordinates temp_vector1(prism[0][0] - prism[0][1] , prism[1][0] - prism[1][1], prism[2][0] - prism[2][1]); //A-B
    coordinates temp_vector2(prism[0][1] - prism[0][2] , prism[1][1] - prism[1][2], prism[2][1] - prism[2][2]); //B-C
    normal[0].x_component = temp_vector1.y_component * temp_vector2.z_component - temp_vector1.z_component*temp_vector2.y_component;
    normal[0].y_component = -(temp_vector1.x_component * temp_vector2.z_component - temp_vector1.z_component * temp_vector2.x_component);
    normal[0].z_component = temp_vector1.x_component * temp_vector2.y_component - temp_vector1.y_component * temp_vector2.x_component;
    coordinates E_A ( prism[0][4] - prism[0][0] , prism[1][4] - prism[1][0], prism[2][4] - prism[2][0]);
     if(check_samedirection(normal[0],E_A))
       {
        normal[0].x_component = -normal[0].x_component;
        normal[0].y_component = -normal[0].y_component;
        normal[0].z_component = -normal[0].z_component;
       }

  //ABE
  temp_vector1.setter(prism[0][0] - prism[0][1] , prism[1][0] - prism[1][1], prism[2][0] - prism[2][1]); // A-B
 temp_vector2.setter(prism[0][1] - prism[0][4] , prism[1][1] - prism[1][4], prism[2][1] - prism[2][4]); // B - E
    normal[1].x_component = temp_vector1.y_component * temp_vector2.z_component - temp_vector1.z_component*temp_vector2.y_component;
    normal[1].y_component = -(temp_vector1.x_component * temp_vector2.z_component - temp_vector1.z_component * temp_vector2.x_component);
    normal[1].z_component = temp_vector1.x_component * temp_vector2.y_component - temp_vector1.y_component * temp_vector2.x_component;
    coordinates D_A (prism[0][3] - prism[0][0] , prism[1][3] - prism[1][0], prism[2][3] - prism[2][0]);
    if(check_samedirection(normal[1],D_A))
       {
         normal[1].x_component = -normal[1].x_component;
        normal[1].y_component = -normal[1].y_component;
        normal[1].z_component = -normal[1].z_component;
       }

    //BCE
     temp_vector1.setter(prism[0][1] - prism[0][2] , prism[1][1] - prism[1][2], prism[2][1] - prism[2][2]); // B-C
    temp_vector2.setter(prism[0][2] - prism[0][4] , prism[1][2] - prism[1][4], prism[2][2] - prism[2][4]); // C -E
    normal[2].x_component = temp_vector1.y_component * temp_vector2.z_component - temp_vector1.z_component*temp_vector2.y_component;
    normal[2].y_component = -(temp_vector1.x_component * temp_vector2.z_component - temp_vector1.z_component * temp_vector2.x_component);
    normal[2].z_component = temp_vector1.x_component * temp_vector2.y_component - temp_vector1.y_component * temp_vector2.x_component;
    coordinates A_B (prism[0][0] - prism[0][1] , prism[1][0] - prism[1][1], prism[2][0] - prism[2][1]);
    if(check_samedirection(normal[2],A_B))
       {
         normal[2].x_component = -normal[2].x_component;
        normal[2].y_component = -normal[2].y_component;
        normal[2].z_component = -normal[2].z_component;
       }

     //CDE
     temp_vector1.setter(prism[0][2] - prism[0][3] , prism[1][2] - prism[1][3], prism[2][2] - prism[2][3]); // C-D
     temp_vector2.setter(prism[0][3] - prism[0][4] , prism[1][3] - prism[1][4], prism[2][3] - prism[2][4]); // D-E
    normal[3].x_component = temp_vector1.y_component * temp_vector2.z_component - temp_vector1.z_component*temp_vector2.y_component;
    normal[3].y_component = -(temp_vector1.x_component * temp_vector2.z_component - temp_vector1.z_component * temp_vector2.x_component);
    normal[3].z_component = temp_vector1.x_component * temp_vector2.y_component - temp_vector1.y_component * temp_vector2.x_component;
    coordinates A_D (prism[0][0] - prism[0][3] , prism[1][0] - prism[1][3], prism[2][0] - prism[2][3]);
     if(check_samedirection(normal[3],A_D))
       {
         normal[3].x_component = -normal[3].x_component;
        normal[3].y_component = -normal[3].y_component;
        normal[3].z_component = -normal[3].z_component;
       }

    //ADE
     temp_vector1.setter(prism[0][0] - prism[0][3] , prism[1][0] - prism[1][3], prism[2][0] - prism[2][3]); // A-D
     temp_vector2.setter(prism[0][3] - prism[0][4] , prism[1][3] - prism[1][4], prism[2][3] - prism[2][4]); // D-E
    normal[4].x_component = temp_vector1.y_component * temp_vector2.z_component - temp_vector1.z_component*temp_vector2.y_component;
    normal[4].y_component = -(temp_vector1.x_component * temp_vector2.z_component - temp_vector1.z_component * temp_vector2.x_component);
    normal[4].z_component = temp_vector1.x_component * temp_vector2.y_component - temp_vector1.y_component * temp_vector2.x_component;
    coordinates B_A (prism[0][1] - prism[0][0] , prism[1][1] - prism[1][0], prism[2][1] - prism[2][0]);
    if(check_samedirection(normal[4],B_A))
       {
         normal[4].x_component = -normal[4].x_component;
        normal[4].y_component = -normal[4].y_component;
        normal[4].z_component = -normal[4].z_component;
       }
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
    find_normals();
    find_Centroid();
    Front_View_Projection();
    delay(100);
}

getch();
closegraph();
}

