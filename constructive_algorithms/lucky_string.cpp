#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map> 
using namespace std; 
int main(){
	int n; 
	cin >> n; 
	map<char,int> mp; 
	char list[26]; 
	for (int i = 0, c = 'a'; i < 26; i++,c++){
		list[i] = c; 
	}
	string ans = ""; 
	int idx = 0; 
	for (int i = 1; i <= n; i++){
		bool added = false; 
		for (map<char,int>::iterator it = mp.begin(); it != mp.end(); it++){
			if (it->second+4 == i){
				added = true; 
				ans += string(1,it->first); 
				it->second += 4; 
				break; 
			}
		}
		if (!added && idx < 26){
			ans += string(1,list[idx]); 
			mp[list[idx]] = i;  
			idx++; 
		}
	}
	cout << ans << "\n"; 
	return 0; 
}
