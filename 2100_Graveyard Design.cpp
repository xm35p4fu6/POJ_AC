#include <iostream>
#include <cstdlib>
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
#include <iomanip>
#define X first
#define Y second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
inline ll getint(){
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}

////////  template end   //////////

ll T,M,N,K,I,a,b,c,cnt;
vii ans;

void init(){
  ans.clear();
  cnt = 1;
}

void sol(){
  ll f1 = 1, f2 = 1;
  while(f2*f2 <= N){
    while(f1+1<=f2 && cnt > N){
      cnt -= (f1*f1);
      ++f1;
    }
    if(cnt == N) ans.PB(MP(f1,f2));
    ++f2;
    cnt += (f2*f2);
  }
  cout << ans.size() << endl;
  for(int i=0;i<ans.size();i++){
    cout << ans[i].Y-ans[i].X+1 ;
    for(int j=ans[i].X;j<=ans[i].Y;j++)
      cout << " " << j;
    cout << endl;
  }
}

int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  while(cin>>N){
    init();
    sol();
  }
}

