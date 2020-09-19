#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

int MOD = 1000000007;

int main(){
  int n = 100000000;
  int* arr = new int[n];
  for(int j = 0; j < n; j++) {
    arr[j] = 1;
  }
  int sum = 0,i;
  int threadnum = 0, numthread = 0;
  double t1 = omp_get_wtime();
  #pragma omp parallel default(shared) private(i,threadnum)
  {
    threadnum = omp_get_thread_num();
    numthread = omp_get_num_threads(); 
    //assigning each thread different ranges
    int from,to;
    from = (n/numthread)*threadnum;
    to = (n/numthread)*(threadnum+1)-1;
    
    //the edge case if the total cases isn't exactly divisible by numthread
    if(threadnum == numthread-1 ) to = n-1;

    //the region  where the array elements are added into the sum , pragme omp critical is important because it 
    //does not allow multiple threads to write to sum at the same time
    for(int i = from; i <= to; ++i){
      #pragma omp critical
      sum += arr[i];
    }
  }
  double t2 = omp_get_wtime();
  printf("Sum of the elements in the array is %d , Time is %g, the thread count is %d\n", sum , t2-t1, numthread);
  return 0;
}