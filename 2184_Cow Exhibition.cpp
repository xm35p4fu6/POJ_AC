#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int mxn = 200000;
const int inf = 0x80808080;

int N;
int dp[mxn + 1];
int s[101], f[101], n;

int main() {
  scanf("%d", &N);
  for(int i=0; i<N; ++i) {
    scanf("%d%d", s+n, f+n);
    if(s[n]>0 || f[n]>0) ++n;
  }
  N = n;
  if(N == 0) {
    puts("0");
    return 0;
  }
  memset(dp, 0x80, sizeof(dp));
  dp[mxn/2] = 0;

  int ans = 0;
  for(int i=0; i<N; ++i) {
    if(s[i] >= 0) {
      for(int j=mxn; j-s[i]>=0; --j) if(dp[j-s[i]] != inf)
        dp[j] = max(dp[j], dp[j-s[i]] + f[i]);
    }
    else {
      for(int j=0; j-s[i]<=mxn; ++j) if(dp[j-s[i]] != inf)
        dp[j] = max(dp[j], dp[j-s[i]] + f[i]);
    }
  }
  for(int i=mxn/2; i<=mxn; ++i) if(dp[i] >= 0)
    ans = max(ans, dp[i] - mxn/2 + i);

  printf("%d\n", ans);
}
