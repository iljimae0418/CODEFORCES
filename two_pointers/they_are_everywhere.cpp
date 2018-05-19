#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring> 
#include <map> 
#include <set> 
using namespace std; 
const int INF = (int)2e9+88; 
int main(){
	int n; 
	cin >> n; 
	string s; 
	cin >> s; 
	map<int,int> mp;  
	for (int i = 0; i < s.size(); i++){
		mp[s[i]]++; 
	}
	int types = mp.size();  
	map<char,int> collections; 
	int l = 0, r = 0, minLen = INF; 
	while (l < s.size()){	
		while (r < s.size() && collections.size() < types){
			collections[s[r]]++;  
			r++; 
		}
		if (collections.size() == types) minLen = min(minLen,r-l); 
		collections[s[l]]--; 
		if (collections[s[l]] == 0){ // if we don't have anymore then erase 
			collections.erase(s[l]);  
		}
		l++;  
	}
	cout << minLen << endl; 
	return 0; 
}
