#include <iostream>
#include <cstdio>
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
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> p2i;
typedef vector<pii> vii;

ll T,M,N,K,I,a,b,c,ans,cnt;
vector<p2i> edge;
ll dis[501][501];
int ds[2501];
void init(){
  for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)
    dis[i][j] = (i==j?0:(1ll<<30));
  edge.clear();
}
bool suc(){
  memset(ds, 0, sizeof(ds));
  for(int I=0;I<N;I++){
    for(int i=0;i<edge.size();i++){
      p2i x = edge[i];
      if(ds[x.X.Y] > ds[x.X.X] + x.Y){
        ds[x.X.Y] = ds[x.X.X] + x.Y;
        if(I == N-1) return true;
      }
    }
  }
  return false;
}
int main(){
  scanf("%lld", &T);
  while(T--){
    scanf("%lld %lld %lld", &N, &M, &K);
    init();
    while(M--){
      scanf("%lld %lld %lld", &a, &b, &c);
      dis[a][b] = min(dis[a][b], c);
      dis[b][a] = min(dis[b][a], c);
    }
    while(K--){
      scanf("%lld %lld %lld", &a, &b, &c);
      dis[a][b] = min(dis[a][b], -c);
    }
    for(int i=1;i<=N;i++){
      for(int j=1;j<=N;j++)if(i!=j && dis[i][j] != 1ll<<30){
        edge.PB(MP(MP(i,j), dis[i][j])),
        edge.PB(MP(MP(j,i), dis[j][i]));
      }
    }
    printf(suc()?"YES\n":"NO\n");
  }
}

