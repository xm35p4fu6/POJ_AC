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
inline int getint(){
  int _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}

////////  template end  //////////

int T,M,N,K,I,a,b,c,ans,cnt;
int arr[1000005];
map<int, int> m;

void init(){
  N = getint();
  for(int i=1;i<=N;i++) {
    arr[i] = getint();
    m[arr[i]] ++;
  }
  cnt = m.size();
  m.clear();
}

void sol(){
  int f1 = 0, f2 = 0, ans = N;
  while(f2 <= N){
    if(c == cnt){
      ans = min(ans, f2-f1);
      m[arr[++f1]] --;
      if( m[arr[f1]] == 0 ) c--;
    }
    else{
      m[arr[++f2]] ++;
      if( m[arr[f2]] == 1 ) c++;
    }
  }
  cout << ans << endl;
}

int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  init();
  sol();
}

