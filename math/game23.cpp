#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main(int argc,char **argv){
  int n,m;
  scanf("%d %d",&n,&m);
  if (m%n != 0){
    return !printf("-1\n");
  }else{
    int k = m/n;
    if (k == 1){
      printf("0\n");
    }else{
      // prime factorize using only 2 and 3
      int cnt[4] = {0,0,0,0};
      for (int i = 2; i <= 3; i++){
        while (k%i == 0){
          k /= i;
          cnt[i]++;
        }
      }
      if (k != 1) return !printf("-1\n");
      printf("%d\n",cnt[2]+cnt[3]);
    }
  }
  return 0;
}
