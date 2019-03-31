#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int mxn = 405;

int K;
int dp[40001];
struct node {
  int h, a, c;
  bool operator< (const node &x) const {
    return a < x.a;
  }
} n[mxn];

int main() {
  scanf("%d", &K);
  for(int i=0; i<K; ++i) scanf("%d%d%d", &n[i].h, &n[i].a, &n[i].c);
  sort(n, n+K);
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  int ans = 0;
  for(int j=0; j<K; ++j) for(int i=0; i<=n[j].a; ++i) {
    if(dp[i] >= 0) dp[i] = n[j].c;
    else if(i-n[j].h >= 0 && dp[i-n[j].h] > 0) 
      dp[i] = dp[i-n[j].h] - 1, ans = max(ans, i);
  }
  printf("%d\n", ans);
}
