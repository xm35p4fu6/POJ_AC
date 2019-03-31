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

int T,M,N,K,I,b,c,ans,cnt;
char a;
int arr[200], dp[2002][2002];
string str;

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>N>>M>>str;
  for(int i=0;i<N;i++){
    cin>>a>>b>>c;
    arr[a] = min(b, c);
  }
  for(int i=2 ; i<=M ; i++) for(int j=0 ; j+i<=M ; j++){
    dp[j][j+i] = min(dp[j][j+i-1]+arr[ str[j+i-1] ], dp[j+1][j+i]+arr[ str[j] ]);
    if(str[j] == str[j+i-1]) dp[j][j+i] = min(dp[j][j+i], dp[j+1][j+i-1]);
  }
  cout<<dp[0][M]<<endl;
}

