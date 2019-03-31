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

ll N,M,arr[100005], L,R, sum,cnt;

void init(){
  N = getint(), M = getint();
  for(int i=0;i<N;i++){
    arr[i] = getint();
    L = max(L,arr[i]);
    R += arr[i];
  }
  --L;
}

inline bool suc(const ll &x){
  cnt = sum = 0;
  for(int i=0;++cnt<=M;){
    while(i<N and sum+arr[i]<=x)
      sum += arr[i++];
    if(i==N) return true;
    sum = arr[i++];
  }
  return false;
}

inline ll sol(){
#define mid ((R+L)>>1)
  while(R-L>1)
    suc(mid) ? R=mid : L=mid;
  return R;
}

int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  init();
  cout << sol() << endl;
}

