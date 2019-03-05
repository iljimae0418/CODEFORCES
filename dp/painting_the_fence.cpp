// MLE need greedy solution 
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef pair<int,int> P;
const int MAXN = 5005;
P a[MAXN];
int cache[MAXN][MAXN][3];
int n,q;
int solve(int i,int prev,int used){
  if (i == q) return 0;
  if (i == q-1 && used < 2) return 0;
  int &ret = cache[i][prev][used];
  if (ret != -1) return ret;
  ret = 0;
  // cout << prev << endl;
  if (used < 2){
    ret = max(a[i].second-max(a[i].first,prev)+(a[i].first <= prev ? 0 : 1)+solve(i+1,a[i].second,used),
              solve(i+1,prev,used+1));
  }else if (used >= 2){
    ret = a[i].second-max(a[i].first,prev)+(a[i].first <= prev ? 0 : 1)+solve(i+1,a[i].second,used);
  }
  return ret;
}
int main(){
  IOFAST();
  cin >> n >> q;
  for (int i = 0; i < q; i++){
    cin >> a[i].first >> a[i].second;
  }
  sort(a,a+q);
  memset(cache,-1,sizeof(cache));
  int ans = solve(0,0,0);
  cout << ans << "\n";
  return 0;
}
