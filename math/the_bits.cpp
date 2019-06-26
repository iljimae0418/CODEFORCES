#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main(int argc,char **argv){
  int n;
  string a,b;
  cin >> n >> a >> b;
  int cnt00 = 0, cnt01 = 0, cnt1 = 0, cnt10 = 0;
  for (int i = 0; i < n; i++){
    if (b[i] == '0'){
      if (a[i] == '0') cnt00++;
      else if (a[i] == '1') cnt10++;
    }
    if (a[i] == '1') cnt1++;
    if (a[i] == '0' && b[i] == '1') cnt01++;
  }
  long long ans = (long long)cnt00*(long long)cnt1 + (long long)cnt10*(long long)cnt01;
  cout << ans << "\n";
  return 0;
}
