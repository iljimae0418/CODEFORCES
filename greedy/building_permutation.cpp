#include <iostream>
#include <algorithm> 
using namespace std; 
int a[300005]; 
int main(){
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
	}
	sort(a,a+n);  
	long long ans = 0; 
	for (int i = 0; i < n; i++){	
		ans += abs((long long)a[i]-(long long)(i+1)); 
	}
	cout << ans << endl; 
	return 0; 
}
