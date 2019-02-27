#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
const int MAXN = 10005;
ll a[MAXN],b[MAXN];
typedef pair<int,int> P;
set<P> exists;
ll overlapCnt(ll x1,ll y1,ll x2,ll y2){
  // count overlap between intervals [x1,y1],[x2,y2]
  if (x1 > y2 || y1 < x2) return 0LL;
  return min(y1,y2)-max(x1,x2)+1LL;
}
int main(int argc,char **argv){
  a[0] = 0LL, b[0] = 0LL;
  exists.insert(P(0,0));
  int n,idx = 1,cnt = 1;
  scanf("%d",&n);
  while (cnt <= n){
    ll x,y;
    scanf("%lld %lld",&x,&y);
    if (!exists.count(P(x,y))){
      exists.insert(P(x,y));
      a[idx] = x;
      b[idx] = y;
      idx++;
    }
    cnt++;
  }
  ll ans = 0;
  if (idx == 1 && a[idx-1] == b[idx-1]){
    printf("1\n");
  }else{
    for (int i = 0; i <= idx-2; i++){
      ans += overlapCnt(a[i],a[i+1],b[i],b[i+1]);
      if (i < idx-2 && a[i+1] == b[i+1]) ans--;
    }
    printf("%lld\n",ans);
  }
  return 0; 
}
