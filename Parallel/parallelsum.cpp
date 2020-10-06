#include <bits/stdc++.h>
#include <omp.h>
#define endle "\n"
using namespace std;

int main(){
  int m = 20;
  cin >> m;
  int n = pow(2, m);
  int* arr = new int[n];
  
  double t1 = omp_get_wtime();
  for(int i = 0; i < n; i++) {
    arr[i] = 1;
  }
  double t2 = omp_get_wtime();

  double t3 = omp_get_wtime();
  int sum = 0;
  for(int i = 0; i < n; i++) {
    sum += arr[i];
  }
  double t4 = omp_get_wtime();

  //t6 -t5 is the running time of the algorithm
  double t5 = omp_get_wtime();

  //ALGORITHM 
  // m denotes the depth of the algorithm
  for(int i = m - 1; i >= 0; --i) {

    //here we calculate 

    int locallen = pow(2, i);
    #pragma omp parallel for
    for(int j = 0; j < locallen ; j++) {
      arr[j] = arr[j] + arr[j + locallen];
    }
  }

  double t6 = omp_get_wtime();
  printf("The sum of %d numbers is %d in normal and %d in parallel\n", n, sum, arr[0]);
  printf("time in normal is %lf seconds, time in parallel is %lf seconds\n", t4 - t3, t6 - t5);
  return 0;
}