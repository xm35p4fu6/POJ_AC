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

const int VN = 400 + 5;

int N, M, g,B;
int match[VN];     // 與誰match
vi G[VN];         // 邊
bool pass[VN];

bool dfs(int i){
  pass[i] = 1;
  for(int j=0; j<(int)G[i].size(); ++j) {
    int x = G[i][j];
    if(match[x] == -1 or (!pass[match[x]] and dfs(match[x]))){
      match[i] = x;
      match[x] = i;
      return true;
    }
  }
  return false;
}
bool mat[405][405];
void init(){
  int a, b;
  N = g + B;
  memset(match, -1, sizeof(match));
  memset(mat, 0, sizeof(mat));
  for(int i=0; i<N; ++i) G[i].clear();  // 建邊
  while(M--){
    scanf("%d %d", &a, &b);
    --a, --b;
    // a b 之間有一條邊
    mat[a][b+g] = mat[b+g][a] = 1;
  }
  for(int i=0; i<g; ++i) for(int j=g; j<N; ++j) if(i!=j) {
    if(mat[i][j] == 0) G[i].PB(j), G[j].PB(i);
  }
}
int sol(){
  int cnt = 0;
  for(int i=0;i<N;i++){     // 每個點找matching
    if(match[i] == -1){
      memset(pass, 0, sizeof(pass));
      cnt += dfs(i);             // 回傳這個點是否matching
    }
  }
  return N - cnt;
}

int main(){
  int T = 0;
  while(scanf("%d %d %d", &g, &B, &M)==3 && g+B+M) {
    init();
    int res = sol();
    printf("Case %d: %d\n", ++T, res);
  }
}
