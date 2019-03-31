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
inline ll getint(){
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}

////////  template end   //////////
const int VN = 1005, VM = 20005;
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
    for(int i=0;i<N;i++) par[i] = i;
  }
  inline void insert(int f, int t, int l){
    e[M++] = Edge(f,t,l);
  }
  inline void get(int M_){
    M = M_;
    for(int i=0;i<M;i++){
      cin >> e[i].f >> e[i].t >> e[i].l;
      e[i].f--, e[i].t--;
    }
  }
  inline int build(){
    int t1, t2, res=0;
    sort(e, e+M);
    for(int i=0;i<M;i++){
      t1 = _find(e[i].f), t2 = _find(e[i].t);
      if(t1 == t2) continue;
// there, get a edge in mst
      res = max(res, e[i].l);
      (i&1) ? par[t1] = t2 : par[t2] = t1;
    }
    return res;
  }
  int _find(int v) {
    return ( v == par[v] ? v : par[v] = _find(par[v]));
  }
}kk;

void init(){
  int N, M;
  N = getint(), M = getint();
  kk.init(N);
  kk.get(M);
}
void sol(){
  printf("%d\n", kk.build());
}
int main(){
  init();
  sol();
}

