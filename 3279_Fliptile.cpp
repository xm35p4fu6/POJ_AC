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
int di[] = {0,-1, 0, 1, 0}; // to move
int dj[] = {0, 0, 1, 0,-1};
bool arr[20][20], flip[20][20], tmp_flip;
pii ans;    // {times, flip of first row}

void init(){
  N = getint(), M = getint();
  for(int i=0;i<N;i++)for(int j=0;j<M;j++)
    arr[i][j] = getint();   // need to be reversed
}
inline bool ok(int &i, int &j){
  return not(i<0 or j<0 or i>=N or j>=M);
}
inline bool need(int i, int j){
  int ii,jj;
  tmp_flip = 0;
  for(int k=0;k<5;k++)
    if(ok(ii=i+di[k], jj=j+dj[k]))
      tmp_flip ^= flip[ii][jj];
  return tmp_flip^arr[i][j];
}
int cal(){
  int times = 0;    // 注意，此時第0列已經flip，未記錄
  for(int i=0;i+1<N;i++)
    for(int j=0;j<M;j++)
      if(need(i,j)) flip[i+1][j]=1, ++times;

  for(int i=0;i<M;i++){
    times += flip[0][i];  // 補紀錄第0列
    if(need(N-1, i)) return -1;
  }
  return times;
}
// 只要翻好第一排，就唯一決定了全部的翻法
void sol(){
  ans = MP(INT_MAX, 1);
  for(int i=0;i<1<<M;i++){  // enumerate all status of flip
    memset(flip, 0, sizeof(flip));

    for(int j=0;j<M;j++)if((i>>j)&1)
      flip[0][j] = 1;

    a = cal();
    if(a > -1 and a < ans.X) ans = MP(a, i);
  }
  if(ans.X == INT_MAX) puts("IMPOSSIBLE");
  else {
    memset(flip, 0, sizeof(flip));

    for(int j=0;j<M;j++)if((ans.Y>>j)&1)
      flip[0][j] = 1;

    cal();
    
    for(int i=0;i<N;i++)for(int j=0;j<M;j++)
      cout << flip[i][j] << " \n"[j==M-1];
  }
}

int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  init();
  sol();
}

