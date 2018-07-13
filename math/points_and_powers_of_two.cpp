#include <iostream>
#include <cstdlib>
#include <set>
#include <vector> 
using namespace std; 
int x[200005]; 
int main(){
	int n; 
	cin >> n; 
	set<int> st;  
	for (int i = 0; i < n; i++){
		cin >> x[i];
		st.insert(x[i]);  
	}
	// check if 3
	vector<int> v; 
	int ans = 0;  
	for (int j = 0; j <= 30; j++){
		int p = (1<<j); 
		for (int i = 0; i < n; i++){
			if (st.count(x[i]+p) && st.count(x[i]-p)){
				if (3 > ans){
					ans = 3; 
					v.clear(); 
					v.push_back(x[i]); 
					v.push_back(x[i]+p); 
					v.push_back(x[i]-p); 
				}
			}else if (st.count(x[i]+p)){
				if (2 > ans){
					ans = 2; 
					v.clear(); 
					v.push_back(x[i]);  
					v.push_back(x[i]+p);  
				} 
			}
		}
	}
	if (ans < 2){
		cout << 1 << endl; 
		cout << x[0] << endl; 
	}else{
		cout << ans << endl; 
		for (int i = 0; i < v.size(); i++){
			cout << v[i] << " "; 
		}
		cout << endl; 
	}
	return 0; 
}
