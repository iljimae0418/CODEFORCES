#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map> 
using namespace std; 
int n,q; 
int a[200005]; 
int main(){
	cin >> n >> q; 
	map<int,int> mp;   
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
		mp[a[i]]++; 
	}
	while (q--){
		int x,cnt = 0; 
		cin >> x; 
		for (int i = 30; i >= 0; i--){	
			if (x == 0) break; 
			int k = -1;  
			if (mp.count(1<<i)){
				k = min(x/(1<<i),mp[(1<<i)]);  
			}
			if (k != -1){
				cnt += k;  
				x -= k*(1<<i);  
			}
		}
		if (x == 0) cout << cnt << endl; 
		else cout << -1 << endl; 
	}
	return 0; 
}
