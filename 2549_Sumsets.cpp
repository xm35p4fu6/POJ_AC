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
typedef vector<pair<int, pii> >::iterator Iter;
inline bool operator!= (const pii &x, const pii &y){
  return (x.X != y.X && x.X != y.Y && x.Y != y.X && x.Y != y.Y);
}

ll N, arr[1005], ans;

vector<pair<int, pii> > record;

void init(){
  for(int i=0;i<N;i++) arr[i] = getint();
  sort(arr, arr+N, greater<ll>());
  record.clear();
  ans = -INT_MAX;
}

inline bool cmp(const pair<int,pii> &a, const int& b){
  return a.X < b;
}
inline bool succ(int x, int v) {
  return record[x].X <= v;
}

void sol(){
  pair<int, pii> piii;
  int l, r;
  for(int i=0;i<N;i++)for(int j=i+1;j<N;j++){
    piii.X = arr[i] + arr[j];
    piii.Y.X = i;
    piii.Y.Y = j;
    record.PB(piii);
  }
  sort(record.begin(), record.end());
  for(int i=0;i<N;i++)for(int j=0;j<N;j++)if(i!=j){
    l=0, r=record.size();
#define mid ((l+r)>>1)
    while(r-l>1) succ(mid, arr[i]-arr[j]) ? l=mid : r=mid;
    if(arr[i]-arr[j] == record[l].X && MP(i,j) != record[l].Y){
      ans = arr[i];
      return;
    }
  }
}

inline void prin(){
  if(ans == -INT_MAX) puts("no solution");
  else cout << ans << endl;
}

int main(){
  while(cin >> N && N){
    init();
    sol();
    prin();
  }
}

