#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
#include <map> 
using namespace std;  
int a[101]; 
int n,m;  
vector<int> freq; 
bool ok(int x){
	if (x == 0) return true;  
	int cnt = 0; 
	for (int i = 0; i < freq.size(); i++){
		cnt += freq[i]/x; 
	} 
	return cnt >= n; 
}
int main(){
	cin >> n >> m; 
	map<int,int> mp; 
	for (int i = 0; i < m; i++){
		cin >> a[i]; 
		mp[a[i]]++; 
	} 
	for (map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
		freq.push_back(it->second); 
	}
	// conduct binary search algorithm  
	int l = 0, r = m, ans = 0; 
	while (l <= r){
		int mid = (l+r)>>1; 
		if (ok(mid)){
			l = mid+1;  
			ans = mid; 
		}else{
			r = mid-1;  
		}
	}
	cout << ans << endl; 
	return 0;  
}
