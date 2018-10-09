#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 

int main(){
	typedef long long ll; 
	ll n,q; 
	cin >> n >> q;  
	if (n%2 == 0){
		while (q--){
			ll a,b; 
			cin >> a >> b; 
			if ((a+b)%2 == 0){
				cout << 1 + (a-1)*(n/2) + (a%2 == 0 ? (b-1)/2 : b/2) << endl;  
			}else{
				cout << (n*n/2 + 1) + (a-1)*(n/2) + (a%2 == 0 ? (b-1)/2 : b/2 - 1) << endl;  
			}
		}
	}else{
		while (q--){
			ll a,b; 
			cin >> a >> b;  
			if ((a+b)%2 == 0){
				cout << 1 + (a/2)*((n+1)/2) + ((a-1)/2)*(n/2) + (a%2 == 0 ? (b-1)/2 : b/2) << endl; 
			}else{
				cout << (n*n/2 + 1) + (a/2)*((n+1)/2) + ((a-1)/2)*(n/2) + (a%2 == 0 ? (b-1)/2 : b/2) << endl; 
			}
		}
	}
	return 0; 
}
