#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map> 
using namespace std;  
int main(){
	int n; 
	cin >> n; 
	string s; 
	cin >> s;  
	map<string,int> mp; 
	for (int i = 0; i < s.size()-1; i++){
		string t; 
		t += s[i]; 
		t += s[i+1]; 
		mp[t]++; 
	}
	int maxval = 0; 
	string maxStr;  
	for (map<string,int>::iterator it = mp.begin(); it != mp.end(); it++){
		if (it->second > maxval){
			maxval = it->second;  
			maxStr = it->first; 
		}
	}
	cout << maxStr << endl;
	return 0; 
}
