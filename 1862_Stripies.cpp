#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int N;
double arr[1000];
int main(){
  scanf("%d", &N);
  for(int i=0;i<N;i++)
    scanf("%lf", arr+i);
  sort(arr, arr+N);
  while(N>1){
    arr[N-2] = sqrt(arr[N-1]*arr[N-2])*2;
    --N;
  }
  printf("%.3lf\n", arr[0]);
}
