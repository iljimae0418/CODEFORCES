#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std; 
const int INF = 2e9+88;
int main(){
	int n,m; // experienced, newbie 
	cin >> n >> m;  
	if (n == 0 || m == 0){
		cout << 0 << endl; 
		return 0; 
	}
	int ans = -INF;  
	for (int i = 0; i <= min(m,n/2); i++){
		// there are i teams of (XP,XP,NB) 
		ans = max(ans,i+min(n-2*i,(m-i)/2)); 
	}
	cout << ans << endl; 
	return 0;  
}
