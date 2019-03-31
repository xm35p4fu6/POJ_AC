#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#define eps (1e-9)
#define lt(x) ((x<<1)+1)
#define rt(x) ((x<<1)+2)
#define mid(x,y) ((x+y)/2)
using namespace std;
const int MXN = 405;

struct Seg{
  double u, d, pos;
  bool s; //start
  
  Seg(double a=0, double b=0, double c=0, bool d=0):
    u(a), d(b), pos(c), s(d){}
  
  bool operator < (const Seg& a)const{
    return (fabs(pos-a.pos)<eps) ? (s>a.s) : (pos<a.pos);
  }
}seg[MXN];
int T,I,N,dN, st[MXN*5+5];
double x[MXN], y[MXN], ans, _x, cnt[MXN*5+5];
map<double, int> lu; //lookup

void init(){
  dN = 1;
  ans = 0;
  lu.clear();
  memset(x, 0, sizeof(x));
  memset(y, 0, sizeof(y));
  memset(seg, 0, sizeof(seg));
  memset(st, 0, sizeof(st));
  memset(cnt, 0, sizeof(cnt));
}

void update(int v, int l, int r, int L, int R, int flag){ //[]
  if(r<=L || l>=R) return;
  if(l>=L && r<=R){
    st[v] += flag;
    cnt[v] = ((st[v]) ? (y[r]-y[l]) : (cnt[lt(v)] + cnt[rt(v)]));
    return ;
  }
  update(lt(v), l, mid(l,r), L, R, flag);
  update(rt(v), mid(l,r), r, L, R, flag);
  cnt[v] = ((st[v]) ? (y[r]-y[l]) : (cnt[lt(v)] + cnt[rt(v)]));
}

int main(){
  while(scanf("%d", &N) && N){
    init();
    for(int i=0,j=0;i<N;i++, j=(i<<1)){
      scanf("%lf %lf %lf %lf", x+j, y+j, x+(j+1), y+(j+1));
      //x1 y1 x2 y2
      seg[j] = Seg(y[j+1], y[j], x[j], 1);
      seg[j+1] = Seg(y[j+1], y[j], x[j+1], 0);
    }
    N <<= 1;
    sort(seg, seg+N);
    sort(y, y+N);
    for(int i=1;i<=N-1;i++)if(y[i] > y[i-1])
      y[dN++] = y[i]; //unique
    for(int i=0;i<dN;i++)
      lu[y[i]] = i;
    _x = seg[0].pos;

    for(int i=0;i<N;i++){
      ans += ((seg[i].pos - _x)*(cnt[0]));
      update(0, 0, dN-1, lu[seg[i].d], lu[seg[i].u], (seg[i].s)?1:-1);
      _x = seg[i].pos;
    }
    printf("Test case #%d\nTotal explored area: %.2lf\n\n", ++I, ans);
  }
}

