#include <iostream>
#include <map>
using namespace std; 
int main(int argc,char **argv){
	string s; 
	cin >> s; 
	map<char,int> mp; 
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '4') mp[s[i]]++; 
		else if (s[i] == '7') mp[s[i]]++; 
	}
	if (mp.empty()) cout << -1 << endl; 
	else cout << (max(mp['4'],mp['7']) == mp['4'] ? 4 : 7) << endl; 
	return 0; 
}
