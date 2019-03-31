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

struct Node{
  int f, t, l;
  Node(int F=0, int T=0, int L=0):
    f(F), t(T), l(L){}
  inline bool operator < (const Node& a)const{
    return l<a.l;
  }
}e[20005];

int T,M,N,K,I,a,b,c,ans,cnt;
int par[1005];

void init(){
  ans = cnt = 0;
  N = getint(), M = getint();
  for(int i=0;i<N;i++) par[i] = i;
  for(int i=0;i<M;i++){
    a = getint(), b = getint(), c = getint();
    e[i] = Node(a-1,b-1,c);
  }
}
int _find(int v){
  return ( par[v]==v ? v : par[v]= _find(par[v]));
}
void sol(){
  int t1, t2;
  sort(e, e+M);
  for(int i=0;i<M;i++){
    t1 = _find(e[i].f), t2 = _find(e[i].t);
    if(t1 == t2) continue;
    ans = max(ans, e[i].l);
    (i&1) ? par[t1] = t2 : par[t2] = t1;
  }
  printf("%d\n", ans);
}
int main(){
  init();
  sol();
}

