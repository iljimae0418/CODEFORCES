#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std; 
#define UPPER 200000
#define INF 99999999
vector<int> p; 
int prime[200005];  
int grid[505][505]; 
int rowScore[505],colScore[505]; 
void eratos(){
	for (int i = 0; i < UPPER; i++){
		prime[i] = 1;  
	}
	prime[0] = prime[1] = 0; 
	for (long long i = 2; i < (long long)UPPER; i++){
		if (prime[i]){
			p.push_back(i);  
			for (long long j = i*i; j < (long long)UPPER; j += i){
				prime[j] = 0;  
			}
		}
	}
}
int main(){
	int n,m; 
	cin >> n >> m; 
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> grid[i][j]; 
		}
	}
	eratos();  
	int ans = INF;  
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			int x = grid[i][j]; 
			rowScore[i] += *lower_bound(p.begin(),p.end(),x)-x;  
		}
		ans = min(ans,rowScore[i]); 
	}
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			int x = grid[j][i];  
			colScore[i] += *lower_bound(p.begin(),p.end(),x)-x;  
		}
		ans = min(ans,colScore[i]);  
	}
	cout << ans << endl; 
	return 0; 
}
