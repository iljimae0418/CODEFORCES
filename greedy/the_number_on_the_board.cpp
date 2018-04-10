#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <vector> 
#include <map> 
using namespace std; 
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);  
	int k; 
	cin >> k; 
	string s;  
	cin >> s; 
	map<int,int> mp; 
	int sum = 0;  
	for (int i = 0; i < s.size(); i++){
		sum += (s[i]-'0');  
		mp[s[i]-'0']++;  
	}
	int ans = 0;  
	while (sum < k){
		for (map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
			if (it->second > 0){
				it->second--;  
				sum += (9-it->first); 
				ans++;  
				break; 
			}
		}	
	}
	cout << ans << endl; 
	return 0; 
}
