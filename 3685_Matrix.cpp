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
inline ll getint(){
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}

////////  template end   //////////

ll T,M,N,K,I,a,b,c,ans;
#define mid ((L+R)>>1)


void init(){
  N = getint(), M = getint();
}

inline ll cal(ll i, ll j){
  return (i*(i+100000)+j*(j-100000)+i*j);
}

inline bool succ(ll i, ll j, ll k){
  return cal(i, j) < k;
}

inline bool suc(ll x){
  ll L,R,cnt = 0;
  for(int i=2;i<=N;i++){
    if( succ(1, i, x) ){
      L = i, R = N+1;
      while(R-L>1) succ(1+mid-i, mid, x) ? L=mid : R=mid;
      cnt += L-i+1;
    }
    if( succ(i, 1, x) ){
      L = i, R = N+1;
      while(R-L>1) succ(mid, 1+mid-i, x) ? L=mid : R=mid;
      cnt += L-i+1;
    }
  }
  if( succ(1, 1, x) ){
    L = 1, R = N+1;
    while(R-L>1) succ(mid, mid, x) ? L=mid : R=mid;
    cnt += L;
  }
  return cnt < M;
}
ll sol(){
  ll L=-12500000001ll, R=12500000001ll;
  while(R-L>1) suc(mid) ? L=mid : R=mid;
  return L;
}

int main(){
  cin >> T;
  while(T--){
    init();
    cout << sol() << endl;
  }
}

