#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc,char **argv){
  int n,m;
  cin >> n >> m;
  if (m > n){
    cout << -1 << endl;
  }else{
    for (int k = 1; k <= n/m; k++){
      int x = n-m*k;
      int y = m*k-x;
      if (x+y == m*k && 2*x + y == n && x >= 0 && y >= 0){
        // cout << x << " " << y << endl;
        cout << m*k << endl;
        return 0;
      }
    }
    cout << -1 << endl;
  }
  return 0;
}
