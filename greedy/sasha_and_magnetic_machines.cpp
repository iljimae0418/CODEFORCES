#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 5e4+5;
int a[MAXN];
int main(int argc,char **argv){
  int n, sum = 0, minval = 1000;
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> a[i];
    sum += a[i];
    minval = min(minval,a[i]);
  }
  int ans = sum;
  for (int i = 0; i < n; i++){
    for (int x = 1; x*x <= a[i]; x++){
      if (a[i]%x == 0){
        ans = min(ans,sum+minval*(x-1)-(a[i]-a[i]/x));
        ans = min(ans,sum+minval*(a[i]/x-1)-(a[i]-x));
      }
    }
  }
  cout << ans << "\n";
  return 0; 
}
