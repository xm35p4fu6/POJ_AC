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
int z[1020000];

void z_value(string s){
  int l=0, r=0;
  for(int i=1;i<s.length();i++){
    int j = max(min(z[i-l], r-i), 0);
    for(; i+j<s.length() && s[i+j]==s[j];j++);
    z[i] = j;
    if(i+z[i] > r){
      r = i+z[i];
      l = i;
    }
  }
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>N;
  while(N--){
    cin>>p>>s;
    z_value(p+"$"+s);
    int len = p.length() + s.length() + 1, ans = 0;
    for(int i=0;i<len;i++) if(z[i] == p.length())
      ans ++;
    cout<<ans<<endl;
  }

}

