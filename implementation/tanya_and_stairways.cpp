#include <iostream>
#include <vector> 
using namespace std; 
int a[1004];  
int main(){
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
	}
	vector<int> v;  
	int idx = n-1;  
	while (idx >= 0){
		v.push_back(a[idx]);  
		idx -= a[idx];  
	}
	cout << v.size() << endl; 
	for (int i = v.size()-1; i >= 0; i--){
		cout << v[i] << " "; 
	}
	cout << endl; 
	return 0; 
}
