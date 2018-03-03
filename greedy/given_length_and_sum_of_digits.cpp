#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std; 
int m,sum;
int main(){
	cin >> m >> sum; 
	if (m == 1){
		if (sum >= 10){
			cout << -1 << " " << -1 << endl; 
		}else{
			cout << sum << " " << sum << endl; 
		}
		return 0; 
	}else{
		if (sum == 0 || sum > 9*m){
			cout << -1 << " " << -1 << endl; 
			return 0; 
		}
	}	
	vector<int> v;  
	int s = sum-1;  
	for (int i = 0; i < m-1; i++){
		int add = min(9,s); 
		s -= add; 
		v.push_back(add); 
	}
	v.push_back(s+1); 
	for (int i = 0; i < v.size(); i++){
		cout << v[v.size()-1-i]; 
	}
	cout << " "; 
	v.clear(); 
	s = sum;  
	for (int i = 0; i < m; i++){
		int add = min(9,s); 
		s -= add; 
		v.push_back(add); 
	}
	for (int i = 0; i < v.size(); i++){
		cout << v[i]; 
	}
	cout << endl; 
	return 0; 
}
