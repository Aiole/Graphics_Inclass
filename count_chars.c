
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


int main(int argc, char **argv){

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
  
  int new_i,p_size,temp_n;

  while(1){
    new_i = 0;
   *p_size = &(psize[i]);

    while(p_size < new_i){

      
      temp_n = &(psize[p_size][new_i]);
      
      new_i++;
    }

  

  }



  
}



void draw_polygon(double xp[], double yp[], int n){


    G_init_graphics(800,800);
    G_rgb(0,0,0);
    G_clear;
    G_rgb(0,1,0);
    G_wait_key();

  
  G_fill_polygon(xp,yp,n);

  w = G_wait_key();
  onum = w-48;

}
