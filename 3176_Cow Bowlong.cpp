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

int T,M,N,I,a,b,c,ans,cnt;
int dp[400][400];

int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  scanf("%d", &N);
  for(int i=0;i<N;i++){
    for(int j=0;j<=i;j++){
      scanf("%d", &a);
      dp[i][j] += a;
      ans = max(dp[i][j], ans);
      dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
      dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
    }
  }
  printf("%d\n", ans);
}

