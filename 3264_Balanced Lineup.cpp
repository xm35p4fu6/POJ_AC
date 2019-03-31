#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <string>
#include <climits>
#define X first
#define Y second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vii;

#define lt(x) ((x<<1)+1)
#define rt(x) ((x<<1)+2)
#define MID ((l+r)>>1)
const int VN = 50005;
struct Seg{
  ll buf[2][VN << 2], *mx, *mn, *arr;
  int N;
  inline void init(ll ary[], int len){
    memset(buf, 0, sizeof(buf));
    mx = &buf[0][0], mn = &buf[1][0], arr = ary, N = len;
  }
  inline void build(){
    Build(0, N, 0);
  }
  inline ll query(int l, int r){    // []
    return Querymx(0, N, l, r+1, 0) - Querymn(0, N, l, r+1, 0);
  }

  inline void pull(int pos){
    mx[pos] = max(mx[lt(pos)], mx[rt(pos)]);
    mn[pos] = min(mn[lt(pos)], mn[rt(pos)]);
  }
  void Build(int l, int r, int pos){
    if(r-l == 1){
      mx[pos] = mn[pos] = arr[l];
      return ;
    }
    Build(l, MID, lt(pos));
    Build(MID, r, rt(pos));
    pull(pos);
  }
  ll Querymx(int l, int r, int tl, int tr, int pos){
    if(l >= tl && r <= tr) return mx[pos];
    if(l >= tr || r <= tl) return 0;
    return max(Querymx(l, MID, tl, tr, lt(pos)), Querymx(MID, r, tl, tr, rt(pos)));
  }
  ll Querymn(int l, int r, int tl, int tr, int pos){
    if(l >= tl && r <= tr) return mn[pos];
    if(l >= tr || r <= tl) return INT_MAX;
    return min(Querymn(l, MID, tl, tr, lt(pos)), Querymn(MID, r, tl, tr, rt(pos)));
  }
}st;
int T,M,N,K,Q,I,a,b,c,ans,cnt;
ll arr[50001];

int main(){
  scanf("%d %d", &N, &Q);
  for(int i=0;i<N;i++) scanf("%lld", arr+i);
  st.init(arr, N);
  st.build();
  while(Q--){
    scanf("%d %d", &a, &b);
    printf("%lld\n", st.query(a-1, b-1));
  }
}

