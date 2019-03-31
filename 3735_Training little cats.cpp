#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <iomanip>
#include <cstdio>

using namespace std;

typedef long long ll;
// ele 為 矩陣內元素
typedef ll ele;
typedef vector<ele> vec;
typedef vector<vec> mat;

typedef long long ll;

int N, M, K;

mat Mat, Base;
char in[20];

void prin(mat &A) {
  for(size_t i=0; i<=N; ++i){
    for(size_t j=0; j<=N; ++j)
      cout << setw(6) << A[i][j];         // include iomanip
    cout << endl;
  }
}

mat mul(mat &A, mat &B){
  //assert(A[0].size() == B.size());        // include cassert
  mat res (N+1, vec(N+1));
  for(size_t i=0; i<=N; ++i)
    for(size_t j=0; j<=N; ++j) if(A[i][j])
      for(size_t k=0; k<=N; ++k)
        res[i][k] += A[i][j]*B[j][k];
  return res;
}

mat pow(mat A, ll n){       // 必須是方陣
  mat res (N+1, vec(N+1));
  for(size_t i=0;i<=N;++i) res[i][i] = 1;
  for(;n; A=mul(A,A), n>>=1) if(n&1) res = mul(res,A);
  return res;
}
void pre(){
  Mat = mat(101, vec(101));
  Base = mat(101, vec(101));
}
void init(){
  int a,b;
  Mat.clear();
  Base.clear();
  Mat = mat(N+1, vec(N+1));
  Base = mat(N+1, vec(N+1));
  for(int i=0; i<=N; ++i) Mat[i][i] = 1;
  Base[N][0] = 1;
  for(int i=0; i<=N; ++i) {
    for(int j=0; j<=N; ++j) {
      if(i == j) Mat[i][j] = 1;
      else Mat[i][j] = 0;
    }
    Base[i][0] = 0;
  }
  Base[N][0] = 1;

  while(K--){
    scanf("%s", in);
    if(in[0] == 'g'){
      scanf("%d", &a);
      Mat[a-1][N]++;
    }
    else if(in[0] == 'e'){
      scanf("%d", &a);
      for(int i=0; i<=N; ++i) Mat[a-1][i] = 0;
    }
    else{
      scanf("%d %d", &a, &b);
      swap(Mat[a-1], Mat[b-1]);
    }
  }
}
void sol() {
  mat res = pow(Mat, M);
  res = mul(res, Base);
  for(int i=0; i<N; ++i) cout << res[i][0] << " \n"[i==N-1];
}

int main(){
  //pre();
  while(scanf("%d %d %d", &N, &M, &K) == 3 && (N||M||K)) {
    init();
    sol();
  }
}
