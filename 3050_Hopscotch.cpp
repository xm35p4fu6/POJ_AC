#include <set>
#include <iostream>
#include <string>
#define PB push_back
using namespace std;

int mp[5][5], dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
string arr;
set<string> S;

bool ok(int x, int y){
  return (x>=0 && y>=0 && x<5 && y<5);
}

void dfs(int st, int x, int y){
  arr.PB(char('0'+mp[x][y]));
  if(st == 5){
    S.insert(arr);
    arr.erase(5, 1);
    return;
  }
  for(int i=0;i<4;i++)if(ok(x+dx[i], y+dy[i]))
    dfs(st+1, x+dx[i], y+dy[i]);
  arr.erase(st, 1);
}

int main(){
  for(int i=0;i<5;i++)for(int j=0;j<5;j++)
    cin>>mp[i][j];
  for(int x=0;x<5;x++)for(int y=0;y<5;y++)
    dfs(0, x, y);
  cout<<S.size()<<endl;
}
