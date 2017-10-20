#include <iostream>
#include <cstdlib> 
#include <algorithm>
using namespace std; 
int a[100001],pre_Min[100001],suf_Min[100001];   
int main(){
	int n,k; 
	cin >> n >> k; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
	}
	if (k == 1){
		// simply print minimum
		int minval = a[0];  
		for (int i = 1; i < n; i++){
			minval = min(minval,a[i]); 
		}
		cout << minval << endl; 
	}else if (k == 2){
		// pre_Min[i] = minval in [0,i] 
		// suf_Min[i] = minval in [i+1,n-1]
		suf_Min[n-1] = a[n-1]; 
		for (int i = n-2; i >= 0; i--){
			suf_Min[i] = min(suf_Min[i+1],a[i]); 
		}
		pre_Min[0] = a[0];  
		for (int i = 1; i < n; i++){
			pre_Min[i] = min(pre_Min[i-1],a[i]); 
		}
		int ans = max(pre_Min[0],suf_Min[1]); // [0,0],[1,n-1] partition 
		for (int i = 1; i < n-1; i++){
			// comparing max( min([0,i]),min([i+1,n-1])) 
			ans = max(ans,max(pre_Min[i],suf_Min[i+1])); 
		}
		cout << ans << endl; 
	}else if (k >= 3){
		// simply print maximum 
		int maxval = a[0];  
		for (int i = 1; i < n; i++){
			maxval = max(maxval,a[i]); 
		}
		cout << maxval << endl; 
	}
	return 0;  
}
