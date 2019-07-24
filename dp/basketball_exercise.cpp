#include <iostream>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
const int MAXN = 100005;
const ll INF = LLONG_MAX;
int n;
ll h1[MAXN],h2[MAXN];
ll cache[MAXN][3]; // cache[i][j] = max sum of heights when we are currently at index i and we previously chose j
ll solve(int i,int previous){
  if (i == n+1) return 0;
  ll &ans = cache[i][previous];
  if (ans != -1) return ans;
  ans = -INF;
  if (previous == 1){
    ans = max(ans,max(solve(i+1,previous),solve(i+1,2)+h2[i]));
  }else if (previous == 2){
    ans = max(ans,max(solve(i+1,previous),solve(i+1,1)+h1[i]));
  }else if (previous == 0){
    ans = max(ans,max(solve(i+1,previous),max(solve(i+1,1)+h1[i],solve(i+1,2)+h2[i])));
  }
  return ans;
}
int main(int argc,char **argv){
  IOFAST();
  cin >> n;
  for (int i = 1; i <= n; i++){
    cin >> h1[i];
  }
  for (int i = 1; i <= n; i++){
    cin >> h2[i];
  }
  memset(cache,-1,sizeof(cache));
  ll ans = solve(0,0);
  cout << ans << "\n";
  return 0;
}
