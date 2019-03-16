#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e6;
int a[MAXN],f[MAXN],g[MAXN];
int main(int argc,char **argv){
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++){
    f[i] = (a[i] == a[i-1] ? f[i-1]+1 : 1);
  }
  for (int i = n; i >= 1; i--){
    g[i] = (a[i] == a[i+1] ? g[i+1]+1 : 1);
  }
  int ans = 0;
  for (int i = 1; i < n; i++){
    if (a[i] != a[i+1]){
      ans = max(ans,min(f[i],g[i+1])*2);
    }
  }
  cout << ans << endl;
  return 0; 
}
