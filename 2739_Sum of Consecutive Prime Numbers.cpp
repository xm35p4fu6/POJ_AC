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

int T,M,N,K,I,a,b,c,ans,cnt;

vector<int> prim;
bool prim_[16345];

void build(){
  fill(prim_, prim_ + 16345, 1);
  prim_[0] = prim_[1] = 0;
  prim.push_back(0);
  for(int i=2;i<16345;i++)if(prim_[i]){
    prim.push_back(i);
    for(int j = i*i ; j<16345 ; j+=i)
      prim_[j] = 0;
  }
}
void pre(){
  build();
  for(int i=1;i<prim.size();i++)
    prim[i] += prim[i-1];
}
void init(){
  ans = 0;
}
void sol(){
  int f1 = 0, f2 = 0;
  while(f2 < prim.size()){
    while(f1+1<f2 && prim[f2]-prim[f1]>N){
      ++f1;
    }
    if(prim[f2]-prim[f1] == N)
      ++ans;
    ++f2;
  }
  cout << ans << endl;
}
int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  pre();
  while( cin >> N && N ){
    init();
    sol();
  }
}

