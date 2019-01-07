// put all the heavy ones in individual boxes 
// distribute remaining ones in pairs 
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;  
int s[100005]; 
int main(){
	int n,k;
	cin >> n >> k;  
	for (int i = 1; i <= n; i++){
		cin >> s[i]; 
	}
	if (n <= k){
		cout << s[n] << endl; 
	}else{
		int ans = s[n]; 	
		for (int i = 1; i <= 2*(n-k); i++){
			ans = max(ans,s[i]+s[2*(n-k)-i+1]);  
		}
		cout << ans << endl; 
	}
	return 0; 
}
