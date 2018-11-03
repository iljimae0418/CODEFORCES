// seems like a dfs problem 
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std; 
vector<int> v,printout;  
bool can(int l,int r,int prev,int m,int turn,vector<int> ans){
	if (m == 0){
		printout = ans; 
		return true;
	} 
	if (turn == 0){
		for (int i = 0; i < v.size(); i++){
			if (v[i] != prev && l+v[i] > r){
				ans.push_back(v[i]); 
				if (can(l+v[i],r,v[i],m-1,1,ans)) return true; 
				ans.pop_back();  
			}
		}
	}else{
		for (int i = 0; i < v.size(); i++){
			if (v[i] != prev && r+v[i] > l){
				ans.push_back(v[i]); 
				if (can(l,r+v[i],v[i],m-1,0,ans)) return true; 
				ans.pop_back();  
			}
		}
	}
	return false; 
}
int main(){
	string s; 
	int m;  
	cin >> s; 
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '1') v.push_back(i+1); 
	}
	cin >> m;  
	vector<int> ans; 
	if (can(0,0,-1,m,0,ans)){
		cout << "YES" << endl; 
		for (int i = 0; i < printout.size(); i++){
			cout << printout[i] << " "; 
		}
		cout << endl; 
	}else cout << "NO" << endl; 
	return 0;  
}
