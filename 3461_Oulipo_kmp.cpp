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

int T,M,N,K,I,a,b,c,ans,cnt;
string s,p;

int nxt[10005];
void build(string &s){
  memset(nxt, 0, sizeof(nxt));
  for(int i=2;i<=s.length();i++){
    int p = nxt[i-1];
    while(p>0 && s[i-1] != s[p])
      p = nxt[p];
    if(s[i-1] == s[p])
      p++;
    nxt[i] = p;
  }
}
int kmp(string &s, string &p){
  if(p.length() > s.length())
    return 0;
  int ans = 0, cnt=0;
  build(p);
  for(int i=0;i<s.length();i++){
    while(cnt>0 && s[i] != p[cnt])
      cnt = nxt[cnt];
    if(s[i] == p[cnt])
      cnt++;
    if(cnt == p.length()){
      ans++;
      cnt = nxt[cnt];
    }
  }
  return ans;
}
int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>N;
  while(N--){
    cin>>p>>s;
    cout<<kmp(s, p)<<endl;
  }

}

