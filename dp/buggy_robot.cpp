#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <map> 
using namespace std; 
int main(){
	int n; 
	cin >> n; 
	string s; 
	cin >> s;  
	map<char,int> mp; 
	for (int i = 0; i < s.size(); i++){
		mp[s[i]]++; 
	}
	int ans = 0; 
	if (mp['L'] > 0 && mp['R'] > 0){
		ans += 2*min(mp['L'],mp['R']); 
	}
	if (mp['U'] > 0 && mp['D'] > 0){
		ans += 2*min(mp['U'],mp['D']);  
	}
	cout << ans << endl;
	return 0; 
}
