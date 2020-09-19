#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

//the implementation of fibonacci using parallel technique
int fibpar(int n){
  int f1,f2;
  
  if(n <= 1) return n;

  else{

    f1 = fibpar(n - 1);

    f2 = fibpar(n - 2);

    return f1+f2;
  }
}

//normal fibonacci implementation
int fib(int n){
  int f1,f2;
  if(n <= 1) return n;
  else{
    f1 = fib(n - 1);
    f2 = fib(n - 2);
    return f1+f2;
  }
}

int main(){
  int n;
  scanf("%d", &n);
  int par;
  //parallel fibonacci implementation
   double t1 = omp_get_wtime();
  #pragma omp parallel shared(par)
  {
    // #pragma omp single nowait
    par = fibpar(n);
  }
   double t2 = omp_get_wtime();

  //for normal fibonacci
  double t3 = omp_get_wtime();
  int normal = fib(n);
  double t4 = omp_get_wtime();

  printf("The nth fibonacci number:\n\nparallel = %d\nnormal = %d\n\nand the time taken to execute is :\n\nparallel = %g\nnormal = %g\n", par, normal, t2-t1, t4-t3);
  return 0;
}