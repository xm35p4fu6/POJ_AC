#include <iostream>
#include <ctime>
#include <cstdlib>
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

int N;
int g[150][150];

void init(){
  int n, a,b;
  for(int i=1;i<=N;++i)for(int j=1;j<=N;++j) g[i][j] = (1<<20);
  for(int i=1;i<=N;++i){
    scanf("%d", &n);
    for(int j=0;j<n;++j){
      scanf("%d %d", &a, &b);
      g[i][a] = b;
    }
  }
}
void sol(){
  for(int k=1;k<=N;++k)for(int i=1;i<=N;++i)for(int j=1;j<=N;++j)
    if(g[i][j] > g[i][k]+g[k][j]) g[i][j] = g[i][k]+g[k][j];

  int mx=INT_MAX, id;
  for(int i=1;i<=N;++i){
    int m = 0;
    for(int j=1;j<=N;++j)if(i!=j) m = max(g[i][j], m);
    if(m < mx) id=i, mx=m;
  }
  printf("%d %d\n", id, mx);
}

int main(){
  while(~scanf("%d", &N) and N){
    init();
    sol();
  }
}