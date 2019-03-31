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

////////  template end   //////////

struct Node{
  int f, t, l;
  Node(int F=0, int T=0, int L=0):
    f(F), t(T), l(L){}
  bool operator < (const Node& a)const{
    return l<a.l;
  }
}e[10005];
int T,M,N,K,I,a,b,c,ans,cnt;
int par[105];

void init(){
  cnt = ans = 0;
  for(int i=0;i<N;i++) par[i] = i;
  for(int i=0;i<N;i++)for(int j=0;j<N;j++){
    cin >> a;
    e[cnt++] = Node(i,j,a);
  }
}
int _find(int v){
  return (par[v] == v ? v : par[v] = _find(par[v]));
}
void sol(){
  int t1,t2;
  Node t;
  sort(e, e+cnt);
  for(int i=0;i<cnt;i++){
    t = e[i];
    t1 = _find(t.f), t2 = _find(t.t);
    if(t1 == t2) continue;
    (i&1) ? par[t1]=t2 : par[t2]=t1;
    ans += t.l;
  }
  cout<<ans<<endl;
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  while(cin>>N){
    init();
    sol();
  }
}

