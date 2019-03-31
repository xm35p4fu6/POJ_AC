#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int INF = 0x7f7f7f7f;

int N;
int xin[15], yin[15];
int cover[500], area[500], sz;
int dp[1<<16];

void init(){
  int x1, y1, x2, y2;
  for(int i=0; i<N; ++i) scanf("%d %d", xin+i, yin+i);
  memset(dp, 0x7f, sizeof(dp));
  dp[0] = 0;
  sz = 0;
  for(int i=0; i<N; ++i) for(int j=i+1; j<N; ++j, ++sz){
    x1 = xin[i], x2 = xin[j], y1 = yin[i], y2 = yin[j];
    if(x2 < x1) swap(x1, x2);
    if(y2 < y1) swap(y1, y2);

    cover[sz] = 0;
    for(int k=0; k<N; ++k) 
      if(xin[k] >= x1 and xin[k] <= x2 and yin[k] >= y1 and yin[k] <= y2)
        cover[sz] |= 1<<k;

    area[sz] = max(x2 - x1, 1) * max(y2 - y1, 1);
  }
}

void sol(){
  for(int mask=0; mask<1<<N; ++mask){
    if(dp[mask] == INF) continue;
    for(int i=0; i<sz; ++i) 
      dp[mask | cover[i]] = min( dp[mask | cover[i]], dp[mask] + area[i]);
  }
  printf("%d\n", dp[(1<<N)-1]);
}

int main(){
  while(~scanf("%d", &N) and N){
    init();
    sol();
  }
}
