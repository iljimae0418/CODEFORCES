#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;
const int MAXN = 2e5+5;
const int MAXK = 105;
int d[MAXN],f[MAXK];
int main(int argc,char **argv){
  int n,k,cnt = 0;
  scanf("%d %d",&n,&k);
  for (int i = 0; i < n; i++){
    scanf("%d",d+i);
    d[i] %= k;
    f[d[i]]++;
  }
  cnt += f[0]/2;
  cnt += (k%2 == 0 ? f[k/2]/2 : 0);
  for (int i = 1; i < (k+1)/2; i++){
    cnt += min(f[i],f[k-i]); 
  }
  return !printf("%d\n",2*cnt);
}
