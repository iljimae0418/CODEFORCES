#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <vector> 
using namespace std; 
typedef pair<int,int> P; 
int main(){
	string s; 
	cin >> s;  
	vector<P> v; 
	for (int i = 0; i < s.size(); i++){
		int cur = s[i]-'0'; 
		if (cur%2 == 0){
			v.push_back(P(cur,i)); 
		}
	}
	if (v.empty()){
		cout << -1 << endl; 
		return 0; 
	}
	int swap_pos = -1, pivot = s[s.size()-1]-'0';  
	for (int i = v.size()-1; i >= 0; i--){
		if (v[i].first < pivot){
			swap_pos = v[i].second; 
		}
	}
	if (swap_pos == -1){
		swap(s[s.size()-1],s[v[v.size()-1].second]);  
	}else{
		swap(s[s.size()-1],s[swap_pos]);  
	}
	cout << s << endl; 
	return 0; 
}
