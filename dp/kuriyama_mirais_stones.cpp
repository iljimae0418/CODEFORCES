#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
typedef long long ll;  
ll v[100005];  
ll u[100005];  
ll psumv[100005]; 
ll psumu[100005];  
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL); 
	int n; 
	cin >> n; 
	for (int i = 1; i <= n; i++){
		cin >> v[i];  
		u[i] = v[i]; 
	}
	sort(u+1,u+n+1); 
	for (int i = 1; i <= n; i++){
		psumv[i] = psumv[i-1]+v[i];  
		psumu[i] = psumu[i-1]+u[i];  
	}
	int m;  
	cin >> m; 
	while (m--){
		int type,l,r; 
		cin >> type >> l >> r; 
		if (type == 1) cout << psumv[r]-psumv[l-1] << endl; 
		else cout << psumu[r]-psumu[l-1] << endl; 
	}
	return 0;  
}
