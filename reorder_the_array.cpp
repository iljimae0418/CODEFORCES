#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include <algorithm>
using namespace std; 
int a[100005];  
int main(){
	int n; 
	cin >> n; 
	map<int,int> mp;  
	for (int i = 0; i < n; i++){
		cin >> a[i];  
		mp[a[i]]++;  
	}
	int x = -1; 
	for (map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
		x = max(x,it->second);  
	}
	int ans = n-x; 
	cout << ans << endl; 
	return 0; 
}
