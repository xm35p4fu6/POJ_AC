#include <iostream>
#include <ctime>
#include <cstdlib>
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
#include <numeric>
#include <iomanip>

using namespace std;

int N1;

const int VN = 30005, VM = 70005;
struct KK{          // init is necessary
  int N, M, par[VN];
  struct Edge{
    int f, t, l;
    Edge(int F=0, int T=0, int L=0):f(F), t(T), l(L){}
    inline bool operator < (const Edge& a)const{
      return l<a.l;
    }
  }e[VM];
  
  inline void init(int N_){
    N = N_, M = 0;
    for(int i=0;i<=N;i++) par[i] = i;
  }
  inline void insert(int f, int t, int l){
    e[M++] = Edge(f,t,10000-l);
  }
  inline void get(int M_){
    M = M_;
    for(int i=0;i<M;i++){
      scanf("%d %d %d", &(e[i].f), &(e[i].t), &(e[i].l));
      e[i].t += N1;
      e[i].l = 10000-e[i].l;
    }
  }
  inline long long build(){
    int t1, t2;
    long long res=0;
    sort(e, e+M);       // 排序所有邊
    for(int i=0;i<M;i++){
      t1 = _find(e[i].f), t2 = _find(e[i].t);
      if(t1 == t2) continue;    // 如果在同一個disjoint set
      res += e[i].l;    // 答案加上邊的權重
      (i&1) ? par[t1] = t2 : par[t2] = t1;  // 合併disjoint set
    }
    return res;
  }
  int _find(int v) {
    return ( v == par[v] ? v : par[v] = _find(par[v]));
  }
}kk;

int N;
void init(){
  int n,m,q;
  scanf("%d %d %d", &n, &m, &q);
  N1 = n;
  N = n+m;
  kk.init(N);
  kk.get(q);
}
void sol(){
  for(int i=0;i<N;++i) kk.insert(N, i, 0);
  cout << kk.build() << endl;
  /*
  int ans = kk.build();
  map<int, int> cnt;
  for(int i=0;i<N;++i) cnt[kk._find(i)]++;
  printf("%d\n", ans + (cnt.size())*10000);
  */

}
int main(){
  int ncase;
  scanf("%d", &ncase);
  while(ncase--){
    init();
    sol();
  }
}