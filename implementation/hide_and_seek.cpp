#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int MAXN = 100005;
const int INF = 987654321;
typedef pair<int,int> P;
int x[MAXN];
P pos[MAXN];
int main(int argc,char **argv){
  IOFAST();
  int n,k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++){
    pos[i] = P(INF,-INF);
  }
  for (int i = 1; i <= k; i++){
    cin >> x[i];
    pos[x[i]].first = min(pos[x[i]].first,i);
    pos[x[i]].second = max(pos[x[i]].second,i);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++){
    if (pos[i] == P(INF,-INF)){
      if (i > 1 && i < n){
        ans += 3;
      }
      else{
        ans += 2;
      }
    }else{
      if (i > 1 && pos[i].first > pos[i-1].second) ans++;
      if (i < n && pos[i].first > pos[i+1].second) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
