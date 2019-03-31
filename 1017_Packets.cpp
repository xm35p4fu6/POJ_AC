#include <iostream>
#include <cstring>
using namespace std;
int cnt[10], ans;
bool get_data(){
  ans = 0;
  memset(cnt, 0, sizeof(cnt));
  for(int i=1;i<=6;i++)
    scanf("%d", cnt+i);
  for(int i=1;i<7;i++)if(cnt[i])
    return true;
  return false;
}
int main(){
  while(get_data()){
    ans+=(cnt[6]+cnt[5]+cnt[4]+(cnt[3]>>2));
    cnt[1] -= (cnt[5]*11);
    cnt[2] -= (cnt[4]*5);
    cnt[3] %= 4;
    if(cnt[3]>0){
      ans++;
      cnt[2]-=(7-(cnt[3]<<1));
      cnt[1]-=(8-cnt[3]);
    }
    if(cnt[2]>0){
      ans+=(cnt[2]/9);
      cnt[2]%=9;
      if(cnt[2]){
        ans++;
        cnt[1]-=(36-(cnt[2]<<2));
      }
    }
    else if(cnt[2]<0){
      cnt[2] *= -1;
      cnt[1]-=(cnt[2]<<2);
    }
    if(cnt[1]>0){
      ans+=(cnt[1]/36 + (cnt[1]%36?1:0));
    }
    printf("%d\n", ans);
  }
}
    /*
    switch(cnt[3]){
      case 1:
        cnt[2]-=5;
        cnt[1]-=7;
        break;
      case 2:
        cnt[2]-=3;
        cnt[1]-=6;
        break;
      case 3:
        cnt[2]-=1;
        cnt[1]-=5;
    }*/
