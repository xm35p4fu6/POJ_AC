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
//

int N, sz;
int x[100005], y[100005], xN, yN;
// l r : query of each row
bool start[100005];
int l[100005], r[100005], t[100005];
int bit[200005];
vector<int> g[100005];
pii arr[100005];
ll ans;

inline int lowerbit(const int& x){
  return x&-x;
}
inline int sum(int pos){
  ll res = 0;
  for(; pos ; pos-=lowerbit(pos)) res += bit[pos];
  return res;
}
inline int query(const int& l, const int& r){
  if(l>r) return 0;
  return sum(r) - sum(l-1);
}
inline void add(int pos, const int& val){
  for(; pos <= sz ; pos+=lowerbit(pos) ) 
    bit[pos]+=val;
}
void init(){
  ans = N = getint();
  for(int i=0;i<N;i++){
    x[i] = arr[i].X = getint();
    y[i] = arr[i].Y = getint();
  }
}

void sol(){
  // x y 離散化
  sort(x, x+N);
  sort(y, y+N);
  xN = unique(x, x+N) - x;
  yN = unique(y, y+N) - y;
  sz = (1<<(int)ceil(log2(yN)));

  // 重新給編號
  for(int i=0;i<N;i++){
    arr[i].X = lower_bound(x, x+xN, arr[i].X) - x + 1;
    arr[i].Y = lower_bound(y, y+yN, arr[i].Y) - y + 1;
    if( l[arr[i].X] == 0 or l[arr[i].X] > arr[i].Y ) l[arr[i].X] = arr[i].Y;
    if( r[arr[i].X] == 0 or r[arr[i].X] < arr[i].Y ) r[arr[i].X] = arr[i].Y;    // 紀錄每個row要詢問的區間
    if( t[arr[i].Y] == 0 or t[arr[i].Y] < arr[i].X ) t[arr[i].Y] = arr[i].X;    // 紀錄每個column的結尾
    g[arr[i].X].push_back(arr[i].Y);
  }

  // 掃描每個row, 先移除會重複計算黑子，詢問區間內哪些點可以轉黑, 之後再插入該插入的棋子
  for(int i=1;i<=xN;i++){
    for(size_t j=0;j<g[i].size();j++)if(start[g[i][j]] and g[i][j]>l[i] and g[i][j]<r[i])
      add(g[i][j], -1), start[g[i][j]] = 0;       // 區間內會重複計算
    ans += query(l[i]+1, r[i]-1);
    for(size_t j=0;j<g[i].size();j++){
      if(start[g[i][j]] and t[g[i][j]] == i)
        add(g[i][j], -1), start[g[i][j]] = 0;
      else if(!start[g[i][j]] and t[g[i][j]] != i)
        add(g[i][j], 1), start[g[i][j]] = 1;
    }
  }
  cout << ans << endl;
}

int main(){
  init();
  sol();
}

