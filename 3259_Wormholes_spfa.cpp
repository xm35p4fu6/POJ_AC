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
#include <climits>
#define X first
#define Y second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vii;

const int NV = 505, NE = 250005, INF = 1<<30;

struct SPFA{
  int n, size, dis[NV], head[NV];
  bool in[NV];

  struct edge {
    int v,w,nxt;
    edge(){}
    edge(int V, int NXT, int W=0): v(V), nxt(NXT), w(W){}
  }E[NE];

  void init(int nn){
    n = nn, size = 0;
    for(int i=0;i<=n;i++)
      head[i]=-1, in[i]=0, dis[i]=INF;
  }

  inline void insert(int u, int v, int w){
    E[size] = edge(v, head[u], w);
    head[u] = size++;
  }
  inline bool relax(int u, int v, int w){
    if(dis[v] == INF or dis[u]+w < dis[v]){
      dis[v] = dis[u] + w;
      return true;
    }
    return false;
  }
  int spfa(int src, int des){   
  // cal all dis[] and return dis[des]
  //  if exist negative cycle, use vs[] and return INT_MAX
    int vs[NV] = {0};
    vs[src] = 1;
    queue<int> que;
    dis[src] = 0;
    que.push(src);
    in[src] = true;
    while(!que.empty()){
      int u = que.front();
      que.pop();
      in[u] = false;
  /*
      for(int i = head[u]; i!=-1; i=E[i].nxt){
        if(relax(u, E[i].v, E[i].w) and !in[E[i].v]){
          in[E[i].v] = true;
          que.push(E[i].v);
        }
      }
  */
    
    
      
      for(int i = head[u]; i!=-1; i=E[i].nxt){
        if(relax(u, E[i].v, E[i].w)){
          vs[E[i].v] ++;
          if(vs[E[i].v] == n) return INT_MAX;
          if(!in[E[i].v]){
            in[E[i].v] = true;
            que.push(E[i].v);
          }
        }
      }

    

    }
    return dis[des];
  }
}G;

int T, a,b,c, N,M,K,graph[505][505];

int main(){
  scanf("%d", &T);
  while(T--){
    scanf("%d %d %d", &N,&M,&K);
    G.init(N);
    for(int i=0;i<=N;i++)for(int j=0;j<=N;j++)
      graph[i][j] = 1<<30;
    while(M--){
      scanf("%d %d %d", &a,&b,&c);
      graph[a][b] = min(graph[a][b], c);
      graph[b][a] = min(graph[b][a], c);
    }
    while(K--){
      scanf("%d %d %d", &a, &b, &c);
      graph[a][b] = min(graph[a][b], -c);
    }
    for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)
      if(i!=j and graph[i][j] != 1<<30)
        G.insert(i,j,graph[i][j]);
    printf(G.spfa(1,N) == INT_MAX ? "YES\n" : "NO\n");
  }
}
