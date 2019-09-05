
#include <FPT.h>   

int main()
{
   double swidth, sheight ;
   double lowleftx, lowlefty, width, height ;
   double x[10],y[10] ;
   double numpoints,q, x0,y0,x1,y1,x_dif,y_dif,rad;
   double p[2],new_sin,n,angle,extra;

   // must do this before you do 'almost' any other
   // graphical tasks 
   swidth = 400 ;  sheight = 400;
   G_init_graphics (swidth, sheight);


   // draw a point, a line, some rectangles, some triangles 

   G_rgb(0, 0, 1) ;  // blue

   G_wait_click(p) ;   // wait for a mouse click
   x0 = p[0] ; y0 = p[1] ; // extract coordinates
   G_point(x0, y0);
   G_wait_click(p) ;   // wait for a mouse click
   x1 = p[0] ; y1 = p[1] ; // extract coordinates
   G_point(x1, y1);
   x_dif = abs(x0 - x1);
   y_dif = abs(y0 - y1);
   rad = x_dif*x_dif + y_dif*y_dif;
   rad = sqrt(rad);
   G_circle (x0, y0, rad) ;

   int i = 0;
     
   while(1==1){

     for (i = 0; i<16; i++){
       angle = i*2*M_PI/16;
       G_line(x0,y0, x0 + (cos(angle+extra)*rad), y0 + (sin(angle+extra)*rad));
     }


     extra+=.001;
     G_display_image();
     usleep(30000);
     
     
   }

 

   q = G_wait_key() ;    // pause again before exit 

   G_save_image_to_file ("t01c.xwd") ;

   G_close() ; // terminate graphics...probably not fatal if forgotten
   

 

}



