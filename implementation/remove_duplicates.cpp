#include <iostream>
#include <cstdlib> 
#include <vector>
#include <algorithm>
#include <map> 
using namespace std; 
int a[55];  
int main(){
	int n; 
	cin >> n; 
	map<int,int> mp; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
		mp[a[i]]++;  
	}
	vector<int> ans; 
	for (int i = 0; i < n; i++){
		if (mp[a[i]] == 1){
			ans.push_back(a[i]); 
			mp[a[i]]--; 
		}else if (mp[a[i]] > 1){
			mp[a[i]]--;  
		}
	}
	cout << ans.size() << endl; 
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i] << " "; 
	}
	cout << endl; 
	return 0; 
}
