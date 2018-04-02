#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map> 
using namespace std; 
int main(){
	string s; 
	cin >> s;  
	int k; 
	cin >> k; 
	map<char,int> mp; 
	int maxval = 0;  
	for (char c = 'a'; c <= 'z'; c++){
		int val; 
		cin >> val; 
		mp[c] = val;  
		maxval = max(maxval,mp[c]); 
	}
	long long ans = 0; 
	for (int i = 0; i < s.size(); i++){
		ans += mp[s[i]]*(i+1); 
	}
	for (int i = s.size()+1; i < s.size()+1+k; i++){
		ans += maxval*i; 
	}
	cout << ans << endl; 
	return 0; 
}
