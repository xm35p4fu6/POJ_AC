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
#define dis(x,y) (abs(arr[x]-lu[y]))
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vii;

int N, arr[2005], lu[2005], in[2005][2], de[2005][2], n, mi, md, ans;

int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  ans = (1<<30);
  scanf("%d", &N);
  for(int i=0;i<N;i++)scanf("%d", arr+i);
  memcpy(lu, arr, sizeof(lu));
  sort(lu, lu+N);
  n = 1;
  for(int i=1;i<N;i++)if(lu[i] != lu[i-1])
    lu[n++] = lu[i];
  for(int j=0;j<n;j++)
    in[j][0] = de[j][0] = dis(0, j);
  for(int i=1;i<N;i++){
    mi = in[0][((i-1)&1)];
    md = de[n-1][((i-1)&1)];
    in[0][(i&1)] = dis(i, 0) + mi;
    de[n-1][(i&1)] = dis(i, n-1) + md;
    //printf("%d ", de[0][(i&1)]);
    for(int j=1;j<n;j++){
      mi = min(mi, in[j][(i-1)&1]);
      in[j][i&1] = dis(i, j) + mi;

    }
    for(int j=n-2;j>=0;j--){
      md = min(md, de[j][(i-1)&1]);
      de[j][i&1] = dis(i, j) + md;
     // printf("%d ", de[j][(i&1)]);
    }
    //puts("");
  }
  for(int i=0;i<n;i++)
    ans = min(ans, min(in[i][(N-1)&1], de[i][(N-1)&1]));
  printf("%d\n", ans);
}

