#include <iostream>
#define GI(i) scanf("%d", &i)
using namespace std;

typedef long long LL;

const int MAXN = 1000000;
double eps = 1e-9;

char arr[50][50];
int ncase,N,M, act[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
LL a,b,c;
inline bool ok(int i, int j){
  if(i<0 || j<0 || i>=N || j>=M || arr[i][j]!='.')return false;
  return true;
}
int dfs(int ii, int jj){
  int tmp = 1, ti, tj;
  arr[ii][jj] = '#';
  for(int i=0;i<4;i++){
    ti = ii + act[i][0];
    tj = jj + act[i][1];
    if(!ok(ti, tj))continue;
    tmp += dfs(ti, tj);
  }
  return tmp;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int ci, cj;
  while(cin>>M>>N && (N+M)){
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        cin>>arr[i][j];
        if(arr[i][j] == '@')
          ci = i, cj = j;
      }
    }
    cout<<dfs(ci, cj)<<endl;
  }
}
