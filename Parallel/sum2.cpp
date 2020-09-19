#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

int MOD = 1000000007;

int main(){
  int n = 1000000000;
  int* arr = new int[n];
  for(int j = 0; j < n; j++) {
    arr[j] = 1;
  }
  int sum = 0,i;
  double t1 = omp_get_wtime();
  // #pragma omp parallel for reduction(+:sum)
  for(i = 0; i < n ; i++){
    // #pragma omp critical
    sum += arr[i];
  }
  double t2 = omp_get_wtime();
  printf("The time for normal algorithm : \n");
  // printf("The time for the parallel algorithm : \n");
  printf("Sum of the elements in the array is %d , Time is %g\n", sum , t2-t1);
  return 0;
}
