#include <iostream>
#include <algorithm> 
#include <cstdlib> 
using namespace std; 
int a[1001]; 
int main(int argc,char **argv){
	int n,limit = -1; 
	cin >> n; 
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
		limit = max(limit,a[i]); 
	}
	int mincost = 1e9,ans = -1; 
	for (int t = 1; t <= limit; t++){
		int cost = 0; 
		for (int i = 1; i <= n; i++){
			cost += min(abs(a[i]-t),min(abs(a[i]-t-1),abs(a[i]-t+1))); 
		}
		if (cost < mincost){
			mincost = cost; 
			ans = t;  
		}
	}
	cout << ans << " " << mincost << "\n";
	return 0; 
}
