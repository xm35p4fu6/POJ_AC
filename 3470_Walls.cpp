#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
typedef long long ll;

int N, M;
const ll inf = 1ll<<60;

struct Wall {
  ll x1, y1, x2, y2;
};

struct Bird {
  ll x, y;
};

struct Sort {
  ll k1, k2, i;
};  // k1=set key k2=sort key   i:= (>N =bird), (<0->+N, <N =wall)

vector<Wall> w;
vector<Bird> b;
vector<Sort> s; 
vector<ll> dis, tar;
bool c1(const Sort &s1, const Sort &s2) {
  return ((s1.k2 == s2.k2) ? s1.i < s2.i : s1.k2 < s2.k2);
}
struct C1 {
  bool operator() (const Sort &s1, const Sort &s2) const {
    return ((s1.k1 == s2.k1) ? s1.i < s2.i : s1.k1 < s2.k1);
  }
};

void fly(bool tag) {   // toward small (left, down)
  set<Sort, C1> g;
  set<Sort, C1> :: iterator it;
  for(size_t i=0; i<s.size(); ++i) {
    Sort &t = s[i];
    if(t.i >= N) {       // bird
      t.i -= N;
      it = g.lower_bound(t);
      if((tag && it != g.begin()) || (!tag && it != g.end())){
        if(tag) --it;
        int d = t.k1 - it->k1;
        if(!tag) d = -d;
        if(d < dis[t.i]) {
          dis[t.i] = d;
          tar[t.i] = it -> i;
        }
      }
    }
    else if(t.i < 0) {  // wall, end
      t.i += N;
      g.erase(t);
    }
    else {              // wall, start
      g.insert(t);
    }
  }
}

void sol() {
  // fly left
  for(int i=0; i<N; ++i) {
    s[i] = {w[i].x2, w[i].y1, i};
    s[N+i] = {w[i].x2, w[i].y2+1, i-N};
  }
  for(int i=0; i<M; ++i)
    s[N*2+i] = {b[i].x, b[i].y, N+i};
  sort(s.begin(), s.end(), c1);
  fly(1);

  // fly down
  for(int i=0; i<N; ++i) {
    s[i] = {w[i].y2, w[i].x1, i};
    s[N+i] = {w[i].y2, w[i].x2+1, i-N};
  }
  for(int i=0; i<M; ++i)
    s[N*2+i] = {b[i].y, b[i].x, N+i};
  sort(s.begin(), s.end(), c1);
  fly(1);

  // fly right
  for(int i=0; i<N; ++i) {
    s[i] = {w[i].x1, w[i].y1, i};
    s[N+i] = {w[i].x1, w[i].y2+1, i-N};
  }
  for(int i=0; i<M; ++i)
    s[N*2+i] = {b[i].x, b[i].y, N+i};
  sort(s.begin(), s.end(), c1);
  fly(0);

  // fly up
  for(int i=0; i<N; ++i) {
    s[i] = {w[i].y1, w[i].x1, i};
    s[N+i] = {w[i].y1, w[i].x2+1, i-N};
  }
  for(int i=0; i<M; ++i)
    s[N*2+i] = {b[i].y, b[i].x, N+i};
  sort(s.begin(), s.end(), c1);
  fly(0);


  vector<int> cnt(N);
  for(int i=0; i<M; ++i)
    ++cnt[tar[i]];
  for(int i=0; i<N; ++i)
    printf("%d\n", cnt[i]);
  /*
  for(int i=0; i<M; ++i) {
    printf("%d(%d,%d): %d:%d (%d,%d,%d,%d)\n",
        i, b[i].x, b[i].y, tar[i], dis[i],
        w[tar[i]].x1,w[tar[i]].y1, w[tar[i]].x2, w[tar[i]].y2);
  }
  */
}

int main() {
  scanf("%d%d", &N, &M);
  w.resize(N);
  b.resize(M);
  dis.resize(M, inf);
  tar.resize(M);
  s.resize(2*N+M);
  for(int i=0; i<N; ++i) {
    scanf("%lld%lld%lld%lld", &w[i].x1, &w[i].y1, &w[i].x2, &w[i].y2);
    if(w[i].x1 > w[i].x2) swap(w[i].x1, w[i].x2);
    if(w[i].y1 > w[i].y2) swap(w[i].y1, w[i].y2);
  }
  for(int i=0; i<M; ++i)
    scanf("%lld%lld", &b[i].x, &b[i].y);

  sol();
}
