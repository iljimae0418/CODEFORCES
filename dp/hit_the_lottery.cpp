#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int main(){
	int n,ans = 0; 
	cin >> n; 
	int a[5] = {100,20,10,5,1}; 
	for (int i = 0; i < 5; i++){
		int k = n/a[i]; 
		ans += k;  
		n -= k*a[i]; 
	}
	cout << ans << endl; 
	return 0; 
}
