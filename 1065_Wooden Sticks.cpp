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

ll T,M,N,K,I,a,b,c,ans,cnt;
int dp[5005];
pair<int, int> arr[5005];
void init(){
  memset(dp, -1, sizeof(dp));
  N = getint();
  for(int i=0;i<N;i++)
    arr[i].X = getint(), arr[i].Y = getint();
  sort(arr, arr+N);
}
void sol(){
  dp[0] = INT_MAX;
  for(int i=0;i<N;i++)
    for(int j=0;j<=N && dp[j]!=-1;j++){
      if(dp[j] > arr[i].Y) 
        dp[j+1] = max(dp[j+1], arr[i].Y);
    }
  for(int i=1;i<=N;i++){
    if(dp[i] != -1) ans = i;
    else break;
  }
  cout<<ans<<endl;
}
int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  T = getint();
  while(T--){
    init();
    sol();
  }
}

