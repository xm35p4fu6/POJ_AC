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
struct Node{
  int first, second;
  Node(int a=0, int b=0):
    first(a), second(b){}
  bool operator < (const Node& a)const{
    return ((first==a.first) ? (second<a.second) : (first>a.first));
  }//x increase, y decrease
}arr[20005];

////////  template end   //////////

int T,M,N,K,I,a,b,c,ans,cnt, len;
multiset<int> s;
multiset<int>::iterator ubi;
void init(){
  N = getint();
  s.clear();
  for(int i=0;i<N;i++){
    a = getint(),
    b = getint();
    arr[i] = Node(a,b);
  }
}

void sol(){
  sort(arr, arr+N);
  for(int i=0;i<N;i++){
    ubi = s.upper_bound(arr[i].Y);
    if(ubi != s.end()) s.erase(ubi);
    s.insert(arr[i].Y);
  }
  cout << s.size() << endl;
}

int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  T = getint();
  while(T--){
    init();
    sol();
  }
}

