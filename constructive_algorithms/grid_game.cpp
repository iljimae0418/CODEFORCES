#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
typedef pair<int,int> P; 
P vertical[4] = {P(1,1),P(1,2),P(1,3),P(1,4)};  
P horizontal[4] = {P(3,1),P(3,3),P(4,1),P(4,3)};  
int main(int argc,char **argv){
  string s;  
  cin >> s;  
  int v = 0, h = 0;  
  for (int i = 0; i < s.size(); i++){
    if (s[i] == '0'){
      cout << vertical[v].first << " " << vertical[v].second << endl; 
      v = (v+1)%4;  
    }else{
      cout << horizontal[h].first << " " << horizontal[h].second << endl; 
      h = (h+1)%4;  
    }
  } 
  return 0;
} 
 	
