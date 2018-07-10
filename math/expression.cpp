#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int a[3]; 
int main(){
	cin >> a[0] >> a[1] >> a[2]; 
	int ans = (a[0]+a[1])*a[2]; 
	ans = max(ans,a[0]*(a[1]+a[2]));  
	ans = max(ans,a[0]*a[1]*a[2]); 
	ans = max(ans,a[0]+a[1]+a[2]);  
	cout << ans << endl;  
	return 0; 
}
