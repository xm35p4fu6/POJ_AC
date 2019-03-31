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

int N,K;
double eps = 1e-3;
ll sa[1005], sb[1005];
long double sorting[1005];
void init(){
  for(int i=0;i<N;i++)
    sa[i] = getint() * 100;
  for(int i=0;i<N;i++)
    sb[i] = getint();
}
inline bool suc(long double x){
  long double cnt = 0.0;
  for(int i=0;i<N;i++)
    sorting[i] = (long double)sa[i] - x*sb[i];
  sort(sorting, sorting+N, greater<long double>());
  for(int i=0;i<N-K;i++) cnt += sorting[i];
  return cnt > -eps;
}
int sol(){
  long double L = 0.0, R = 101;
#define mid ((L+R)/2)
  while(R-L>eps) suc(mid) ? L=mid : R=mid;
  return int(L+0.5);
}
int main(){
  while(cin >> N >> K && N+K){
    init();
    cout << sol() << endl;
  }
}

