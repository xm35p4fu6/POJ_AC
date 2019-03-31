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

ll T,M,N,K,I,C,F,a,b,c,ans,cnt;

pii arr[100005];
ll pre[100005], pof[100005];
priority_queue<int> pq, pq2;
int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  cin>>N>>C>>F;
  for(int i=0;i<C;i++)
    cin>>arr[i].X>>arr[i].Y;
  sort(arr, arr+C);

  pre[0] = arr[0].Y;
  pq.push(pre[0]);
  pof[C-1] = arr[C-1].Y;
  pq2.push(pof[C-1]);
  for(int i=1;i<(N/2);i++){
    pre[i] = pre[i-1]+arr[i].Y;
    pq.push(arr[i].Y);
    pof[C-1-i] = pof[C-i]+arr[C-1-i].Y;
    pq2.push(arr[C-1-i].Y);
  }
  for(int i=(N/2);i<C;i++){
    pre[i] = pre[i-1];
    pof[C-1-i] = pof[C-i];
    if(pq.top() > arr[i].Y){
      pre[i] -= (pq.top() - arr[i].Y);
      pq.pop();
      pq.push(arr[i].Y);
    }
    if(pq2.top() > arr[C-1-i].Y){
      pof[C-i-1] -= (pq2.top() - arr[C-1-i].Y);
      pq2.pop();
      pq2.push(arr[C-1-i].Y);
    }
  }
  ans = -1;
  for(int i=(N/2);i+(N/2)<C;i++)if(pre[i-1]+pof[i+1]+arr[i].Y<=F){
      ans = arr[i].X;
  }
  cout<<ans<<endl;
}

