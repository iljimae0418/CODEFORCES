#include <iostream>
#include <cstdlib>
#include <map> 
#include <algorithm> 
using namespace std; 
int a[101]; 
int main(){
	map<int,int> mp; 
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
		mp[a[i]]++; 
	}
	int ans = 0;  
	for (map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
		ans = max(ans,it->second); 
	}
	cout << ans << endl;
	return 0; 
}
