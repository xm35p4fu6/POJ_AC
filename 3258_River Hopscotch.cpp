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

ll N,M,End,a,b,c, L,R;
ll arr[50005];

void init(){
  End = getint(), N = getint(), M = getint();
  for(int i=0;i<N;i++)
    arr[i] = getint();
  sort(arr, arr+N);
}
inline bool suc(const ll &x){
  a = 0;
  b = M;
  for(int i=0;i<N;++i){
    while(arr[i]-a < x){
      if(b-- == 0)
        return false;
      if(++i == N){
        if(End-a < x)
          return false;
        return true;
      }
    }
    a = arr[i];
  }
  return (!(End-a < x and b <= 0) );
}
ll sol(){
  R = L = End;
  R++;
  for(int i=1;i<N;i++)
    L = min(L,arr[i]-arr[i-1]);
  L = min(L,End-arr[N-1]);
  if(R == L) return L;
#define mid ((L+R)>>1)
  while(R-L>1) 
    suc(mid) ? L=mid : R=mid;
  return L;
}
int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  init();
  cout << sol() << endl;
}

