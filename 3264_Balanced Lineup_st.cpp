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
#define X first
#define Y second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vii;

#define lt(x) ((x<<1)+1)
#define rt(x) ((x<<1)+2)
#define MID ((l+r)>>1)
int T,M,N,K,Q,I,a,b,c,ans,cnt;
/*
inline ll log2(ll x_){
  return (log(double(x_))/log(2.0));
}
*/
const int VN = 100005, LGN = 20;  // LGN is logN + 1
struct STMX{    // init(), build()/scan() is necessary
  ll ST_[LGN][VN], tmp;
  int N, lgn;
  inline void init(int n){
    N = n;
    lgn = log2(n);
    memset(ST_, 0, sizeof(ST_));
  }
  inline void build(ll *ary){
    for(int i=0;i<N;i++) ST_[0][i] = ary[i];
    build_();
  }
  inline void scan(){
    for(int i=0;i<N;i++) scanf("%lld", &ST_[0][i]);
    build_();
  }
  inline void prin(){
    for(int i=0;i<=lgn;i++){
      for(int j=0;j<=(N-(1<<i));j++)
        printf("%lld ", ST_[i][j]);
      puts("");
    }
  }
  inline ll query(int l, int r){  // []
    tmp = log2(r-l+1);
    return cal_(ST_[tmp][l], ST_[tmp][r-(1<<tmp)+1]);
  }
  inline void build_(){
    for(int i=1;i<=lgn;i++) for(int j=0;j<=(N-(1<<i));j++)
      ST_[i][j] = cal_(ST_[i-1][j], ST_[i-1][j+(1<<(i-1))]);
  }
  inline ll cal_(ll a, ll b){
    return max(a,b);
  }
}stmx;
struct STMN{    // init(), build()/scan() is necessary
  ll ST_[LGN][VN], tmp;
  int N, lgn;
  inline void init(int n){
    N = n;
    lgn = log2(n);
    memset(ST_, 0, sizeof(ST_));
  }
  inline void build(ll *ary){
    for(int i=0;i<N;i++) ST_[0][i] = ary[i];
    build_();
  }
  inline void scan(){
    for(int i=0;i<N;i++) scanf("%lld", &ST_[0][i]);
    build_();
  }
  inline void prin(){
    for(int i=0;i<=lgn;i++){
      for(int j=0;j<=(N-(1<<i));j++)
        printf("%lld ", ST_[i][j]);
      puts("");
    }
  }
  inline ll query(int l, int r){  // []
    tmp = log2(r-l+1);
    return cal_(ST_[tmp][l], ST_[tmp][r-(1<<tmp)+1]);
  }
  inline void build_(){
    for(int i=1;i<=lgn;i++) for(int j=0;j<=(N-(1<<i));j++)
      ST_[i][j] = cal_(ST_[i-1][j], ST_[i-1][j+(1<<(i-1))]);
  }
  inline ll cal_(ll a, ll b){
    return min(a,b);
  }
}stmn;
ll arr[50001];

int main(){
  scanf("%d %d", &N, &Q);
  stmx.init(N);
  stmn.init(N);
  for(int i=0;i<N;i++) scanf("%lld", arr+i);
  stmx.build(arr);
  stmn.build(arr);
  while(Q--){
    scanf("%d %d", &a, &b);
    printf("%lld\n", stmx.query(a-1, b-1)-stmn.query(a-1,b-1));
  }
}

