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
#define abs(x) ((x)<0 ? (-(x)) : (x) )
typedef pair<ll, int> li;     // sum, size
li operator+ (const li &x, const li &y){
  li res = MP(x.X + y.X, x.Y + y.Y);
  return res;
}

int N, cnt;
ll arr[40], sum;
map<ll, int> part1, part2;
typedef map<ll, int>::iterator Iter;
li ans;

void cal_part(ll arr[], int sz, map<ll, int> &part){

  for(int i=1 ; i<1<<sz ; i++){
    sum = cnt = 0;
    for(int j=0 ; j<sz ; j++) if(i&(1<<j)){
      ++ cnt;
      sum += arr[j];
    }
    int &ori_size = part[sum];
    if(ori_size == 0 || ori_size > cnt ) 
      ori_size = cnt;
  }
}

inline void maintain_ans(li x){
  x.X = abs(x.X);
  ans = min(ans, x);
}

void init(){
  for(int i=0;i<N;i++) arr[i] = getint();
  part1.clear();
  part2.clear();
}

void sol(){
  if(N == 1){     // poor special case
    ans = MP(abs(arr[0]), 1);
    return;
  }
  cal_part ( arr, N>>1, part1 );
  cal_part ( arr+(N>>1), N - (N>>1), part2 );

  ans = MP(abs(sum), cnt);   // 拿最後一個當作初始答案
  
  Iter iter1 = part1.upper_bound(0), iter2 = part2.upper_bound(0);

  if(iter1 != part1.end() ) maintain_ans(*iter1);
  if(iter1 != part1.begin() ) maintain_ans(*(--iter1));

  if(iter2 != part2.end() ) maintain_ans(*iter2);
  if(iter2 != part2.begin() ) maintain_ans(*(--iter2));

  for(iter1 = part1.begin() ; iter1 != part1.end() ; ++iter1){
    iter2 = part2.upper_bound( -(*iter1).X );
    if(iter2 != part2.end() ) maintain_ans(*iter1 + *iter2);
    if(iter2 != part2.begin() ) maintain_ans(*iter1 + *(--iter2));
  }

}

inline void prin(){
  cout << ans.X << " " << ans.Y << endl;
}

int main(){
  while(cin >> N && N ){
    init();
    sol();
    prin();
  }
}

