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
typedef pair<long double, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
inline int getint(){
  int _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}

////////  template end   //////////

int N,K;
int v[100005], w[100005];
int vt[100005], wt[100005];
double eps = 1e-4;
pii sorting[100005];
void init(){
  N = getint(), K = getint();
  for(int i=0;i<N;i++)
    vt[i] = v[i] = getint(), wt[i] = w[i] = getint();   // v, w
}
inline void trick_sort(){
  nth_element(sorting, sorting+K, sorting+N, greater<pii>());
}
inline bool suc(double x){
  double cnt = 0;
  for(int i=0;i<N;i++)
    sorting[i] = MP(- x*w[i] + v[i],i);
  trick_sort();
  for(int i=0;i<K;i++)
    cnt += sorting[i].X;
  return cnt>=-eps;
}
inline double trick(){
  ll cnt1 = 0, cnt2 = 0;
  nth_element(vt, vt+K, vt+N, greater<int>());
  nth_element(wt, wt+K, wt+N);
  for(int i=0;i<K;i++)
    cnt1 += vt[i], cnt2 +=wt[i];
  return (double)cnt1 / cnt2;
}
void sol(){
  double L = 0, R = trick();
#define mid ((L+R)/2)
  while(R-L>eps) suc(mid) ? L=mid : R=mid;
  suc(L);
  for(int i=0;i<K;i++){
    printf("%d", sorting[i].Y+1);
    if(i+1<K) printf(" ");
    else puts("");
  }
}
int main(){
  init();
  sol();
}

