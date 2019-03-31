#include <iostream>
#include <ctime>
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
#define X first
#define Y second
#define PB push_back
#define MP make_pair
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
inline ll getint(){
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}

////////  template end   //////////

struct Node{
  int sz, v, mn, tag_add;
  bool tag_rev;
  Node *lt, *rt;
  Node(): sz(1), v(0), mn(INT_MAX), tag_add(0), tag_rev(0), lt(NULL), rt(NULL) {}
  Node(const int& x): sz(1), v(x), mn(x), tag_add(0), tag_rev(0), lt(NULL), rt(NULL) {}
};

inline int size(Node *n){
  return (n?n->sz:0);
}
inline int min(Node *n){
  return (n?n->mn:INT_MAX);
}
inline void pull(Node *n){
  if(n){
    n->sz = 1 + size(n->lt) + size(n->rt);
    n->mn = min(n->v, min(min(n->lt), min(n->rt)));
  }
}
inline void push(Node *n){
  if(n){
    if(n->tag_add){
      if(n->rt) n->rt->mn += n->tag_add, n->rt->v += n->tag_add, n->rt->tag_add += n->tag_add;
      if(n->lt) n->lt->mn += n->tag_add, n->lt->v += n->tag_add, n->lt->tag_add += n->tag_add;
    }
    if(n->tag_rev){
      if(n->rt) swap(n->rt->lt, n->rt->rt), n->rt->tag_rev ^= 1;
      if(n->lt) swap(n->lt->lt, n->lt->rt), n->lt->tag_rev ^= 1;
    }
    n->tag_add = n->tag_rev = 0;
  }
}
void split(Node *n, int k, Node* &l, Node* &r){   // n依照sz(0-base)切成  l(<k) r(>=k)
  if(!n) return l=r=NULL, void();
  push(n);
  if(k <= size(n->lt)){   
  // 要被切的位置在左子樹: 目前點放入r, 將目前點左子樹接點切給遞迴呼叫r
    r = n;
    split(n->lt, k, l, r->lt);
    pull(r);
  }else{
  // 要被切的點在此點或右子樹: 目前點放入l
    l = n;
    split(n->rt, k-size(n->lt)-1, l->rt, r);
    pull(l);
  }
}
Node* merge(Node *l, Node *r){   // l左 r右 合併
  if(!l || !r) return (l?l:r);
  if(rand()%(l->sz+r->sz) < l->sz){     // l/(l+r) 的機率把l當root
    push(l);
    l->rt = merge(l->rt, r);
    pull(l);
    return l;
  }else{
    push(r);
    r->lt = merge(l, r->lt);
    pull(r);
    return r;
  }
}
void prin(Node* root, int level=0){
  fprintf(stderr, " ");
  for(int i=0;i<level;++i) fprintf(stderr, "\t");
  if(root == NULL) return fprintf(stderr, "NULL\n"), void();

  fprintf(stderr, "sz=%d v=%d\n", root->sz, root->v);      // 印出此點資料
  prin(root->lt, level+1);
  prin(root->rt, level+1);
  if(level==0) fprintf(stderr, "\n");
}

Node *root = NULL;
int T,M,N,K,I,a,b,c,ans,cnt;

void init(){
  Node *in;
  scanf("%d", &N);
  for(int i=0;i<N;++i){
    scanf("%d", &a);
    in = new Node(a);
    root = merge(root, in);
  }
  scanf("%d", &M);
}

// n依照sz(0-base)切成  l(<k) r(>=k)
void sol(){
  char in[10];
  Node *tmp1, *tmp2, *tmp3;
  while(M--){
    scanf("%s", in);
    if     (in[0] == 'A'){
      scanf("%d %d %d", &a, &b, &c);
      --a;     // [0, a) [a, b) [b, N)
      split(root, a, tmp1, root);
      split(root, b-a, root, tmp2);
      root -> mn += c, root -> v += c;
      root -> tag_add += c;
      root = merge(tmp1, merge(root, tmp2));
    }
    else if(in[0] == 'I'){
      scanf("%d %d", &a, &b);   // [0, a)
      tmp1 = new Node(b);
      split(root, a, tmp2, root);
      root = merge(tmp2, merge(tmp1, root));
    }
    else if(in[0] == 'D'){
      scanf("%d", &a);
      --a;                    // [0, a) [a, a+1) [a+1, N)
      split(root, a, tmp1, root);
      split(root, 1, root, tmp2);
      root = merge(tmp1, tmp2);
    }
    else if(in[0] == 'M'){
      scanf("%d %d", &a, &b);
      --a;                  // [0, a) [a, b) [b, N)
      split(root, a, tmp1, root);
      split(root, b-a, root, tmp2);
      printf("%d\n", root->mn);
      root = merge(tmp1, merge(root, tmp2));
    }
    else if(in[3] == 'E'){      // reverse
      scanf("%d %d", &a, &b);
      --a;                  // [0, a) [a, b) [b, N)
      split(root, a, tmp1, root);
      split(root, b-a, root, tmp2);
      swap(root->rt, root->lt);
      root->tag_rev ^= 1;
      root = merge(tmp1, merge(root, tmp2));
    }
    else{
      scanf("%d %d %d", &a, &b, &c);
      --a;
      int len = b-a;
      c %= len;
      if(c<0) c = 0;
      if(c){                // [0, a) [a, b) [b, N) -> [0, a) [a, b-c) [b-c, b) [b, N)
        split(root, a, tmp1, root);
        split(root, b-a, root, tmp2);
        split(root, len-c, root, tmp3);
        root = merge(merge(tmp1, tmp3), merge(root, tmp2));
      }
    }
  }
}

int main(){
  //ios::sync_with_stdio(false);cin.tie(0);
  init();
  sol();
}

