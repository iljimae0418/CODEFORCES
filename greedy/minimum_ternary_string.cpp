#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map> 
using namespace std; 
int main(){
	string s; 
	cin >> s;  
	map<char,int> mp; 
	int cnt1 = 0, cnt0 = 0, idx = -1; 
	bool firstAppear = false; 
	for (int i = 0; i < s.size(); i++){
		mp[s[i]]++; 
		if (s[i] == '1') cnt1++; 
		if (!firstAppear && s[i] == '0') cnt0++; 
		if (s[i] == '2' && !firstAppear){
			firstAppear = true;
			idx = i;  
		}
	}
	string ans;  
	for (int i = 0; i < cnt0; i++){
		ans += "0"; 
	}
	for (int i = 0; i < cnt1; i++){
		ans += "1"; 
	}
	for (int i = idx; i < s.size(); i++){
		if (s[i] == '2' || s[i] == '0'){
			ans += s[i]; 
		}
	}
	cout << ans << endl; 
	return 0; 
}
