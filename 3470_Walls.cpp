#include <iostream>
#include <cstdlib>
#include <cstdio>
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
#include <climits>
#include <numeric>
#include <iomanip>

using namespace std;
int N, M;

int wx1[50005], wx2[50005], wy1[50005], wy2[50005], birdx[50005], birdy[50005];
int dwx1[50005], dwx2[50005], dwy1[50005], dwy2[50005], dbirdx[50005], dbirdy[50005];
int val_[600005], id_[600005], tv[600005], tid[600005];
int ans[50005];

vector<int> x_wall[150005], y_wall[150005], x_bird[150005], y_bird[150005], x_dis, y_dis;
pair<int, int> bird_dead[50005];

inline int getint(){
  int _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}

inline void st_clear(const int& pos, const int& l, const int& r){
  val_[pos] = id_[pos] = tid[pos] = tv[pos] = -1;
  if(l!=r){
    st_clear((pos<<1)+1, l, (l+r)>>1);
    st_clear((pos<<1)+2, ((l+r)>>1)+1, r);
  }
}

inline void update(const int& pos, const int& l, const int& r, 
    const int& tar_l, const int& tar_r, const int& val, const int& id){
  if(l>=tar_l and r<=tar_r){
    val_[pos] = tv[pos] = val;      // 真正的值(要拿來算距離用的)
    id_[pos] = tid[pos] = id;
  }else{
    if(tid[pos] != -1){
      tv[(pos<<1)+1] = tv[(pos<<1)+2] = val_[(pos<<1)+1] = val_[(pos<<1)+2] = tv[pos];
      tid[(pos<<1)+1] = tid[(pos<<1)+2] = id_[(pos<<1)+1] = id_[(pos<<1)+2] = tid[pos];
      tv[pos] = tid[pos] = -1;
    }
    if((l+r)>>1 >= tar_l) update((pos<<1)+1, l, (l+r)>>1, tar_l, tar_r, val, id);
    if(((l+r)>>1) +1 <= tar_r) update((pos<<1)+2, ((l+r)>>1)+1, r, tar_l, tar_r, val, id);
  }
}
pair<int, int> res;
inline void query(const int& pos, const int& l, const int& r, const int& tar){
  if(l==r){
    res.first = val_[pos], res.second = id_[pos];
    return;
  }
  if(tid[pos] != -1){
      tv[(pos<<1)+1] = tv[(pos<<1)+2] = val_[(pos<<1)+1] = val_[(pos<<1)+2] = tv[pos];
      tid[(pos<<1)+1] = tid[(pos<<1)+2] = id_[(pos<<1)+1] = id_[(pos<<1)+2] = tid[pos];
      tv[pos] = tid[pos] = -1;
  }
  if((l+r)>>1 >= tar) query((pos<<1)+1, l, (l+r)>>1, tar);
  else query((pos<<1)+2, ((l+r)>>1)+1, r, tar);
}
inline void discrete(){
  for(int i=0;i<N;++i) {
    if(wx1[i] > wx2[i]) swap(wx1[i], wx2[i]);
    if(wy1[i] > wy2[i]) swap(wy1[i], wy2[i]);
    x_dis.push_back(wx1[i]);
    x_dis.push_back(wx2[i]);
    y_dis.push_back(wy1[i]);
    y_dis.push_back(wy2[i]);
  }
  for(int i=0;i<M;++i){
    x_dis.push_back(birdx[i]);
    y_dis.push_back(birdy[i]);
  }
  sort(x_dis.begin(), x_dis.end());
  sort(y_dis.begin(), y_dis.end());
  x_dis.erase(unique(x_dis.begin(), x_dis.end()), x_dis.end());
  y_dis.erase(unique(y_dis.begin(), y_dis.end()), y_dis.end());

  for(int i=0;i<N;++i){
    x_wall[ dwx2[i]=dwx1[i]=(lower_bound(x_dis.begin(), x_dis.end(), wx1[i]) - x_dis.begin()) ].push_back(i);
    y_wall[ dwy2[i]=dwy1[i]=(lower_bound(y_dis.begin(), y_dis.end(), wy1[i]) - y_dis.begin()) ].push_back(i);
    if(wx1[i] != wx2[i])
      x_wall[ dwx2[i]=(lower_bound(x_dis.begin(), x_dis.end(), wx2[i]) - x_dis.begin()) ].push_back(i);
    else if(wy1[i] != wy2[i]) 
      y_wall[ dwy2[i]=(lower_bound(y_dis.begin(), y_dis.end(), wy2[i]) - y_dis.begin()) ].push_back(i);
  }
  for(int i=0;i<M;++i){
    x_bird[ dbirdx[i]=(lower_bound(x_dis.begin(), x_dis.end(), birdx[i]) - x_dis.begin()) ].push_back(i);   // 此x上有鳥
    y_bird[ dbirdy[i]=(lower_bound(y_dis.begin(), y_dis.end(), birdy[i]) - y_dis.begin()) ].push_back(i);
  }
}

