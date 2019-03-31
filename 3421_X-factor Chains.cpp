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

////////  template end   //////////

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

int T,M,N,K,I,a,b,c,ans,cnt;
int arr[100000], flag, sum;
ll frac[50];
void sol(){
  flag = sum = 0;
  for(int i=2;i*i<=a;i++)if(a%i == 0){
    int cnt = 0;
    while(a>1 && a%i==0)
      ++cnt, a/=i;
    arr[flag++] = cnt;
    sum += cnt;
  }
  if(a>1) {
    ++sum;
    arr[flag++] = 1;
  }
  ll ans = frac[sum];
  for(int i=0;i<flag;i++) ans /= frac[arr[i]];
  cout << sum << " " << ans << endl;
}
void build(){
  frac[1] = 1;
  for(int i=2;i<50;i++) frac[i] = frac[i-1] * i;
}
int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  build();
  while(cin>>a){
    sol();
  }
}

