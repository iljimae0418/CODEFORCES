#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int main(int argc,char **argv){
  int x,y,z,a,b,c;  
  cin >> x >> y >> z >> a >> b >> c;  
  if (x > a){
    cout << "NO" << endl; 
    return 0; 
  } 
  a -= x; 
  if (y > a+b){
    cout << "NO" << endl; 
    return 0; 
  } 
  int sum = a+b+c-y;  
  if (z > sum){
    cout << "NO" << endl; 
    return 0; 
  } 
  cout << "YES" << endl; 
  return 0; 
} 
