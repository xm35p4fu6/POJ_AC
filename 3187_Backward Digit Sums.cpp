#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int N, ans[13], tg;
vector<int> arr[11];
void init(){
  for(int i=0;i<11;i++)
    arr[i].push_back(1);
  for(int i=2;i<11;i++){
    for(int j=1;j<arr[i-1].size();j++)
      arr[i].push_back(arr[i-1][j] + arr[i-1][j-1]);
    arr[i].push_back(1);
  }
}

void sol(){
  int tmp = 0;
  do{
    tmp = 0;
    for(int i=0;i<N;i++)
      tmp += (ans[i] * arr[N][i]);
    if(tmp == tg)
      return;
  }while(next_permutation(ans, ans+N));
}

int main(){
  init();
  while(cin>>N>>tg){
    for(int i=1;i<=N;i++)
      ans[i-1] = i;
    sol();
    for(int i=0;i<N;i++){
      if(i)cout<<" ";
      cout<<ans[i];
    }
    cout<<endl;
  }
}
