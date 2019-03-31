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
#include <numeric>
#define X first
#define Y second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
inline int getint(){
  int _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}

////////  template end   //////////

int N,P,K, a,b,l, mx;

vii G[1005];
bool visit[1005];
void init(){
  N = getint(),
  P = getint(),
  K = getint();
  mx = 0;
  while(P--){
    a = getint(),
    b = getint(),
    l = getint();
    mx = max(mx, l);
    G[a].PB(MP(b,l));
    G[b].PB(MP(a,l));
  }
}

typedef priority_queue<pii> pq;
pq q;
int karr[1005];
inline bool suc(int x){
  memset(visit, 0, sizeof(visit));
  fill(karr, karr+N+1, -INT_MAX);
  q = pq();
  karr[1] = K;
  q.push(MP(K,1));
  while(!q.empty()){
    int k = q.top().X, v = q.top().Y;
    q.pop();
    if(visit[v]) continue;
    visit[v] = 1;
    for(int i=0;i<G[v].size();i++){
      int vv = G[v][i].X, len = G[v][i].Y;
      if(!visit[vv] and ((len<=x and k>karr[vv]) or (k>0 and k-1>karr[vv]))){
        if(vv == N) return true;
        if(len <= x){
          q.push(MP(k, vv));
          karr[vv] = k;
        }
        else{
          q.push(MP(k-1, vv));
          karr[vv] = k-1;
        }
      }
    }
  }
  return false;
}

void sol(){
  visit[1] = 1;
#define mid ((L+R)>>1)
  int L = -1, R = mx;   // 注意L為-1才能做到 suc(0) 的case
  if(!suc(mx)){
    puts("-1");
    return;
  }
  while(R-L>1) suc(mid) ? R=mid : L=mid;
  cout << R << endl;
}

int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  init();
  sol();
}

