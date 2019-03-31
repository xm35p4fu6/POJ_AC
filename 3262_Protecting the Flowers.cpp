#include <iostream>
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
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define MXN (1000005)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
ll T,M,N,I,a,b,c,ans,cnt;

pair<double, pii> cow[MXN];

int main(){
  ios::sync_with_stdio(false);cin.tie(0);

  cin>>N;
  for(int i=0;i<N;i++){
    cin >> cow[i].Y.X >> cow[i].Y.Y;
    cow[i].X = (double)cow[i].Y.X/cow[i].Y.Y;
  }
  sort(cow, cow+N);
  cnt = ans = 0;
  for(int i=0;i<N;i++){
    ans += (cnt*cow[i].Y.Y);
    cnt += (cow[i].Y.X<<1);
  }
  cout<<ans<<endl;
}

