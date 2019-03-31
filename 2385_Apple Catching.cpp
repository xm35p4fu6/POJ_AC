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
int dp[2][35];

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>N>>M;
  dp[1][0] = -10;
  while(N--){
    cin>>a; --a;
    dp[a][0]++;
    for(int i=1;i<=M;i++){
      dp[a][i] = max(dp[a][i], dp[!a][i-1])+1;
      ans = max(dp[a][i], ans);
    }
  }
  cout<<max(ans, max(dp[1][0], dp[0][0]))<<endl;
}

