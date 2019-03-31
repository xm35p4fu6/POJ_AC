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
typedef vector<pii> vii;

int T,M,N,K,I,a,b,c,ans,cnt;
int dis[1005], disr[1005];
bool visit[1005];
vii G[1005], G2[1005];
typedef priority_queue<pii, vii, greater<pii> > pqQAQ;
pqQAQ pq;
void sol(int ds[], vii g[]){
  pq = pqQAQ ();
  memset(visit, 0, sizeof(visit));
  pq.push(MP(0,K));
  while(!pq.empty()){
    int w = pq.top().X, v = pq.top().Y;
    pq.pop();
    if(visit[v]) continue;
    visit[v] = 1;
    for(int i=0;i<g[v].size();i++)if(!visit[g[v][i].X]){
      int vv = g[v][i].X, ww = g[v][i].Y;
      if(ds[vv] > w + ww){
        ds[vv] = w + ww;
        pq.push(MP(ds[vv], vv));
      }
    }
  }

}
int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  cin>>N>>M>>K;
  --K;
  for(int i=0;i<N;i++) dis[i] = disr[i] = (1<<30);
  while(M--){
    cin>>a>>b>>c;
    --a,--b;
    G[a].PB(MP(b,c));
    G2[b].PB(MP(a,c));
  }
  dis[K] = disr[K] = 0;
  sol(dis, G);
  sol(disr, G2);
  for(int i=0;i<N;i++)if(i!=K)
    ans = max(ans, dis[i]+disr[i]);
  cout<<ans<<endl;
}

