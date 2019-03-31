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
inline ll getint(){
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}

////////  template end   //////////

int N;
long double A,B, eps = 1e-9;

void init(){
  cin >> N >> A;
}

inline bool suc(long double x2){
  long double x1 = A;
  for(int i=2;i<N;i++){
    long double tmp = x2*2 - x1 + 2;
    if(tmp<0) return false;
    x1 = x2;
    x2 = tmp;
  }
  B = x2;
  return true;
}

void sol(){
#define mid ((L+R)/2)
  long double L = -eps, R = A + eps;
  for(int i=0;i<50;i++)
    suc(mid) ? R = mid : L = mid;
  suc(R);
  cout << fixed << setprecision(2) << B << endl;
}

int main(){
  init();
  sol();
}

