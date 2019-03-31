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
/*
inline ll gcd(ll a, ll b){
  while( a ){
    b = b%a;
    swap(a,b);
  }
  return b;
}
*/

string str;
ll num;
int leng ;
pll ans;

pll sol(int x){
  ll ry=0,rx=num;
  for(int i=0;i<x;i++){
    rx /= 10;
    ry *= 10;
    ry += 9;
  }
  for(int i=x;i<leng;i++) ry *= 10;
  rx = num - rx;
  ll gcd = __gcd(rx, ry);
  return MP(rx/gcd, ry/gcd);
}

int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  while(cin >> str && str.length()>1){
    leng = num = 0;
    for(int i=2;i<str.length();i++){
      if(str[i] == '.') break;
      num *= 10;
      num += (str[i]-'0');
      leng ++;
    }
    
    ans = sol(1);
    for(int i=2;i<=leng;i++){
      pll x = sol(i);
      if(x.Y < ans.Y) ans = x;
    }
    cout << ans.X << '/' << ans.Y << endl;
  }
}

