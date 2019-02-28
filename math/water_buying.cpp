#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main(int argc,char **argv){
  int n;
  cin >> n;
  while (n--){
    typedef long long ll;
    ll n,a,b;
    cin >> n >> a >> b;
    if (n%2 == 0){
      cout << min(n*a,(n/2)*b) << endl;
    }else{
      cout << min(n*a,((n-1)/2)*b + a) << endl;
    }
  }
  return 0;   
}
