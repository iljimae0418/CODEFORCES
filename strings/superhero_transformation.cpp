#include <iostream>
#include <cstdlib>
#include <cstring> 
#include <algorithm>
#include <set> 
using namespace std; 
set<char> vowel; 
int main(){
  vowel.insert('a');  
  vowel.insert('e');  
  vowel.insert('i');  
  vowel.insert('o'); 
  vowel.insert('u');  
  string s,t; 
  cin >> s >> t;  
  if (s.size() != t.size()){
    cout << "No" << endl; 
  }else{
    for (int i = 0; i < s.size(); i++){
      if ((vowel.count(s[i]) && vowel.count(t[i])) ||(!vowel.count(s[i]) && 
	    !vowel.count(t[i]))){
	  continue; 
      }else{
      	cout << "No" << endl; 
	return 0; 
      } 
    } 
    cout << "Yes" << endl; 
  }
  return 0;  
} 
	    
	
