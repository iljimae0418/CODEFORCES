// http://codeforces.com/contest/401/problem/C
#include <iostream>
#include <cstdlib>
#include <cstring> 
#include <algorithm> 
#include <vector> 
using namespace std; 
// n: cards with 0, m: cards with 1 
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL); 
	int n,m,orig_n,orig_m; 
	cin >> n >> m; 
	orig_n = n; 
	orig_m = m; 
	if (n-1 <= m && m <= 2*(n+1)){
		if (n == m){
			// print a sequence of alternating 0s and 1s 
			for (int i = 1; i <= 2*n; i++){
				if (i%2) cout << 1; 
				else cout << 0; 
			}
			cout << endl; 
		}else if (m < n){
			// still print a sequence of alternating 0s and 1s 
			// also it must be that m = n-1 in this case 
			cout << 0; 
			for (int i = 1; i <= 2*m; i++){
				if (i%2) cout << 1; 
				else cout << 0; 
			}
			cout << endl; 
		}else if (m > n){
			int turn = 0;  
			int idx = 0;  
			vector<int> v(n+m+5); 
			while (n){
				if (!turn){
					// every even index is 1 
					v[idx] = 1; 
					m--;  
				}else{
					v[idx] = 0; 
					n--;  
				}
				turn = !turn; 
				idx++;  
			} 
			int idx2 = 0; 
			while (m){
				if (v[idx2] == 1){
					v[idx2] = 11; 
					m--; 
				}else if (v[idx2] == 0){
					if (m == 2){
						v[idx2] = 11; 
						m -= 2; 
					}else{
						v[idx2] = 1; 
						m--; 
					}
				}
				idx2 += 2;  
			}
			idx--, idx2 -= 2;  
			for (int i = 0; i <= max(idx,idx2); i++){
				cout << v[i]; 
			}
			cout << endl; 
		}
	}else{
		// impossible cases
		cout << -1 << endl; 
	}
	return 0; 
}
