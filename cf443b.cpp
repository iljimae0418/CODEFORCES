#include <iostream>
#include <cstdlib>
#include <deque> 
#include <algorithm>
using namespace std; 
typedef long long ll; 
ll a[501]; 
ll wincnt[501]; 
ll n,k;  
int main(){
	cin >> n >> k; 
	ll maxval = 0, pos = -1; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
		if (maxval < a[i]){
			maxval = a[i]; 
			pos = i; 
		}
	}
	for (int i = 0; i <= pos; i++){
		for (int j = (i-1 >= 0 ? i-1 : i+1); j <= pos; j++){
			if (a[i] < a[j]){
				break; 
			}else if (a[i] > a[j]){ 
				wincnt[a[i]]++;  
			}
		}
	}
	for (int i = 0; i <= pos; i++){
		if (wincnt[a[i]] >= k){
			cout << a[i] << endl; 
			return 0; 
		}
	}
	cout << maxval << endl; 
	return 0; 
}
