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

int T=1,M,N,K,I,a,b,c,ans,cnt;
int di[] = {-1,0};
bool arr[30], flip[30], tmp_flip;

void init(){
  for(int i=0;i<20;i++) arr[i] = getint();
  ans = INT_MAX;
}

inline bool ok(int &v){
  return (not(v<0 || v>=20));
}

inline bool need(int &i){
  int ii;
  tmp_flip = 0;
  for(int j=0;j<2;j++)if(ok(ii=i+di[j]))
    tmp_flip ^= flip[ii];
  tmp_flip ^= arr[i];
  return tmp_flip;
}
void cal(){
  int times = flip[0], last = 19;
  
  for(int i=0;i<19;i++){
    if(need(i)){
      flip[i+1]=1;
      ++times;
    }
  }
  
  if(!need(last)) ans = min(ans, times);
}
void sol(){
  for(int I=0;I<2;I++){ // 假設第一個碗的flip狀況
    memset(flip, 0, sizeof(flip));
    flip[0] = I;
    cal();
  }
  cout << ans << endl;
}

int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  //cin >> T;
  while(T--){
    init();
    sol();
  }
}

