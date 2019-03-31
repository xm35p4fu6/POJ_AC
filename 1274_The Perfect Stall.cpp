#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define PB push_back
using namespace std;
typedef vector<int> vi;
const int VN = 600 + 5;

int N, M;
int match[VN];     // 與誰match
vi G[VN];         // 邊
bool pass[VN];

void init(){
  int cnt, n;
  memset(match, -1, sizeof(match));
  for(int i=1; i<=N+M; ++i) G[i].clear();
  for(int i=1; i<=N; ++i) {
    scanf("%d", &cnt);
    while(cnt--) {
      scanf("%d", &n);
      G[i].PB(N+n);
      G[N+n].PB(i);
    }
  }
  N += M;
}
bool dfs(int i){
  pass[i] = 1;
  for(int ii=0; ii<G[i].size(); ++ii) {
    int x = G[i][ii];
    if(match[x] == -1 or (!pass[match[x]] and dfs(match[x]))){
      match[i] = x;
      match[x] = i;
      return true;
    }
  }
  return false;
}
void sol(){
  int ans = 0;
  for(int i=1; i<=N; ++i){     // 每個點找matching
    if(match[i] == -1){
      memset(pass, 0, sizeof(pass));
      ans += dfs(i);             // 回傳這個點是否matching
    }
  }
  printf("%d\n", ans);
}

int main(){
  while(scanf("%d %d", &N, &M) == 2) {
    init();
    sol();
  }
}

