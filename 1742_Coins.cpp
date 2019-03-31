#include <iostream>
#include <cstring>
using namespace std;

int M,N,ans, dp[100005], arr[101][2] ;
void init(){
  memset(dp, -1, sizeof(dp));
  ans = dp[0] = 0;
}

int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  while(scanf("%d %d", &N, &M)==2 && (N+M)){
    init();
    for(int i=0;i<N;i++)
      scanf("%d", &(arr[i][0]));
    for(int i=0;i<N;i++)
      scanf("%d", &(arr[i][1]));
    for(int i=0;i<N;i++)for(int j=0;j<=M;j++){
      if(dp[j]>=0) dp[j] = arr[i][1];
      else if(j<arr[i][0] || dp[j-arr[i][0]]<1)
        dp[j] = -1;
      else dp[j] = dp[j-arr[i][0]] -1;
    }
    for(int i=1;i<=M;i++)if(dp[i]>=0)ans++;
    printf("%d\n",ans);

  }
}

