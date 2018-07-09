#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std; 
int main(){
	string s,t; 
	cin >> s >> t; 
	int cnt = 0; 
	int i = s.size()-1, j = t.size()-1; 
	while (i >= 0 && j >= 0 && s[i] == t[j]){
		i--; 
		j--;  
	}	
	if (i >= 0) cnt += s.size() - (s.size()-1-i);  
	if (j >= 0) cnt += t.size() - (t.size()-1-j);  
	cout << cnt << endl; 
	return 0; 
}
