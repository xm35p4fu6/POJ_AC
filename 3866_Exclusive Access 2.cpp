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

int T,M,N,K,I,c,ans,cnt;
char to_char[20];
int to_int[200], to_grp[200];
bool conn[20][20], withedge[3000000];
int dp[50000], dprecord[50000];
string in[105];

inline bool pre_cal(int mask){
  int lsb = 0;
  while((1<<lsb) & ~mask) ++lsb;
  for(int pos = lsb+1 ; (1<<pos) < mask ; ++pos)
    if(((1<<pos) & mask) && conn[lsb][pos] ) 
      return true;
  return withedge[mask ^ (1<<lsb)];
}

void init(){
  string s1,s2;
  char a,b;
  memset(to_int, -1, sizeof(to_int));
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> s1 >> s2;
    a = s1[0], b = s2[0];
    if(to_int[a] == -1){
      to_int[a] = cnt;
      to_char[cnt++] = a;
    } 
    if(to_int[b] == -1){
      to_int[b] = cnt;
      to_char[cnt++] = b;
    }
    conn[to_int[a]][to_int[b]] = 1;
    conn[to_int[b]][to_int[a]] = 1;
    in[i] = a;
    in[i] += b;
  }
  fill(dp, dp+50000, 30);
  dp[0] = 0;
}
void sol(){
  for(int mask=1 ; mask<(1<<cnt) ; mask++){
    withedge[mask] = pre_cal(mask);
  }

  for(int mask=1 ; mask<(1<<cnt) ; mask++){
    for(int submask=mask ; submask>0 ; submask = ((submask-1)&mask)){
      if(withedge[submask]) continue;
      if(dp[mask-submask] + 1 < dp[mask]){
        dp[mask] = dp[mask-submask] + 1;
        dprecord[mask] = submask;
      }
    }
  }
  
  for(int mask=(1<<cnt)-1, grp=0 ; mask ; ++grp,mask -= dprecord[mask]){
    int sbmsk = dprecord[mask] ; 
    for(int i=0 ; sbmsk>>i ; i++)if((sbmsk>>i) & 1)
      to_grp[i] = grp;
  }
  
  cout << dp[(1<<cnt)-1]-2 << endl;
#define group(x) (to_grp[to_int[in[i][x]]])
  for(int i=0;i<N;i++){
    if( group(0) > group(1)) swap(in[i][0], in[i][1]);
    cout << in[i][0] << " " << in[i][1] << endl;
  }
}

int main(){
  init();
  sol();
}

