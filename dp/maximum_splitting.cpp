#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std; 
int a[3] = {4,6,9}; 
int main(){
	vector<int> ans(16,-1);  
	ans[0] = 0; 
	for (int i = 1; i < 16; i++){
		for (int j = 0; j < 3; j++){
			if (i >= a[j] && ans[i-a[j]] != -1){
				ans[i] = max(ans[i],ans[i-a[j]]+1);  
			}
		}
	}
	int q; 
	cin >> q; 
	while (q--){
		int n; 
		cin >> n; 
		if (n < 16){
			cout << ans[n] << endl; 
		}else{
			int t = (n-16)/4 + 1; 
			cout << t + ans[n-4*t] << endl; 
		}
	}
	return 0; 
}
