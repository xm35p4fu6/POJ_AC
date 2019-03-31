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
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
inline ll getint(){
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}

////////  template end   //////////
inline ll gcd(ll a, ll b){
  while( a ){
    b = b%a;
    swap(a,b);
  }
  return b;
}

ll a,b;

map<pll, pll> dp;

void sol(){
  ll A = a, B = b;
  b /= a;
  ll x = sqrt(lb(b));
  x ++ ;
  while(x){
    if(b % x == 0){
      ll aa = x*a , bb = b/x*a;
      if ( aa > bb ) swap ( aa,bb);
      cout << aa << " " << bb << endl;
      dp[MP(A,B)] = MP(aa, bb);
      return ;
    }
    x -= gcd(x,b);
  }
}
int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  while(cin>>a>>b){
    if(dp.count(MP(a,b))) cout << dp[MP(a,b)].X << " " << dp[MP(a,b)].Y << endl;
    else
      sol();
  }
}

