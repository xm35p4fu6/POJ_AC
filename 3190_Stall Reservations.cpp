#include <cstdio>
#include <vector>
#include <utility>
#include <functional>
#include <queue>
#include <cmath>
#include <algorithm>
#define MP make_pair
#define PB push_back
#define X first
#define Y second
using namespace std;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

int N, a, b, ans[50005], cnt;
vector<PIII> vec;
priority_queue<PII, vector<PII>, greater<PII> > pq;
int main(){
  scanf("%d", &N);
  for(int i=0;i<N;i++){
    scanf("%d %d", &a, &b);
    vec.PB(MP(MP(a,b), i));
  }
  sort(vec.begin(), vec.end(), less<PIII>() );
  pq.push(MP(0,1));
  cnt = 1;
  for(int i=0;i<vec.size();i++){
    if(pq.top().X < vec[i].X.X){
      ans[vec[i].Y] = pq.top().Y;
      pq.pop();
    }
    else
      ans[vec[i].Y] = ++cnt;
    pq.push(MP(vec[i].X.Y, ans[vec[i].Y]));
  }
  printf("%d\n", cnt);
  for(int i=0;i<N;i++)printf("%d\n", ans[i]);
}



