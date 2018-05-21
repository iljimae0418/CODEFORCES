#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <set> 
#include <vector> 
using namespace std; 
int main(){
	// george can simplify the difficulty of already prepared problems
	int n,m; 
	cin >> n >> m; 
	vector<int> v(n); 
	for (int i = 0; i < n; i++){
		cin >> v[i]; 
	}
	multiset<int> s; 
	for (int i = 0; i < m; i++){
		int x; 
		cin >> x; 
		s.insert(x); 
	}
	int cnt = 0; 
	for (int i = 0; i < n; i++){
		if (!s.count(v[i])){
			if (s.empty() || (!s.empty() && v[i] > *s.rbegin())){
				cnt++; // we need to prepare a new problem  
			}else{
				set<int>::iterator it = s.lower_bound(v[i]);  
				if (it != s.end()) s.erase(it);  
			}
		}
	}
	cout << cnt << endl; 
	return 0;  
}
