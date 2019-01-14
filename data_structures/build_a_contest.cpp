#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std; 
int a[100005],cnt[100005]; 
typedef pair<int,int> P;  
int main(int argc,char **argv){
	int n,m;  
	cin >> n >> m;  
	set<P> st; 
	for (int i = 1; i <= n; i++){
		st.insert(P(0,i));  
	}
	int ans = 0;  
	string out = ""; 
	for (int i = 1; i <= m; i++){
		cin >> a[i]; 
		st.erase(P(cnt[a[i]],a[i]));  
		st.insert(P(++cnt[a[i]],a[i])); 
		int mn = (*st.begin()).first; // this takes out the least element in set    
		if (mn > ans){
			ans++; 
			out += "1"; 
		}else{
			out += "0"; 
		}
	}
	cout << out << endl; 
	return 0; 
}
