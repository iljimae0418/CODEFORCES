#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <map> 
using namespace std; 
int main(){
	int n; 
	cin >> n; 
	int p,q,x; 
	cin >> p; 
	map<int,int> mp;  
	for (int i = 0; i < p; i++){
		cin >> x; 
		mp[x]++;  
	}
	cin >> q; 
	for (int i = 0; i < q; i++){
		cin >> x; 
		mp[x]++; 
	}
	bool flag = true; 
	for (int i = 1; i <= n; i++){
		if (mp[i] == 0){
			flag = false; 
			break; 
		}
	}
	if (flag) cout << "I become the guy." << endl; 
	else cout << "Oh, my keyboard!" << endl; 
	return 0; 
}
