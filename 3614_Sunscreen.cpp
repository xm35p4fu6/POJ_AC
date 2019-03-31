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
const int MXN = 2500;

int T,M,N,K,I,a,b,c,ans;
pii arr[MXN], arr2[MXN];
int main(){
  ios::sync_with_stdio(false); cin.tie(0);
  cin>>N>>M;
  for(int i=0;i<N;i++)
    cin>>arr[i].Y>>arr[i].X;
  for(int i=0;i<M;i++)
    cin>>arr2[i].X>>arr2[i].Y;
  sort(arr, arr+N);
  sort(arr2, arr2+M);
  for(int i=0,j;i<M;i++){
    for(j=0;arr2[i].Y && j<N;j++)
      if(arr[j].Y<=arr2[i].X && arr[j].X>=arr2[i].X){
        arr2[i].Y--;
        arr[j].X = -1;
        ans++;
      }
    for(j=0, a=0;j<N;j++)if(arr[j].X != -1)
      arr[a++] = arr[j];
    N = a;
  }
  cout<<ans<<endl;
}
