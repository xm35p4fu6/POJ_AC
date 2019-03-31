#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int sz[22], path[22][22];
int dp[2][1<<22];

void init(){
  int tmp;
  cin >> N >> M;
  for(int i=1;i<=N;++i){
    cin >> sz[i];
    for(int j=0;j<sz[i];++j){
      cin >> tmp;
      path[i][tmp] = 1;
    }
  }
}
void sol(){
  if(M<N) {
    cout << "0\n";
    return ;
  }
  dp[0][0] = 1;
  
  // 前N個人，各情況累計幾個
  for(int i=1;i<=N;++i)
    for(int mask=1; mask<1<<M; ++mask){    // 每種情況
      dp[i&1][mask] = 0;
      for(int j=0;j<M;++j)if(path[i][j+1] && mask&(1<<j))
        dp[i&1][mask] += dp[~i&1][mask^(1<<j)];
    }

  int ans = 0;
  for(int mask=1;mask<(1<<M);++mask)if(__builtin_popcount(mask)==N)
    ans += dp[N&1][mask];
  cout << ans << endl;
}

int main(){
  init();
  sol();
}
