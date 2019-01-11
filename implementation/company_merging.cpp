#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std; 
vector<int> a[200005]; 
int maxval[200005];  
int main(){
	int n,m,x,ultimate = 0; 
	cin >> n; 
	for (int i = 1; i <= n; i++){	
		cin >> m;  
		for (int j = 0; j < m; j++){
			cin >> x;  
			a[i].push_back(x); 
			maxval[i] = max(maxval[i],x); 
		}
		ultimate = max(maxval[i],ultimate); 
	}
	long long ans = 0; 
	for (int i = 1; i <= n; i++){
		if (maxval[i] < ultimate){
			ans += (long long)a[i].size() * (long long)(ultimate-maxval[i]); 
		}
	}
	cout << ans << endl; 
	return 0; 
}
