#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map> 
using namespace std; 
int a[100005];  
int cnt[100005];  
int main(){
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
	}
	int l = 0,r = 0;  
	map<int,int> mp; 
	int maxLen = 0, maxval = a[l], minval = a[l]; 
	while (l < n){
		while (r < n && maxval-minval <= 1){
			mp[a[r]]++; 
			r++; 
			minval = min(minval,a[r]); 
			maxval = max(maxval,a[r]);   
		}
		maxLen = max(maxLen,r-l);
		if (mp.count(a[l])){
			// logic: we are going to increment left pointer 
			// delete the count of a[l] from map 
			// if count of a[l] is zero, then we don't have anymore values
			// equal to a[l] in our new range, so get rid of it in our map 
			// if a[l] was previously equal to min or maxval, update them 
			mp[a[l]]--; 
			if (mp[a[l]] == 0) mp.erase(a[l]);  
			// if a[l] does not exist in mp anymore and it was previously the range's 
			// min or max, we need to update the min and max values. 
			if (mp.size() > 0 && minval == a[l]) minval = mp.begin()->first; 
			if (mp.size() > 0 && maxval == a[l]) maxval = mp.rbegin()->first; 
		}
		l++;  
	}
	cout << maxLen << endl; 
	return 0;  
}
