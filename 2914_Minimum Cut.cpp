// wage[x] 代表要剔除該點所需打斷的邊數，也就是一個割
// 隨便一個起點，每個點透過相鄰的邊更新相鄰點的wage[]
// 為了使某個(最後一個)wage[]最小，優先往wage[]大的點走訪
// 如此一來，最後被走訪到的點，wage[]值已經算好了，且此點的割是最終解或不屬於最終解
// 不屬於最終解的話，該點不會影響答案，把他跟其他點合併，選倒數第二個更新的
// 以上是我自己理解最小割的方法，不是很嚴謹的描述。

#include <cstdio>
#include <cstring>
#include <cstdlib>

int N, M;
int w[505][505];
int wage[505];
bool visit[505];

void init() {
  int a, b, c;
  memset(w, 0, sizeof(w));

  while(M--) {
    scanf("%d %d %d", &a, &b, &c);
    w[a][b] += c;
    w[b][a] += c;
  }
}
int dfs(int v) {
  int res = 1;
  visit[v] = 1;
  for(int i=0; i<N; ++i) if(!visit[i] && w[v][i]) res += dfs(i);
  return res;
}
inline bool connected() {
  memset(visit, 0, sizeof(visit));
  return dfs(0) == N;
}

int sol() {
  if(!connected()) return 0;
  int ans = 1<<30;
  int curr, next, past;
  while(N>1) {
    memset(wage, 0, sizeof(wage));
    memset(visit, 0, sizeof(visit));
    
    curr = rand() % N;
    while(1) {
      visit[curr] = 1, next = -1;
      
      for(int i=0; i<N; ++i) wage[i] += w[curr][i];

      // 找wage[] 最大的遍歷
      for(int i=0; i<N; ++i) if(!visit[i]) 
        if(next == -1 || wage[i] > wage[next]) next = i;
      
      if(next == -1) break;
      past = curr, curr = next;
    }

    if(wage[curr] < ans) ans = wage[curr];

    // 將最後一點合併到倒數第二：1.加總上去 2. 拿最後一個填掉它
    for(int i=0; i<N; ++i) if(i != past)
      w[i][past] += w[i][curr], w[past][i] = w[i][past];
    for(int i=0; i<N; ++i) {
      if(i == curr) w[curr][curr] = 0;
      else w[curr][i] = w[i][curr] = w[i][N-1];
    }
    --N;
  }
  return ans;
}
int main() {
  while(scanf("%d %d", &N, &M) == 2) {
    init();
    printf("%d\n", sol());
  }
}
