#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 4e5+5;
int a[MAXN],dp[MAXN];
int main(int argc,char **argv){
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }
  for (int i = n+1; i <= 2*n; i++){
    a[i] = a[i-n];
  }
  dp[1] = (a[1] == 1 ? 1 : 0);
  int maxval = dp[1];
  for (int i = 2; i <= 2*n; i++){
    dp[i] = (a[i-1] == a[i] && a[i] == 1 ? dp[i-1] + 1 : a[i] == 1 ? 1 : 0);
    maxval = max(maxval,dp[i]);
  }
  cout << maxval << endl;
  return 0;
}
