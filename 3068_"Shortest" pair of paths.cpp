#include <vector>
#include <iostream>
#include <utility>
#include <functional>
#include <cmath>
#include <deque>
#include <cstring>
using namespace std;
const int mxn = 200;
struct Edge {
  int to, rev, wei, vol;
};
int N, M;
vector<Edge> G[mxn];

void path_add(int, int, int, int);
int flow_spfa(int, int);
int res;

void init() {
  int a, b, c;
  for(int i=0; i<2*N; ++i) G[i].clear();
  for(int i=1; i<N-1; ++i) path_add(i, N+i, 0, 1);
  path_add(0, N, 0, 2);
  path_add(N-1, N+N-1, 0, 2);

  while(M--) {
    cin >> a >> b >> c;
    path_add(N+a, b, c, 1);
  }
}

int sol() {
  int flow = flow_spfa(0, N+N-1);
  return (flow==2) ? res : -1;
}

int main() {
  ios::sync_with_stdio(false);
  vector<int> ans;
  while(cin >> N >> M && N+M) {
    init();
    ans.push_back(sol());
  }
  for(size_t i=0; i<ans.size(); ++i) {
    cout << "Instance #" << i+1 << ": ";
    if(ans[i] == -1) cout << "Not possible";
    else cout << ans[i];
    cout << '\n';
  }
}

void path_add(int from, int to, int w, int v) {
  G[from].push_back({to, (int)G[to].size(), w, v});
  G[to].push_back({from, (int)G[from].size()-1, -w, 0});
}

bool spfa_inq[130];
int d[130], rev[130];
void spfa(int S) {  
  memset(d, 0x7f, sizeof(d));
  deque<int> q;
  q.push_front(S), spfa_inq[S] = 1, d[S] = 0;
  while(!q.empty()) {
    int u = q.front();
    q.pop_front(), spfa_inq[u] = 0;
    for(size_t i=0; i<G[u].size(); ++i) {
      Edge &e = G[u][i];
      if(e.vol && d[u]+e.wei < d[e.to]) {
        d[e.to] = d[u] + e.wei;
        rev[e.to] = e.rev;
        if(spfa_inq[e.to]) {
          if(d[q.back()] < d[q.front()]) 
            q.push_front(q.back()), q.pop_back();
          continue;
        }
        spfa_inq[e.to] = 1;
        if(!q.empty() && d[e.to] <= d[q.front()]) q.push_front(e.to);
        else q.push_back(e.to);
      }
    }
  }
}

int flow_spfa(int S, int T) {
  res = 0;
  int flow = 0;
  while(1){
    spfa(S);
    if(d[T] == 0x7f7f7f7f) return flow;
    int f = 1e9;
    for(int i=T; i!=S;) {
      Edge &rev_e = G[i][rev[i]];
      Edge &e = G[rev_e.to][rev_e.rev];
      f = min(f, e.vol);
      res += e.wei;
      i = rev_e.to;
    }
    for(int i=T; i!=S;) {
      Edge &rev_e = G[i][rev[i]];
      Edge &e = G[rev_e.to][rev_e.rev];
      e.vol -= f;
      rev_e.vol += f;
      i = rev_e.to;
    }
    flow += f;
  }
  return -1;
}

