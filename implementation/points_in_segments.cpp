#include <iostream>
#include <cstdlib>
#include <vector> 
using namespace std;  
int a[111]; 
int main(){
	int n,m,cnt = 0; 
	cin >> n >> m; 
	for (int i = 0; i < n; i++){
		int l,r; 
		cin >> l >> r; 
		for (int j = l; j <= r; j++){
			a[j] = 1; 
		}
	}
	vector<int> ans; 
	for (int i = 1; i <= m; i++){
		if (!a[i]){
			cnt++; 
			ans.push_back(i); 
		}
	}
	cout << cnt << endl; 
	if (ans.empty()) return 0; 
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i] << " "; 
	}
	cout << endl; 
	return 0; 
}
