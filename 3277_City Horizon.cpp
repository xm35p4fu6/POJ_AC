#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#define lt(x) ((x<<1)+1)
#define rt(x) ((x<<1)+2)
#define mid(x,y) ((x+y)/2)
using namespace std;
const long long MXN = 400050;

struct Seg{
  long long u, d, pos;
  bool s; //start
  
  Seg(long long a=0, long long b=0, long long c=0, bool d=0):
    u(a), d(b), pos(c), s(d){}
  
  bool operator < (const Seg& a)const{
    return ((pos==a.pos)) ? (s>a.s) : (pos<a.pos);
  }
}seg[MXN];

long long T,I,N,dN, st[MXN * 5+5];
long long x[MXN], y[MXN], ans, _x, cnt[MXN * 5 + 5];
map<long long, long long> lu; //lookup

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

void update(long long v, long long l, long long r, long long L, long long R, long long flag){ //[]
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
  scanf("%lld", &N);
    init();
    for(long long i=0,j=0;i<N;i++, j=(i<<1)){
      //scanf("%lf %lf %lf %lf", x+j, y+j, x+(j+1), y+(j+1));
      scanf("%lld %lld %lld", x+j, x+j+1, y+j+1);
      y[j]=0;
      //x1 y1 x2 y2
      seg[j] = Seg(y[j+1], y[j], x[j], 1);
      seg[j+1] = Seg(y[j+1], y[j], x[j+1], 0);
    }
    N <<= 1;
    sort(seg, seg+N); //線段排序
    
    /*對y離散化開始*/
    sort(y, y+N);
    for(long long i=1;i<N;i++)if(y[i] > y[i-1])
      y[dN++] = y[i]; //unique (去除重複)
    //for(long long i=0;i<dN;i++)
    //  lu[y[i]] = i;   //速查表
    /*離散化結束*/

    _x = seg[0].pos;
    for(long long i=0;i<N;i++){   //掃描x軸 (依x枚舉各線段)
      ans += ((seg[i].pos - _x)*(cnt[0]));  //目前的線段長度 * x變化
      int d = lower_bound(y, y+dN, seg[i].d)-y, u = lower_bound(y,y+dN,seg[i].u)-y;
      //update(0, 0, dN-1, lu[seg[i].d], lu[seg[i].u], (seg[i].s)?1:-1);  // 丟下個線段進去
      update(0, 0, dN-1, d, u, (seg[i].s)?1:-1);  // 丟下個線段進去
      _x = seg[i].pos;
    }
    //printf("Test case #%lld\nTotal explored area: %lld\n\n", ++I, ans);
    printf("%lld\n", ans);

}