inline void init(){
  N = getint(), M = getint();     // both not exceeding 50,000
  for(int i=0;i<N;++i){
    wx1[i]=getint(), wy1[i]=getint(), wx2[i]=getint(), wy2[i]=getint();
  }// scanf("%d %d %d %d", wx1+i, wy1+i, wx2+i, wy2+i);
  for(int i=0;i<M;++i){
    birdx[i]=getint(), birdy[i]=getint();
  }// scanf("%d %d", birdx+i, birdy+i);
  fill(bird_dead, bird_dead+M, make_pair(INT_MAX, 0));
  discrete();
}

inline void sol(){
  st_clear(0, 0, y_dis.size()-1);
  for(size_t i=0;i<x_dis.size();++i){     // scan along x
    for(size_t j=0;j<x_bird[i].size();++j){
      query( 0, 0, y_dis.size()-1, dbirdy[x_bird[i][j]] );   // {data, id}
      if(res.second!=-1 and ((res.first=x_dis[i]-res.first) < bird_dead[x_bird[i][j]].first))
        bird_dead[x_bird[i][j]] = res;
    }
    for(size_t j=0;j<x_wall[i].size();++j)
      update( 0, 0, y_dis.size()-1, dwy1[x_wall[i][j]], dwy2[x_wall[i][j]], x_dis[i], x_wall[i][j]);
  }

  st_clear(0, 0, y_dis.size()-1);
  for(int i=x_dis.size()-1;i>=0;--i){     // scan along x reverse
    for(size_t j=0;j<x_bird[i].size();++j){
      query( 0, 0, y_dis.size()-1, dbirdy[x_bird[i][j]] );
      if(res.second!=-1 and ((res.first=res.first-x_dis[i]) < bird_dead[x_bird[i][j]].first))
        bird_dead[x_bird[i][j]] = res;
    }
    for(size_t j=0;j<x_wall[i].size();++j)
      update(0, 0, y_dis.size()-1, dwy1[x_wall[i][j]], dwy2[x_wall[i][j]], x_dis[i], x_wall[i][j]);
  }

  st_clear(0, 0, x_dis.size()-1);
  for(size_t i=0;i<y_dis.size();++i){
    for(size_t j=0;j<y_bird[i].size();++j){
      query( 0, 0, x_dis.size()-1, dbirdx[y_bird[i][j]] );
      if(res.second!=-1 and ((res.first=y_dis[i]-res.first) < bird_dead[y_bird[i][j]].first))
        bird_dead[y_bird[i][j]] = res;
    }
    for(size_t j=0;j<y_wall[i].size();++j)
      update(0, 0, x_dis.size()-1, dwx1[y_wall[i][j]], dwx2[y_wall[i][j]], y_dis[i], y_wall[i][j]);
  }

  st_clear(0, 0, x_dis.size()-1);
  for(int i=y_dis.size()-1;i>=0;--i){
    for(size_t j=0;j<y_bird[i].size();++j){
      query( 0, 0, x_dis.size()-1, dbirdx[y_bird[i][j]] );
      if(res.second!=-1 and ((res.first=res.first-y_dis[i]) < bird_dead[y_bird[i][j]].first))
        bird_dead[y_bird[i][j]] = res;
    }
    for(size_t j=0;j<y_wall[i].size();++j)
      update(0, 0, x_dis.size()-1, dwx1[y_wall[i][j]], dwx2[y_wall[i][j]], y_dis[i], y_wall[i][j]);
  }
  for(int i=0;i<M;++i) {
    ++ans[bird_dead[i].second];
  }
  for(int i=0;i<N;++i) printf("%d\n", ans[i]);
}

int main(){
  init();
  sol();
}
