#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int goal, n[20], v[20], N;
int dp[100005];

void init(){
  cin >> N;
  for(int i=0;i<N;++i) cin >> n[i] >> v[i];
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
}
void sol(){
  for(int nth=0;nth<N;++nth){
    for(int i=0;i<=goal;++i){
      if(dp[i] >= 0) dp[i] = n[nth];
      else if(i-v[nth] >= 0 and dp[i-v[nth]]) dp[i] = dp[i-v[nth]]-1;
      else dp[i] = -1;
    }
  }
  for(int i=goal;;--i)if(dp[i] >= 0){
    cout << i << endl;
    return;
  }
}

int main(){
  while(cin >> goal){
    init();
    sol();
  }
}