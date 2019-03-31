#include <iostream>
using namespace std;
int M,N, arr[30][30], ans;
int ci, cj, act[4][2]={{1,0},{0,1},{0,-1},{-1,0}}, de;
char ch[4] = {'D', 'R', 'L', 'U'};
inline bool ok(int i, int j){
  if(i>=N || j>=M || i<0 || j<0)return false;
  return true;
}
void dfs(int ii, int jj, int ts){
  if(ts == 10)return;
  int ci, cj;
  for(int i=0;i<4;i++){
    ci = ii, cj = jj;
    if(ok(ci+act[i][0], cj+act[i][1]) && arr[ci+act[i][0]][cj+act[i][1]] == 1)
      continue;
    while(ok(ci+act[i][0], cj+act[i][1])){
      ci+=act[i][0], cj+=act[i][1];
      if(arr[ci][cj] == 1){
        arr[ci][cj] = 0;
        dfs(ci-act[i][0], cj-act[i][1], ts+1);
        arr[ci][cj] = 1;
        break;
      }
      if(arr[ci][cj] == 3){
        ans = min(ans, ts+1);
        return;
      }
    }
  }
  return;
}
int main(){
  while(cin>>M>>N && (N+M)){
    ans = 100;de=0;
    for(int i=0;i<N;i++)for(int j=0;j<M;j++){
      cin>>arr[i][j];
      if(arr[i][j] == 2)
        ci = i, cj = j, arr[i][j] = 0;
    }
    dfs(ci, cj, 0);
    cout<<(ans == 100 ? -1 : ans)<<endl;
  }
}
