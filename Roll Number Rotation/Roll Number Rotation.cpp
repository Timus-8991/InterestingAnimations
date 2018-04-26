#include<cmath>
#include<iostream>
#include<graphics.h>
using namespace std;
#define ox 318
#define oy 240


void line2(int x1,int y1,int x2,int y2){
    line(x1,y1,x2,y2);
    line(x1,y1,x1+5,y1);
    line(x2,y2,x2+10,y2);
    line(x1+10,y1,x2+10,y2);
    line(x2+10,y2,x2+14,y2-4);
    line(x2+14,y2-4,x1+14,y1-4);
    line(x1+10,y1,x1+14,y1-4);
    line(x1+14,y1-4,x1+4,y1-4);
    line(x1,y1,x1+4,y1-4);
}

float theta ;
float mul[4][19];
float obj[4][19] = {-160,-160,-40,-80,-80,-40,-40,-80,80,40,80,40,80,40,200,160,200,160,200,
                       -80,80,-80,-80,0,  0,  80,80,-80,-80,0,0,80,80,-80,-80,0,0,80,
                       0,  0, 0,  0,0,  0,   0,  0,  0, 0,0, 0, 0, 0,  0, 0,0,0, 0,
                        1,  1, 1, 1,1,   1,  1,   1,  1, 1,1, 1,1,  1,  1, 1,1,1,1};


float temp[4][19];


float roty[4][4] = {cos(theta),0,sin(theta),0,
                0,1,0,0,
                -sin(theta),0,cos(theta),0,
                0,0,0,1};

float rotz[4][4] = {cos(theta),-sin(theta),0,0,
                sin(theta),cos(theta),0,0,
                0,0,1,0,
                0,0,0,1};

float rotx[4][4] = {1,0,0,0,
                0,cos(theta),-sin(theta),0,
                0,sin(theta),cos(theta),0,
                0,0,0,1};

void xrotate(){
    float t[4][4] = {1,0,0,0,
                0,cos(theta),-sin(theta),0,
                0,sin(theta),cos(theta),0,
                0,0,0,1};

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            rotx[i][j] = t[i][j];
        }
    }
}


void yrotate(){

 float t[4][4] = {cos(theta),0,sin(theta),0,
                0,1,0,0,
                -sin(theta),0,cos(theta),0,
                0,0,0,1};

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            roty[i][j] = t[i][j];
        }
    }

}


void zrotate(){

float t[4][4] = {cos(theta),-sin(theta),0,0,
                sin(theta),cos(theta),0,0,
                0,0,1,0,
                0,0,0,1};

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            rotz[i][j] = t[i][j];
        }
    }

}

void mult(float a[4][4],float b[4][19]){
    float r1, c1, r2, c2;
    int  i, j, k;
    r1 = 4;
    c1 = 4;
    r2 = 4;
    c2 = 19;
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
            mul[i][j]=0;

    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
            for(k = 0; k < c1; ++k)
                mul[i][j] += a[i][k] * b[k][j];
}

void front_view(float obj[4][19]){
    line2(ox+obj[0][0],oy+obj[1][0],ox+obj[0][1],oy+obj[1][1]);
    line2(ox+obj[0][2],oy+obj[1][2],ox+obj[0][3],oy+obj[1][3]);
    line2(ox+obj[0][3],oy+obj[1][3],ox+obj[0][4],oy+obj[1][4]);
    line2(ox+obj[0][4],oy+obj[1][4],ox+obj[0][5],oy+obj[1][5]);
    line2(ox+obj[0][5],oy+obj[1][5],ox+obj[0][6],oy+obj[1][6]);
    line2(ox+obj[0][6],oy+obj[1][6],ox+obj[0][7],oy+obj[1][7]);
    line2(ox+obj[0][8],oy+obj[1][8],ox+obj[0][9],oy+obj[1][9]);
    line2(ox+obj[0][9],oy+obj[1][9],ox+obj[0][11],oy+obj[1][11]);
    line2(ox+obj[0][11],oy+obj[1][11],ox+obj[0][10],oy+obj[1][10]);
    line2(ox+obj[0][10],oy+obj[1][10],ox+obj[0][8],oy+obj[1][8]);
    line2(ox+obj[0][10],oy+obj[1][10],ox+obj[0][12],oy+obj[1][12]);
    line2(ox+obj[0][14],oy+obj[1][14],ox+obj[0][15],oy+obj[1][15]);
    line2(ox+obj[0][15],oy+obj[1][15],ox+obj[0][17],oy+obj[1][17]);
    line2(ox+obj[0][17],oy+obj[1][17],ox+obj[0][16],oy+obj[1][16]);
    line2(ox+obj[0][16],oy+obj[1][16],ox+obj[0][14],oy+obj[1][14]);
    line2(ox+obj[0][16],oy+obj[1][16],ox+obj[0][18],oy+obj[1][18]);
}
int main(){
    int gd=DETECT,gm;
    initgraph(&gd,&gm,nullptr);
    front_view(obj);
        getch();
       for( theta = 0;;theta+=0.1){
        cleardevice();
        xrotate();
        mult(rotx,obj);
        front_view(mul);
        delay(100);

    }
    return 0;
}

