#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std; 
// simply check for a cycle 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);  
int p[100005],seen[100005];  
int main(){
	IOFAST(); 
	int n,s,t;
	cin >> n >> s >> t;  
	for (int i = 1; i <= n; i++){
		cin >> p[i];  
	} 
	int cur = s, cnt = 0;  
	while (true){
		if (cur == t){
			cout << cnt << endl; 
			return 0;  
		}
		if (seen[cur]){ 
			// impossible 
			cout << -1 << endl; 
			return 0;  
		}
		seen[cur] = 1;  
		cur = p[cur];
		cnt++;    
	}
	return 0; 
}
