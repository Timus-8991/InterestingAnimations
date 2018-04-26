
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
p0.x=20,p0.y=50,p2.x=20,p2.y= 30;
p3.x=17,p3.y=10,p4.x=40,p4.y=30;
p5.x=50,p5.y=30,p6.x=53,p6.y=20,p7.x=56,p7.y=30,p8.x=60,p8.y=15;
p9.x=65,p9.y=30,p10.x=70,p10.y=15,p11.x=75,p11.y=30,p12.x=80,p12.y=15;
p13.x=87,p13.y= 30,p14.x=90,p14.y=15,p15.x=97,p15.y=50,p16.x=100,p16.y=15;
p17.x=91,p17.y=35,p18.x=102,p18.y=35;
p19.x = 87,p19.y = 34, p20.x = 89, p20.y = 35;
 initgraph(&gdrive,&gmode,nullptr);

 for(float t=0.0;t<=1;t+=0.001)
 {     hermite(p0,p2,-100,100,t);
       hermite(p2,p3,50,-200,t);
       hermite(p4,p5,0,200,t);
       hermite(p5,p6,0,100,t);
       hermite(p7,p8,100,0,t);
       hermite(p8,p9,0,100,t);
       hermite(p9,p10,100,0,t);
       hermite(p10,p11,0,100,t);
       hermite(p11,p12,100,0,t);
       hermite(p13,p14,0,50,t);
       hermite(p19,p20,0,50,t);
       hermite(p15,p16,0,100,t);
       hermite(p17,p18,0,0,t);

 }

  getche();
    return 0;
}


