#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <map>
#include <vector> 
using namespace std; 
int a[100005];  
int main(){
	int n,k,m; 
	cin >> n >> k >> m; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
	}
	map<int,vector<int> > mp; 
	for (int i = 0; i < n; i++){
		mp[a[i]%m].push_back(a[i]); 
	}
	bool foundAns = false; 
	for (int i = 0; i < m; i++){
		if (mp[i].size() >= k){
			foundAns = true; 
			cout << "Yes" << endl; 
			vector<int> v = mp[i];  
			for (int j = 0; j < k; j++){
				cout << v[j] << " "; 
			}
			cout << endl;
			break; 
		}
	}
	if (!foundAns){
		cout << "No" << endl; 
	}
	return 0;  
}
