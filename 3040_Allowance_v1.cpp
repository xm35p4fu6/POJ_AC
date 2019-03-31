#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <utility>
#define PB push_back
#define MP make_pair
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
vector<pll> v;
vector<pll>::iterator vi;
ll N, C, a, b, ans, sum;
ll cnt[30], curr, tmp;

int main(){
  cin>>N>>C;
  while(N--){
    cin>>a>>b;
    if(a >= C) ans+=b;
    else{
      v.PB(MP(a,b));
      sum += (a*b);
    }
  }
  sort(v.begin(), v.end(), greater<pll>());

  while(sum >= C){
    curr = C;
    for(vi = v.begin(); vi != v.end();)
      (*vi).Y == 0 ? v.erase(vi) : vi++ ;
    for(int i=0;i<v.size();i++){
      cnt[i] = min(v[i].Y, curr/v[i].X);
      curr -= (cnt[i]*v[i].X);
    }
    for(int i=v.size()-1; i>=0 && curr>0 ; i--)if(v[i].Y - cnt[i]){
      tmp = min(v[i].Y-cnt[i], (curr+v[i].X-1)/v[i].X);
      cnt[i] += tmp;
      curr -= (tmp * v[i].X);
    }
    tmp = (1<<30);
    for(int i=0;i<v.size();i++)if(cnt[i])
      tmp = min(tmp, v[i].Y/cnt[i]);
    for(int i=0;i<v.size();i++)if(cnt[i]){
      v[i].Y -= (tmp*cnt[i]);
      sum -= (tmp*cnt[i]*v[i].X);
    }
    ans+=tmp;
  }
  cout<<ans<<endl;
}
