#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring> 
#include <set> 
#include <vector> 
using namespace std; 
typedef long long ll;  
int main(int argc,char **argv){
	ll n; 
	cin >> n; 
	vector<ll> factors,ans; 
	for (ll i = 1; i*i <= n; i++){
		if (n%i == 0){
			if (n/i == i){
				factors.push_back(i);  
			}else{
				factors.push_back(i); 
				factors.push_back(n/i); 
			}
		}
	}
	for (int i = 0; i < factors.size(); i++){
		ll q = (n-1)/factors[i]; 
		ans.push_back(1+q+factors[i]*q*(q+1)/2); 
	}
	sort(ans.begin(),ans.end()); 
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	cout << endl; 
	return 0; 	
}
