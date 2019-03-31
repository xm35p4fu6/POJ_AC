#include <iostream>
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
#define X first
#define Y second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vii;

int T,M,N,I,a,b,c,ans,cnt;
ll arr[1000005];

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>N;
  arr[1] = 1;
  for(int i=2;i<=N;i++){
    arr[i] = arr[i-1];
    if(~i&1) arr[i]+=arr[(i>>1)];
    arr[i] %= 1000000000;
  }
  cout<<arr[N]<<endl;
}

