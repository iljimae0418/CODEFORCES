// just simple implementation. Have to be careful with checking if the string is valid.  
#include <iostream>
#include <cstdlib>
#include <cstring> 
#include <algorithm> 
#include <vector> 
#include <map> 
using namespace std; 
// name has to appear only once  
int main(){
	vector<string> v; 
	v.push_back("Danil"); 
	v.push_back("Olya"); 
	v.push_back("Slava"); 
	v.push_back("Ann"); 
	v.push_back("Nikita"); 
	string s; 
	cin >> s; 
	int cnt[5]; 
	memset(cnt,0,sizeof(cnt)); 
	for (int i = 0; i < v.size(); i++){
		vector<int> ret; 
		for (int begin = 0; begin+v[i].size() <= s.size(); begin++){
			bool matched = true; 
			for (int j = 0; j < v[i].size(); j++){
				if (s[begin+j] != v[i][j]){
					matched = false; 
					break; 
				}
			}
			if (matched) ret.push_back(begin);  
		}
		cnt[i] = ret.size(); 
	}
	map<int,int> mp; 
	for (int i = 0; i < 5; i++){
		mp[cnt[i]]++; 
	}
	if (mp.size() > 2) cout << "NO" << endl; 
	else if (mp.size() == 2 && mp[0] == 4 && mp[1] == 1) cout << "YES" << endl; 
	else cout << "NO" << endl; 
	return 0;  
}
