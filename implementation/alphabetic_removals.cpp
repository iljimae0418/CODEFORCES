#include <iostream>
#include <cstdlib>
#include <vector> 
#include <algorithm>
#include <map> 
using namespace std; 
int mark[400005]; // mark[i] = skip the ith character when printing 
int main(){
	int n,k; 
	cin >> n >> k; 
	string s; 
	cin >> s; 
	int cnt = 0;  
	map<char,int> mp;  
	for (int i = 0; i < s.size(); i++){
		mp[s[i]]++;  
	}
	char last;
	int temp = k;  
	for (map<char,int>::iterator it = mp.begin(); it != mp.end(); it++){
		temp -= min(it->second,temp);  
		if (temp == 0){
			last = it->first; 
			break; 
		}
	}
	temp = k;  
	for (int i = 0; i < s.size(); i++){
		if (s[i] < last){
			mark[i] = 1; 
			temp--;  
		}
	}
	for (int i = 0; i < s.size(); i++){
		if (temp == 0) break; 
		if (s[i] == last){
			mark[i] = 1; 
			temp--;  
		}
	}
	for (int i = 0; i < s.size(); i++){
		if (!mark[i]){
			cout << s[i]; 
		}
	}
	cout << endl; 
	return 0;  
}
