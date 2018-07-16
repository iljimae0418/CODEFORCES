#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <vector> 
#include <string> 
#include <set> 
#include <map> 
using namespace std; 
int main(){
	int n,ans = 0; 
	string a,b; 
	cin >> n >> a >> b; 
	for (int i = 0; i < n/2; i++){
		int j = n-i-1;  
		if (a[i] == b[i] && a[j] == b[j]) continue;  
		else if (a[i] == b[i] && a[j] != b[j]) ans++; 
		else if (a[i] != b[i] && a[j] == b[j]) ans++; 
		else if (a[i] != b[i] && a[j] != b[j]){
			set<int> st; 
			st.insert(a[i]); 
			st.insert(b[i]); 
			st.insert(a[j]); 
			st.insert(b[j]);  
			if (st.size() == 4){
				ans += 2; 
			}else if (st.size() == 3){
				ans++;  
				if (a[i] == a[j]) ans++;  
			}else if (st.size() == 2){
				ans += 0; // no changes need to be made. Think about it 
			}
		}
	}
	if (n%2 == 1){
		ans += (a[n/2] != b[n/2]); 
	}
	cout << ans << endl; 
	return 0; 
}
