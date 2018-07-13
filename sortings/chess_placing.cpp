#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <vector> 
using namespace std;  
const int INF = 2e9+88; 
int main(){
	int n;  
	cin >> n; 
	vector<int> v(n/2); 
	for (int i = 0; i < n/2; i++){
		cin >> v[i]; 
	}
	sort(v.begin(),v.end()); 
	// all odd positions are black 
	// all even positions are white 
	int d = INF, difference = 0; 
	for (int i = 1, idx = 0; i <= n-1; i += 2,idx++){
		difference += abs(i-v[idx]);  
	}
	d = min(d,difference); 
	difference = 0; 
	for (int i = 2, idx = 0; i <= n; i += 2,idx++){
		difference += abs(i-v[idx]); 
	}
	d = min(d,difference); 
	cout << d << endl; 
	return 0; 
}
