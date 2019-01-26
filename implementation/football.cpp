#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int main(int argc,char **argv){
  string s; 
  cin >> s;  
  int streak = 1;  
  for (int i = 1; i < s.size(); i++){
    if (streak >= 7){
      // dangerous situation  
      cout << "YES" << endl; 
      return 0; 
    } 
    if (s[i-1] == s[i]){
	streak++; 
    }else{
      streak = 1;  
    } 
  } 
  if (streak >= 7){
    cout << "YES" << endl; 
  }else{
    cout << "NO" << endl; 
  } 
  return 0; 
} 
