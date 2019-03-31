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
#define X first
#define Y second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vii;

int T,M,N,K,I,a,b,c,ans,cnt;
int dis[301][301], buf[301];

int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  cin >> N >> M;
  for(int i=1;i<=N;i++)
    for(int j=1;j<=N;j++)
      dis[i][j] = (i==j?0:(1<<20));
  while(M--){
    cin >> K;
    for(int i=0;i<K;i++) {
      cin >> buf[i];
      for(int j=0;j<i;j++){
        dis[ buf[i] ][ buf[j] ] = 1;
        dis[ buf[j] ][ buf[i] ] = 1;
      }
    }
  }

  for(int k=1;k<=N;k++)
    for(int i=1;i<=N;i++)
      for(int j=1;j<=N;j++)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

  ll tot,mn=(1ll<<40);
  for(int i=1;i<=N;i++){
    tot = 0;
    for(int j=1;j<=N;j++) 
      tot += dis[i][j];
    if(tot<mn) ans = i, mn = tot;
  }
  double mn_ = mn;
  cout << int((mn_/(double(N-1)))*100) << endl;
}

