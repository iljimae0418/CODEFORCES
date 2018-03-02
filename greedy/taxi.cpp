#include <iostream>
#include <map> 
#include <algorithm>
using namespace std; 
int main(){
	int n; 
	cin >> n; 
	map<int,int> mp; 
	for (int i = 0; i < n; i++){
		int x; 
		cin >> x; 
		mp[x]++; 
	}
	int cnt = 0;  
	// 1,3 pairs 
	cnt += min(mp[1],mp[3]);
	int subtract = min(mp[1],mp[3]);    
	mp[1] -= subtract; 
	mp[3] -= subtract;
	// 2,2 pairs 
	cnt += mp[2]/2;  
	mp[2] %= 2;  
	// 1,1,2 triples 
	if (mp[2] == 1){
		if (mp[1] >= 2){
			cnt++; 
			mp[2]--;  
			mp[1] -= 2; 
		}else if (mp[1] >= 1){
			cnt++; 
			mp[2]--; 
			mp[1]--;  
		}
	}
	// add in the remaining 
	cnt += (mp[1]+4-1)/4 + (mp[2]+2-1)/2 + mp[3] + mp[4];  
	cout << cnt << endl;
	return 0; 
}		
