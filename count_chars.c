
#include <FPT.h>
#include <stdio.h>
#include <stdlib.h>

int numobjects;
int numpoints[10];
double x[10][1500], y[10][1500];
double dx[1500], dy[1500];
int numpolys[10];
int psize[10][1000];
int con[10][1000][20];
double red[10][1000],grn[10][1000],blu[10][1000];


void translate(int onum, double dx, double dy){

  for(int i = 0; i < numpoints[onum]; i++){

    x[onum][i] += dx;
    y[onum][i] += dy;

  }

}


void scale(int onum, double sx, double sy){

  for(int i = 0; i < numpoints[onum]; i++){

    x[onum][i] *= sx;
    y[onum][i] *= sy;

  }

}




void draw(int onum){

  double xp[100], yp[100];
  int i,pnum,n,temp_n;
  double redd,grnn,bluu;
  


  G_rgb (1,1,1);
  G_clear();
  
  printf("onum = %d\n",onum) ;
  printf("numpolys = %d\n",numpolys[onum]);

  
  for(pnum = 0; pnum < numpolys[onum]; pnum++){

    n = psize[onum][pnum];

    for(i = 0; i < n; i++){
      temp_n = con[onum][pnum][i];      
      xp[i] = x[onum][temp_n];
      yp[i] = y[onum][temp_n];
      printf("(%lf, %lf) ",xp[i],yp[i]);
    }
    printf("\n") ;

    redd = red[onum][pnum];
    grnn = grn[onum][pnum];
    bluu = blu[onum][pnum];

    G_rgb (redd, grnn, bluu);


    G_fill_polygon (xp,yp,i);
    
  }


}



 


int main(int argc, char **argv){


   G_init_graphics(800,800);
   G_rgb(0,0,0);
   G_clear;
   G_rgb(0,1,0);
    
   int i,onum,count,j,w,pnum,n;
   double xtrans,ytrans,yhi,ylo,xhi,xlo,sclr;
   ylo = 1000;
   xlo = 1000;

  FILE *fp;

  numobjects = argc - 1 ;
  
  for(onum=0; onum < numobjects; onum++){
  
  fp = fopen(argv[onum+1], "r");
  
  if(fp == NULL){
    printf("cant open file %s \n", argv[onum+1]);
    exit(0);
  }
  
  fscanf(fp, "%d", &numpoints[onum]);
  
  for(i=0; i < numpoints[onum]; i++){
    fscanf(fp, "%lf %lf", &x[onum][i], &y[onum][i]);
  }

   fscanf(fp, "%d", &numpolys[onum]);

   for(i=0; i < numpolys[onum]; i++){

    fscanf(fp, "%d", &psize[onum][i]);
    
    for(j=0; j < psize[onum][i]; j++){
     fscanf(fp, "%d", &con[onum][i][j]);
    }
   }

    for(i=0; i < numpolys[onum]; i++){
      fscanf(fp, "%lf %lf %lf", &red[onum][i], &grn[onum][i], &blu[onum][i]);
    }
  

  }

  for(j=0; j<numobjects; j++){

   for(pnum = 0; pnum < numpolys[j]; pnum++){

    n = psize[j][pnum];

    for(i = 0; i < n; i++){

      if(x[j][i] > xhi){
	xhi = x[j][i];
      }

      if(y[j][i] > yhi){
	yhi = y[j][i];
      }

      if(x[j][i] < xlo){
	xlo = x[j][i];
      }

      if(y[j][i] < ylo){
	ylo = y[j][i];
      }

    }
   }
 
    ytrans = (yhi + ylo) / 2;
    xtrans = (xhi + xlo) / 2;
    printf("xhi = %lf, yhi = %lf, xlo = %lf, ylo = %lf",xhi,yhi,xlo,ylo);  
  
  translate(j,-xtrans,-ytrans);

  if(xtrans >= ytrans){

    sclr = (800 / ytrans);
    
  } else{

    sclr = (800 / xtrans);
    
  }

  
  scale(j,sclr,sclr);
  translate(j,400,400);
  
  }

 

  while(1){


  
  w = G_wait_key();
  onum = w-49;

  
  draw(onum);


  
  }
  
    G_wait_key() ;
    
}
