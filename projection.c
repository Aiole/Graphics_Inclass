

#include <FPT.h>
#include <stdio.h>
#include <stdlib.h>
//#include "3d_matrix_tools.c"
#include "M3d_matrix_tools.c"

int swidth = 800, sheight = 800 ;
int numobjects;
int numpoints[10000];
double x[10][15000], y[10][15000], z[10][15000];
double dx[15000], dy[15000], dz[15000];
int numpolys[10000];
int psize[10][1000];
int con[10][15000][8];
double red[10][1000],grn[10][1000],blu[10][1000];


void draw(int onum, double h){

  double xp[15000], yp[15000], zp[15000];
  int i,pnum,n,temp_n;
  double redd,grnn,bluu;
  double H = tan(45*M_PI/180) ;  


  G_rgb (1,1,1);
  G_clear();
  
  printf("onum = %d\n",onum) ;
  printf("numpoints = %d\n",numpoints[onum]);
   
  for(pnum = 0; pnum < numpolys[onum]; pnum++){

    n = psize[onum][pnum];

    //printf("psize = %d \n", n);

    for(i = 0; i < n; i++){
      temp_n = con[onum][pnum][i];
      xp[i] = ( (400 / H) * (x[onum][temp_n] / z[onum][temp_n]) ) + 400;
      yp[i] = ( (400 / H) * (y[onum][temp_n] / z[onum][temp_n]) ) + 400;
      // printf("(%lf, %lf) H = %lf z = %lf\n",x[onum][temp_n],y[onum][temp_n],H,z[onum][temp_n]);
    }
    
    //printf("\n") ;

    G_rgb (0,0,0);

    G_polygon (xp,yp,n);    
    
  }


}




