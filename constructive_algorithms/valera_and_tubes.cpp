#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
#include <set>
#include <map> 
using namespace std;  
typedef pair<int,int> P; 
const int MAXK = 300*300+11;  
vector<P> a[MAXK]; 
int grid[333][333];  
int main(){
	int n,m,k; 
	cin >> n >> m >> k; 
	int x = 1, y = 1;  
	for (int i = 1; i <= k; i++){
		if (i == k){
			while (x <= n){
				if (x%2 == 1){
					if (y > m){
						x = x+1;  
						y = y-1;  
						if (x > n) break; 
					}else{
						a[i].push_back(P(x,y));
						y = y+1;   
					}
				}else{
					if (y < 1){
						x = x+1;  
						y = y+1; 
						if (x > n) break; 
					}else{
						a[i].push_back(P(x,y)); 
						y = y-1; 
					}
				}
			}
			continue; 
		}
		if (x%2 == 1){
			if (y+1 > m){
				a[i].push_back(P(x,y)); 
				a[i].push_back(P(x+1,y)); 
				x = x+1; 
				y = y-1;  
			}else if (y+2 > m){
				a[i].push_back(P(x,y)); 
				a[i].push_back(P(x,y+1)); 
				x = x+1; 
				y = y+1; 
			}else{
				a[i].push_back(P(x,y));  
				a[i].push_back(P(x,y+1)); 
				y = y+2; 
			}
		}else{
			if (y-1 < 1){
				a[i].push_back(P(x,y));  
				a[i].push_back(P(x+1,y)); 
				x = x+1;  
				y = y+1;  
			}else if (y-2 < 1){
				a[i].push_back(P(x,y)); 
				a[i].push_back(P(x,y-1)); 
				x = x+1;  
				y = y-1;  
			}else{
				a[i].push_back(P(x,y)); 
				a[i].push_back(P(x,y-1)); 
				y = y-2;  
			}
		}	
	}
	for (int i = 1; i <= k; i++){
		cout << a[i].size() << " "; 
		for (int j = 0; j < a[i].size(); j++){
			cout << a[i][j].first << " " << a[i][j].second << " "; 
		} 
		cout << endl; 
	}
	return 0; 
}	
