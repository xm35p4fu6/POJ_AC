/*
 * [G] 最大獨立集 + 最小點覆蓋 = 所有點
 * [G] |最小邊覆蓋| + |最大匹配| = |所有點|
 * [B] 最大匹配 = 最小點覆蓋
 */
#include <cstring>
#include <vector>
#include <cstdio>
#define PB push_back
using namespace std;

typedef vector<int> vi;
const int VN = 500 + 5;

int N, M;
int match[VN];     // 與誰match
vi G[VN];         // 邊
bool pass[VN];

bool dfs(int i){
  pass[i] = 1;
  for(int j=0; j<G[i].size(); ++j) {
    int x = G[i][j];
    if(match[x] == -1 or (!pass[match[x]] and dfs(match[x]))){
      match[i] = x;
      match[x] = i;
      return true;
    }
  }
  return false;
}
void init(){
  int u, n, v;
  memset(match, -1, sizeof(match));
  for(int i=0; i<N; ++i) G[i].clear();  // 建邊
  for(int i=0; i<N; ++i) {
    scanf("%d: (%d)", &u, &n);
    for(int i=0; i<n; ++i) {
      scanf("%d", &v);
      G[u].PB(v);
    }
  }
}
void sol(){
  int cnt = 0;
  for(int i=0;i<N;i++){     // 每個點找matching
    if(match[i] == -1){
      memset(pass, 0, sizeof(pass));
      cnt += dfs(i);             // 回傳這個點是否matching
    }
  }
  printf("%d\n", N-cnt);
}

int main(){
  while(~scanf("%d", &N)){
    init();
    sol();
  }
}

