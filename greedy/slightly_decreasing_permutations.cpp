#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int a[100005]; 
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	int n,k; 
	cin >> n >> k;  
	if (k == 0){
		for (int i = 1; i <= n; i++){
			cout << i << " "; 
		}
		cout << endl; 
	}else{
		int idx = 0; 
		a[idx] = n; 
		for (int i = k; i >= 1; i--){
			a[++idx] = i; 
		}
		for (int i = k+1; i <= n-1; i++){
			a[++idx] = i;  
		}
		for (int i = 0; i < n; i++){
			cout << a[i] << " "; 
		}
		cout << endl; 
	}
	return 0; 
}
