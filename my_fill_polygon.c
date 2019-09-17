
#include <FPT.h>

int swidth, sheight ;


void swap(double *xp, double *yp) { 
    double temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 


int click_and_save (double x[], double y[]){
  
  int n;
  double P[2] ;

  G_rgb(0,1,0.5) ;
  G_fill_rectangle(0,0,swidth,20) ;

  G_rgb(1,0,0) ;
  G_wait_click(P);

  n = 0 ;
  while (P[1] > 20) {
    x[n] = P[0] ;
    y[n] = P[1] ;
    G_circle(x[n],y[n],2);
    if (n > 0){
      G_line(x[n-1],y[n-1], x[n],y[n]);
    }
    n++;
    G_wait_click(P) ;
  }

  if (n >= 1) { G_line(x[0],y[0], x[n-1],y[n-1]) ; }

  G_wait_key() ;
  return n ;
}


void my_fill_polygon(double x[], double y[], int n){


  int i = 0;
  int temp_n = n;
  int m ;
  double v[100];
  double slope, y_inter;
  int a,k,j ;
  int h ;

  
  while (i < 800){

    n = 0 ;
    a = 0 ;
    
  while(n < temp_n){

     printf("%d ",n);
     m = n + 1 ;  if (m == temp_n) { m = 0 ; }

     
     if( (y[n] > i && y[m] < i) || (y[n] < i && y[m] > i) || (y[n] >= i && y[m] < i) || (y[n] < i && y[m] >= i)) {
      
      slope = (y[n] - y[m]) / (x[n] - x[m]); 
      y_inter = y[m] - slope*x[m];
      v[a] = ((i - y_inter + 0.1) / slope); //x of intersection
      a++;

     } 

    n++ ;
  }

  
  printf("i = %d    a = %d : ",i,a) ;
  for (h = 0 ; h < a ; h++) {
    printf("%lf ",v[h]) ;
    G_rgb(0,1,0) ;
    G_circle(v[h],i,2) ;
  }
  printf("\n") ;
  usleep(15000);
  G_display_image();
  
  
  for (k = 0; k < a-1; k++){       
  
     for (j = 0; j < a-k-1; j++){
       
       if (v[j] > v[j+1]){
              swap(&v[j], &v[j+1]); 
       }
  
     }

  }


  h = 0 ; 
  while(h < a) { 
     printf("%lf",v[a]);
     G_rgb(1, 0, 0) ;
     G_line(v[h],i, v[h+1],i);
     h += 2 ;
    }

  i++;
  } // end while i



}









int main(){
  
   double n;
   double lowleftx, lowlefty, width, height ;
   double numpoints,q, x0,y0,x1,y1 ;
   double p[2] ;
   double x[1000],y[1000] ;
   // must do this before you do 'almost' any other
   // graphical tasks 
   swidth = 800 ;  sheight = 800 ;
   G_init_graphics (swidth, sheight) ;



     n = click_and_save(x,y);
     my_fill_polygon(x,y,n);
     q = G_wait_key() ; 
 

     
}
