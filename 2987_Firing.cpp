#include <cstring>
#include <cstdio>
#include <limits>
#include <algorithm>

typedef long long ll;

typedef ll ele;

const ele ele_inf = std::numeric_limits<ele>::max() >> 8;
const int VN = 200060;

int to[VN], head[VN], next[VN], psz;
ele w[VN];

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
    for(int i=head[v]; ~i; i=next[i]) if(w[i]>0 && lev[to[i]]<0)
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
  for(int i=head[v]; ~i && res<low; i=next[i]) 
    if(w[i]>0 && lev[to[i]]==lev[v]+1) {
      tmp = dinic_find(to[i], std::min(w[i], low-res));
      w[i] -= tmp;
      w[i^1] += tmp;
      res += tmp;
    }
  if(!res) lev[v] = -1;
  return res;
}

ll dinic() {
  ll res = 0;
  while(dinic_bfs()) res += dinic_find();
  return res;
}
void path_add(int s, int t, ele ca) {      // 使用 array linked list 方式存邊
  to[psz]=t, w[psz]=ca, next[psz]=head[s], head[s]=psz++;
  to[psz]=s, w[psz]=0, next[psz]=head[t], head[t]=psz++;       // 反向容量可能為0
}

// 必須設置dinic_S, dinic_T 為源點、匯點
// 先檢查完dinit_init path_add 再跑dinic

ll ans;
int N;
bool exist_path[5001][5001];
void init() {
  int M, a,b;
  ans = psz = 0;
  memset(head, -1, sizeof(head));   // 建邊之前服用
  scanf("%d %d", &N, &M);         // 點數量，邊數量
  for(int i=1; i<=N; ++i) {
    scanf("%d", &a);
    if(a>0) path_add(0, i, a), ans += a;
    else if(a<0) path_add(i, N+1, -a);
  }
  while(M--) {
    scanf("%d %d", &a, &b);    // 點a 到b 容量c(注意型態)
    exist_path[a][b] = 1;
  }
  ele ca, cb;
  for(int i=1; i<=N; ++i) for(int j=i+1; j<=N; ++j) {
    if(exist_path[i][j] && exist_path[j][i]) ca = cb = ele_inf;
    else if(exist_path[i][j]) ca = ele_inf, cb = 0;
    else if(exist_path[j][i]) ca = 0, cb = ele_inf;
    else continue;
    to[psz]=j, w[psz]=ca, next[psz]=head[i], head[i]=psz++;
    to[psz]=i, w[psz]=cb, next[psz]=head[j], head[j]=psz++;       // 反向容量可能為0
  }
  dinic_S = 0, dinic_T = N+1;       // 記得設置 源點 匯點
}

void sol() {
  int cnt = 0;
  ans = ans - dinic();
  for(int i=1; i<=N; ++i) if(dinic_level[i]>0) ++cnt;
  printf("%d %lld\n", cnt, ans);
}

int main() {
  init();
  sol();
}
