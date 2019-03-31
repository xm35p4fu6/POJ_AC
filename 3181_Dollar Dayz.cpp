#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long ll;

struct bigInt {
  static const ll mod = 1e17;
  ll a1, a2;
  bigInt() { a1 = -1ll, a2 = -1ll;}
  bigInt(ll x1, ll x2) { a1 = x1, a2 = x2; }
  bigInt operator+ (const bigInt &r) const{
    bigInt res(0, 0);
    res.a2 = a2 + r.a2;
    res.a1 = a1 + r.a1 + res.a2/mod;
    res.a2 %= mod;
    return res;
  }
} dp[1001][101];

bigInt cal(int n, int m) {
  if(!(dp[n][m].a1 == -1ll && dp[n][m].a2 == -1ll)) return dp[n][m];
  dp[n][m] = {0, 0};
  for(int i=0; n-i*m >=0; ++i)
    dp[n][m] = dp[n][m] + cal(n-i*m, m-1);
  return dp[n][m];
}

int main() {
  int N, K;
  scanf("%d%d", &N, &K);
  dp[0][0] = bigInt(0, 1);
  for(int i=1; i<=N; ++i) dp[i][1] = bigInt(0, 1);
  bigInt res = cal(N, K);
  if(res.a1) cout << res.a1;
  cout << res.a2;
  cout << endl;
}
