#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef pair<int,int> P;
P a[101];
int main(int argc,char **argv){
  int n,u = 0,l = 0;
  bool parity = false;
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> a[i].first >> a[i].second;
    u += a[i].first;
    l += a[i].second;
    if (a[i].first%2 != a[i].second%2){
      parity = true;
    }
  }
  if (u%2 == 0 && l%2 == 0){
    cout << 0 << endl;
  }else if (u%2 != l%2){
    cout << -1 << endl;
  }else if (u%2 == 1 && l%2 == 1){
    if (parity) cout << 1 << endl;
    else cout << -1 << endl; 
  }
  return 0;
}
