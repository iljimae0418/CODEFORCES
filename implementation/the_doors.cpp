#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 2e5+5;
int a[MAXN],cnt[2];
int main(int argc,char **argv){
  int n;
  scanf("%d",&n);
  for (int i = 1; i <= n; i++){
    scanf("%d",a+i);
    cnt[a[i]]++;
  }
  for (int i = 1; i <= n; i++){
    cnt[a[i]]--;
    if (cnt[a[i]] == 0){
      return !printf("%d\n",i);
    }
  }
  return 0; 
}
