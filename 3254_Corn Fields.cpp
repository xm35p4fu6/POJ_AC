#include <iostream>
#include <algorithm>

using namespace std;

const int MOD = 1e8;
int N, M, ans;
int Mask[15];
int dp[20][1<<14];
bool ok[1<<14];

void build_ok(){
  for(int mask=0; mask<1<<M; ++mask){
    ok[mask] = 1;
    for(int i=0; 1<<i<=mask; ++i)         // 不可相鄰
      if(mask&(1<<i) && mask&(1<<(i+1))){
        ok[mask] = 0;
        break;
      }
  }
}
void init(){
  int in;
  cin >> N >> M;
  for(int i=1;i<=N;++i)for(int j=0;j<M;++j){
    cin >> in;
    if(in) Mask[i] |= 1<<j;
  }
  build_ok();
}
void sol(){
  dp[0][0] = 1;             // 初始狀態答案為1
  ans = 0;

  for(int i=1; i<=N; ++i){      // each row
    for(int mask=Mask[i]; ; mask=(mask-1)&Mask[i])if(ok[mask]){           // 枚舉該row每種情況
      for(int submask=((1<<M)-1)&~mask; submask>=0; submask=(submask-1)&~mask){  // 枚舉所有上層可能情況
        dp[i][mask] += dp[i-1][submask];
        if(dp[i][mask] >= MOD) dp[i][mask] -= MOD;
      }
      if(mask==0) break;
    }
  }

  for(int mask=0; mask<1<<M; ++mask){
    ans += dp[N][mask];
    if(ans >= MOD) ans-=MOD;
  }

  cout << ans << endl;
}

int main(){
  init();
  sol();
}
