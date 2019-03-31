#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int T, arr[15], N, ans, t1, t2;
string str;
stringstream ss;

void init(){
  memset(arr, 0, sizeof(arr));
  ss.clear();
  ans = 1<<30;
  N=0;
}


int main(){
  cin>>T;
  getchar();
  while(T--){
    init();
    getline(cin, str);
    ss << str;
    while(ss >> arr[N]){
      N++;
    }
    sort(arr, arr+N);
    swap(arr[0], arr[1]);
    do{
      t1 = t2 = 0;
      for(int i=0;i<(N>>1);i++){
        t1*=10;
        t1+=arr[i];
      }
      if(arr[N>>1] == 0)
        swap(arr[N>>1], arr[(N>>1)+1]);
      for(int i=(N>>1);i<N;i++){
        t2*=10;
        t2+=arr[i];
      }
      ans = min(ans, abs(t1-t2));
    }while(next_permutation(arr, arr+N));
    cout<<ans<<endl;
  }
}
