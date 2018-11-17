#include <iostream>
#include <cstdlib>
#include <cmath> 
#include <vector>
#include <set> 
#include <cmath> 
#include <map> 
#include <algorithm>
using namespace std; 
int main(){
	int n, temp; 
	cin >> n;
	temp = n;  
	map<int,int> mp; 
	for (int i = 2; i*i <= temp; i++){
		while (temp%i == 0){
			mp[i]++;  
		 	temp /= i;  
		}
	}
	if (temp != 1) mp[temp]++;  
	vector<int> ans; 
	ans.push_back(n);  
	for (map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
		while (it->second > 0){
			n /= it->first; 
			ans.push_back(n); 
			it->second--;  
		}
	}
	sort(ans.begin(),ans.end(),greater<int>());  
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i] << " "; 
	}
	cout << endl; 
	return 0; 
}
