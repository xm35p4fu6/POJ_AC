#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility>
#include <functional>
#include <cstring>
#define MP make_pair
#define PB push_back
#define X first
#define Y second
using namespace std;
typedef pair<double, int> PDI;
typedef pair<PDI, int> PDII;

int N,M,a,b,fail, I;
double x,y;
bool in[3000];
vector<PDII> vec; //((x, LorR), index)

void init(){
  fail = 0;
  vec.clear();
  memset(in, 0, sizeof(in));
}

int sol(){
  int ans=0;
  sort(vec.begin(), vec.end(), less<PDII>() );
  for(int i=0;i<vec.size();i++){
    if(vec[i].X.Y == 0)  //L
      in[vec[i].Y] = 1;
    else if(in[vec[i].Y]){
      ans++;
      memset(in, 0, sizeof(in));
    }
  }
  return ans;
}

int main(){
  while(cin>>N>>M && (N+M)){
    I++;
    init();
    for(int i=0;i<N;i++){
      cin>>a>>b;
      if(b>M)fail=1;
      else{
        x = sqrt(double(M*M - b*b));
        vec.PB(MP(MP(-x+a, 0), i));
        vec.PB(MP(MP(x+a, 1), i));
      }
    }
    printf("Case %d: %d\n", I, (fail ? -1 : sol()) );
  }
}
