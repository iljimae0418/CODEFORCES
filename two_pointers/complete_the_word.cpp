#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <vector>
#include <deque> 
#include <set> 
#include <map> 
using namespace std; 
int main(){
	// we need a contiguous segment of length 26 where all letters of english 
	// alphabet appears exactly once 
	string s; 
	cin >> s; 
	int l = 0, r = 0; 
	map<char,int> mp; 
	deque<int> pos;  
	bool found = false; 
	while (l < s.size()){
		while (r < s.size() && r-l+1 <= 26){
			if (s[r] == '?'){
				pos.push_back(r);  
			}else{
				mp[s[r]]++;  
			}
			r++;  
		}
		if (r-l < 26) break; // edge case 
		bool keep_going = false; 
		// check map 
		vector<char> not_in;  
		for (char c = 'A'; c <= 'Z'; c++){
			if (mp[c] > 1){
				// there is a repeat 
				keep_going = true; 
				break; 
			}else if (mp[c] == 0){
				not_in.push_back(c);  
			}
		}
		if (!keep_going){
			found = true; 
			for (int i = 0; i < pos.size(); i++){
				s[pos[i]] = not_in[i];  
			}
			break; // we have found a substring, so get out of the while loop   
		}else{
			// we need to keep going. 
			// let's move the left pointer 
			// make proper adjustments 
			if (s[l] == '?') pos.pop_front();  
			else if (mp[s[l]] >= 1) mp[s[l]]--;  
			l++; 
		}
	}
	if (!found) cout << -1 << endl; 
	else{
		for (int i = 0; i < s.size(); i++){
			if (s[i] == '?') s[i] = 'A'; 
		}
		cout << s << endl; 
	}
	return 0;  
}	
