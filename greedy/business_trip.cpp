#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std;  
int a[12]; 
int main(){
	int k; 
	cin >> k;  
	for (int i = 0; i < 12; i++){
		cin >> a[i]; 
	}
	if (k == 0){
		cout << 0 << endl; 
		return 0; 
	}
	sort(a,a+12); 
	int cnt = 0, idx = 11;  
	while (k > 0 && idx >= 0){
		k -= a[idx];  
		idx--; 
		cnt++; 
	}
	if (k <= 0) cout << cnt << endl; 
	else cout << -1 << endl; 
	return 0; 
}
