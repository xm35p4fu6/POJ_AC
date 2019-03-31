#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#define S(i) sqr[i]
#define Mx ((x1+x2)>>1)
#define My ((y1+y2)>>1)
using namespace std;
const int MXN = 405;

struct Sqr{
  double x1, x2, y1, y2;
  Sqr(double a=0, double b=0, double c=0, double d=0):
    x1(a), y1(b), x2(c), y2(d){}  //initial
}sqr[MXN];

int I,N,dx,dy;
double x[MXN], y[MXN], cnt[MXN * MXN + 5];
map<double, int> lux, luy; //lookup x y

void init(){
  dx = dy = 1;
  lux.clear();
  luy.clear();
  memset(x, 0, sizeof(x));
  memset(y, 0, sizeof(y));
  memset(sqr, 0, sizeof(sqr));
  memset(cnt, 0, sizeof(cnt));
}

int X1, X2, Y1, Y2; //要丟入qtree 的矩形
void update(int v, int x1, int y1, int x2, int y2){
  if(x1>=X2 || y1>=Y2 || x2<=X1 || y2<=Y1) return;
  if(x1>=X1 && y1>=Y1 && x2<=X2 && y2<=Y2){
    cnt[v] = (x[x2]-x[x1])*(y[y2]-y[y1]);
    return ;
  }
  if(x2 > x1+1 && y2 > y1+1) //左下角
    update((v<<2)+1, x1, y1, Mx, My);
  if(x2 > x1+1)  //左右分裂（左上角）
    update((v<<2)+2, x1, My, Mx, y2);
  if(y2 > y1+1)  //上下分裂（右下角）
    update((v<<2)+3, Mx, y1, x2, My);
  update((v<<2)+4, Mx, My, x2, y2); //右上角
  cnt[v] = max(cnt[v], cnt[(v<<2)+1] + cnt[(v<<2)+2] + cnt[(v<<2)+3] + cnt[(v<<2)+4]);
}

int main(){
  while(scanf("%d", &N) && N){
    init();
    for(int i=0,j=0;i<N;i++, j=(i<<1)){
      scanf("%lf %lf %lf %lf", x+j, y+j, x+(j+1), y+(j+1)); //x1 y1 x2 y2
      sqr[i] = Sqr(x[j], y[j], x[j+1], y[j+1]);
    }
    N <<= 1;
    sort(x, x+N); //離散化
    sort(y, y+N);
    for(int i=1;i<N;i++){ //unique
      if(x[i] > x[i-1])
        x[dx++] = x[i];
      if(y[i] > y[i-1])
        y[dy++] = y[i]; 
    }
    for(int i=0;i<dx;i++) lux[x[i]] = i;
    for(int i=0;i<dy;i++) luy[y[i]] = i;  //結束離散化

    for(int i=0, n=(N>>1);i<n;i++){  //S(i) = sqr[i]
      X1 = lux[S(i).x1], Y1 = luy[S(i).y1], X2 = lux[S(i).x2], Y2 = luy[S(i).y2]; //更新目標
      update(0, 0, 0, dx-1, dy-1);  //丟目標進入qtree
    }
    printf("Test case #%d\nTotal explored area: %.2lf\n\n", ++I, cnt[0]);
  }
}

