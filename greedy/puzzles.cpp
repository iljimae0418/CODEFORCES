#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std; 
int a[55]; 
int main(){
	int n,m; 
	cin >> n >> m; 
	for (int i = 0; i < m; i++){
		cin >> a[i]; 
	}
	sort(a,a+m); 
	int ans = 100000; 
	for (int i = 0; i < m && i+n-1 < m; i++){
		ans = min(ans,a[i+n-1]-a[i]); 
	}
	cout << ans << endl; 
	return 0; 
}
