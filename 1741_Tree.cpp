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
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vii;

int N,K, ans, a,b,c, cnt[10001];
bool used[10001];
vii G[10001], fc;
vector<int> dist, sub_dist;

void init(){
  for(int i=0;i<N;i++) G[i].clear();
  memset(used, 0, sizeof(used));
  ans = 0;
}

void dfs(int v, int pa, int len, vector<int> &dist){
  dist.PB(len);
  for(int i=0;i<G[v].size();i++){
    pii w = G[v][i];
    if(w.X != pa && !used[w.X])
      dfs(w.X, v, len+w.Y, dist);
  }
}

int cal(vector<int> &dist){
  int ret=0;
  sort(dist.begin(), dist.end());
  for(int i=0, j=dist.size();i<dist.size();i++){
    while(j>0 && dist[i]+dist[j-1]>K) j--;
    ret += (j-(j>i));
  }
  return (ret>>1);
}

int find_central(int v, int pa){
  int w, child, res=0;
  cnt[v] = 1;
  for(int i=0;i<G[v].size();i++){
    w = G[v][i].X;
    if(w!=pa && !used[w]){
      child = find_central(w, v);
      res = max(res, child);
      cnt[v] += child;    // size of the tree
    }
  }
  fc.PB(MP(v, res));  // index, size of the largest subtree
  return cnt[v];
}

void sol(int v){
  fc.clear(); // X,Y : index,length
  int central = 0, sz = find_central(v, -1);
  for(int i=0;i<fc.size();i++){
    fc[i].Y = max(fc[i].Y, sz-cnt[fc[i].X]);
    if(fc[i].Y <= fc[central].Y)
      central = i;
  }
  central = fc[central].X;
  used[central] = 1;
  
  // 繼續分下去
  for(int i=0;i<G[central].size();i++)
    if(!used[ G[central][i].X ])
      sol( G[central][i].X );

  dist.clear();
  for(int i=0;i<G[central].size();i++){
    if(used[ G[central][i].X ])
      continue;
    sub_dist.clear();
    dfs(G[central][i].X, -1, G[central][i].Y, sub_dist);
    ans -= cal(sub_dist);

    dist.insert( dist.end(), sub_dist.begin(), sub_dist.end());
  }
  dist.PB(0);
  ans += cal(dist);
  
  used[central] = 0;
}

int main(){
  while(scanf("%d %d", &N, &K) && (N+K)){
    init();
    for(int i=1;i<N;i++){
      scanf("%d %d %d", &a, &b, &c);
      --a,--b;
      G[a].PB(MP(b,c));
      G[b].PB(MP(a,c));
    }
    sol(0);
    printf("%d\n", ans);
  }
}

