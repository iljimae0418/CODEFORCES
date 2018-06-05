#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring> 
#include <set> 
#include <map> 
using namespace std; 
int a[100005][2];
int tot[100005][2]; 
int main(){
	int n; 
	cin >> n; 
	map<int,set<int> > mp; 
	for (int i = 0; i < n; i++){
		cin >> a[i][0] >> a[i][1]; 
		tot[i][0] = tot[i][1] = n-1; 
		mp[a[i][0]].insert(i);   
	}
	// loop over away games, and look at how many home games except for current one 
	// is equal to current away game, call this cnt. Take away cnt from tot[i][1] and 
	// add cnt to tot[i][0] 
	for (int i = 0; i < n; i++){
		int away = a[i][1];  
		if (mp[away].empty()) continue;  
		int d = 0;  
		if (mp[away].count(i)){
			d--; 
		}
		d += mp[away].size();  
		tot[i][1] -= d; // cannot play d away games  
		tot[i][0] += d; // need to play additional d home games  
	}
	for (int i = 0; i < n; i++){
		cout << tot[i][0] << " " << tot[i][1] << endl; 
	}
	return 0; 
} 
