


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


void increasex(float x)
{
/*    p0.x += x;
     p2.x += x;
     p3.x += x;
     p4.x += x;
     p5.x += x;
     p6.x += x;
     p7.x += x;
     p8.x += x;
     p9.x += x;
     p10.x += x;
     p11.x += x;
     p12.x += x;
     p13.x += x;
     p14.x += x;
     p15.x += x;
     p16.x += x;
     p17.x += x;
*/
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

 float x = 0,y = 0;

 int flag = 1;
while(1)
{

   if(flag == 1)
   {
       x += 0.5;
   }
   if(x > 9 && flag == 1)
   {
       flag = 2;
       //exit(1);
   }
   if(flag == 2)
   {
       y += 1;
      x = 0;
   }
   if( y > 11 && flag == 2)
   {
       flag = 3;
   }
   if(flag == 3)
   {
       y +=  (205 - 105)/(60 - getmaxx()/2);
       x = x - 0.5;
   }

   if( x < -13 && flag == 3)
   {

       flag = 4;
   }
   if(flag == 4)
   {

       y -= 0.5;
       x += 1/ ((205 - 60) / (105 - getmaxx()/4));
   }
   /*
   if(y < 0 && flag == 4)
   {
       x = 0;
       y= 0;
   }
*/
    p0.x += x;
     p2.x += x;
     p3.x += x;
     p4.x += x;
     p5.x += x;
     p6.x += x;
     p7.x += x;
     p8.x += x;
     p9.x += x;
     p10.x += x;
     p11.x += x;
     p12.x += x;
     p13.x += x;
     p14.x += x;
     p15.x += x;
     p16.x += x;
     p17.x += x;

         p0.y += y;
     p2.y += y;
     p3.y += y;
     p4.y += y;
     p5.y += y;
     p6.y += y;
     p7.y += y;
     p8.y += y;
     p9.y += y;
     p10.y += y;
     p11.y += y;
     p12.y += y;
     p13.y += y;
     p14.y += y;
     p15.y += y;
     p16.y += y;
     p17.y += y;


    line(60,205,getmaxx()/2,205);
    line(getmaxx()/2,205,(getmaxx()/2),105);
    line((getmaxx()/2),105,60,205);


 for(float t=0.0;t<=1;t+=0.001)
 {   // one
     hermite(p0,p2,-50,50,t);
       hermite(p2,p3,50,-50,t);
       hermite(p3,p4,0,0,t);
     //five
     hermite(p5,p6,0,50,t);
     hermite(p6,p7,10,0,t);
     hermite(p6,p8,0,0,t);
     he.rmite(p8,p9,0,80,t);

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
 delay(100);

 }
  getche();
    return 0;
}




