#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std;  
int main(){
	int n; 
	cin >> n; 
	vector<int> v;  
	for (int i = 1; i <= n; i++){
		if (i%2 == 0) v.push_back(i);  
	}
	for (int i = 1; i <= n; i++){
		if (i%2 == 1) v.push_back(i); 
	}
	for (int i = 1; i <= n; i++){
		if (i%2 == 0) v.push_back(i);  
	}
	cout << v.size() << endl; 
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << " "; 
	}
	cout << endl; 
	return 0; 
}
