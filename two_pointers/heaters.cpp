#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
#include <map> 
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
#define INF (int)2e9 
int a[1005]; 
int p[1005]; // p[i] = position i is covered by switching on the switch p[i] 
int n,r; 
int main(){
	cin >> n >> r; 
	int ans = 0;  
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
		if (a[i]){
			for (int pos = max(1,i-r+1); pos <= min(n,i+r-1); pos++){
				p[pos] = max(p[pos],i);  
			}
		}
	}
	int idx = 1; 
	while (idx <= n){
		if (p[idx] == 0){
			cout << -1 << endl;
			return 0; 
		}
		ans++; 
		idx = p[idx]+r; // jump to the next uncovered position 
	}
	cout << ans << endl; 
	return 0; 
}
