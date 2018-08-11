#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll; 
int main(){
	ll n,m; 
	cin >> n >> m; 
	ll x, sum = 0, prev = 1LL;  
	for (int i = 0; i < m; i++){
		cin >> x; 
		sum += (x-prev + n)%n; 
		prev = x; 
	}	
	cout << sum << endl; 
	return 0; 
}
