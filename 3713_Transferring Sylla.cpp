#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
vector<int> G[505];
bool connected[505][505];
bool banned[505], over;

const int VN = 505;

int low[VN], dfn[VN];
bool is_cut[VN];

int tarjan_tag;
int cut_bridge(int v, int pa) {
  low[v] = dfn[v] = ++tarjan_tag;
  int children = 0;
  for(int ii=0; ii<G[v].size(); ++ii) {
    int i = G[v][ii];
    if(i != pa && !banned[i]) {
      if(dfn[i] && dfn[i] < dfn[v]) low[v] = min(dfn[i], low[v]);
      else if(dfn[i] == 0) {
        ++children;
        low[v] = min(cut_bridge(i, v), low[v]);
        if(over == 1) return 1;
        if((pa == -1 && children > 1) || (pa != -1 && low[i] >= dfn[v])) {
          return over = 1;
        }
      }
    }
  }
  return low[v];
}

void init() {
  int a, b;
  memset(connected, 0, sizeof(connected));
  for(int i=0; i<N; ++i) G[i].clear();
  while(M--) {
    scanf("%d %d", &a, &b);
    connected[a][b] = connected[b][a] = 1;
  }
  for(int i=0; i<N; ++i) for(int j=0; j<N; ++j)
    if(connected[i][j]) G[i].push_back(j);
}
bool sol() {
  for(int i=0; i<N; ++i) {
    // 每個點都移除看看 還有無 cut vertex
    banned[i] = 1;
    over = tarjan_tag = 0;
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    cut_bridge(i==0?1:0, -1);
    banned[i] = 0;
    if(over == 1 || tarjan_tag < N-1) {
      return false;
    }
  }
  return true;
}

int main() {
  while(scanf("%d %d", &N, &M) == 2 && N+M) {
    init();
    if(sol()) puts("YES");
    else puts("NO");
  }
}
