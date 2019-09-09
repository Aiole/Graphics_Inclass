
#include <FPT.h> 


void click_and_save(double x[], double y[]){

  

}

int main(){

  double p[2],x[100],y[100],swidth,sheight;
  int i = 0;

  
  swidth = 800 ;  sheight = 800;
  G_init_graphics (swidth, sheight);
  
  while(1){
    
  G_rgb(0, 0, 1);  // blue
 
  
  G_wait_click(p);   // wait for a mouse click
  x[i] = p[0]; y[i] = p[1]; // extract coordinates
  
  if(x[i] < 25 && y[i] < 25){
    break;
  }
  
  G_fill_circle (x[i], y[i], 5);
  
  if(i>0){
    printf("here");
    G_rgb(0, 1, 0);
    G_line(x[i],y[i],x[i-1],y[i-1]);
    G_rgb(0, 0, 1);  // blue
  }

  
  i++;
  
  }


   G_rgb(0, 1, 0);
   G_line(x[i-1],y[i-1],x[0],y[0]);
   G_wait_key();  

  

  
}

  
