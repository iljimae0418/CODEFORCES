#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <set> 
#include <vector> 
using namespace std; 
int a[101]; 
int main(){
	int n,k; 
	cin >> n >> k; 
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
	}
	set<int> st; 
	int cnt = 0;  
	vector<int> ans;  
	for (int i = 1; i <= n; i++){
		if (st.empty()){
			st.insert(a[i]); 
			cnt++;  
			ans.push_back(i);  
		}else{
			if (!st.count(a[i])){
				st.insert(a[i]);
				cnt++; 
				ans.push_back(i);  
			}
		}
	}
	if (cnt >= k){
		cout << "YES" << endl; 
		for (int i = 0; i < k; i++){
			cout << ans[i] << " "; 
		}
		cout << endl; 
	}else{
		cout << "NO" << endl; 
	}
	return 0; 
}
