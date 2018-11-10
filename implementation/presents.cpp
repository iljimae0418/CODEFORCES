#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int a[105],ans[105]; 
int main(){
	int n; 
	cin >> n; 
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
	}
	for (int i = 1; i <= n; i++){
		ans[a[i]] = i;  
	}	
	for (int i = 1; i <= n; i++){
		cout << ans[i] << " "; 
	}
	cout << endl; 
	return 0; 
}
