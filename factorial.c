#include <stdio.h>


int factorial(int n){

  int i,f;
  f=1;
  for(i = 1; i<=n; i++){
    f*=i;
  }

  return f;
  
}

int choose(int u, int v){

  int a,b,c,d;
  
  a = factorial(u);
  b = factorial(v);
  c = factorial(u-v);
  d = a/(b*c);
  return d;
  

}


int main(){

  double val = choose(6,2);
  printf("%lf", val);

}
