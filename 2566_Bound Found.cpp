#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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

ll T,M,N,K,I,a,b,c,cnt, q;
pll arr[100005];
pii ans;
#define abs(x) ((x) < 0 ? (x)*-1 : (x))
void init(){
  arr[0] = MP(0,0);
  for(int i=1;i<=N;i++) arr[i].X = getint();
  for(int i=1;i<=N;i++){
    arr[i].Y = i;
    arr[i].X += arr[i-1].X;
  }
}
void sol(){
  sort(arr, arr+N+1);
  int f1 = 0, f2 = 1;
  while(M--){
    q = getint();
    f1 = 0, f2 = 1;         // f2 : 下一個要被收進來的  f1 : 下一個要被移出的  range:[f1,f2)
    ans = MP(f1,f2);
    while(f2 <= N){
      if(abs(arr[ans.Y].X - arr[ans.X].X - q) > abs(arr[f2].X - arr[f1].X - q))
        ans = MP(f1,f2);
      if(f1+1<f2 && arr[f2].X - arr[f1].X > q) ++f1;
      else ++f2;
    }

    if( arr[ans.X].Y > arr[ans.Y].Y)
      printf("%lld %lld %lld\n", arr[ans.Y].X-arr[ans.X].X, arr[ans.Y].Y+1, arr[ans.X].Y);
    else
      printf("%lld %lld %lld\n", arr[ans.Y].X-arr[ans.X].X, arr[ans.X].Y+1, arr[ans.Y].Y);
  }
}

int main(){
  while(cin>>N>>M && (N+M)){
    init();
    sol();
  }
}

