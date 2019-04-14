#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
struct info{
  int s,d,idx;
  info(){}
};
info a[111];
bool cmp(info &x1,info &x2){
  return x1.s < x2.s;
}
int main(int argc,char **argv){
  int n,t;
  scanf("%d %d",&n,&t);
  for (int i = 1; i <= n; i++){
    scanf("%d %d",&a[i].s,&a[i].d);
    a[i].idx = i;
  }
  sort(a+1,a+n+1,cmp);
  if (t <= a[1].s){
    printf("%d\n",a[1].idx);
  }else{
    int mindiff = 1e9,ans = -1;
    for (int i = 1; i <= n; i++){
      int x = 0;
      if (t > a[i].s){
        x = (t-a[i].s+a[i].d-1)/a[i].d;
        if (a[i].s + a[i].d * x - t < mindiff){
          mindiff = a[i].s + a[i].d * x - t;
          ans = a[i].idx;
        }
      }else{
        x = a[i].s-t;
        if (x < mindiff){
          mindiff = x;
          ans = a[i].idx;
        }
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}
