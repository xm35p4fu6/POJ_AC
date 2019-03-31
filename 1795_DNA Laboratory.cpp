#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int INF = 0x7f7f7f7f;
int N;
string str[15];
int dp[15][1<<15];    // dp[x][S] : 開頭為x 包含S集合的最大重疊長度
vector<int> tdp[15][1<<15];  // dp[x][S] 是由哪邊轉移過來的
int dist[15][15];     // dist[x][y] : 在x前擺y 重疊的長度
char output[1505];

inline bool match(int x, int y, int len){
  for(int i=0; i<len; ++i) if(str[x][len-i-1] != str[y][str[y].length()-i-1]) return false;
  return true;
}
string best, temp;
void prin(int curr, int start, int S) {
  for(int i=start; i<(int)str[curr].length(); ++i) temp.push_back(str[curr][i]);
  if(tdp[curr][S].size() == 0 && temp < best) best = temp;
  if(temp < best){
    for(int i=0, nxt; i<(int)tdp[curr][S].size(); ++i) {     // 決定誰是下一個
      nxt = tdp[curr][S][i];
      prin(nxt, dist[nxt][curr], S^(1<<curr));
    }
  }
  temp.resize(temp.size() + start - str[curr].length());
}
void init(){
  cin >> N;
  for(int i=0; i<N; ++i) cin >> str[i];
  for(int i=0; i<N; ++i) {
    for(int j=0; j<N; ++j) if(i!=j)
      if(str[j].find(str[i]) != string::npos){
        str[i] = str[j];
        break;
      }
  }
  sort(str, str+N);
  N = unique(str, str+N) - str;
  for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) if(i!=j){   // 在i前面放j
    dist[i][j] = 0;
    for(int k=min(str[i].length(), str[j].length()); k>=0; --k) if(match(i,j,k)){
      dist[i][j] = k;
      break;
    }
  }
  //for(int i=0;i<N;++i) cout << i << " " << str[i] << endl;
}

void sol(){
  memset(dp, -1, sizeof(dp));
  for(int i=0; i<N; ++i) {        // 只有一個string 的情況
    dp[i][1<<i] = 0;
  }
  for(int S=1; S<(1<<N); ++S) 
    for(int i=0; i<N; ++i) if( S & (1<<i)) { 
      //cout << i << " " << str[i] << " " << S << " " << dp[i][S] << " " << tdp[i][S] << endl;
      for(int j=0; j<N; ++j) if(~S & (1<<j)) {
        // 在i之前擺上j看看有無比較好(重疊更多)
        if(dp[j][S|(1<<j)] < dp[i][S] + dist[i][j]) {
          dp[j][S|(1<<j)] = dp[i][S] + dist[i][j];
          tdp[j][S|(1<<j)].clear();
          tdp[j][S|(1<<j)].push_back(i);
        }
        else if(dp[j][S|(1<<j)] == dp[i][S] + dist[i][j]) tdp[j][S|(1<<j)].push_back(i);
      }
    }
  int ans = 0, start=0;
  for(int i=1; i<N; ++i) if(dp[i][(1<<N)-1] > dp[ans][(1<<N)-1]) ans = i;
  best = "Zzz", temp = "";
  prin(ans, 0, (1<<N)-1);
  cout << best << endl << endl;
}

int main(){
  int ncase;
  cin >> ncase;
  for(int i=1; i<=ncase; ++i){
    cout << "Scenario #" << i << ":\n";
    init();
    sol();
  }
}
