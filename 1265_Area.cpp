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

using namespace std;

// 自行補上 inline / const type& blabla...
const double eps = 1e-10;
const double pi  = acos(-1);

struct Point{
  double x,y;
  Point(double x=0, double y=0):x(x), y(y){}
};
typedef Point Vector;

Vector operator + ( Vector A, Vector B) { return Vector(A.x+B.x, A.y+B.y); }   // 向量加向量
Vector operator - ( Point A, Point B) { return Vector(A.x-B.x, A.y-B.y); }   // 兩點間向量
Vector operator * ( Vector A, double p) { return Vector(A.x*p, A.y*p); }
Vector operator / ( Vector A, double p) { return Vector(A.x/p, A.y/p); }

bool operator < ( const Point &A, const Point &B) {
  return A.x<B.x || ( A.x == B.x && A.y < B.y);
}

int dcmp(double x){
  if( fabs(x) < eps ) return 0; else return x<0?-1:1;
}
bool operator == ( const Point &a, const Point &b) { return dcmp(a.x-b.x)==0 && dcmp(a.y-b.y)==0; }

ostream& operator << ( ostream &os, const Point& p) { return os << "(" << p.x << "," << p.y << ")"; }
Point getPoint(){ Point res; scanf("%lf %lf", &res.x, &res.y); return res; }

double Dot( Vector A, Vector B) { return A.x*B.x+A.y*B.y; } // 點積
double Len( Vector A) { return sqrt(Dot(A,A)); }      // 向量長度
double Ang( Vector A, Vector B) { return acos(Dot(A,B)/Len(A)/Len(B)); }    // 極角

double Cross( Vector A, Vector B) { return A.x*B.y-A.y*B.x; }
double Area2( Point A, Point B, Point C) { return Cross(B-A, C-A); }    // 有向面積

Vector Rotate( Vector A, double rad){   // rad < 0 : 順時針旋轉
  return Vector(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad));
}
Vector Normal( Vector A){   // 法單位向量, A不能是零向量
  double L = Len(A);
  return Vector(-A.y/L, A.x/L);
}

bool Intersection( Point A1, Point A2, Point B1, Point B2){     // 不包含端點在線上的Case
  double c1 = Cross(A2-A1, B1-A1), c2 = Cross(A2-A1, B2-A1), c3 = Cross(B2-B1, A1-B1), c4 = Cross(B2-B1, A2-B1);
  return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0 ;
}
bool OnSegment( Point p, Point A1, Point A2){         // p 是否在線段內，不包含端點（自行判斷重疊
  return dcmp(Cross(A1-p, A2-p))==0 && dcmp(Dot(A1-p, A2-p))<0;
}
Point GetLineIntersection( Point p, Vector V, Point q, Vector W){   // 須保證兩點斜式有唯一交點
  Vector U = p-q;
  double t = Cross(W,U)/Cross(V,W);
  return p+V*t;
}
double DistanceToLine( Point P, Point A, Point B ){       // 平行四邊形求P到AB的距離
  Vector v1=B-A, v2=P-A;
  return fabs(Cross(v1,v2))/Len(v1);        // 面積除底邊，去fabs為有向面積
}
double DistanceToSeg( Point P, Point A, Point B ){      // 點到線段距離
  if(A == B) return Len(P-A);
  Vector v1=B-A, v2=P-A, v3=P-B;
  if(dcmp(Dot(v1,v2))<0) return Len(v2);
  if(dcmp(Dot(v1,v3))>0) return Len(v3);
  return fabs(Cross(v1,v2)) / Len(v1);
}
Point GetLineProjection( Point p, Point A, Point B){    // 點在直線上投影點
  Vector v = B-A;
  return A+v*(Dot(v,p-A)/Dot(v,v));
}
double PolygonArea( Point p[], int n){
  double area = 0;
  for(int i=1;i<n-1;++i)
    area += Cross(p[i]-p[0], p[i+1]-p[0]);
  return area/2;
}


Vector path[150];
Point pos[150];
int N;

int cal(Point &p1, Point &p2){
  int dx=abs(int(p1.x)-(int)p2.x), dy=abs(int(p1.y)-int(p2.y));
  if(dx<dy) swap(dy,dx);
  int ux = dx/__gcd(dx,dy);
  return dx/ux+1;
}
void init(){
  pos[0] = Point(0,0);
  scanf("%d", &N);
  for(int i=1;i<=N;++i){
    path[i] = getPoint();
    pos[i] = pos[i-1] + path[i];
  }
}
void sol(){
  int E=0,I;
  double A = PolygonArea( pos+1, N);
  for(int i=1;i<=N;++i) E += cal(pos[i-1], pos[i]);
  E -= N;
  I = (int)A+1-E/2;
  printf("%d %d %.1f\n\n", I, E, A);
}

int main(){
  int ncase, cc=1;
  scanf("%d", &ncase);
  while(ncase--){
    printf("Scenario #%d:\n", cc++);
    init();
    sol();
  }
}