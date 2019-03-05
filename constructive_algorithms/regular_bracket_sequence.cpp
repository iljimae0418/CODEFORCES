#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(){
  ll k1,k2,k3,k4;
  cin >> k1 >> k2 >> k3 >> k4;
  if (k1 == k4){
    if (k1 == 0 && k3 > 0) cout << 0 << endl;
    else cout << 1 << endl; 
  }else{
    cout << 0 << endl;
  }
  return 0;
}
