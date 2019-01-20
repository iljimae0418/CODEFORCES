#include <iostream>
#include <cstdlib>
using namespace std; 
int main(){
	int n,len = 0;   
	cin >> n; 
	string s; 
	cin >> s;  
	for (int i = 1; i <= 10; i++){
	  if (i*(i+1)/2 == n){
	    len = i; 
	    break; 
	  }
	}
	string ans = ""; 
	for (int i = 1; i <= len; i++){
	  ans += s[i*(i+1)/2 - 1]; 
	} 
	cout << ans << endl; 
	return 0; 
}
