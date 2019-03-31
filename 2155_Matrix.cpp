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

int N, Q, sz, x_1, x_2, y_1, y_2;
int bit[2050][2050];

inline int lowerbit(const int &x) { return x&(-x); }

inline void insert(const int &x, const int &y, const int &val){
  for(int xx=x ; xx<=sz ; xx+=lowerbit(xx)){
    for(int yy=y ; yy<=sz ; yy+=lowerbit(yy))
      bit[xx][yy] += val;
  }
}

inline int query(const int& x, const int &y){
  int res = 0;
  for(int xx=x ; xx ; xx-=lowerbit(xx))
    for(int yy=y ; yy ; yy-=lowerbit(yy))
      res += bit[xx][yy];
  return res&1;
}

void init(){
  cin >> N >> Q;
  sz = 1<<(int)ceil(log2(N+1));
  for(int i=1;i<=sz;i++)
    memset(bit[i], 0, sizeof(int)*(sz+1));
}
char ch;
void sol(){
  while(Q--){
    cin >> ch;
    if(ch == 'C'){
      cin >> x_1 >> y_1 >> x_2 >> y_2;
      insert(x_1, y_1, 1);      // 使用差分矩陣
      insert(x_1, y_2+1, -1);
      insert(x_2+1, y_1, -1);
      insert(x_2+1, y_2+1, 1);
    }else{
      cin >> x_1 >> y_1;
      cout << query(x_1, y_1) << endl;
    }
  }
}



int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  int ncase = 1;
  cin >> ncase;
  while(ncase--){
    init();
    sol();
    if(ncase) cout << endl;
  }
}

