#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main(int argc,char **argv){
  int n,m;
  cin >> n >> m;
  if (m == 0){ // group size intact
    cout << 1 << endl;
  }else if (m == n){ // no cats remaining
    cout << 0 << endl;
  }else if (m > 0 && m < n){
    if (m <= n/2){
      cout << m << endl;
    }else{
      cout << n-m << endl;
    }
  }
  return 0;  
}
