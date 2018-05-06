#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map> 
#include <set> 
using namespace std; 
int a[200005]; 
set<int> seen;  
int main(){
	int n,k; 
	cin >> n >> k; 
	map<int,int> mp; 
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
		mp[a[i]]++;  
	}
	sort(a+1,a+n+1); 
	if (k == 0){
		if (a[1] == 1) cout << -1 << endl; 
		else cout << 1 << endl; 
		return 0;  
	}
	int cmp = 0; 
	for (int i = 1; i <= k; i++){
		if (!seen.count(a[i])){
			seen.insert(a[i]);    
			cmp += mp[a[i]]; 
		}
	}
	if (cmp == k && a[k] >= 1 && a[k] <= (int)1e9) cout << a[k] << endl;
	else cout << -1 << endl; 
	return 0;  
}
