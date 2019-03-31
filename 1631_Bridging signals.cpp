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

int T,N,a,i,ans, dp[40005];

int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  scanf("%d", &T);
  while(T--){
    scanf("%d", &N);
    ans = 0;
    while(N--){
      scanf("%d", &a);
      for(i=ans;dp[i]>a;i--);
      if(i == ans)
        ans++;
      dp[i+1] = a;
    }
    printf("%d\n", ans);
  }
}

