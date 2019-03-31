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

int T,M,N,K,I,a,b,c,cnt;
char ch;
int arr[5005];
pii ans;    // {times, K}

void init(){
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> ch;
    arr[i] = (ch == 'B'); // need to be reversed
  }
}
int flip[5005], k;
inline bool get_dir(int &v){
  if(v-k<0) return (flip[v-1]&1)^arr[v];
  return ((flip[v-1]-flip[v-k])&1)^arr[v];
}
pii cal(){
  memset(flip, 0, sizeof(flip));
  int times = flip[0] = arr[0];
  for(int i=1;i+k-1<N;i++){
    flip[i] = flip[i-1];
    if(get_dir(i))
      ++times, ++flip[i];
  }
  // check if wrong direction
  for(int i=N-k+1;i<N;i++){
    flip[i] = flip[i-1];
    if(get_dir(i))  
      return make_pair(INT_MAX, 1);
  }
  return make_pair(times, k);
}
void sol(){
  k = 1;
  ans = cal();
  for(int i=2;i<=N;i++){  // K
    k = i;
    ans = min(ans, cal());
  }
  cout << ans.Y << " " << ans.X << endl;
}
int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  init();
  sol();
}

