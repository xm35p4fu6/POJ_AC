#include <iostream>
#include <cmath>
#include <cstring>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <string>
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define safe(x) max(0,x)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vii;

int T,M,N,K,I,a,b,c,ans,cnt;
vii v[1000001];
ll dp[1000001];

int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  scanf("%d%d%d", &M, &N, &K);
  for(int i=0;i<N;i++){
    scanf("%d%d%d", &a, &b, &c);
    v[b].PB(MP(a, c));
  }
  for(int i=1;i<=M;i++){
    dp[i] = dp[i-1];
    for(int j=0;j<v[i].size();j++){
      dp[i] = max(dp[i], dp[safe(v[i][j].X - K)] + v[i][j].Y);
    }
  }
  printf("%lld\n", dp[M]);
}

