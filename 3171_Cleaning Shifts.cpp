#include <cstdio>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

typedef long long ll;

struct Node{
  int x, y;
  ll val;
  Node(int a=0, int b=0, ll c=0):
    x(a), y(b), val(c){}
  bool operator < (const Node& a)const{
    return ((y==a.y) ? (x<a.x) : (y<a.y));
  }
};
const ll INF = 0x7f7f7f7f7f7f7f7fll;
const int VN = 87000;
typedef ll ele;

ele segt_arr[4*VN];
int segt_sz;

inline void segt_pull(int v) {
  segt_arr[v] = min(segt_arr[v<<1], segt_arr[v<<1|1]);
}
inline void segt_push(int v) {

}
void segt_update(int L, int val, int l=0, int r=segt_sz, int v=1) {
  if(l>=L && r<=L+1) segt_arr[v] = val;
  else {
    segt_push(v);
    if((l+r)>>1 >= L+1) segt_update(L, val, l, (l+r)>>1, v<<1);
    if((l+r)>>1 <= L) segt_update(L, val, (l+r)>>1, r, v<<1|1);
    segt_pull(v);
  }
}
ll segt_query(int L, int R, int l=0, int r=segt_sz, int v=1) {
  if(l>=L && r<=R) return segt_arr[v];
  if(l>=R || r<=L) return INF;
  segt_push(v);
  return min( segt_query(L, R, l, (l+r)>>1, v<<1), 
      segt_query(L, R, (l+r)>>1, r, v<<1|1));
}


int N, M, E;

Node inter[VN]; 
ll dp[VN];

void init() {
  int l, r, v, n=0;
  memset(dp, 0x7f, sizeof(dp));
  memset(segt_arr, 0x7f, sizeof(segt_arr));
  scanf("%d %d %d", &N, &M, &E);
  segt_sz = E+1;
  for(int i=0; i<N; ++i) {
    scanf("%d %d %d", &l, &r, &v);
    if(l==M) {
      if(dp[r] > v) {
        dp[r] = v;
        segt_update(r, v);
      }
    }
    else inter[n++] = Node(l, r, (ll)v);
  }
  N = n;
}

// segt_update(pos, val) arr[pos] 修改為 val, 需要區間更新時 補上push(v) 以及L+1 改 R
// segt_query(L, R) [L,R)，記得修改 INT_MAX
void sol() {
  ll q;
  sort(inter, inter+N);
  for(int i=0; i<N; ++i) {
    q = segt_query(inter[i].x-1, inter[i].y) + inter[i].val;
    if(q < dp[inter[i].y]) {
      dp[inter[i].y] = q;
      segt_update(inter[i].y, q);
    }
  }
  if(dp[E] == INF) puts("-1");
  else printf("%lld\n", dp[E]);
}

int main() {
  init();
  sol();
}
