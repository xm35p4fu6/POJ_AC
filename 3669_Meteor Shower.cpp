#include <cstdio>
#include <algorithm>
#define MXN 400
using namespace std;
struct node{
  int x, y, ts;
};
node pos[MXN*MXN];
int flag, mp[MXN][MXN], dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};
int xx, yy, x, y, t, M;  //i = x, j = y
int que[MXN*MXN], head, tail;

inline bool ok(int x, int y){
  return (x>=0 && y>=0);
}

int sol(){
  node tmp;
  while(tail - head){
    tmp = pos[que[head++]];
    if((mp[tmp.x][tmp.y]^(1<<12)) == 0)
      return tmp.ts;
    for(int i=0;i<4;i++){
      xx = tmp.x+dx[i];
      yy = tmp.y+dy[i];
      if(!ok(xx,yy) || mp[xx][yy] & (1<<12) || (mp[xx][yy] && mp[xx][yy] <= tmp.ts+2))
        continue;
      mp[xx][yy] |= (1<<12);
      pos[flag].x = xx, pos[flag].y = yy, pos[flag].ts = tmp.ts+1;
      que[tail++] = flag++;
    }
  }
  return -1;
}

int main(){
  scanf("%d", &M);
  while(M--){
    scanf("%d %d %d", &x, &y, &t);
    mp[x][y] = (mp[x][y] == 0 ? t+1: min(mp[x][y], t+1));
    for(int i=0;i<4;i++)if(ok(x+dx[i], y+dy[i])){
      xx = x+dx[i];
      yy = y+dy[i];
      mp[xx][yy] = (mp[xx][yy] == 0 ? t+1 : min(mp[xx][yy], t+1));
    }
  }
  x = y = t = flag = head = tail = 0; //[head, tail)
  pos[flag].x = x, pos[flag].y = y, pos[flag].ts = t;
  que[tail++] = flag++;
  mp[x][y] |= (1<<12);  //visited
  printf("%d\n", sol());
}
