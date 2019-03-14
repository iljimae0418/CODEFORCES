#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
const int MAXN = 1e6+5;
int cnt[MAXN];
int setBits(int x){
  int ret = 0;
  while (x){
    ret += (x&1);
    x >>= 1;
  }
  return ret;
}
int main(int argc,char **argv){
  int n,w;
  scanf("%d",&n);
  for (int i = 0; i < n; i++){
    scanf("%d",&w);
    cnt[w]++;
  }
  int ans = 0;
  for (int i = 1; i < MAXN; i++){
    cnt[i] += cnt[i-1]/2;
    cnt[i-1] %= 2;
  }
  for (int i = 0; i < MAXN; i++){
    ans += setBits(cnt[i]);
  }
  return !printf("%d\n",ans);
}
