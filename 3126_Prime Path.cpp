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
#include <climits>
#include <numeric>
#define X first
#define Y second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
inline ll getint(){
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}

vector<int> prim;
bool prim_[46345];

void build(){
  fill(prim_, prim_ + 46345, 1);
  prim_[0] = prim_[1] = 0;
  for(int i=2;i<46345;i++)if(prim_[i]){
    prim.push_back(i);
    for(int j = i*i ; j<46345 ; j+=i)
      prim_[j] = 0;
  }
}

inline bool is_pr(int x){
  if(x < 46345) return prim_[x];
  for(int i=0;i<prim.size() && prim[i]*prim[i]<=x ; i++) if(x % prim[i] == 0)
    return 0;
  return 1;
}

////////  template end   //////////

int T,M,N,K,I,a,b,c,ans,cnt, head, tail;
int visit[10000];
queue<int> que;
void init(){
  memset(visit, 0, sizeof(visit));
  cin >> head >> tail;
  que.push(head);
  visit[head] = 1;
}
stringstream ss;
string str,ts;
void sol(){
  int x, num;
  if(tail != head)
  while(!que.empty()){
    x = que.front();
    que.pop();
    ss.clear();
    ss << x;
    ss >> str;
    for(int i=0;i<10;i++){
      for(int j=0;j<4;j++)if(str[j]-'0' != i){
        ts = str;
        ts[j] = '0'+i;
        ss.clear();
        ss << ts;
        ss >> num;
        //cout << num << endl;
        if(num == tail){
          cout << visit[x] << endl;
          while(!que.empty()) que.pop();
          return;
        }
        if(!visit[num] && is_pr(num)){
          visit[num] = visit[x]+1;
          que.push(num);
        }
      }
    }
  }
  cout << 0 << endl;
}
int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  build();
  cin >> T;
  while(T--){
    init();
    sol();
  }
}

