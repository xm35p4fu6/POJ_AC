#include <cstring>
#include <cstdio>
#include <limits>
#include <algorithm>
#include <vector>
#include <cmath>

typedef long long ll;

typedef double ele;

const double eps = 1e-8;
const ele ele_inf = 100000;
const int VN = 60600;

int to[VN], head[VN], next[VN], psz;
ele w[VN], W[VN];

int dinic_S, dinic_T, dinic_level[VN];
int dinic_queue[VN];

/*
 *  把所有點分區，往下一區走保證接近匯點
 */

bool dinic_bfs() {
  int s=0, t=1, v;       // [s, t)
  int *que = dinic_queue, *lev = dinic_level;
  memset(dinic_level, -1, sizeof(dinic_level));   // 初始化所有層級
  lev[dinic_S] = 0;
  que[s] = dinic_S;
  while(s<t) {
    v = que[s++];
    for(int i=head[v]; ~i; i=next[i]) if(w[i]>eps && lev[to[i]]<0)
      lev[to[i]] = lev[v]+1, que[t++] = to[i];
  }
  return lev[dinic_T] != -1;
}

/*
 *  維護每條可通往T的流量上限：
 *    只向下一層且有剩餘容量的移動節點
 *  回傳流出的流量，若為零則順手將此點移出這層，以免其他點再次經過
 */

ele dinic_find(int v=dinic_S, ele low=ele_inf) {
  ele tmp, res=0;
  int *lev = dinic_level;
  if(v == dinic_T) return low;
  for(int i=head[v]; ~i && res<low-eps; i=next[i]) 
    if(w[i]>eps && lev[to[i]]==lev[v]+1) {
      tmp = dinic_find(to[i], std::min(w[i], low-res));
      w[i] -= tmp;
      w[i^1] += tmp;
      res += tmp;
    }
  if(!res) lev[v] = -1;
  return res;
}

ele dinic() {
  ele res = 0;
  while(dinic_bfs()) res += dinic_find();
  return res;
}
void path_add(int s, int t, ele ca) {      // 使用 array linked list 方式存邊
  to[psz]=t, w[psz]=ca, next[psz]=head[s], head[s]=psz++;
  to[psz]=s, w[psz]=0, next[psz]=head[t], head[t]=psz++;       // 反向容量可能為0
}
// 必須設置dinic_S, dinic_T 為源點、匯點
// 必需檢查完dinit_init ""path_add"" 再跑dinic
// dinic_level[] 中 >= 0 的即為 S劃分

int N, M;

bool succ(double D) {
  for(int i=1; i<=N; ++i) W[head[i]] = D;
  memcpy(w, W, sizeof(W));
  double ans = dinic();
  return (1.0*M-ans) < eps;
}
void init(){
  int a, b;
  psz = 0;
  memset(head, -1, sizeof(head));   // 建邊之前服用
  scanf("%d %d", &N, &M);
  for(int i=1; i<=M; ++i) path_add(0, N+i, 1);
  for(int i=1; i<=M; ++i) {
    scanf("%d %d", &a, &b);
    path_add(N+i, a, ele_inf);
    path_add(N+i, b, ele_inf);
  }
  for(int i=1; i<=N; ++i) path_add(i, N+M+1, 0);
  dinic_S = 0, dinic_T = N+M+1;       // 記得設置 源點 匯點
  memcpy(W, w, sizeof(w));
}
void sol(){
  if(M == 0) {
    printf("1\n1\n");
    return;
  }
  std::vector<int> ans;
  double l=0, r=M, precision = 1.0/N/N;
  while(r-l >= precision) succ((l+r)/2) ? r=(l+r)/2 : l=(l+r)/2;
  succ(l);
  for(int i=1; i<=N; ++i) if(dinic_level[i] > 0) ans.push_back(i);
  if(ans.size() == 0) {
    puts("1\n1");
    return;
  }
  printf("%d\n", (int)ans.size());
  for(int i=0; i<(int)ans.size(); ++i) printf("%d\n", ans[i]);
}
int main(){
  init();
  sol();
}
