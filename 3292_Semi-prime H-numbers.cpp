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
typedef vector<pii> vii;
inline ll getint(){
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}

////////  template end   //////////

ll T,M,N,K,I,a,b,c,ans,cnt;
bool is_pr[1000005];
int rev[1000005];
vector<ll> h, sp, pr;
vector<ll>::iterator iv;
void build(){
  fill(is_pr, is_pr+1000000, 1);
  for(int i=0;(i<<2)+1<1000005;i++){
    rev[(i<<2)+1] = h.size();
    h.PB((i<<2)+1);
  }
  for(int i=1;i<h.size();i++)if(is_pr[i]){
    pr.PB(h[i]);
    for(int j=i;h[i]*h[j]<1000005ll;j++){
      is_pr[rev[h[i]*h[j]]] = 0;
    }
  }
  for(int i=0;i<pr.size();i++)for(int j=0;j<pr.size() && pr[i]*pr[j] < 1000005ll;j++)
    sp.PB(pr[i]*pr[j]);
  sort(sp.begin(), sp.end());
  iv = unique(sp.begin(), sp.end());
  sp.erase(iv, sp.end());
  
}
#define mid ((L+R)>>1)
inline bool suc(int x){
  return (sp[x] <= a);
}
int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  build();
  while(cin>>a && a){
    int L=0, R=sp.size();
    while(R-L>1)
      suc(mid) ? L=mid : R=mid;
    cout << a << " " << (L>0 ? L+1 : 0) << endl;
  }
}

