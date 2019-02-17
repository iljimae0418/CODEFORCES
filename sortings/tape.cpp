/*
Find k segments, where the sum of the max value of the segment - min value of the segment
is minimized.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
typedef long long ll;
ll n,m,k;
ll b[MAXN],d[MAXN];
int main(int argc,char **argv){
  cin >> n >> m >> k;
  for (ll i = 1; i <= n; i++){
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++){
    d[i] = b[i+1]-b[i]-1;
  }
  ll ans = (b[n]-b[1]+1);
  sort(d+1,d+n+1,greater<ll>());
  for (int i = 1; i <= k-1; i++){
    ans -= d[i];
  }
  cout << ans << endl;
  return 0;
}
