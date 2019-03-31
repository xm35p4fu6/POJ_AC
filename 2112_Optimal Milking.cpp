#include <cstring>
#include <cstdio>
#include <limits>
#include <algorithm>

typedef long long ll;

typedef int ele;

const ele ele_inf = std::numeric_limits<ele>::max() /500;
const int VN = 13000;

int to[VN], head[VN], next[VN], psz;
ele w[VN];
int weight[VN];

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

ele dinic() {
  ele res = 0;
  while(dinic_bfs()) res += dinic_find();
  return res;
}
inline void path_add(int s, int t, ele ca, int W) {      // 使用 array linked list 方式存邊
  to[psz]=t, w[psz]=ca, weight[psz]=W, next[psz]=head[s], head[s]=psz++;
  to[psz]=s, w[psz]=0 , weight[psz]=W, next[psz]=head[t], head[t]=psz++;       // 反向容量可能為0
}

// 必須設置dinic_S, dinic_T 為源點、匯點
// 必需檢查完dinit_init ""path_add"" 再跑dinic
// dinic_level[] 中 >= 0 的即為 S劃分
int ds[250][250];
int N, maxLen, K, C, M;

inline bool succ(int ub) {
  //fprintf(stderr, "<%d> ", ub);
  psz = 0;
  memset(w, 0, sizeof(w));        // 多測資時要初始化
  memset(head, -1, sizeof(head));   // 建邊之前服用

  for(int i=0; i<K; ++i)        // 連線 milking machine 到 cow
    for(int j=0; j<C; ++j) if(ds[i][K+j] <= ub)
      path_add(i, K+j, 1, ds[i][K+j]);

  for(int i=0; i<K; ++i)        // 連線 S 到 milking machine
    path_add(N, i, M, 0); 

  for(int i=0; i<C; ++i)        // 連線 cow 到 T
    path_add(K+i, N+1, 1, 0);

  return dinic() == C;
}
void init() {
  scanf("%d %d %d", &K, &C, &M);
  N = K+C;
  for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) {
    scanf("%d", &ds[i][j]);
    if(ds[i][j] == 0) ds[i][j] = 1<<29;
  }
  
  for(int k=0; k<N; ++k)
    for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) {
      if(ds[i][j] > ds[i][k] + ds[k][j])
        ds[i][j] = ds[i][k] + ds[k][j];
      if(ds[i][j] != 1<<29 && ds[i][j] > maxLen) maxLen = ds[i][j];
    }
  dinic_S = N, dinic_T = N+1;       // 記得設置 源點 匯點
}
void sol() {
  int L=0, R=maxLen;
  while(R-L>1) succ(R+L>>1) ? R=R+L>>1 : L=R+L>>1;
  printf("%d\n", R);
}
int main() {
  init();
  sol();
}
