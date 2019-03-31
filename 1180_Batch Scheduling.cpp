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

int T,M,N,K,I,a,b,c,ans,cnt, arr[10005], pre[10005];
int dp[10005], INF=1e9+7, Time[10005];

int f(int k, int j){
  int t = (M + pre[j]-pre[k])*(arr[N]-arr[k]);
  return dp[k]+t;
}

int main(){
  scanf("%d %d", &N, &M);
  for(int i=1;i<=N;i++){
    scanf("%d %d", pre+i, arr+i);
    pre[i] += pre[i-1];
    arr[i] += arr[i-1];
  }
  int mn = 0;
  for(int i=1;i<=N;i++){
    for(int j=mn;j<i;j++){
      if(f(j,i) < f(mn,i))
        mn = j;
    }
    dp[i] = f(mn, i);
  }
  printf("%d\n", dp[N]);
}

