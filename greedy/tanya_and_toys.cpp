#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <vector> 
using namespace std; 
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);   
	int n,m,x; 
	cin >> n >> m; 
	set<int> has;  
	for (int i = 0; i < n; i++){
		cin >> x; 
		has.insert(x);  
	}
	vector<int> ans; 
	int sum = 0;  
	for (int i = 1;;i++){
		if (sum+i > m) break; 
		if (!has.count(i)){
			sum += i;  
			ans.push_back(i);  
		}
	}
	cout << ans.size() << endl; 
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i] << " "; 
	}
	cout << endl; 
	return 0; 
}
