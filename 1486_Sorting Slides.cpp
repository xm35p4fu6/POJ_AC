#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define PB push_back
typedef vector<int> vi;
const int VN = 100;

int N, M;
int match[VN];     // 與誰match
vi G[VN];         // 邊
bool pass[VN];

int bx, by;
bool dfs(int i){
  pass[i] = 1;
  for(int j=0; j<G[i].size(); ++j) {
    int x = G[i][j];
    if((i==bx && x==by) || (i==by && x==bx)) continue;
    if(match[x] == -1 or (!pass[match[x]] and dfs(match[x]))){
      match[i] = x;
      match[x] = i;
      return true;
    }
  }
  return false;
}
int x1[100], y1[100], x2[100], y2[100], T;
void init(){
  int x, y;
  bx = by = -1;
  for(int i=0; i<N*2; ++i) G[i].clear();  // 建邊
  for(int i=0; i<N; ++i) scanf("%d %d %d %d", x1+i, x2+i, y1+i, y2+i);
  for(int i=0; i<N; ++i) {
    scanf("%d %d", &x, &y);
    for(int j=0; j<N; ++j) if( x>=x1[j] && x<=x2[j] && y>=y1[j] && y<=y2[j]) {
      G[j].PB(N+i);
      G[N+i].PB(j);
    }
  }
}
int Bipar() {
  memset(match, -1, sizeof(match));
  int cnt = 0;
  for(int i=0; i<N*2; ++i){     // 每個點找matching
    if(match[i] == -1){
      memset(pass, 0, sizeof(pass));
      cnt += dfs(i);             // 回傳這個點是否matching
    }
  }
  return cnt;
}
void sol(){
  bool fir = 1;
  int res = Bipar(), match_tmp, save[100];
  for(int i=0; i<N; ++i) save[i] = match[i];
  printf("Heap %d\n", ++T);

  for(int i=0; i<N; ++i) {          // 確認唯一性
    bx = i, by = save[i];         // 把這條邊禁掉
    int tmp = Bipar();
    if(tmp < res) {         // 這個匹配是唯一的
      if(fir) fir = 0;
      else printf(" ");
      printf("(%c,%d)", 'A'+i, save[i]-N+1);
    }
  }
  if(fir) printf("none");
  printf("\n\n");
}

int main(){
  while(~scanf("%d", &N) && N) {
    init();
    sol();
  }
}
