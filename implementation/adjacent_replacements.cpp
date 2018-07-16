#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std; 
int a[1001]; 
int main(){
	int n; 
	cin >> n; 
	vector<int> v; 
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
		v.push_back(a[i]);  
	}
	sort(v.begin(),v.end());  
	for (int i = 0; i < v.size(); i++){
		if (v[i]%2 == 1) continue; 
		for (int j = 1; j <= n; j++){
			if (v[i] == a[j]){
				a[j] = v[i]-1;  
			}
		}
	}
	// print out result 
	for (int i = 1; i <= n; i++){
		cout << a[i] << " "; 
	}
	cout << endl; 
	return 0; 
}
