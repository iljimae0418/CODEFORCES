#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std; 
bool cmp(string s1,string s2){
	return s1.size() < s2.size();  
}
bool isContained(string s1,string s2){
	for (int i = 0; i <= s2.size()-s1.size(); i++){
		bool contained = true; 
		for (int j = 0; j < s1.size(); j++){
			if (s1[j] != s2[i+j]){
				contained = false; 
				break; 
			}
		}
		if (contained) return true;  
	}
	return false; 
}
int main(){
	int n; 
	cin >> n; 
	vector<string> v; 
	for (int i = 0; i < n; i++){
		string s; 
		cin >> s; 
		v.push_back(s); 
	}
	sort(v.begin(),v.end(),cmp);  
	for (int i = 0; i+1 < v.size(); i++){
		if (!isContained(v[i],v[i+1])){
			cout << "NO" << endl;
			return 0; 
		}
	}
	cout << "YES" << endl; 
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << endl; 
	}
	return 0;  
}
