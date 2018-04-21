#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <vector> 
using namespace std; 
int main(){
	string s; 
	cin >> s; 
	map<char,int> mp; 
	for (int i = 0; i < s.size(); i++){
		mp[s[i]]++;  
	}
	int turn = 0; // 0: first, 1: second  
	while (true){
		int even = 0, odd = 0, maxodd = -1;
		char f;  
		for (map<char,int>::iterator it = mp.begin(); it != mp.end(); it++){
			if (it->second%2 == 0 && it->second > 0) even++; 
			else if (it->second%2 == 1) odd++; 
			if (it->second%2 != 0 && it->second > maxodd){
				maxodd = it->second; 
				f = it->first;  
			}
		}
 		if (odd <= 1){
			// we have a palindrome 
			cout << (turn ? "Second" : "First") << endl; 
			break; 
		}else if (odd > 1){
			// if we can't win this turn, we maximise the number of odds 
			if (even > 0){
				for (map<char,int>::iterator it = mp.begin(); it != mp.end(); it++){
					if (it->second%2 == 0){
						it->second -= 1; 
						break; 
					}	
				}
			}else{
				mp[f]--;  
			}	
		}
		turn = !turn;  
	}
	return 0;  
}
