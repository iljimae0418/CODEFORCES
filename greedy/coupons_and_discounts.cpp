// one pizza for two consecutive days 
// two pizzas in one day  
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;  
int a[200005];  
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);  
	int n; 
	cin >> n; 
	for (int i = 1; i <= n; i++){
		cin >> a[i];  
	}
	bool can = true; 
	for (int i = 1; i <= n; i++){
		if (a[i]%2 == 0){
			a[i] = 0; // move on 
		}else if (a[i]%2 == 1 && i < n && a[i+1] > 0){
			// we use discounts to reduce a[i] down to 1
			// afterwards we use coupon to buy 1 pizza on the 
			// ith day. due to the coupon we also need to buy 1 pizza on the 
			// (i+1)th day  
			a[i] = 0; 
			a[i+1]--;  
		}else if (a[i]%2 == 1 && i == n){
			// all hope is lost 
			can = false; 
		}else{
			// all hope is lost 
			can = false; 
			break; 
		}
	}
	if (can) cout << "YES" << endl; 
	else cout << "NO" << endl; 
	return 0; 
}
