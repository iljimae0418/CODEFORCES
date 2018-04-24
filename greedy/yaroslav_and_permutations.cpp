#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std; 
int a[111]; 
int main(){
	int n;
	cin >> n; 
	map<int,int> mp; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
		mp[a[i]]++;  
	}
	if (n == 1){ // edge case 
		cout << "YES" << endl;
		return 0;  
	}
	bool can = true;  
	for (int i = 0; i < n; i++){
		if (mp[a[i]] > (n+1)/2){
			can = false; 
			break; 
		}
	}
	if (can) cout << "YES" << endl; 
	else cout << "NO" << endl; 
}
