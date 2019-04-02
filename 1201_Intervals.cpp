#include <cstdio>
#include <algorithm>

using namespace std;

const int mxn = 50001;
int N;

struct Node {
  int l, r, c;
} n[mxn];

bool cmp(const Node& a, const Node& b) {
  return (a.r==b.r) ? (a.l<b.l) : (a.r<b.r);
}

int st[mxn*3], tag[mxn*3];    // st, tag:=st已經加了 要往下壓
void update(int &v, int L, int R, int l=0, int r=mxn, int i=0) {
  if(l >= R || r <= L) return ;
  if(l >= L && r <= R) {
    int t = min(r-l-st[i], v);
    st[i] += t, tag[i] += t, v -= t;
    return;
  }
    
  int mid = (l+r)/2, lc = i*2+1, rc = i*2+2;
  // push
  if(tag[i]) {
    int tr = (r-mid) - st[rc];
    tr = min(tag[i], tr);
    int tl = tag[i] - tr;
    st[rc] += tr, tag[rc] += tr;
    if(tl > 0) st[lc] += tl, tag[lc] += tl;
    tag[i] = 0;
  }
  update(v, L, R, mid, r, rc);
  if(v) update(v, L, R, l, mid, lc);
  st[i] = st[lc] + st[rc];
}
int query(int L, int R, int l=0, int r=mxn, int i=0) {
  if(l >= R || r <= L) return 0;
  if(l >= L && r <= R) return st[i];
  if(st[i] == r-l) return min(R, r) - max(L, l);
    
  int mid = (l+r)/2, lc = i*2+1, rc = i*2+2;
  // push
  if(tag[i]) {
    int tr = (r-mid) - st[rc];
    tr = min(tag[i], tr);
    int tl = tag[i] - tr;
    st[rc] += tr, tag[rc] += tr;
    if(tl > 0) st[lc] += tl, tag[lc] += tl;
    tag[i] = 0;
  }

  int res = query(L, R, l, mid, lc) + query(L, R, mid, r, rc);
  st[i] = st[lc] + st[rc];
  return res;
}
int main() {
  scanf("%d", &N);
  for(int i=0; i<N; ++i)
    scanf("%d%d%d", &n[i].l, &n[i].r, &n[i].c);
  sort(n, n+N, cmp);

  int ans = 0;

  for(int i=0; i<N; ++i) {
    int q = query(n[i].l, n[i].r+1);
    q = n[i].c - q;
    if(q <= 0) continue;
    ans += q;
    update(q, n[i].l, n[i].r+1);
  }

  printf("%d\n", ans);
}

