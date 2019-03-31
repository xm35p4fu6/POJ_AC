#include <iostream>
#include <cstdio>
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

ll BASE=41, MOD7=1e9+7;
int T,M,N,K,I,a,b,c,ans,cnt;
string s,p;
char in1[10005], in2[1000005];
ll hpat, hstr, hbase;

void init(){
  hbase = 1;
  for(int i=1;i<p.length();i++)
    hbase = (hbase * BASE) % MOD7;
}
ll gethash(string &str){
  ll res = 0;
  for(int i=0;i<p.length();i++){
    res = (res * BASE) % MOD7;
    res = (res + (int)str[i]) % MOD7;
  }
  return res;
}

int sol(){
  if(p.length() > s.length()) return 0;
  int res = 0;
  init();
  hpat = gethash(p);
  hstr = gethash(s);
  for(int i=0;;i++){
    if(hpat == hstr) res++;
    if(i+p.length() >= s.length())
      break;
    hstr = (hstr - ((hbase*s[i]) % MOD7) + MOD7) % MOD7;
    hstr = ((hstr * BASE)%MOD7 + (int)s[i+p.length()]) % MOD7;
  }
  return res;
}
int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>N;
  while(N--){
    cin>>p>>s;
    cout<<sol()<<endl;
  }

}

