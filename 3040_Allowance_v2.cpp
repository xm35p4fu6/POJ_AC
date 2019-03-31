#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
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
ll cnt[30], pos[30], curr, tmp;

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
    memset(cnt, 0, sizeof(cnt));
    for(vi = v.begin(); vi != v.end();)
      (*vi).Y == 0 ? v.erase(vi) : vi++ ;
    pos[v.size()-1] = v[v.size()-1].X * v[v.size()-1].Y;
    for(int i=v.size()-1; i; i--)
      pos[i-1] = pos[i] + v[i-1].X * v[i-1].Y;
    for(int i=0;i<v.size();i++){
      cnt[i] = min(v[i].Y, curr/v[i].X);
      curr -= (cnt[i]*v[i].X);
      if((curr > 0 && i == v.size()-1 )|| curr > pos[i+1]){
        cnt[i]++;
        if(i < v.size()-1)
          for(int j = i+1;j<v.size();j++){
            sum -= (v[j].X * v[j].Y);
            v[j].Y=0;
          }
        break;
      }
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
