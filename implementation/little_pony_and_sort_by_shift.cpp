#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int a[100005]; 
int n, idx = -1, minval = (int)2e8; 
bool isSorted(){
	for (int i = 0; i < n-1; i++){
		if (a[i] > a[i+1]) return false; 
	}
	return true; 
}
int main(){
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
		minval = min(a[i],minval);  
	}
	if (isSorted()){ // sequence is already sorted 
		cout << 0 << endl; 
		return 0; 
	}
	for (int i = 0, cnt = 0; i < n; i++){
		if (cnt > 1){
			cout << -1 << endl; 
			return 0;  
		}
		if (a[(i+1)%n] < a[i] && a[(i+1)%n] != minval){
			cout << -1 << endl; // no solution 
			return 0; 
		}else if (a[(i+1)%n] < a[i] && a[(i+1)%n] == minval){
			cnt++;   
			idx = i+1;  
		}
	}
	if (idx == -1) cout << -1 << endl; 
	else cout << n-idx << endl; 
	return 0;  
}
