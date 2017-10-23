// O(n^3) brute force solution 
// Simply try all intervals [l,r] 
#include <iostream>
#include <cstdlib>
#include <set> 
#include <algorithm> 
using namespace std; 
int main(){
	int n; 
	cin >> n; 
	string s; 
	cin >> s;  
	int maxlen = 0; 
	for (int l = 0; l < s.size(); l++){
		for (int r = l; r < s.size(); r++){
			set<char> st; 
			bool capitalExists = false;  
			for (int k = l; k <= r; k++){
				if (s[k] >= 'A' && s[k] <= 'Z'){
					capitalExists = true; 
					break; 
				}
				st.insert(s[k]);  
			}
			if (capitalExists) continue;  
			maxlen = max(maxlen,(int)st.size()); 
		}
	}
	cout << maxlen << endl;
	return 0; 
}
