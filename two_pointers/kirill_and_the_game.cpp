#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
typedef long long ll; 
int main(){
	ll l,r,x,y,k; 
	cin >> l >> r >> x >> y >> k; 
	ll i = l, j = x; 
	bool found = false; 
	while (i <= r && j <= y){
		if (i == k*j){
			cout << "YES" << endl; 
			found = true;  
			break; 
		}else if (i < k*j){
			i++; 
		}else if (i > k*j){
			j++; 
		}
	}
	if (!found){
		cout << "NO" << endl; 
	}
	return 0; 
}