int main(int argc, char **argv){


   G_init_graphics(800,800);
   G_rgb(0,0,0);
   G_clear;
   G_rgb(0,1,0);
   
   int i,onum,count,j,w,pnum,n,temp_onum,rtflag,signf;
   double xtrans,ytrans,yhi,ylo,xhi,xlo,sclr,zhi,zlo,ztrans,h,trans,x_cmass,y_cmass,z_cmass,tempcs,tempsn;
   double a[4][4],b[4][4],c[4][4],d[4][4];
   ylo = 1000;
   xlo = 1000;
   xhi = -1000;
   yhi = -1000;
   h = tan(0.785398);
   
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
    fscanf(fp, "%lf %lf %lf", &x[onum][i], &y[onum][i], &z[onum][i]);
    printf("x = %lf \n", x[onum][i]);
  }

   fscanf(fp, "%d", &numpolys[onum]);

   for(i=0; i < numpolys[onum]; i++){

    fscanf(fp, "%d", &psize[onum][i]);
  
    for(j=0; j < psize[onum][i]; j++){
     fscanf(fp, "%d", &con[onum][i][j]);
    }
   }

  

  }

  



  
  
   
   
  temp_onum = 0;
  signf = 1;
  trans = .1;
  rtflag = 0;
  tempcs = 0.99939082701*signf;
  tempsn = 0.0348994967*signf;

  while(1){


  w = G_wait_key();
  onum = w-49;


  
  if(onum < 10 && onum > -1){

    temp_onum = onum;

  }
   

  if(w == 'c'){
    signf *= -1;
  }

  
  
  if(w == 't'){
    rtflag = 1;
  }


  printf("rtflag = %d trans = %lf \n", rtflag,trans);
  trans = 0.1 * signf;

 

  if (w == 'x' && rtflag == 1){

        M3d_make_translation(a,trans,0,0);
    M3d_mat_mult_points(x[temp_onum],y[temp_onum],z[temp_onum],a,x[temp_onum],y[temp_onum],z[temp_onum],numpoints[temp_onum]);

  x_cmass += trans;

  
       printf("x_cmass = %lf y_cmass = %lf z_cmass = %lf \n", x_cmass, y_cmass, z_cmass);
  }

  if (w == 'y' && rtflag == 1){

 
    M3d_make_translation(a,0,trans,0);
    M3d_mat_mult_points(x[temp_onum],y[temp_onum],z[temp_onum],a,x[temp_onum],y[temp_onum],z[temp_onum],numpoints[temp_onum]);

  y_cmass += trans;

  
    printf("x_cmass = %lf y_cmass = %lf z_cmass = %lf \n", x_cmass, y_cmass, z_cmass);
    
  }

   if (w == 'z' && rtflag == 1){
     printf("herez \n");
     M3d_make_translation(a,0,0,trans);
     M3d_mat_mult_points(x[temp_onum],y[temp_onum],z[temp_onum],a,x[temp_onum],y[temp_onum],z[temp_onum],numpoints[temp_onum]);
 
       z_cmass += trans;


  printf("x_cmass = %lf y_cmass = %lf z_cmass = %lf \n", x_cmass, y_cmass, z_cmass);
    
  }


  
   

  

   if(w == 'r'){rtflag = 0;}//rotation x,y,z
   
     if (w == 'x' && rtflag == 0){

     M3d_make_translation(a,-x_cmass,-y_cmass,-z_cmass);
     M3d_mat_mult_points(x[temp_onum],y[temp_onum],z[temp_onum],a,x[temp_onum],y[temp_onum],z[temp_onum],numpoints[temp_onum]);
     M3d_make_x_rotation_cs(a,tempcs,tempsn);
     M3d_mat_mult_points(x[temp_onum],y[temp_onum],z[temp_onum],a,x[temp_onum],y[temp_onum],z[temp_onum],numpoints[temp_onum]);
     M3d_make_translation(a,x_cmass,y_cmass,z_cmass);
     M3d_mat_mult_points(x[temp_onum],y[temp_onum],z[temp_onum],a,x[temp_onum],y[temp_onum],z[temp_onum],numpoints[temp_onum]);

  }

  if (w == 'y' && rtflag == 0){

     M3d_make_translation(a,-x_cmass,-y_cmass,-z_cmass);
     M3d_mat_mult_points(x[temp_onum],y[temp_onum],z[temp_onum],a,x[temp_onum],y[temp_onum],z[temp_onum],numpoints[temp_onum]);
     M3d_make_y_rotation_cs(a,tempcs,tempsn);
     M3d_mat_mult_points(x[temp_onum],y[temp_onum],z[temp_onum],a,x[temp_onum],y[temp_onum],z[temp_onum],numpoints[temp_onum]);
      M3d_make_translation(a,x_cmass,y_cmass,z_cmass);
     M3d_mat_mult_points(x[temp_onum],y[temp_onum],z[temp_onum],a,x[temp_onum],y[temp_onum],z[temp_onum],numpoints[temp_onum]);
 
    
  }

   if (w == 'z' && rtflag == 0){
     printf("tempcs = %lf tempsn = %lf",tempcs,tempsn);
      M3d_make_translation(a,-x_cmass,-y_cmass,-z_cmass);
      M3d_mat_mult_points(x[temp_onum],y[temp_onum],z[temp_onum],a,x[temp_onum],y[temp_onum],z[temp_onum],numpoints[temp_onum]);
      M3d_make_z_rotation_cs(a,tempcs,tempsn);
     M3d_mat_mult_points(x[temp_onum],y[temp_onum],z[temp_onum],a,x[temp_onum],y[temp_onum],z[temp_onum],numpoints[temp_onum]);
      M3d_make_translation(a,x_cmass,y_cmass,z_cmass);
     M3d_mat_mult_points(x[temp_onum],y[temp_onum],z[temp_onum],a,x[temp_onum],y[temp_onum],z[temp_onum],numpoints[temp_onum]);
    
  }
 
  
  draw(temp_onum,h);


  
  }

  
  
    G_wait_key() ;


    

    
}
