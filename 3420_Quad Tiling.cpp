#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <cassert>

using namespace std;
typedef long long ll;


// ele 為 矩陣內元素
typedef ll ele;
typedef vector<ele> vec;
typedef vector<vec> mat;

typedef long long ll;

ll mod7;
void prin(mat &A) {
  for(size_t i=0; i<A.size(); ++i){
    for(size_t j=0; j<A[i].size(); ++j)
      cout << setw(6) << A[i][j];
    cout << endl;
  }
}
mat mul(mat &A, mat &B){
  assert(A[0].size() == B.size());
  mat res (A.size(), vec(B[0].size()));
  for(size_t i=0; i<A.size(); ++i)
    for(size_t j=0; j<B[0].size(); ++j)
      for(size_t k=0; k<B[0].size(); ++k)
        res[i][j] = (res[i][j] + A[i][k]*B[k][j]) % mod7;
  return res;
}

mat pow(mat A, ll n){       // 必須是方陣
  mat res (A.size(), vec(A.size()));
  for(size_t i=0;i<A.size();++i) res[i][i] = 1;
  for(;n; A=mul(A,A), n>>=1) if(n&1) res = mul(res,A);
  return res;
}
ll N;
mat Mat, Base;

void pre(){
  Mat = mat(6, vec(6));
  Mat[0][0] = Mat[0][2] = Mat[0][3] = Mat[0][4] = Mat[0][5] = 1;
  Mat[1][2] = Mat[2][0] = Mat[2][1] = Mat[3][0] = Mat[3][4] = 1;
  Mat[4][0] = Mat[4][3] = Mat[5][0] = 1;
  Base = mat(6, vec(1));
  Base[0][0] = 1;
  /*
  Mat[0] = {1, 0, 1, 1, 1, 1}; // base:  1111
  Mat[1] = {0, 0, 1, 0, 0, 0};        // 1001
  Mat[2] = {1, 1, 0, 0, 0, 0};        // 0110
  Mat[3] = {1, 0, 0, 0, 1, 0};        // 1100
  Mat[4] = {1, 0, 0, 1, 0, 0};        // 0011
  Mat[5] = {1, 0, 0, 0, 0, 0};        // 0000
  Base = mat(6, vec(1));
  Base[0] = {1};
  Base[1] = {0};
  Base[2] = {0};
  Base[3] = {0};
  Base[4] = {0};
  Base[5] = {0};
  */
}

void init(){
  
}

void sol(){
  mat res = pow(Mat, N);
  res = mul(res, Base);
  printf("%lld\n", res[0][0]);
}

int main(){
  pre();
  while(scanf("%lld %lld", &N, &mod7)==2 && (N||mod7)){
    init();
    sol();
  }
}
