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
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vii;

int T,M,N,K,I,a,b,c,ans,cnt;
char ch[3];
int par[200005], rk[200005];

int _find(int v){
  return ((par[v] == v) ? v : par[v] = _find(par[v]));
}

void merge(int a, int b){
  int t1 = _find(a), t2 = _find(b);
  if(t1 == t2) return ;
  rk[t1] > rk[t2] ? par[t2] = t1 : par[t1] = t2;
  if(rk[t1] == rk[t2]) rk[t2]++;
}

int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  scanf("%d", &T);
  while(T--){
    scanf("%d %d", &N, &M);
    for(int i=0;i<(N<<1);i++) par[i] = i;
    memset(rk, 0, sizeof(rk));
    while(M--){
      scanf("%s %d %d", ch, &a, &b);
      a--, b--;
      if(ch[0] == 'A'){
        if(_find(a) == _find(b)) puts("In the same gang.");
        else if(_find(a) == _find(b+N)) puts("In different gangs.");
        else puts("Not sure yet.");
      }else{
        merge(a, b+N);
        merge(a+N, b);
      }
    }
  }
}

