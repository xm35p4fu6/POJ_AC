#include <iostream>
#include <cmath>
#include <cstring>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#define MP make_pair
#define PB push_back
#define X first
#define Y second
using namespace std;
typedef pair<int, int> PII;
typedef long long ll;

const int INF = 1e9;
int N, K, a,b,c;
int bgsubtr[20001];

vector<int> vec[20001];

int dfs1(int v, int pa){
  int ret = 1, tmp, mx=0;
  for(int i=0;i<vec[v].size();i++)
    if(vec[v][i]!=pa){
      tmp = dfs1(vec[v][i], v);
      ret += tmp;
      mx = max(mx, tmp);
    }
  bgsubtr[v] = max(mx, N-ret);
  return ret;
}

int middle(int v, int pa){
  int ret = -1;
  memset(bgsubtr, -1, sizeof(bgsubtr));
  dfs1(v, -1);
  for(int i=0;i<N;i++)
    if(bgsubtr[i]!=-1 && ( ret == -1|| bgsubtr[i]<bgsubtr[ret])){
      ret = i;
    }
  return ret;
}

int main(){
  int ncase;
  scanf("%d", &ncase);
  while(ncase--){
    scanf("%d", &N);
    for(int i=0;i<N;i++) vec[i].clear();
    for(int i=1;i<N;i++){
      scanf("%d %d", &a, &b);
      a--, b--;
      vec[a].PB(b);
      vec[b].PB(a);
    }
    K = middle(0, -1);
    printf("%d %d\n", K+1, bgsubtr[K]);
  }
}
