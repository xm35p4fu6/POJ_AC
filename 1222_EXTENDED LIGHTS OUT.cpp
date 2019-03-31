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
bool arr[10][10], flip[10][10], tmp_flip;
int di[] = {0, 0, 0, 1,-1};
int dj[] = {0,-1, 1, 0, 0};
void init(){
  for(int i=0;i<5;i++)
    for(int j=0;j<6;j++)
      arr[i][j] = getint();
}
inline bool ok(int i, int j){
  return (not(i<0 || j<0 || i>=5 || j>=6));
}
inline bool need(int i, int j){
  tmp_flip = 0;
  for(int k=0;k<5;k++)if(ok(i+di[k], j+dj[k]))
    tmp_flip ^= flip[i+di[k]][j+dj[k]];
  tmp_flip ^= arr[i][j];
  return tmp_flip;
}
inline bool cal(){
  for(int i=1;i<5;i++)
    for(int j=0;j<6;j++)
      if(need(i-1, j)) flip[i][j] = 1;
  for(int i=0;i<6;i++) if(need(4, i))
    return false;
  return true;
}
void sol(){
  for(int i=0 ; i<1<<6 ; i++){
    memset(flip, 0, sizeof(flip));
    for(int j=0;j<6;j++)if(i&(1<<j))
      flip[0][j] = 1;
    if(cal()) return;
  }
}

int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  T = getint();
  for(int i=1;i<=T;i++){
    init();
    sol();
    cout << "PUZZLE #" << i << endl;
    for(int i=0;i<5;i++)for(int j=0;j<6;j++)
      cout << flip[i][j] << " \n"[j==5];
  }
}

