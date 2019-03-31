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
typedef pair<ll, ll> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll, pii> piii;
inline ll getint(){
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}

////////  template end   //////////

ll T,M,N,K,I,a,b,c,ans,cnt;
string in;
stringstream ss;
vector< piii > vec;

inline bool suc(ll x){
  cnt = 0;
  for(int i=0;i<vec.size();i++){
    if(vec[i].X > x) continue;
    cnt += (((min(vec[i].Y.X, x) - vec[i].X)/vec[i].Y.Y)+1);
  }
  return (cnt&1);
}
void sol(){
  ll R=0,L=0;
  vec.clear();
  do{
    ss.clear();
    ss.str(in);
    ss >> a >> b >> c;
    R = max(R,b);
    vec.PB(MP(a,MP(b,c)));
  }while(getline(cin, in) and in != "");
#define mid ((L+R)>>1)
  if(!suc(R)){
    cout << "no corruption" << endl;
    return;
  }
  while(R-L>1) suc(mid) ? R=mid : L=mid;
  suc(R);
  ll c2 = cnt;
  suc(R-1);
  cout << R << " "<< c2-cnt << endl;
}

int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  while(getline(cin, in)){
    if(in != ""){
      sol();
    }
  }
}

