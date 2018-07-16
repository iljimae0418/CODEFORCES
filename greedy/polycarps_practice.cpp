#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <vector> 
#include <set> 
#include <map> 
using namespace std; 
int a[2002]; 
int b[2002]; 
int used[2002]; 
typedef pair<int,int> P; 
int main(){
	int n,k; 
	cin >> n >> k; 
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
		b[i] = a[i];  
	}
	sort(a+1,a+n+1); 
	int sum = 0; 
	map<int,int> mp; 
	for (int i = n; i >= n-k+1; i--){
		sum += a[i]; 
		mp[a[i]]++;  
	}   
	vector<P> ans;  
	int start = 1;  
	for (int i = 1; i <= n; i++){
		if (mp.count(b[i]) && mp[b[i]] > 0){
			ans.push_back(P(start,i)); 
			mp[b[i]]--;  
			start = i+1; 
		}
	}
	cout << sum << endl; 
	for (int i = 0; i < ans.size(); i++){
		if (i == ans.size()-1 && ans[i].second < n){
			ans[i].second = n; 
		} 
		cout << ans[i].second - ans[i].first + 1 << " ";  
	}
	cout << endl; 
	return 0; 
}
