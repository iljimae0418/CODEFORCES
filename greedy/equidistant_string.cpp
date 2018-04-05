#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;  
int main(){
	string s,t; 
	cin >> s >> t; 
	int diffCnt = 0; 
	for (int i = 0; i < s.size(); i++){
		if (s[i] != t[i]) diffCnt++; 
	}
	if (diffCnt%2 == 1){
		cout << "impossible" << endl; 
	}else{
		string ans = ""; 
		for (int i = 0; i < s.size(); i++){
			ans += "@"; 
		}
		for (int i = 0; i < s.size(); i++){
			if (s[i] == t[i]) ans[i] = s[i]; 
		}
		int cur = 0; // if 0 then let ans[i] = s[i], else let ans[i] = t[i]
		for (int i = 0; i < s.size(); i++){
			if (cur == 0 && ans[i] == '@'){
				ans[i] = s[i]; 
				cur = 1; 
			}else if (cur == 1 && ans[i] == '@'){
				ans[i] = t[i]; 
				cur = 0; 
			}
		}
		cout << ans << endl; 
	}
	return 0; 
}
