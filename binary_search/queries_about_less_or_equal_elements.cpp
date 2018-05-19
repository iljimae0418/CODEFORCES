#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int a[200005],b[200005]; 
int main(){
	int n,m; 
	cin >> n >> m; 
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
	}
	for (int i = 1; i <= m; i++){
		cin >> b[i];
	}
	sort(a+1,a+n+1); 
	for (int i = 1; i <= m; i++){	
		int ans = upper_bound(a+1,a+n+1,b[i])-(a+1);  
		cout << ans << " "; 
	}
	cout << endl; 
	return 0; 
}
