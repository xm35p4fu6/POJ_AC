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
typedef vector<int> vi;
typedef vector<pii> vii;
inline int getint(){
  int _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}

////////  template end   //////////

ll N, tar;
vi arr;
void init(){
  int tmp;
  arr.clear();
  for(int i=0;i<N;i++){
    tmp = getint();
    arr.PB(tmp);
  }
  tar = (N * (N-1))>>1;
  tar = (tar-1)>>1; // 中位數前有幾個數字
}
int l,r,cnt;

inline bool suc(ll p){
  l=0, r=0, cnt=0;
  while(r+1<N){
    if(r<l or arr[r+1] - arr[l] < p) 
      ++r;
    else{
      cnt += (r-l);
      ++l;
    }
  }
  cnt += ((r-l+1)*(r-l))>>1;
  return cnt<=tar;
}

int sol(){
  int L=INT_MAX, R;
  sort(arr.begin(), arr.end());
  R = arr.back() - arr[0];
  for( int i=1;i<N;i++ )
    L = min ( L, arr[i] - arr[i-1]);

#define mid ((L+R)/2)
  while(R-L>1) suc(mid) ? L=mid : R=mid;
  return L;
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  while(cin>>N){
    init();
    cout << sol() << endl;
  }
}

