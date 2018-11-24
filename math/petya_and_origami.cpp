#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std; 
typedef long long ll;  
int main(){
	ll n,k; 
	cin >> n >> k; 
	ll r = 2LL * n; 
	ll g = 5LL * n; 
	ll b = 8LL * n;  
	cout << (r+k-1)/k + (g+k-1)/k + (b+k-1)/k << endl; 
	return 0;   
}
