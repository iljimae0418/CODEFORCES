#include <iostream>
#include <cstdlib>
#include <cmath> 
#include <algorithm>
using namespace std; 
typedef long long ll;  
ll a[200005],b[200005];
int main(){
	int n; 
	cin >> n; 
	for (int i = 1; i <= n; i++){
		cin >> b[i];  
	}
	ll ans = 0, add = 0;
	for (int i = 1; i <= n; i++){
		if (i == 1){
			if (a[i] == b[i]) continue; 
			else{
				ans += abs(b[i]-a[i]); 
				add += b[i]-a[i];   
			}
		}else{
			a[i] += add; 
			if (a[i] == b[i]) continue;  
			else{
				ans += abs(b[i]-a[i]); 
				add += b[i]-a[i];
			}
		}
	}
	cout << ans << endl; 
	return 0; 
}  
