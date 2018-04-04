#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <map>
#include <vector>
using namespace std; 
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	map<int,int> mp,tmp1,tmp2; 
	int n,x; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> x; 
		mp[x]++; 
	}
	int ans1 = -1,ans2 = -1; 
	for (int i = 0; i < n-1; i++){
		cin >> x; 
		tmp1[x]++;  
	}
	for (map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
		if (it->second == tmp1[it->first]+1){
			ans1 = it->first; 
			break; 
		}
	}
	for (int i = 0; i < n-2; i++){
		cin >> x; 
		tmp2[x]++; 
	}
	for (map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
		if (it->first == ans1){
			if (it->second == tmp2[it->first]+2){
				ans2 = it->first; 
				break; 
			}
		}else if (it->second == tmp2[it->first]+1){
			ans2 = it->first; 
			break; 
		}
	}
	cout << ans1 << endl; 
	cout << ans2 << endl; 
	return 0; 
}
