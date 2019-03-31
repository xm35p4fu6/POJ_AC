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
typedef vector<pii> vii;
inline ll getint(){
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}

vector<ll> prim;
bool prim_[46345];

void build(){
  fill(prim_, prim_ + 46345, 1);
  prim_[0] = prim_[1] = 0;
  for(int i=2;i<46345;i++)if(prim_[i]){
    prim.push_back(i);
    for(int j = i*i ; j<46345 ; j+=i)
      prim_[j] = 0;
  }
}

inline bool is_pr(ll x){
  if(x < 46345) return prim_[x];
  for(int i=0;i<prim.size() && prim[i]*prim[i]<=x ; i++) if(x % prim[i] == 0)
    return 0;
  return 1;
}
inline ll mul( ll _x , ll _y , ll _mod ){
  _x *= _y;
  return _x >= _mod ? _x % _mod : _x;
}
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _ret = mypow( mul( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = mul( _ret , _a , _mod );
  return _ret;
}
////////  template end   //////////

ll T,M,N,K,I,a,b,c,ans,cnt;

bool sol(){
  if(is_pr(a)) return false;
  return (mypow(b,a,a) == b);
}

int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  build();
  while(cin>>a>>b && (a+b)){
    cout << ((sol()) ? "yes\n" : "no\n");
  }
}

