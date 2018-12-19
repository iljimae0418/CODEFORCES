#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;  
bool same(string s){
	for (int i = 1; i < s.size(); i++){
		if (s[i-1] != s[i]) return false; 
	}
	return true;  
}
int main(){
	int t; 
	cin >> t; 
	while (t--){
		string s; 
		cin >> s; 
		if (same(s)) cout << -1 << endl; 
		else{
			sort(s.begin(),s.end()); 
			cout << s << "\n"; 
		}
	}
	return 0;  
}
