#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
#include <map> 
using namespace std;  
int main(){
	int n; 
	string s,t; 
	cin >> n >> s >> t; 
	// first let's check if we can find an answer 
	map<char,int> mp1,mp2; 
	for (int i = 0; i < s.size(); i++){
		mp1[s[i]]++;  
		mp2[t[i]]++; 
	}
	if (mp1 != mp2){ 
		// no answer 
		cout << -1 << endl; 
		return 0; 
	}
	int cnt = 0; 
	vector<int> ans; 
	for (int i = 0; i < s.size(); i++){
		if (s[i] != t[i]){
			for (int j = i+1; j < s.size(); j++){
				if (s[j] == t[i]){
					for (int k = j-1; k >= i; k--){
						swap(s[k],s[k+1]);  
						ans.push_back(k);  
						cnt++; 
					}
					break; 
				}
			}
		}
	}
	cout << cnt << endl; 
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i]+1 << " "; 
	}
	cout << endl; 
	return 0;  
}
