#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set> 
#include <map> 
using namespace std; 
bool cmp(string &s1,string &s2){
	return (s1.length() < s2.length()) || ((s1.length() == s2.length() && s1 < s2)); 
}
int main(){
	int n,cnt = 0; 
	cin >> n; 
	vector<string> v1,v2; 
	map<string,int> mp1,mp2; 
	for (int i = 0; i < n; i++){
		string s; 
		cin >> s; 	
		mp1[s]++; 
	}
	for (int i = 0; i < n; i++){	
		string s; 
		cin >> s;  
		if (mp1.count(s) && mp1[s] > 0){
			mp1[s]--;  
			continue; 
		}
		mp2[s]++;  
	}
	for (map<string,int>::iterator it = mp1.begin(); it != mp1.end(); it++){
		for (int i = 0; i < it->second; i++){
			v1.push_back(it->first); 
		}
	}
	for (map<string,int>::iterator it = mp2.begin(); it != mp2.end(); it++){
		for (int i = 0; i < it->second; i++){
			v2.push_back(it->first); 
		}
	}
	sort(v1.begin(),v1.end(),cmp); 
	sort(v2.begin(),v2.end(),cmp); 
	for (int i = 0; i < v1.size(); i++){
		string s = v1[i], t = v2[i]; 
		for (int j = 0; j < s.size(); j++){
			if (s[j] != t[j]) cnt++; 
		}
	}
	cout << cnt << endl; 
	return 0; 
}
