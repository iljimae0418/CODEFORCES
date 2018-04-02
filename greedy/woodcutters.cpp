#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int a[100001],b[100001]; 
int main(){
	int ans = 2; // the leftmost and rightmost can always be cut down 
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i] >> b[i]; 
	}
	if (n == 1){
		cout << 1 << endl;
		return 0;  
	}
	for (int i = 1; i < n-1; i++){
		if (a[i]-a[i-1] > b[i]) ans++; 
		else if (a[i+1]-a[i] > b[i]){
			ans++; 
			a[i] += b[i]; 
		}
	}
	cout << ans << endl; 
	return 0;  
}
