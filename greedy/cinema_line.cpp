#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <map> 
using namespace std; 
map<int,int> mp; 
int main(){
	int n,x; 
	cin >> n; 
	bool can = true;   
	mp[25] = 0, mp[50] = 0;  
	for (int i = 0; i < n; i++){
		cin >> x;  
		if (x == 25){
			mp[25]++;  
		}else if (x == 50){
			if (mp[25] >= 1){
				mp[25]--;  
				mp[50]++; 
			}else{
				can = false;  
			}
		}else if (x == 100){
			if (mp[25] >= 1 && mp[50] >= 1){
				mp[25]--; 
				mp[50]--;  
			}else if (mp[25] >= 3){
				mp[25] -= 3; 
			}else{
				can = false; 
			}
		}
	}	
	if (can) cout << "YES" << endl; 
	else cout << "NO" << endl; 
	return 0; 
}
