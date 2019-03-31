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

int T,M,N,K,I,a,b,c,ans,cnt;
double Len, V;
bool dir[33000];
string name[33000];
char tmp;
pair<double, int> arr[33000];

void init(){
  cin >> Len >> V;
  for(int i=0;i<N;i++){
    cin >> tmp >> arr[i].X >> name[i];
    dir[i] = (tmp == 'p' || tmp == 'P');
    arr[i].Y = i;
  }
  cnt = 0;
}
void sol(){
  int dir0=-1, dir1=-1;
  sort(arr, arr+N);
  for(int i=0;i<N;i++)
    if(dir[arr[i].Y]){
      dir1 = i;
      break;
    }
  for(int i=N-1;i>=0;i--)
    if(!dir[arr[i].Y]){
      dir0 = i;
      break;
    }
  if(dir0==-1 or (dir1!=-1 and Len-arr[dir1].X > arr[dir0].X)){
    for(int i=dir1;i<N;i++) if(!dir[arr[i].Y])
      cnt++;
    int ans = ((Len-arr[dir1].X)/V * 100);
    cout << setw(13) << fixed << setprecision(2)
      << ((double)ans/100) << " " << name[arr[dir1+cnt].Y] << endl;
  }
  else{
    for(int i=dir0;i>=0;i--) if(dir[arr[i].Y])
      cnt++;
    int ans =  (arr[dir0].X/V)*100 ;
    cout << setw(13) << fixed << setprecision(2)
      << ((double)ans/100) << " " << name[arr[dir0-cnt].Y] << endl;
  }
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  while(cin >> N and N){
    init();
    sol();
  }
}

