#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int mod7 = 1e6;
int T, A, S, B;
int cnt[1005];
//int dp[100005][1005];

// dp[i][j] := 長度i，j 結尾
// dp[i][j] = dp[i][j-1] + dp[i][j-2] + ... + dp[i][1] ( 0 個 j) 
//          + dp[i-1][j-1] + dp[i-1][j-2] + ... + dp[i-1][1] ( 1 個 j)
//    + ... + dp[i-cj][j-1] + dp[i-cj][j-2] + ... + dp[i-cj][1] ( cnt(j) j)

// dp[i][j] = dp[i-1][j-1] - dp[i-cj-1][j-1]
// dp[i][j] = dp[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]
// dp[i][j] := dp[i-1][j] + dp[i][j-1] - dp[i-cj-1][j-1]

/* i=0:1 0 0 0    1 1 1 1
   i=1 : 1 1 1    1 2 3 4
   i=2 : 1 2 2    1 3 6 9
   i=3 : 0 2 3    1 3 8 14
   i=4 : 0 1 2    1 3 9 17
   i=5 : 0 0 1    1 3 9 18
 */

inline int add(int a, int b, int m=mod7) {
  a += b;
  if(a >= m) a -= m;
  return a;
}
inline int sub(int a, int b, int m=mod7) {
  a -= b;
  if(a < 0) a += m;
  return a;
}

void sol() {
  int dp[B+1][T+1];
  for(int i=0; i<=T; ++i) dp[0][i] = 1;
  for(int len=1; len<=B; ++len) {
    dp[len][0] = 1;
    for(int j=1; j<=T; ++j) {
      int i = len-cnt[j]-1;
      dp[len][j] = add(dp[len][j-1], dp[len-1][j]);
      if(i >= 0) dp[len][j] = sub(dp[len][j], dp[i][j-1]);
    }
  }
//  for(int i=0; i<=B; ++i) for(int j=0; j<=T; ++j)
//    printf("%d%c", dp[i][j], " \n"[j==T]);
  printf("%d\n", sub(dp[B][T], dp[S-1][T]));
}

int main() {
  int a;
  scanf("%d%d%d%d", &T, &A, &S, &B);
  for(int i=0; i<A; ++i) {
    scanf("%d", &a);
    ++cnt[a];
  }
  sol();

}
