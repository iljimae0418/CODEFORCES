#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;
int main(int argc,char **argv){
  int n;
  cin >> n;
  map<char,int> mp;
  for (int i = 0; i < n; i++){
    int x;
    cin >> x;
    if (x > 0) mp['p']++;
    else if (x < 0) mp['n']++;
    else mp['z']++;
  }
  if (mp['p'] >= (n+1)/2){
    cout << 1 << endl;
  }else if (mp['n'] >= (n+1)/2){
    cout << -1 << endl;
  }else{
    cout << 0 << endl;
  }
  return 0;  
}
