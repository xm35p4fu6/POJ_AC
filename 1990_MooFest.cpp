#include <iostream>
#include <cstdlib>
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
#include <iomanip>
#define X first
#define Y second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
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

int N;
pii arr[20005], bit[(1<<15) +1], q1, q2;   // BIT : {cnt, sum}
ll ans;

inline pii operator -= (pii& p1, const pii& p2){
  p1.X -= p2.X;
  p1.Y -= p2.Y;
  return p1;
}
inline pii operator += (pii& p1, const pii& p2){
  p1.X += p2.X;
  p1.Y += p2.Y;
  return p1;
}

inline int lower_bit(int& x) { return x&(-x); }

inline pii query(int v){
  pii res = bit[v];
  for( v-=lower_bit(v) ; v ; v-=lower_bit(v) )
    res += bit[v];
  return res;
}

inline void add(int val){
  pii x = MP(1, val);
  for(int v = val ; v <= 1<<15 ; v+=lower_bit(v) )
    bit[v] += x;
}

void init(){
  N = getint();
  for(int i=1;i<=N;i++) 
    arr[i].X = getint(), arr[i].Y = getint();
  ans = 0;
}

void sol(){
  sort(arr+1, arr+N+1);
  for(int i=1;i<=N;i++){
    q1 = query(arr[i].Y);   // {cnt, sum}
    q2 = query(1<<15);
    q2 -= q1;
    // q1 : less or equal than this coordinate 
    //ans += arr[i].X * (arr[i].Y*q1.X - q1.Y + q2.Y - arr[i].Y*q2.X);

    ans += arr[i].X * (arr[i].Y * (q1.X - q2.X) - q1.Y + q2.Y);
    add(arr[i].Y);
  }
  cout << ans << endl;
}

int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  init();
  sol();
}

