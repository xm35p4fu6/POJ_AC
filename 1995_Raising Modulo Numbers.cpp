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

inline ll add( ll _x , ll _y , ll _mod){
  _x += _y;
  return _x >= _mod ? _x - _mod : _x;
}
inline ll mul( ll _x , ll _y , ll _mod){
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

int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  cin >> T;
  while(T--){
    ans = 0;
    cin >> M >> N;
    while(N--){
      cin >> a >> b;
      ans = add(ans, mypow(a,b,M), M); 
    }
    cout << ans << endl;
  }
}

