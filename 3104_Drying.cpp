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

ll N,M,arr[100005],L,R,cnt;

void init(){
  N = getint();
  for(int i=0;i<N;i++){
    arr[i] = getint();
    R = max(R, arr[i]);
  }
  M = getint();
  ++R;
  sort(arr, arr+N);
}
inline bool suc(const ll &x){
  int flag = 0;
  cnt = 0;
  while(flag<N && arr[flag]<=x)
    ++flag;
  for(;flag<N;flag++)
    cnt += ((arr[flag]-x)/(M-1) + (((arr[flag]-x)%(M-1))>0));
  return cnt <= x;
}

ll sol(){
  if(M == 1)
    return R-1;
#define mid ((L+R)>>1)
  while(R-L>1)                // (]
    suc(mid) ? R=mid : L=mid;
  return R;
}

int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  init();
  cout << sol() << endl;
}

