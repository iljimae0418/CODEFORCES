// having minimum number of changes is top priority 
// with minimum changes, we have to make minimum lexicographical order 
#include <iostream>
#include <algorithm> 
#include <cstdlib>
#include <vector>
using namespace std; 
int a[200001]; 
int cnt[200001]; 
int seen[200001]; // have we seen this number before we are at 
// our current position? 
int main(){
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i];  
		cnt[a[i]]++; 
	}
	vector<int> need; 
	for (int i = 1; i <= n; i++){
		if (cnt[i] == 0) need.push_back(i); 
	}
	int ans = need.size(); 
	int pos = 0;  
	for (int i = 0; i < n; i++){
		if (cnt[a[i]] <= 1) continue; 
		if (pos >= need.size()) continue; 
		if (a[i] > need[pos]){
			// decrease cnt first, then make modification to the array. 
			cnt[a[i]]--; 
			a[i] = need[pos++]; 
		}
		if (seen[a[i]]){
			cnt[a[i]]--; 
			a[i] = need[pos++]; 
		}
		seen[a[i]] = 1; // mark that we've seen this number 
		// before we move on. 
	}
	cout << ans << endl; 
	for (int i = 0; i < n; i++){
		cout << a[i] << " "; 
	}
	cout << endl; 
	return 0; 
}
