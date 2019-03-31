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

ll T,M,N,K,I,a,b,c,ans,cnt;

inline bool cmp(const pii &a, const pii &b){
  return (a.X+a.Y)>(b.X+b.Y);
}

pii arr[50001];

void init(){
  N = getint();
  for(int i=0;i<N;i++){
    arr[i].X = getint(), arr[i].Y = getint();
    cnt += arr[i].X;
  }
  sort(arr, arr+N, cmp);
}
ll sol(){
  ll ans = -INT_MAX;
  for(int i=0;i<N;i++){
    cnt -= arr[i].X;
    ans = max(ans, cnt-arr[i].Y);
  }
  return ans;

}

int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  init();
  cout << sol() << endl;
}

