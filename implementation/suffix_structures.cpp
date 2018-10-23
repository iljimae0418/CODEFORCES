#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map> 
using namespace std;  
bool isSubstr(string s,string t){
	for (int i = 0; i <= s.size()-t.size(); i++){
		bool found = true;  
		for (int j = 0; j < t.size(); j++){
			if (s[i+j] != t[j]){
				found = false; 
				break; 
			}
		}
		if (found) return true;  
	}
	return false;  
}
bool isSubset(map<char,int> mps,map<char,int> mpt){
	for (map<char,int>::iterator it = mpt.begin(); it != mpt.end(); it++){
		if (!mps.count(it->first)){
			return false; 
		}else{
			mps[it->first] -= it->second; 
		}
	}
	for (map<char,int>::iterator it = mps.begin(); it != mps.end(); it++){
		if (it->second < 0) return false; 
	}
	return true; 
}
int main(){
	string s,t;  
	cin >> s >> t;  
	map<char,int> mps,mpt; 
	for (int i = 0; i < s.size(); i++){
		mps[s[i]]++;  
	}
	for (int i = 0; i < t.size(); i++){
		mpt[t[i]]++; 
	}
	// check if array 
	if (s != t && mps == mpt){
		cout << "array" << endl;
		return 0; 
	}
	// check if automaton 
	int cnt = 0; 
	for (int i = 0; i < s.size(); i++){
		if (cnt == t.size()){
			cout << "automaton" << endl;
			return 0;  
		}
		if (s[i] == t[cnt]){
			cnt++; 
		}
	}
	if (cnt == t.size()){
		cout << "automaton" << endl;
		return 0;  
	}
	// check if both 
	if (s.size() > t.size() && isSubset(mps,mpt)){
		cout << "both" << endl; 
	}else{
		cout << "need tree" << endl; 
	}
	return 0; 
}
