
#include<graphics.h>
#include<conio.h>
#include<math.h>

using namespace std;
class point{
    public:
float x,y;}
;
void hermite(point p0,point p3,float p0d,float p3d,float t)
{
    p0.x*=3,p0.y*=3,p3.x*=3,p3.y*=3;
    float ansx= p0.x*(2*t*t*t- 3*t*t+1)+p3.x*(-2*t*t*t+3*t*t)+p0d*(t*t*t -2*t*t +t)+p3d*(t*t*t-t*t);
    float ansy= p0.y*(2*t*t*t- 3*t*t+1)+p3.y*(-2*t*t*t+3*t*t)+p0d*(t*t*t -2*t*t +t)+p3d*(t*t*t-t*t);
    putpixel(20+ansx,320-ansy,WHITE);
}
int main()
{
    int gdrive=DETECT,gmode;

point p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,p17,p18,p19,p20;
//one
p0.x=20,p0.y=30,p2.x=20,p2.y= 35;
p3.x=17,p3.y=20,p4.x=23,p4.y=10;

//five
p5.x=30,p5.y=35,    p6.x=32,p6.y=25,     p7.x=32,p7.y=35,    p8.x=30,p8.y=15;
p9.x=33,p9.y=20;

//nine
p10.x=40,p10.y=25,       p11.x=40,p11.y=35,           p12.x=38,p12.y=15,    p13.x=37,p13.y= 16;

//nine
p14.x=50,p14.y=25,      p15.x=50,p15.y=35,      p16.x=48,p16.y=15,    p17.x=47,p17.y=16;

//p18.x=102,p18.y=35;
//p19.x = 87,p19.y = 34, p20.x = 89, p20.y = 35;
 initgraph(&gdrive,&gmode,nullptr);

 float x = 0;

 for(x = 0; x < 200; x = x+1){

 for(float t=0.0;t<=1;t+=0.001)
 {   // one
     p0.x += x;
     p2.x += x;
     p3.x += x;
     hermite(p0,p2,-50,50,t);
       hermite(p2,p3,50,-50,t);
       hermite(p3,p4,0,0,t);
     //five
     hermite(p5,p6,0,50,t);
     hermite(p6,p7,10,0,t);
     hermite(p6,p8,0,0,t);
     hermite(p8,p9,0,80,t);

     //nine
     hermite(p10,p11,50,-50,t);
     hermite(p11,p12,10,0,t);
     hermite(p12,p13,-10,10,t);


     //nine
     hermite(p14,p15,50,-50,t);
     hermite(p15,p16,10,0,t);
     hermite(p16,p17,-10,10,t);
 }
 cleardevice();
 delay(1000);

 }
  getche();
    return 0;
}



