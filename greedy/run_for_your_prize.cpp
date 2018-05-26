#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
const int INF = (int)2e9+88;  
int a[100005]; 
int main(){
	IOFAST(); 
	int f = 1, s = (int)1e6; // f: me, s: friend  
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
	} 
	int ans = -INF; 
	for (int i = 0; i < n; i++){
		ans = max(ans,min(abs(f-a[i]),abs(s-a[i])));  
	}
	cout << ans << endl; 
	return 0; 
}
