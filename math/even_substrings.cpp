#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std;
int main(int agrc,char **argv){
  int n,ans = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    char c;
    cin >> c;
    a[i] = c-'0';
    if (a[i]%2 == 0) ans += (i+1);
  }
  cout << ans << endl;
  return 0;
}
