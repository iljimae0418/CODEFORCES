#include <iostream>
using namespace std; 
typedef long long ll; 
int main(){
  int n; 
  cin >> n; 
  while (n--){
    ll k,x; 
    cin >> k >> x;  
    cout << x+9LL*(k-1) << endl; 
  } 
  return 0; 
} 
