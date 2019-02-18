#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main(int argc,char **argv){
  int n,v;
  cin >> n >> v;
  if (v >= n-1){
    cout << n-1 << endl;
  }else if (v < n-1){
    int d = (n-1)-v;
    int ans = v;
    for (int i = 0; i < d; i++){
      ans += (2+i);
    }
    cout << ans << endl;
  }
  return 0;  
}
