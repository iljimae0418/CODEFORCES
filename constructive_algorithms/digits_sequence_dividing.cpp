#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int main(){
  int q; 
  cin >> q; 
  while (q--){
    int n; 
    cin >> n; 
    string s; 
    cin >> s;  
    if (s.size() == 2 && s[0] < s[1]){
      cout << "YES" << endl; 
      cout << 2 << endl; 
      cout << s[0] << " " << s[1] << endl; 
    }else if (s.size() > 2){
      cout << "YES" << endl; 
      cout << 2 << endl; 
      cout << s[0] << " " << s.substr(1) << endl; 
    }else{
      cout << "NO" << endl; 
    }
 } 
 return 0; 
} 
