#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std;  
typedef long long ll;  
ll psum[100005];  
const int INF = 987654321;  
int main(){
	int n,t; 
	cin >> n >> t;  
	for (int i = 1; i <= n; i++){
		int x; 
		cin >> x;  
		psum[i] = x+psum[i-1]; 
	}
	// if psum[j]-psum[i-1] <= t, then we can increment j 
	// if psum[j]-psum[i-1] > t, then we increment i 
	// we continue as long as i <= n && j <= n 
	int ans = -INF;  
	int i = 1, j = 1; 
	while (i <= n && j <= n){
		if (psum[j]-psum[i-1] <= t){
			ans = max(ans,j-i+1);  
			j++; 
		}else{
			i++; 
		}
	}
	if (ans == -INF) cout << 0 << endl; 
	else cout << ans << endl; 
	return 0;  
}
