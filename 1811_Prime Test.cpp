#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod7 = 1e9+7;

#define abs(x) ((x)<0 ? (-(x)) : (x) )
inline ll randll(){
  return  ( (ll)rand() << 30 ) + ( rand() << 15 ) + rand();
} 
inline ll add( ll _x , ll _y , ll _mod = mod7 ){
  if(_x > _mod) _x -= _mod;
  if(_y > _mod) _y -= _mod;
  _x += _y;
  return _x >= _mod ? _x - _mod : _x;
}
ll mymul( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 0ll;
  ll _ret = mymul( add( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = add( _ret , _a , _mod );
  return _ret;
}
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _ret = mypow( mymul( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = mymul( _ret , _a , _mod );
  return _ret;
}
inline bool witness(ll a,ll n,ll u,int t){
  ll x = mypow(a, u, n);
  for(int i=0 ; i<t ; i++) {
    ll nx = mymul(x, x, n);
    if(nx==1 && x!=1 && x!=n-1) return 1;
    x=nx;
  }
  return x!=1;
}
bool miller_rabin(ll n,int s=20) {
  if(n<2) return 0;
  if(~n&1) return n == 2;
  ll u=n-1; int t=0;
  while(~u&1) u>>=1, t++;

  while(s--){
    ll a=randll()%(n-1)+1;
    if(witness(a,n,u,t)) return 0;
  }
  return 1;
}
inline ll pollard_rho_f(ll x, ll mod){ return add( mymul(x,x,mod), 1, mod); }
ll pollard_rho(ll n) {
  if(~n&1) return 2;
  while(true){
    ll y=2, x = rand()%(n-1) + 1, res=1;
    for(int sz=2 ; res==1 ; sz<<=1) {
      for(int i=0 ; i<sz && res<=1 ; ++i) {
	x = pollard_rho_f(x, n);
	res = __gcd(abs(x-y), n);
      }
      y = x;
    }
    if (res!=0 && res!=n) return res;
  }
}
typedef pair<ll,ll> pll;
vector<pll> factorization(ll N){    // N > 1
  vector<pll> res;
  ll x,y;

  while(N>1 && !miller_rabin(N)){
    x = pollard_rho(N);
    for(N /= x, y = 1 ; N % x == 0 ; ++y) N /= x;
    res.push_back( {x, y} );
  }
  if(N>1) res.push_back( {N, 1} );
  sort(res.begin(), res.end());
  return res;
}


ll N;
int T;

void init(){
  cin >> T;
}
void sol(){
  while(T--){
    cin >> N;
    const vector<pll> &ans = factorization(N);
    if(ans[0] == make_pair(N,1ll)) puts("Prime");
    else cout << ans[0].first << endl;
  }
}
int main(){
  init();
  sol();
}
