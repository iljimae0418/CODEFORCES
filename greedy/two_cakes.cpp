#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
const int MAXN = (int)2e5 + 5;
typedef long long ll;
int a[MAXN];
map<int,vector<int> > mp;
int main(int argc,char **argv){
  int n;
  scanf("%d",&n);
  // guaranteed that there will be two of each a[i]
  for (int i = 1; i <= 2*n; i++){
    scanf("%d",&a[i]);
    mp[a[i]].push_back(i);
  }
  ll ans = mp[1][0]+mp[1][1]-2;
  for (int i = 2; i <= n; i++){
    ll add = min(abs(mp[i-1][0]-mp[i][0])+abs(mp[i-1][1]-mp[i][1]),
              abs(mp[i-1][0]-mp[i][1])+abs(mp[i-1][1]-mp[i][0]));
    ans += add;
  }
  printf("%lld\n",ans);
  return 0;
}
