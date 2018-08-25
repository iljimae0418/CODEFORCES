#include <iostream>
#include <cstdlib> 
#include <algorithm>
#include <vector> 
#include <cstring> 
#include <map>
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
int count(string s,string key){
	int cnt = 0; 
	for (int i = 0; i <= s.size()-key.size(); i++){
		bool match = true; 
		for (int j = 0; j < key.size(); j++){
			if (s[i+j] != key[j]){
				match = false; 
				break; 
			}
		}
		if (match) cnt++; 
	}
	return cnt; 
}
int main(){
	int n,k; 
	cin >> n >> k; 
	string t; 
	cin >> t;  
	int suffix_match = -1; 	
	for (int i = 1; i < t.size(); i++){
		bool match = true; 
		for (int j = 0; j < t.size()-i; j++){
			if (t[i+j] != t[j]){
				match = false; 
				break; 
			}
		}	
		if (match){
			suffix_match = i; 
			break; 
		}
	}
	//cout << suffix_match << endl; 
	string s = t;  
	for (int i = 1;; i++){ 
		if (count(s,t) >= k){
			if (count(s,t) > k){
				int cnt = 0; 
				string output = "";  
				for (int j = 0; j < s.size(); j++){
					if (cnt == k){
						output = s.substr(0,j+t.size()-1);  
						break; 
					}
					bool match = true; 
					for (int l = 0; l < t.size(); l++){
						if (s[j+l] != t[l]){
							match = false; 
							break; 
						}
					}
					if (match){
						cnt++; 
					}
				}
				cout << output << endl; 
			}else{
				cout << s << endl; 
			}
			break; 
		}
		// now if we did not satisfy the count, we append 
		// accordingly 
		if (suffix_match == -1){
			s += t; 
		}else{
			s += t.substr(t.size()-suffix_match); 
		}
	}
	return 0; 
}
