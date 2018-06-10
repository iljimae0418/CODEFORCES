#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std;  
int a[200005];  
int dead[2000005];  
int n,K; 
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL); 
	cin >> n >> K; 
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
	}
	sort(a+1,a+n+1); 
	for (int j = 1; j <= n; j++){
		int l = 1, r = n; 
		bool found = false;
		while (l <= r){
			int mid = (l+r)>>1;  
			if (a[mid] > a[j] && a[mid] <= a[j]+K){
				found = true; 
				break; 
			}else if (a[mid] <= a[j]){
				l = mid+1;  
			}else{
				r = mid-1;  
			}
		}
		if (found) dead[a[j]] = 1; // mark a[j] to be dead  
	}
	int ans = 0; 
	for (int i = 1; i <= n; i++){
		if (!dead[a[i]]) ans++; 
	}
	cout << ans << endl; 
	return 0;  
}
