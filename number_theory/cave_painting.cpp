#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <set> 
using namespace std; 
typedef long long ll;  
int main(){
	ll n,k; 
	cin >> n >> k;  
	if (k == 1){
		cout << "Yes" << endl; 
	}else{
		if (n%2 == 0){
			cout << "No" << endl; 
		}else{
			if (k >= 50){
				cout << "No" << endl; 
			}else{
				set<ll> s; 
				for (ll i = 1; i <= k; i++){
					s.insert(n%i); 
				}
				cout << (s.size() == k ? "Yes" : "No") << endl; 
			}
		}
	}
	return 0;  
}
