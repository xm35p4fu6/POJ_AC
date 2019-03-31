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

int M, N, point_cnt, tmp[300005];
pii point[150005], pointd[150005], point_tmp[150005];

inline void discre(){
  
}
inline void init(){
  N = getint(), M = getint();
  point_cnt = (N<<1)+M;
  for(int i=0 ; i<point_cnt ; ++i)
    point[i] = {getint(), getint()};
}
inline void sol(){
  discre();
}

int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  init();
  sol();
}

