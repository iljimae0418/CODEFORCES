#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 2e5+5;
int a[MAXN];
int main(int argc,char **argv){
  int n;
  scanf("%d",&n);
  for (int i = 1; i <= n; i++){
    scanf("%d",a+i);
  }
  sort(a+1,a+n+1);
  // start of the two pointers algorithm
  int maxsize = 0;
  int l = 1, r = 1;
  while (l <= n){
    while (r <= n && a[r]-a[l] <= 5){
      r++;
    }
    maxsize = max(maxsize,r-l);
    l++;
  }
  return !printf("%d\n",maxsize); 
}
