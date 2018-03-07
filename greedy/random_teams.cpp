#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std; 
int main(){
	typedef long long ll; 
	ll n,m; 
	cin >> n >> m; 
	// compute min  
	if (n%m == 0){
		cout << m*((n/m)*(n/m - 1)/2) << " "; 
	}else{
		cout << (n%m)*((n/m + 1)*(n/m)/2) + (n-n%m)*((n/m)*(n/m-1)/2) << " "; 
	}
	// compute max 
	cout << (n-m+1)*(n-m)/2 << endl; 
	return 0; 
}
