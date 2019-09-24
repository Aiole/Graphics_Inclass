
#include <FPT.h>
#include <stdio.h>
#include <stdlib.h>

int numobjects;
int numpoints[10];
double x[10][1500], y[10][1500];
int numpolys[10];
int psize[10][10][1000];
int con[10][1000][20];
double red[10][1000],grn[10][1000],blu[10][1000];


void translate(int onum, double dx, double dy){

  for(int i = 0; i < numpoint[onum]; i++){

    x[onum][i] += dx;
    y[onum][i] += dy;

  }

}


void scale(int onum, double sx, double sy){

  for(i=0; i < numpoints[onum]; i++){

    x[onum][i] *= sx;
    y[onum][i] *= sy;

  }

}


int main(int argc, char **argv){


   G_init_graphics(800,800);
   G_rgb(0,0,0);
   G_clear;
   G_rgb(0,1,0);
    
  int i,k,count,j;

  FILE *fp;

  for(k=0; k < numobjects; k++){
  
  fp = fopen(argv[k+1], "r");
  
  if(fp == NULL){

    printf("cant open file %s \n", argv[2]);
    exit(0);
  }
  
  fscanf(fp, "%d", &numpoints[k]);
  
  for(i=0; i < *numpoints; i++){

    fscanf(fp, "%lf %lf", &x[k][i], &y[k][i]);
    
  }

   fscanf(fp, "%d", &numpolys[k]);

   for(i=0; i < numpolys[k]; i++){

    fscanf(fp, "%d", &psize[k][i][j]);
    
    for(j=0; j < *psize[k][i]; j++){
     fscanf(fp, "%d", &con[k][i][j]);


    }
   }

    for(i=0; i < numpolys[k]; i++){
      fscanf(fp, "%lf %lf %lf", &red[k][i], &grn[k][i], &blu[k][i]);

   }
  

   }
  
 

  move();
}

void draw(int onum){

  double xp[100], yp[100];
  int new_i,p_size,temp_n,n,i;
  i = 0;
  n = 0;
  
  
  for(int p = 0; p < numpolys; p++){

    n = psize[onum][p];

    for(i = 0; i < n; i++){

      temp_n = con[n][i];
     
    }

  

  }



}

void move(double xp[], double yp[], int n){

  double yhi,ylo;
  int onum;
 

  w = G_wait_key();
  onum = w-48;

}
 
