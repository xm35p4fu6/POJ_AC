#include <cstdio>
using namespace std;
int N,T, a, b;
int bucket[1000005], arr[25002][2];

int sol(){
  int las=1, mx=0, r=arr[0][1], ans=1;
  if(arr[0][0] > 1)
    return -1;
  while(r < T){
    while(las<N && arr[las][0] <= r+1){
      if(arr[las][1] > arr[mx][1])
        mx = las;
      ++las;
    }
    if( (las==N || arr[las][0]>arr[mx][1]+1) && arr[mx][1]<T )
      return -1;
    ++ans;
    r = arr[mx][1];
  }
  return ans;
}

int main(){
  scanf("%d %d", &N, &T);
  while(N--){
    scanf("%d %d", &a, &b);
    if(b>bucket[a]) bucket[a]=b;
  }
  N=0;
  for(int i=0;i<=1000000;i++)if(bucket[i]){
    arr[N][0]=i;
    arr[N][1]=bucket[i];
    ++N;
  }
  printf("%d\n", sol());
}
