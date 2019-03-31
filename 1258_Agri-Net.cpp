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

int T,M,N,K,I,a,b,c,ans,cnt;
int dis[105][105];
bool mst[105];
priority_queue<pii> q;

void init(){
  memset(mst, 0, sizeof(mst));
  ans = 0;
  for(int i=0;i<N;i++)for(int j=0;j<N;j++)
    cin>>dis[i][j];
}
void sol(){
  int v,w;
  mst[0] = 1;
  for(int i=0;i<N;i++)if(dis[0][i])
    q.push(MP(-dis[0][i], i));
  while(!q.empty()){
    v = q.top().Y, w = -q.top().X;
    q.pop();
    if(mst[v]) continue;
    mst[v] = 1;
    ans += w;
    for(int i=0;i<N;i++)if(!mst[i] && dis[v][i])
      q.push(MP(-dis[v][i], i));
  }
  cout<<ans<<endl;
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  while(cin>>N){
    init();
    sol();
  }
}

