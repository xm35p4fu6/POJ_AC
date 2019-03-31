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
#include <iomanip>
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
ll arr[100005];

void init(){
  N = getint(), M = getint();
  for(int i=1;i<=N;i++)
    arr[i] = getint();
  for(int i=2;i<=N;i++)
    arr[i] += arr[i-1];
}

void sol(){
  int l=0, r=1, ans=INT_MAX;
  while(r<=N){
    if(arr[r]-arr[l] >= M){
      // 維護答案
      ans = min(ans, r-l);
      ++l;
    }
    else{
      ++r;
    }
  }
  if( ans == INT_MAX ) puts("0");
  else cout << ans << endl;
}

int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  int ncase = getint();
  while(ncase -- ){
    init();
    sol();
  }
}

