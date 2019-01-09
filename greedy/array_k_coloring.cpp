#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
#include <map> 
#include <set> 
using namespace std; 
typedef pair<int,int> P; 
P a[5005];
int c[5005]; // colors 
vector<int> info[5005]; 
map<int,int> mp;  
int main(){
	int n,k,maxSize = 0; 
	cin >> n >> k; 
	for (int i = 1; i <= n; i++){
		cin >> a[i].first; 
		a[i].second = i;  
		mp[a[i].first]++; 
		maxSize = max(maxSize,mp[a[i].first]); 
	}
	if (maxSize > k){
		cout << "NO" << endl; 
		return 0; 
	} 
	sort(a+1,a+n+1);
	int color = 1;  
	for (int i = 1; i <= n; i++){
		if (color == k+1) color = 1; 
		c[a[i].second] = color++; 
	} 
	cout << "YES" << endl; 
	for (int i = 1; i <= n; i++){
		cout << c[i] << " "; 
	}
	cout << endl; 
	return 0; 
}
