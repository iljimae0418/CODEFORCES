#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring> 
#include <cassert> 
using namespace std; 
int n,m;  
int a[200005],cnt[200005]; 
int main(){
	vector<int> v;  
	cin >> n >> m; 
	for (int i = 1; i <= n; i++){
		cin >> a[i];  
		v.push_back(a[i]); 
	}
	sort(v.begin(),v.end()); 
	for (int i = 0; i < m; i++){
		int s,t; 
		cin >> s >> t; 
		if (a[s] > a[t]) cnt[s]--; 
		if (a[s] < a[t]) cnt[t]--;   
	}
	for (int i = 1; i <= n; i++){
		int add = lower_bound(v.begin(),v.end(),a[i])-v.begin();  
		cout << cnt[i]+add << " ";  
	}	
	cout << endl; 
	return 0; 
}
