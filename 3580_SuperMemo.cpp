#include <cstdio>
#include <algorithm>
#include <climits>
#include <ctime>

using namespace std;

struct Node{
  int sz, mn;         // for query
  int v, tag_add;
  bool tag_reverse;
  Node *lt, *rt;
  Node(): sz(1), mn(INT_MAX), v(0), tag_add(0), tag_reverse(0), lt(NULL), rt(NULL) {}
  Node(const int& x): sz(1), mn(x), v(x), tag_add(0), tag_reverse(0), lt(NULL), rt(NULL) {}
  ~Node(){
    if(lt) delete lt;
    if(rt) delete rt;
  }
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
    n->mn = min(min(n->lt), min(n->rt));
    if(n->v < n->mn) n->mn = n->v;
  }
}
inline void push(Node *n){
  if(n){
    if(n->tag_add){
      if(n->lt) n->lt->mn += n->tag_add, n->lt->v += n->tag_add, n->lt->tag_add += n->tag_add;
      if(n->rt) n->rt->mn += n->tag_add, n->rt->v += n->tag_add, n->rt->tag_add += n->tag_add;
    }
    if(n->tag_reverse){
      if(n->lt) n->lt->tag_reverse ^= 1;
      if(n->rt) n->rt->tag_reverse ^= 1;
      swap(n->lt, n->rt);
    }
    n->tag_add = n->tag_reverse = 0;
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
Node* merge(Node *l, Node*r){   // l左 r右 合併
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

  fprintf(stderr, "sz=%d v=%d mn=%d tag_add=%d tag_rev=%d\n"
      , root->sz, root->v, root->mn, root->tag_add, root->tag_reverse);      // 印出此點資料
  prin(root->lt, level+1);
  prin(root->rt, level+1);
  if(level==0) fprintf(stderr, "\n");
}

Node *root = NULL;

inline void modify_add(int l, int r, int val){
  if(r<l) return;
  Node *tmp1, *tmp2;
  split(root, l, tmp1, root);       // [0,l) [l, N)
  split(root, r-l+1, root, tmp2);   // [l,r+1) [r+1, N)
  root -> mn += val, root -> v += val, root -> tag_add += val;
  root = merge(tmp1, merge(root, tmp2));
}
inline void modify_reverse(int l, int r){
  if(r<l) return;
  Node *tmp1, *tmp2;
  split(root, l, tmp1, root);       // [0, l) [l, r+1) [r+1, N)
  split(root, r-l+1, root, tmp2);
  root -> tag_reverse ^= 1;
  root = merge(tmp1, merge(root, tmp2));
}
inline void modify_insert(int l, int val){      // [0, l+1) [new, n)
  Node *tmp;
  split(root, l+1, tmp, root);
  root = merge(tmp, merge( new Node(val), root));
}
inline void modify_delete(int l){
  Node *tmp1, *tmp2;
  split(root, l, tmp1, root);
  split(root, 1, root, tmp2);
  //delete root;
  root = merge(tmp1, tmp2);
}
inline void modify_revolve(int l, int r, int val){
  if(r<=l) return;
  int len = r-l+1;
  val %= len;
  if(val < 0) val = 0;
  if(val > 0){
    Node *tmp1, *tmp2, *tmp3, *tmp4;    // [0, l) [l,mid) [mid, r+1) [r+1, N)
    split(root, r+1-val, tmp1, tmp2);
    split(tmp1, l, tmp3, tmp1);         // 3 1 2 4
    split(tmp2, val, tmp2, tmp4);
    root = merge(merge(tmp3, tmp2), merge(tmp1, tmp4));     // 3 2 1 4
  }
}
inline int query_min(int l, int r){
  Node *tmp1, *tmp2;
  split(root, l, tmp1, root);           // [0, l) [l, N)
  split(root, r-l+1, root, tmp2);       // [l, r+1) [r+1, N)
  int res = root->mn;
  root = merge(tmp1, merge(root, tmp2));
  return res;
}

int N, M;

void init(){
  Node *tmp;
  int in;
  scanf("%d", &N);
  for(int i=0;i<N;++i) {
    scanf("%d", &in);
    tmp = new Node(in);
    root = merge(root, tmp);
  }
  scanf("%d", &M);
}

void sol(){
  char input_str[10];
  int a,b,c, ans;
  while(M--){
    scanf("%s", input_str);
    if      (input_str[0] == 'A'){      // ADD x y D : [x, y] +D
      scanf("%d %d %d", &a, &b, &c);
      modify_add(a-1, b-1, c);           // 0-base []

    }else if(input_str[0] == 'M'){      // MIN x y : query
      scanf("%d %d", &a, &b);
      ans = query_min(a-1, b-1);
      printf("%d\n", ans);
    }else if(input_str[0] == 'I'){      // INSERT x P : insert P after Ax
      scanf("%d %d", &a, &b);
      modify_insert(a-1, b);

    }else if(input_str[0] == 'D'){      // DELETE x : delete Ax
      scanf("%d", &a);
      modify_delete(a-1);

    }else if(input_str[3] == 'E'){      // REVERSE x y : reverse [x, y]
      scanf("%d %d", &a, &b);
      modify_reverse(a-1, b-1);         // 0-base []

    }else if(input_str[3] == 'O'){      // REVOLVE x y T : 123 -> 312 T times
      scanf("%d %d %d", &a, &b, &c);
      modify_revolve(a-1, b-1, c);
    }
  }
}

int main(){
  init();
  sol();
}
